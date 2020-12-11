#include "ShapesScene.h"
#include "Camera.h"
#include "shapes/Shape.h"
#include <SupportCanvas3D.h>
#include <QFileDialog>

#include <sstream>

#include "shapes/Cube.h"
#include "shapes/Cylinder.h"
#include "shapes/Cone.h"
#include "shapes/Sphere.h"
#include "shapes/Sheet.h"

using namespace CS123::GL;
#include "gl/shaders/CS123Shader.h"
#include "gl/shaders/Shader.h"

#include "ResourceLoader.h"

#include <unistd.h>
#include <iostream>

#include "gl/textures/Texture2D.h"
#include "gl/textures/TextureParametersBuilder.h"

const float SPHERE_TESSELLATION = 100.0f;

ShapesScene::ShapesScene(int width, int height) :
    m_width(width),
    m_height(height),
    m_sheet(std::make_unique<Sheet>(settings.shapeParameter1, settings.shapeParameter2)),
    m_textureMap()
{
    if (settings.intersectionType == SPHERE) {
        m_sphere = std::make_unique<Sphere>(settings.intersectionRadius, SPHERE_TESSELLATION, SPHERE_TESSELLATION);
    }
    m_square = std::make_unique<Cube>(10, 10);


    loadTextures("/Users/Adam/Desktop/brown/Junior/course/cs1230/data/image/cat.jpg", 0);
    loadTextures("/Users/Adam/Desktop/brown/Junior/course/cs1230/data/image/cheeseTexture.jpg", 1);
    loadTextures("/Users/Adam/Desktop/brown/Junior/course/cs1230/data/image/fabricchessboard.png", 2);
    loadTextures("/Users/Adam/Desktop/brown/Junior/course/cs1230/data/image/fabricchessboard.png", 3);

    initializeSceneMaterial();
    initializeSceneLight();
    loadPhongShader();
    loadWireframeShader();
    loadNormalsShader();
    loadNormalsArrowShader();

}

ShapesScene::~ShapesScene()
{
    // Pro-tip: If you use smart pointers properly, this destructor should be empty
}

void ShapesScene::initializeSceneMaterial() {
//    // Use a shiny orange material
//    m_material.clear();
//    m_material.cAmbient.r = 0.2f;
//    m_material.cAmbient.g = 0.1f;
//    m_material.cDiffuse.r = 1.0f;
//    m_material.cDiffuse.g = 0.5f;
//    m_material.cSpecular.r = m_material.cSpecular.g = m_material.cSpecular.b = 0.4f;
//    m_material.shininess = 80;

    //slightly shiny white
    m_material.clear();
    m_material.cAmbient.r = 0.2f;
    m_material.cAmbient.g = 0.1f;
    m_material.cAmbient.a = 0.5f;
    m_material.cDiffuse.r = 1.0f;
    m_material.cDiffuse.g = 1.0f;
    m_material.cDiffuse.b = 1.0f;
    m_material.cDiffuse.a = 0.5f;
    m_material.cSpecular.r = m_material.cSpecular.g = m_material.cSpecular.b = 0.f;
    m_material.shininess = 100;

    //matte blue
    m_materialSphere.clear();
    m_materialSphere.cAmbient.g = 0.1f;
    m_materialSphere.cAmbient.b = 0.4f;
    m_materialSphere.cDiffuse.r = 0.3f;
    m_materialSphere.cDiffuse.g = 0.3f;
    m_materialSphere.cDiffuse.b = 0.3f;
    m_materialSphere.cSpecular.r = m_materialSphere.cSpecular.g = m_materialSphere.cSpecular.b = 0.5f;
    m_materialSphere.shininess = 100;
}

void ShapesScene::initializeSceneLight() {
    // Use a white directional light from the upper left corner
    memset(&m_light, 0, sizeof(m_light));
    m_light.type = LightType::LIGHT_DIRECTIONAL;
    m_light.dir = m_lightDirection;
    m_light.color.r = m_light.color.g = m_light.color.b = 1;
    m_light.id = 0;

    memset(&m_light2, 0, sizeof(m_light2));
    m_light2.type = LightType::LIGHT_DIRECTIONAL;
    m_light2.dir = m_lightDirection;
    m_light2.color.r = m_light2.color.g = m_light2.color.b = 0.5;
    m_light2.id = 1;
}

void ShapesScene::loadPhongShader() {
    std::string vertexSource = ResourceLoader::loadResourceFileToString(":/shaders/default.vert");
    std::string fragmentSource = ResourceLoader::loadResourceFileToString(":/shaders/default.frag");
    m_phongShader = std::make_unique<CS123Shader>(vertexSource, fragmentSource);
}

void ShapesScene::loadWireframeShader() {
    std::string vertexSource = ResourceLoader::loadResourceFileToString(":/shaders/wireframe.vert");
    std::string fragmentSource = ResourceLoader::loadResourceFileToString(":/shaders/wireframe.frag");
    m_wireframeShader = std::make_unique<Shader>(vertexSource, fragmentSource);
}

void ShapesScene::loadNormalsShader() {
    std::string vertexSource = ResourceLoader::loadResourceFileToString(":/shaders/normals.vert");
    std::string geometrySource = ResourceLoader::loadResourceFileToString(":/shaders/normals.gsh");
    std::string fragmentSource = ResourceLoader::loadResourceFileToString(":/shaders/normals.frag");
    m_normalsShader = std::make_unique<Shader>(vertexSource, geometrySource, fragmentSource);
}

