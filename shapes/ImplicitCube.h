#ifndef IMPLICITCUBE_H
#define IMPLICITCUBE_H

#include "ImplicitShape.h"
#include <glm/glm.hpp>


class ImplicitCube : public ImplicitShape
{
public:
    ImplicitCube();
    virtual ~ImplicitCube();

    float computeTValue(glm::vec4 p, glm::vec4 d);
    glm::vec3 getNormal(glm::vec4 pt);
    glm::vec2 getUV(glm::vec4 pt);
};

#endif // IMPLICITCUBE_H
