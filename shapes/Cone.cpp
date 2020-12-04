#include "Cone.h"

Cone::Cone()
{
}

Cone::Cone(int param1, int param2) : CircleFacedShape(param1, param2),
    m_root5(sqrt(5))
{
    buildVertexSet();
    buildVAO();
}

Cone::~Cone()
{
}

void Cone::getVertexAndNormal(int row, int col, glm::vec3 &outVec, glm::vec3 &norm){
    float y = -0.5+row*m_width;
    float radius = 0.5f/(1.0f/(1-row*m_width));

    outVec.x = radius*m_cosines[col];
    outVec.y = y;
    outVec.z = radius*m_sines[col];

    norm = glm::vec3(2.0f*m_cosines[col]/m_root5, 1/m_root5, 2.0f*m_sines[col]/m_root5);
}

void Cone::buildVertexSet(){
    m_vertexData.clear();
    m_vertexData.reserve(3*6*m_param2*(2*m_param1)+1);
    buildCircularFace(-1);
    buildBarrel();
}



