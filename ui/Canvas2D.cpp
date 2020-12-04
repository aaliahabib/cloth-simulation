/**
 * @file Canvas2D.cpp
 *
 * CS123 2-dimensional canvas. Contains support code necessary for Brush, Filter, Intersect, and
 * Ray.
 *
 * YOU WILL NEED TO FILL THIS IN!
 *
 */

// For your convenience, a few headers are included for you.
#include <assert.h>
#include <iostream>
#include <math.h>
#include <memory>
#include <unistd.h>
#include "Canvas2D.h"
#include "Settings.h"
#include "RayScene.h"

#include <QCoreApplication>
#include <QPainter>
#include "brush/Brush.h"
#include "brush/ConstantBrush.h"
#include "brush/LinearBrush.h"
#include "brush/QuadraticBrush.h"
#include "brush/SmudgeBrush.h"
#include "filter/FilterEdge.h"
#include "filter/FilterBlur.h"
#include "filter/FilterScale.h"
#include "camera/Camera.h"

#include "shapes/ImplicitShape.h"
#include "shapes/ImplicitCube.h"
#include "shapes/ImplicitSphere.h"
#include "shapes/ImplicitCone.h"
#include "shapes/ImplicitCylinder.h"

int DEPTH = 2;

Canvas2D::Canvas2D() :
    // @TODO: Initialize any pointers in this class here.
    m_rayScene(nullptr),
    m_brush(nullptr),
    m_brushType(static_cast<BrushType>(0)),
    m_Cone(std::make_unique<ImplicitCone>()),
    m_Cube(std::make_unique<ImplicitCube>()),
    m_Cylinder(std::make_unique<ImplicitCylinder>()),
    m_Sphere(std::make_unique<ImplicitSphere>())
{
}

Canvas2D::~Canvas2D()
{
}

// This is called when the canvas size is changed. You can change the canvas size by calling
// resize(...). You probably won't need to fill this in, but you can if you want to.
void Canvas2D::notifySizeChanged(int w, int h) {
}

void Canvas2D::paintEvent(QPaintEvent *e) {
    // You probably won't need to fill this in, but you can if you want to override any painting
    // events for the 2D canvas. For now, we simply call the superclass.
    SupportCanvas2D::paintEvent(e);

}

void Canvas2D::settingsChanged() {
    // TODO: Process changes to the application settings.
    std::cout << "Canvas2d::settingsChanged() called. Settings have changed" << std::endl;

    if (m_brush == nullptr || m_brushType != settings.brushType){
        m_brushType = static_cast<BrushType>(settings.brushType);
        switch(m_brushType){
            case BRUSH_CONSTANT:
                m_brush = std::make_unique<ConstantBrush>(settings.brushColor, settings.brushRadius);
                break;
            case BRUSH_LINEAR:
                m_brush = std::make_unique<LinearBrush>(settings.brushColor, settings.brushRadius);
                break;
            case BRUSH_QUADRATIC:
                m_brush = std::make_unique<QuadraticBrush>(settings.brushColor, settings.brushRadius);
                break;
            case BRUSH_SMUDGE:
                m_brush = std::make_unique<SmudgeBrush>(settings.brushColor, settings.brushRadius);
                break;
            default:
                break;
            }
    }

    if (m_brush->getRadius() != settings.brushRadius){
        m_brush->setRadius(settings.brushRadius);
    }

    if (m_brush->getRGBA() != settings.brushColor){
        m_brush->setRGBA(settings.brushColor);
    }


}

// ********************************************************************************************
// ** BRUSH
// ********************************************************************************************


void Canvas2D::mouseDown(int x, int y) {
    // @TODO: [BRUSH] Mouse interaction for brush. You will probably want to create a separate
    //        class for each of your brushes. Remember that you can use the static Settings
    //        object to get the currently selected brush and its parameters.

    // You're going to need to leave the alpha value on the canvas itself at 255, but you will
    // need to use the actual alpha value to compute the new color of the pixel

    std::cout << "Canvas2d::mouseDown() called" << std::endl;

    if (m_brush != nullptr){
        m_brush->brushDown(x, y, this);
    }


//    bool fixAlphaBlending = settings.fixAlphaBlending; // for extra/half credit

}

void Canvas2D::mouseDragged(int x, int y) {
    // TODO: [BRUSH] Mouse interaction for Brush.
    std::cout << "Canvas2d::mouseDragged() called" << std::endl;
    if (m_brush != nullptr){
        m_brush->brushDragged(x, y, this);
    }

}

void Canvas2D::mouseUp(int x, int y) {
    // TODO: [BRUSH] Mouse interaction for Brush.
    std::cout << "Canvas2d::mouseUp() called" << std::endl;
}



// ********************************************************************************************
// ** FILTER
// ********************************************************************************************

