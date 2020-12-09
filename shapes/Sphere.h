#ifndef SPHERE_H
#define SPHERE_H

#include "Shape.h"

class Sphere : public Shape
{
public:
    Sphere();
    Sphere(int param1, int param2);
    Sphere(float radius, int param1, int param2);
    virtual ~Sphere();

private:
    virtual void buildVertexSet();

    float m_radius;
};

#endif // SPHERE_H
