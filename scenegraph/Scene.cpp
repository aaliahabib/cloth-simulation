#include "Scene.h"
#include "Camera.h"
#include "CS123ISceneParser.h"

#include "glm/gtx/transform.hpp"
#include <string.h>
#include <iostream>

Scene::Scene()
{
}

Scene::Scene(Scene &scene)
{
    // We need to set the global constants to one when we duplicate a scene,
    // otherwise the global constants will be double counted (squared)
    CS123SceneGlobalData global = { 1, 1, 1, 1};
    setGlobal(global);

    // TODO [INTERSECT]
    // Make sure to copy over the lights and the scenegraph from the old scene,
    // as well as any other member variables your new scene will need.

    //set up lights list
    CS123SceneLightData sceneLightData;
    for(int i = 0; i < scene.m_LightsList.size(); i++){
        sceneLightData = scene.m_LightsList.at(i);
        CS123SceneLightData toAdd;
        memcpy(&toAdd, &sceneLightData, sizeof(CS123SceneLightData));
        m_LightsList.push_back(toAdd);
    }

    //set global data
    m_Global.ka = scene.m_Global.ka;
    m_Global.kd = scene.m_Global.kd;
    m_Global.ks = scene.m_Global.ks;
    m_Global.kt = scene.m_Global.kt;

    //set up primitives list
    myPrimitive scenePrimitive;
    for(int i = 0; i < scene.m_PrimitivesList.size(); i++){
        scenePrimitive = scene.m_PrimitivesList.at(i);
        myPrimitive toAdd;

        toAdd.type = scenePrimitive.type;

        toAdd.material = scenePrimitive.material;
        toAdd.image = QImage(QString::fromStdString(toAdd.material.textureMap.filename));

        if(!toAdd.image.isNull()){
            toAdd.image = toAdd.image.convertToFormat(QImage::Format_RGB888);
        }
        toAdd.cumulative_matrix = glm::mat4x4(scenePrimitive.cumulative_matrix);
        toAdd.inverse_matrix = glm::inverse(toAdd.cumulative_matrix);

        m_PrimitivesList.push_back(toAdd);
    }
}

Scene::~Scene()
{
    // Do not delete m_camera, it is owned by SupportCanvas3D
}

const std::vector<myPrimitive>& Scene::getPrimtivesList(){
    return m_PrimitivesList;
}

CS123SceneGlobalData Scene::getGlobalData(){
    return m_Global;
}

std::vector<CS123SceneLightData> Scene::getLightsList(){
    return m_LightsList;
}

void Scene::parse(Scene *sceneToFill, CS123ISceneParser *parser) {
    CS123SceneNode* root = parser->getRootNode();
    if (root == nullptr){
        return;
    }

    //set up lights
    int i = 0;
    CS123SceneLightData data;
    int res = parser->getLightData(i, data);
    while (res){
        CS123SceneLightData realData;
        memcpy(&realData, &data, sizeof(CS123SceneLightData));
        sceneToFill->m_LightsList.push_back(realData);

        i++;
        res = parser->getLightData(i, data);
    }

    //set up global data
    parser->getGlobalData(sceneToFill->m_Global);

    //read primitives
    glm::mat4x4 identity =  glm::mat4x4(1.0f);

    dfs(sceneToFill, *root, identity);

}

void Scene::dfs(Scene *sceneToFill, const CS123SceneNode &node, const glm::mat4x4 &matrix){
    //build matrix
    glm::mat4x4 node_matrix = glm::mat4x4(1.0f);
    for(int i = 0; i < node.transformations.size(); i++){
        CS123SceneTransformation* t = node.transformations.at(i);
        
        switch(t->type){
            case TRANSFORMATION_TRANSLATE:
                node_matrix = glm::translate(node_matrix, t->translate);
                break;
            case TRANSFORMATION_SCALE:
                node_matrix = glm::scale(node_matrix, t->scale);
                break;
            case TRANSFORMATION_ROTATE: 
                node_matrix = glm::rotate(node_matrix, t->angle, t->rotate);
                break;
            case TRANSFORMATION_MATRIX:
                node_matrix = matrix*t->matrix;
                break;
            default:
                break;
        }
    }
    
    if (node.children.size() == 0){

        for(int i = 0; i < node.primitives.size(); i++){
            sceneToFill->addPrimitive(*node.primitives.at(i), matrix*node_matrix);
        }
        return;
    }
    for (int i = 0; i < node.children.size(); i++){
        dfs(sceneToFill, *node.children.at(i), matrix*node_matrix);
    }

}

void Scene::addPrimitive(const CS123ScenePrimitive &scenePrimitive, const glm::mat4x4 &matrix) {
    myPrimitive toAdd;

    toAdd.type = scenePrimitive.type;

    toAdd.material = scenePrimitive.material;

    toAdd.material.cAmbient = m_Global.ka*toAdd.material.cAmbient;
    toAdd.material.cDiffuse = m_Global.kd*toAdd.material.cDiffuse;

    toAdd.cumulative_matrix = glm::mat4x4(matrix);

    m_PrimitivesList.push_back(toAdd);
}

void Scene::setGlobal(const CS123SceneGlobalData &global) {
    m_Global = global;
}

