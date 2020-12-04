#include "ImplicitCube.h"

#include <vector>


inline float specialIntersection(glm::vec4 planeLoc, glm::vec4 n, glm::vec4 p, glm::vec4 d){
    float dot = glm::dot(n.xyz(), d.xyz());
    if (dot == 0){
        return INFINITY;
    }
    return (float)(glm::dot(planeLoc.xyz(), n.xyz()) - glm::dot(p.xyz(), n.xyz()))/(float)dot;

}
ImplicitCube::ImplicitCube()
{

}

ImplicitCube::~ImplicitCube(){

}

float ImplicitCube::computeTValue(glm::vec4 p, glm::vec4 d){
    float t1, t2, t3, t4, t5, t6;
    glm::vec4 i;
    //left and right
    t1 = checkPlaneIntersection(p.x, d.x, 0.5);
    t2 = checkPlaneIntersection(p.x, d.x, -0.5);
    //top and bottom
    t3 = checkPlaneIntersection(p.y, d.y, 0.5);
    t4 = checkPlaneIntersection(p.y, d.y, -0.5);
    //front and back
    t5 = checkPlaneIntersection(p.z, d.z, 0.5);
    t6 = checkPlaneIntersection(p.z, d.z, -0.5);
    //try constraining it per face

    std::vector<float> ts = {t1, t2, t3, t4, t5, t6};
    float min = INFINITY;
    for(int i = 0; i < 6; i++){
        if (ts[i] <= 0){
            continue;
        }
        glm::vec4 pt = p+ts[i]*d;
        if(abs(pt.x) >= 0.5f+EPSILON || abs(pt.y) >= 0.5f+EPSILON || abs(pt.z) >= 0.5f+EPSILON){
            continue;
        }

        if (ts[i] < min){
            min = ts[i];
        }
    }
    return min;
}

glm::vec3 ImplicitCube::getNormal(glm::vec4 pt){
    if (abs(pt.x - 0.5f) < EPSILON){
        return glm::vec3(1, 0, 0);
    }
    if (abs(pt.x + 0.5f) < EPSILON){
        return glm::vec3(-1, 0, 0);
    }
    if (abs(pt.y - 0.5f) < EPSILON){
        return glm::vec3(0, 1, 0);
    }
    if (abs(pt.y + 0.5f) < EPSILON){
        return glm::vec3(0, -1, 0);
    }
    if (abs(pt.z - 0.5f) < EPSILON){
        return glm::vec3(0, 0, 1);
    }
    if (abs(pt.z + 0.5f) < EPSILON){
        return glm::vec3(0, 0, -1);
    }
    return glm::vec3();
}

glm::vec2 ImplicitCube::getUV(glm::vec4 pt){
    if (abs(pt.y-0.5) < EPSILON){
        return glm::vec2(pt.x+0.5f, 1-(pt.z+0.5f));
    }
    if (abs(pt.y+0.5) < EPSILON){
        return glm::vec2(pt.x+0.5f, (pt.z+0.5f));
    }

    if (abs(pt.x-0.5) < EPSILON){
        return glm::vec2(1-(pt.z+0.5f), pt.y+0.5f);
    }
    if (abs(pt.x+0.5) < EPSILON){
        return glm::vec2((pt.z+0.5f), (pt.y+0.5f));
    }

    if (abs(pt.z-0.5) < EPSILON){
        return glm::vec2(pt.x+0.5f, pt.y+0.5f);
    }
    if (abs(pt.z+0.5) < EPSILON){
        return glm::vec2(1-(pt.x+0.5f), (pt.y+0.5f));
    }

    return glm::vec2();
}
