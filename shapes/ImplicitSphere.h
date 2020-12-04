#ifndef IMPLICITSPHERE_H
#define IMPLICITSPHERE_H

#include "ImplicitShape.h"
#include <glm/glm.hpp>

class ImplicitSphere : public ImplicitShape
{
public:
    ImplicitSphere();
    virtual ~ImplicitSphere();

    float computeTValue(glm::vec4 p, glm::vec4 d);
    glm::vec3 getNormal(glm::vec4 pt);
    glm::vec2 getUV(glm::vec4 pt);
};

#endif // IMPLICITSPHERE_H
