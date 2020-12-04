#ifndef CONE_H
#define CONE_H

#include "Circlefacedshape.h"

class Cone : public CircleFacedShape
{
public:
    Cone();
    Cone(int param1, int param2);
    virtual ~Cone();

private:
    void buildSurface();
    virtual void buildVertexSet();
    virtual void getVertexAndNormal(int row, int col, glm::vec3 &outVec, glm::vec3 &norm) override;

    float m_root5;
};

#endif // CONE_H
