#ifndef CYLINDER_H
#define CYLINDER_H

#include "Circlefacedshape.h"

class Cylinder : public CircleFacedShape
{
public:
    Cylinder();
    Cylinder(int param1, int param2);
    virtual ~Cylinder();



private:
    void buildCircularFaces();
    virtual void buildVertexSet();
    virtual void getVertexAndNormal(int row, int col, glm::vec3 &outVec, glm::vec3 &norm) override;

};

#endif // CYLINDER_H