void Canvas2D::filterImage() {
    // TODO: [FILTER] Filter the image. Some example code to get the filter type is provided below.
    std::unique_ptr<Filter> filter;
    switch(settings.filterType) {
        case FILTER_BLUR:
            filter = std::make_unique<FilterBlur>(settings.blurRadius);
            break;
        case FILTER_EDGE_DETECT:
            filter = std::make_unique<FilterEdge>(settings.edgeDetectSensitivity);
            break;
        case FILTER_SCALE:
            filter = std::make_unique<FilterScale>(settings.scaleX, settings.scaleY);
            break;
        default:
            filter = std::make_unique<FilterBlur>(settings.blurRadius);
    }

    filter->Apply(this, width(), height());

    // Leave this code here! This code ensures that the Canvas2D will be completely wiped before
    // drawing the new image.
    repaint(rect());
    QCoreApplication::processEvents();
}

// ********************************************************************************************
// ** RAY
// ********************************************************************************************

void Canvas2D::setScene(RayScene *scene) {
    m_rayScene.reset(scene);
}

int Canvas2D::checkIntersection(glm::vec4 p, glm::vec4 d, float &outT){
    std::vector<myPrimitive> primitives = m_rayScene->getPrimtivesList();
    int length = primitives.size();

    float t;
    float minT = INFINITY;
    int minIndex = -1;


    glm::vec4 pt;
    glm::vec3 norm;

    for (int i = 0; i < length; i++){
        myPrimitive object = primitives.at(i);


        glm::vec4 transformed_ray = object.inverse_matrix*d;
        glm::vec4 transformed_eye = object.inverse_matrix*p;

        switch(object.type){
            case PrimitiveType::PRIMITIVE_CONE:
                t = m_Cone->computeTValue(transformed_eye, transformed_ray);
                break;
            case PrimitiveType::PRIMITIVE_CUBE:
                t = m_Cube->computeTValue(transformed_eye, transformed_ray);
                break;
            case PrimitiveType::PRIMITIVE_SPHERE:
                t = m_Sphere->computeTValue(transformed_eye, transformed_ray);
                break;
            case PrimitiveType::PRIMITIVE_CYLINDER:
                t = m_Cylinder->computeTValue(transformed_eye, transformed_ray);
                break;
            default:
                continue;
        }

        //t is valid
        if (t < INFINITY && t >= 0){
            if (t < minT){
                minT = t;
                minIndex = i;
            }
        }
    }
    outT = minT;
    return minIndex;
}

glm::vec4 Canvas2D::computePhongLighting(glm::vec4 pt, glm::vec4 eye, glm::vec4 normal, const CS123SceneMaterial &material, glm::vec4 texture){

    std::vector<myPrimitive> primitives = m_rayScene->getPrimtivesList();
    std::vector<CS123SceneLightData> lights = m_rayScene->getLightsList();
    CS123SceneGlobalData global= m_rayScene->getGlobalData();

    glm::vec4 out;
    out.r = material.cAmbient.r;
    out.g = material.cAmbient.g;
    out.b = material.cAmbient.b;

    for(int i = 0; i < lights.size(); i++){
        CS123SceneLightData light = lights.at(i);
        glm::vec4 l;
        float att = -1.0f;

        if (settings.usePointLights && (light.type == LightType::LIGHT_POINT)){
            l = glm::normalize(light.pos-pt);
            float dist = glm::length(light.pos-pt);
            att = 1.0f/(light.function.x + dist*light.function.y + dist*dist*light.function.z);
            glm::vec4 p = pt+0.001f*l;
            float t;
            if (settings.useShadows && (checkIntersection(p, l, t) > -1.0f)){
                if (glm::length(l*t) <= glm::length(light.pos-p)){
                    att = -1.0f;
                }
            }
        }
        else if (settings.useDirectionalLights && (light.type == LightType::LIGHT_DIRECTIONAL)){
            l = glm::normalize(-1.0f*light.dir);
            att = 1.0f;
            glm::vec4 p = pt+0.001f*l;
            float t;
            if (settings.useShadows && (checkIntersection(p, l, t) > -1.0f)){
                att = -1.0f;
            }
        }

        if(att > -1.0f){

            float dot = std::max(glm::dot(normal, l), 0.0f);
            glm::vec4 diffuse = material.cDiffuse*dot;

            glm::vec4 V = glm::normalize(pt-eye);
            glm::vec4 R = glm::reflect(l, normal);
            glm::vec4 specular = global.ks * pow(std::max(glm::dot(R, V), 0.0f), material.shininess)*material.cSpecular;

            float blend = material.blend;
            if (!settings.useTextureMapping){
                blend = 0;
            }

            out += att*light.color * (blend*texture*dot + (1-blend)*diffuse + specular);

        }

    }
    return out;
}

