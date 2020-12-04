#ifndef IMPLICITSHAPE_H
#define IMPLICITSHAPE_H

#include <glm/glm.hpp>

class ImplicitShape
{
public:
    ImplicitShape();
    virtual ~ImplicitShape();

    virtual float computeTValue(glm::vec4 p, glm::vec4 d){}
    virtual glm::vec3 getNormal(glm::vec4 pt){}
    virtual glm::vec2 getUV(glm::vec4 pt){}

protected:
    const float EPSILON = (float)pow(10, -1*4);
    float checkPlaneIntersection(float p, float d, float planeLoc);
    float applyQuad(float a, float b, float c);


};

#endif // IMPLICITSHAPE_H
