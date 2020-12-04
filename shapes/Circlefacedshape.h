#ifndef CIRCLEFACEDSHAPE_H
#define CIRCLEFACEDSHAPE_H

#include "Shape.h"

class CircleFacedShape : public Shape
{
public:
    CircleFacedShape();
    CircleFacedShape(int pararm1, int param2);
    virtual ~CircleFacedShape();

protected:
    void buildCircularFace(int level);
    void buildBarrel();

    virtual void getVertexAndNormal(int row, int col, glm::vec3 &outVec, glm::vec3 &norm) {}

    float m_section_theta;
    float m_width;
    std::vector<float> m_sines;
    std::vector<float> m_cosines;
};

#endif // CIRCLEFACEDSHAPE_H
