#include "ImplicitCone.h"

#include <vector>
#include <iostream>

ImplicitCone::ImplicitCone()
{

}

ImplicitCone::~ImplicitCone(){

}

glm::vec2 ImplicitCone::checkBodyIntersection(glm::vec4 p, glm::vec4 d){
    float a = d.x*d.x + d.z*d.z - 0.25f*d.y*d.y;
    float b = 2.0f*p.x*d.x + 2.0f*p.z*d.z - 0.5f*p.y*d.y + 0.25f*d.y;
    float c = p.x*p.x + p.z*p.z - 0.25f*p.y*p.y + 0.25f*p.y - 0.0625f;

    float disc =(b*b - 4*a*c);

    if (disc < 0){
        return glm::vec2(INFINITY, INFINITY);
    }

    float sum = (-1.0f*b+sqrt(disc)) / (2.0f*a);
    float sub = (-1.0f*b-sqrt(disc)) / (2.0f*a);

    return glm::vec2(sub, sum);
}

float ImplicitCone::computeTValue(glm::vec4 p, glm::vec4 d){
    float t1, t2, t3;
    t1 = checkBodyIntersection(p, d)[0];
    t2 = checkBodyIntersection(p, d)[1];

    if (t1 < INFINITY){
        glm::vec4 intersection1 = p+t1*d;
        if (intersection1.y < -0.5+EPSILON || intersection1.y > 0.5-EPSILON){
            t1 = INFINITY;
        }
        glm::vec4 intersection2 = p+t2*d;
        if (intersection2.y < -0.5+EPSILON || intersection2.y > 0.5-EPSILON){
            t2 = INFINITY;
        }
    }

    t3 = checkPlaneIntersection(p.y, d.y, -0.5);
    glm::vec4 intersection3 = p+t3*d;
    if (intersection3.x*intersection3.x + intersection3.z*intersection3.z > 0.25f-EPSILON){
        t3 = INFINITY;
    }

    std::vector<float> ts = {t1, t2, t3};
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

glm::vec3 ImplicitCone::getNormal(glm::vec4 pt){
    //std::cout << pt.x << " " << pt.y << " " << pt.z << std::endl;
    if (abs(pt.y+0.5) < EPSILON){
        return glm::vec3(0, -1, 0);
    }
    return glm::vec3(2*pt.x, 0.25f-0.5f*pt.y, 2*pt.z);
}

glm::vec2 ImplicitCone::getUV(glm::vec4 pt){
    if (abs(pt.y+0.5) < EPSILON){
        return glm::vec2((pt.x+0.5f), (pt.z+0.5f));
    }

    float v = pt.y+0.5;
    float theta = atan2(pt.z, pt.x);
    float u;
    if(theta < 0){
        u = -1.0f*theta/(float)(2*M_PI);
    } else {
        u = 1.0f-((theta)/(float)(2*M_PI));
    }
    return glm::vec2(u, v);

}
