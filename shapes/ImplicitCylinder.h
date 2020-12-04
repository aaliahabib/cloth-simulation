#ifndef IMPLICITCYLINDER_H
#define IMPLICITCYLINDER_H

#include "ImplicitShape.h"
#include <glm/glm.hpp>

class ImplicitCylinder : public ImplicitShape
{
public:
    ImplicitCylinder();
    virtual ~ImplicitCylinder();

    float computeTValue(glm::vec4 p, glm::vec4 d);
    glm::vec3 getNormal(glm::vec4 pt);
    glm::vec2 getUV(glm::vec4 pt);
private:
    float checkBodyIntersection(glm::vec4 p, glm::vec4 d);
};
#endif // IMPLICITCYLINDER_H
