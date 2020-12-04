#include "ImplicitCylinder.h"

#include <vector>
#include <iostream>

ImplicitCylinder::ImplicitCylinder()
{

}

ImplicitCylinder::~ImplicitCylinder(){

}

float ImplicitCylinder::checkBodyIntersection(glm::vec4 p, glm::vec4 d){
    float a = d.x*d.x + d.z*d.z;
    float b = 2.0f*p.x*d.x + 2.0f*p.z*d.z;
    float c = p.x*p.x + p.z*p.z - 0.25f;

    return applyQuad(a, b, c);
}

float ImplicitCylinder::computeTValue(glm::vec4 p, glm::vec4 d){
    float t1, t3, t4;
    glm::vec4 i;

    t1 = checkBodyIntersection(p, d);

    if (t1 < INFINITY){
        i = p+t1*d;
        if(i.y < -0.5 || i.y > 0.5){
            t1 = INFINITY;
        }
    }

    t3 = checkPlaneIntersection(p.y, d.y, 0.5);
    t4 = checkPlaneIntersection(p.y, d.y, -0.5);
    i = p+t3*d;
    if (i.x*i.x + i.z*i.z > 0.25f-EPSILON){
        t3 = INFINITY;
    }
    i = p+t4*d;
    if (i.x*i.x + i.z*i.z > 0.25f-EPSILON){
        t4 = INFINITY;
    }

    std::vector<float> ts = {t1, t3, t4};
    float min = INFINITY;

    for(int i = 0; i < 3; i++){
        if (ts[i] < 0){
            continue;
        }
        if (ts[i] < min){
            min = ts[i];
        }
    }
    return min;
}

glm::vec3 ImplicitCylinder::getNormal(glm::vec4 pt){
    if (abs(pt.y-0.5f) < EPSILON){
        return glm::vec3(0, 1, 0);
    }
    if (abs(pt.y+0.5f) < EPSILON){
        return glm::vec3(0, -1, 0);
    }
    return glm::vec3(2*pt.x, 0, 2*pt.z);
}

glm::vec2 ImplicitCylinder::getUV(glm::vec4 pt){

    if (abs(pt.y-0.5) < EPSILON){
        return glm::vec2(pt.x+0.5f, 1-(pt.z+0.5f));
    }
    if (abs(pt.y+0.5) < EPSILON){
        return glm::vec2((pt.x+0.5f), (pt.z+0.5f));
    }

    float v = pt.y+0.5f;


    float theta = atan2(pt.z, pt.x);
    float u;
    if(theta < 0){
        u = -1.0f*theta/(float)(2*M_PI);
    } else {
        u = 1.0f-((theta)/(float)(2*M_PI));
    }
    return glm::vec2(u, v);

}

