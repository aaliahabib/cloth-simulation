#include "Shape.h"
#include "gl/datatype/VAO.h"
#include "gl/datatype/VBO.h"
#include "gl/datatype/VBOAttribMarker.h"
#include "gl/shaders/ShaderAttribLocations.h"

#include <iostream>

using namespace CS123::GL;

void insertVec3(std::vector<float> &data, glm::vec3 v){
    data.push_back(v.x);
    data.push_back(v.y);
    data.push_back(v.z);
}

Shape::Shape() :
    m_VAO(nullptr)
{
}

Shape::Shape(int param1, int param2) :
    m_VAO(nullptr),
    m_param1(param1),
    m_param2(param2)
{
    if(m_param1 < 1){
        m_param1 = 1;
    }
    if(m_param2 < 1){
        m_param2 = 1;
    }
    if(m_param1 > 100){
        m_param1 = 100;
    }
    if(m_param2 > 100){
        m_param2 = 100;
    }
}

Shape::~Shape()
{
}

void Shape::draw() {
    if (m_VAO) {
        m_VAO->bind();
        m_VAO->draw();
        m_VAO->unbind();
    }
}

void Shape::buildVAO() {
    const int numFloatsPerVertex = 8;
    const int numVertices = m_vertexData.size() / numFloatsPerVertex;

    std::vector<VBOAttribMarker> markers;
    markers.push_back(VBOAttribMarker(ShaderAttrib::POSITION, 3, 0));
    markers.push_back(VBOAttribMarker(ShaderAttrib::NORMAL, 3, 3*sizeof(float)));
    markers.push_back(VBOAttribMarker(ShaderAttrib::TEXCOORD2, 2, 6*sizeof(float)));
    VBO vbo = VBO(m_vertexData.data(), m_vertexData.size(), markers);
    m_VAO = std::make_unique<VAO>(vbo, numVertices);
}


