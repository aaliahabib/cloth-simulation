#ifndef IMPLICITCONE_H
#define IMPLICITCONE_H

#include "ImplicitShape.h"
#include <glm/glm.hpp>

class ImplicitCone : public ImplicitShape
{
public:
    ImplicitCone();
    virtual ~ImplicitCone();

    float computeTValue(glm::vec4 p, glm::vec4 d);
    glm::vec3 getNormal(glm::vec4 pt);
    glm::vec2 getUV(glm::vec4 pt);

private:
    glm::vec2 checkBodyIntersection(glm::vec4 p, glm::vec4 d);
};

#endif // IMPLICITCONE_H
