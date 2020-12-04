#include "Cylinder.h"

Cylinder::Cylinder()
{
}

Cylinder::Cylinder(int param1, int param2) : CircleFacedShape(param1, param2)
{
    buildVertexSet();
    buildVAO();
}

Cylinder::~Cylinder()
{
}

void Cylinder::buildCircularFaces(){
    for(int j = -1; j < 2; j=j+2){
        buildCircularFace(j);
    }
}

void Cylinder::getVertexAndNormal(int row, int col, glm::vec3 &outVec, glm::vec3 &norm){
    outVec.x = 0.5*m_cosines[col];
    outVec.y = -0.5+row*m_width;
    outVec.z = 0.5*m_sines[col];
    norm = glm::vec3(m_cosines[col], 0, m_sines[col]);
}

void Cylinder::buildVertexSet(){
    m_vertexData.clear();
    m_vertexData.reserve(3*6*m_param2*2*(m_param1+1));
    buildCircularFaces();
    buildBarrel();
}