void ShapesScene::loadNormalsArrowShader() {
    std::string vertexSource = ResourceLoader::loadResourceFileToString(":/shaders/normalsArrow.vert");
    std::string geometrySource = ResourceLoader::loadResourceFileToString(":/shaders/normalsArrow.gsh");
    std::string fragmentSource = ResourceLoader::loadResourceFileToString(":/shaders/normalsArrow.frag");
    m_normalsArrowShader = std::make_unique<Shader>(vertexSource, geometrySource, fragmentSource);
}

void ShapesScene::render(SupportCanvas3D *context) {
    // Clear the screen in preparation for the next frame. (Use a gray background instead of a
    // black one for drawing wireframe or normals so they will show up against the background.)
    setClearColor();

    renderPhongPass(context);

    if (settings.drawWireframe) {
        renderWireframePass(context);
    }

    if (settings.drawNormals) {
        renderNormalsPass(context);
    }
}

void ShapesScene::renderPhongPass(SupportCanvas3D *context) {
    m_phongShader->bind();

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    clearLights();
    setLights(context->getCamera()->getViewMatrix());

    setMatrixUniforms(m_phongShader.get(), context);
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

    if (m_sphere) {
        setPhongSceneUniforms(m_materialSphere);
        m_sphere->draw();
    }
    if (m_square) {
        setPhongSceneUniforms(m_materialSphere);
        m_square->draw();
    }

    if (m_sheet) {
        setPhongSceneUniforms(m_material);
        enableTexture();
        m_sheet->draw();
    }


    //renderGeometryAsFilledPolygons();

    m_phongShader->unbind();
}

void ShapesScene::setPhongSceneUniforms(const CS123SceneMaterial &m) {
    m_phongShader->setUniform("useLighting", settings.useLighting);
    m_phongShader->setUniform("useArrowOffsets", false);

    m_phongShader->applyMaterial(m);

    m_phongShader->setUniform("useTexture", 0); //turn of texture by default. If it's the sheet it will be turned back on
}

void ShapesScene::setMatrixUniforms(Shader *shader, SupportCanvas3D *context) {
    shader->setUniform("p", context->getCamera()->getProjectionMatrix());
    shader->setUniform("v", context->getCamera()->getViewMatrix());
    shader->setUniform("m", glm::mat4(1.0f));
}

void ShapesScene::renderGeometryAsFilledPolygons() {
    renderGeometry();
}

void ShapesScene::renderWireframePass(SupportCanvas3D *context) {
    m_wireframeShader->bind();
    setMatrixUniforms(m_wireframeShader.get(), context);
    renderGeometryAsWireframe();
    m_wireframeShader->unbind();
}

void ShapesScene::renderGeometryAsWireframe() {
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    renderGeometry();
}

void ShapesScene::renderNormalsPass (SupportCanvas3D *context) {
    // Render the lines.
    m_normalsShader->bind();
    setMatrixUniforms(m_normalsShader.get(), context);
    renderGeometryAsWireframe();
    m_normalsShader->unbind();

    // Render the arrows.
    m_normalsArrowShader->bind();
    setMatrixUniforms(m_normalsArrowShader.get(), context);
    renderGeometryAsFilledPolygons();
    m_normalsArrowShader->unbind();
}

void ShapesScene::renderGeometry() {
//    if (m_sheet) {
//        m_sheet->draw();
//    }
//    if (m_sphere) {
//        m_sphere->draw();
//    }
}

void ShapesScene::updateCloth() {
    if (m_sheet) {
        m_sheet->updateVertexSet();
        m_sheet->draw();
    }
}

void ShapesScene::clearLights() {
    for (int i = 0; i < MAX_NUM_LIGHTS; i++) {
        std::ostringstream os;
        os << i;
        std::string indexString = "[" + os.str() + "]"; // e.g. [0], [1], etc.
        m_phongShader->setUniform("lightColors" + indexString, glm::vec3(0.0f, 0.0f, 0.0f));
    }
}

void ShapesScene::setLights(const glm::mat4 viewMatrix) {
    // YOU DON'T NEED TO TOUCH THIS METHOD, unless you want to do fancy lighting...

    m_light.dir = glm::inverse(viewMatrix) * m_lightDirection;
    m_light2.dir = glm::inverse(viewMatrix) * m_lightDirection2;

    clearLights();
    m_phongShader->setLight(m_light);
    m_phongShader->setLight(m_light2);
}

void ShapesScene::settingsChanged() {
        m_sheet = std::make_unique<Sheet>(settings.shapeParameter1, settings.shapeParameter2);
        if (settings.intersectionType == SPHERE) {
            m_sphere = std::make_unique<Sphere>(settings.intersectionRadius, SPHERE_TESSELLATION, SPHERE_TESSELLATION);
            m_sphere->draw();
        }
        else {
            m_sphere = nullptr;

        }
}

void ShapesScene::loadTextures(const std::string &filePath, const int num) {

//    load in texture
    QImage image = QImage(QString::fromStdString(filePath));
    QImage fImage = QGLWidget::convertToGLFormat(image);


    Texture2D m_texture(fImage.bits(), fImage.width(), fImage.height());
    TextureParametersBuilder builder;
    builder.setFilter(TextureParameters::FILTER_METHOD::LINEAR);
    builder.setWrap(TextureParameters::WRAP_METHOD::REPEAT);
    TextureParameters parameters = builder.build();
    parameters.applyTo(m_texture);
    m_textureMap.insert({num, std::move(m_texture)});
}

void ShapesScene::enableTexture() {
    std::unordered_map<int,CS123::GL::Texture2D>::const_iterator got;

    got = m_textureMap.find(settings.textureType);

    if ( got == m_textureMap.end() ) {
        std::cout << "tex not found";
    }
    else {
      m_phongShader->setTexture("tex", got->second);
    }


    m_phongShader->setUniform("useTexture", 1);
    m_phongShader->setUniform("repeatUV", glm::vec2(1.0f, 1.0f));

}

