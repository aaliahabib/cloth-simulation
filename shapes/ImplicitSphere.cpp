#include "ImplicitSphere.h"

ImplicitSphere::ImplicitSphere()
{

}

ImplicitSphere::~ImplicitSphere(){
}

float ImplicitSphere::computeTValue(glm::vec4 p, glm::vec4 d){
    float a = d.x*d.x + d.y*d.y + d.z*d.z;
    float b = 2.0f*p.x*d.x + 2.0f*p.y*d.y + 2.0f*p.z*d.z;
    float c = p.x*p.x + p.y*p.y + p.z*p.z - 0.25f;

    return applyQuad(a, b, c);
}

glm::vec3 ImplicitSphere::getNormal(glm::vec4 pt){
    return glm::vec3(2*pt.x, 2*pt.y, 2*pt.z);
}

glm::vec2 ImplicitSphere::getUV(glm::vec4 pt){

    float phi = asin(pt.y/0.5f);
    float v = phi/(float)(M_PI) + 0.5f;

    float theta = atan2(pt.z, pt.x);
    float u;
    if(theta < 0){
        u = -1.0f*theta/(float)(2*M_PI);
    } else {
        u = 1.0f-((theta)/(float)(2*M_PI));
    }

    if (abs(pt.y-0.5) < EPSILON || abs(pt.y+0.5) < EPSILON){
        u = 0.5f;
    }

    return glm::vec2(u, v);
}
