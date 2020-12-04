#ifndef SCENE_H
#define SCENE_H

#include "CS123SceneData.h"
#include "shapes/Shape.h"

class Camera;
class CS123ISceneParser;


/**
 * @class Scene
 *
 * @brief This is the base class for all scenes. Modify this class if you want to provide
 * common functionality to all your scenes.
 */
class Scene {
public:
    Scene();
    Scene(Scene &scene);
    virtual ~Scene();

    virtual void settingsChanged() {}

    static void parse(Scene *sceneToFill, CS123ISceneParser *parser);
    const std::vector<myPrimitive> &getPrimtivesList();
    CS123SceneGlobalData getGlobalData();
    std::vector<CS123SceneLightData> getLightsList();

protected:
    std::vector<myPrimitive> m_PrimitivesList;
    std::vector<CS123SceneLightData> m_LightsList;
    CS123SceneGlobalData m_Global;

    std::unique_ptr<Shape> m_Cube;
    std::unique_ptr<Shape> m_Sphere;
    std::unique_ptr<Shape> m_Cylinder;
    std::unique_ptr<Shape> m_Cone;


    // Adds a primitive to the scene.
    virtual void addPrimitive(const CS123ScenePrimitive &scenePrimitive, const glm::mat4x4 &matrix);

    // Sets the global data for the scene.
    virtual void setGlobal(const CS123SceneGlobalData &global);

    //traverses using dfs
    static void dfs(Scene *sceneToFill, const CS123SceneNode &node, const glm::mat4x4 &matrix);


};

#endif // SCENE_H