glm::vec4 Canvas2D::rayTrace(int objIndex, float t, glm::vec4 p, glm::vec4 d, glm::vec4 eye, int depth){
    glm::vec4 color;
    if (objIndex > -1 && depth > 0){
        myPrimitive object = m_rayScene->getPrimtivesList().at(objIndex);

        glm::vec4 transformed_ray = object.inverse_matrix*d;
        glm::vec4 transformed_origin = object.inverse_matrix*p;

        glm::vec3 norm;
        glm::vec2 uv;
        glm::vec4 pt = transformed_origin+transformed_ray*t;

        switch(object.type){
            case PrimitiveType::PRIMITIVE_CONE:
                norm = m_Cone->getNormal(pt);
                uv = m_Cone->getUV(pt);
                break;
            case PrimitiveType::PRIMITIVE_CUBE:
                norm = m_Cube->getNormal(pt);
                uv = m_Cube->getUV(pt);
                break;
            case PrimitiveType::PRIMITIVE_SPHERE:
                norm = m_Sphere->getNormal(pt);
                uv = m_Sphere->getUV(pt);
                break;
            case PrimitiveType::PRIMITIVE_CYLINDER:
                norm = m_Cylinder->getNormal(pt);
                uv = m_Cylinder->getUV(pt);
                break;
            default:
                t = INFINITY;
        }
        if (t != INFINITY){
            norm = glm::normalize(glm::transpose(glm::mat3(object.inverse_matrix))*norm);
            pt = object.cumulative_matrix*pt;

            glm::vec4 normal = glm::vec4(norm, 0);
            std::vector<myPrimitive> primitives = m_rayScene->getPrimtivesList();
            CS123SceneGlobalData global= m_rayScene->getGlobalData();
            CS123SceneMaterial material = object.material;

            glm::vec4 out;
            glm::vec4 texColor;

            if (settings.useTextureMapping){
                float j = object.material.textureMap.repeatU;
                float k = object.material.textureMap.repeatV;
                if (!object.image.isNull()){
                    int w = object.image.width();
                    int h = object.image.height();

                    int s = ((int)(uv.x*j*w)) % w; //col
                    int t = (h-1)-((int)(uv.y*k*h)) % h; //row

                    QRgb pix = object.image.pixel(s, t);
                    texColor = glm::vec4(qRed(pix)/255.0f, qGreen(pix)/255.0f, qBlue(pix)/255.0f, 1);
                }
            }

            out = computePhongLighting(pt, eye, normal, material, texColor);
            glm::vec4 r1 = glm::normalize(glm::reflect(d, normal));
            pt = pt+0.0001f*r1;
            float t;
            int index = checkIntersection(pt, r1, t);
            out = out + global.ks*material.cReflective*rayTrace(index, t, pt, r1, eye, depth-1);
            color = out;
        }
    }
    return color;

}

void Canvas2D::renderImage(Camera *camera, int width, int height) {
    if (m_rayScene) {
        this->resize(width, height);

        glm::mat4x4 inverseScaleMatrix = glm::inverse(camera->getScaleMatrix());
        glm::mat4x4 inverseViewMatrix = glm::inverse(camera->getViewMatrix());
        glm::mat4x4 inverseViewTimesScale = inverseViewMatrix*inverseScaleMatrix;

        glm::vec4 eye = inverseViewMatrix*glm::vec4(0, 0, 0, 1);

        RGBA* curr_pixel = this->data();

        for(int row = 0; row < height; row++){
            //calculate normalized y
            float y = 1-(2.0f*row/height);
            //each point that you can shoot a ray out of can be sent to a thread (look at c++ threads)


            for(int col = 0; col < width; col++){
                //calculate normalized x
                float x = (2.0f*col/width)-1;

                glm::vec4 normalized_film_pt = glm::vec4(x, y, -1, 1);
                glm::vec4 world_pt = inverseViewTimesScale*normalized_film_pt;
                glm::vec4 d = glm::normalize(world_pt-eye);

                float t;
                int minIndex = checkIntersection(eye, d, t);
                if (minIndex > -1){
                    int depth = DEPTH;
                    if(!settings.useReflection){
                        depth = 1;
                    }
                        glm::vec4 color = rayTrace(minIndex, t, eye, d, eye, depth);
                        curr_pixel->r = std::min(255*color.x, 255.0f);
                        curr_pixel->g = std::min(255*color.y, 255.0f);
                        curr_pixel->b = std::min(255*color.z, 255.0f);
                }
                curr_pixel++;
            }
            QCoreApplication::processEvents();
            this->update();
        }
    }
}

void Canvas2D::cancelRender() {
    // TODO: cancel the raytracer (optional)
}




