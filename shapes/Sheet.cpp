#include "Sheet.h"
#include "glm/ext.hpp"
#include "Particle.h"
#include <iostream>

//int SIZE = 8;

int Sheet::getIndex(int row, int col) {
    return row*(m_size+1)+col;
}

inline glm::vec3 getNormal(glm::vec3 v1, glm::vec3 v2) {
    return glm::cross(v2, v1);
}

Sheet::Sheet()
{
}

Sheet::Sheet(int param1, int param2) : Shape(param1, param2), m_size(param1)
{
    /**
     * We build in vertex data for a cube, in this case they are handwritten.
     * You'll want to expand upon or refactor this code heavily to take advantage
     * of polymorphism, vector math/glm library, and utilize good software design
     *
     */
//    m_size = 8;

    buildVertexSet();
    /** build the VAO so that the shape is ready to be drawn */
    buildVAO();
}

Sheet::~Sheet()
{
}


void Sheet::buildVertexSet(){
    m_vertexData.clear();
    m_vertexData.reserve(6*pow(m_size, 2));

    std::vector<glm::vec3> xy_face_triangles;

    glm::vec3 normal = glm::vec3(0.0f, 1.0f, 0.0f);

    for(int row = 0; row <= m_size; row++){
        for(int col = 0; col <= m_size; col++){
            Particle p;
            p.m_Pos = glm::vec3(determineCoordinates(row, col));
            p.m_OldPos = glm::vec3(determineCoordinates(row, col));

            m_Particles.push_back(p);
        }
    }

    for(int row = 0; row < m_size; row++){
        for(int col = 0; col < m_size; col++){

            //restructure this to go directly into m_vertexData

            xy_face_triangles.push_back(determineCoordinates(row, col));
            xy_face_triangles.push_back(normal);

            xy_face_triangles.push_back(determineCoordinates(row, col+1));
            xy_face_triangles.push_back(normal);

            xy_face_triangles.push_back(determineCoordinates(row+1, col+1));
            xy_face_triangles.push_back(normal);


            xy_face_triangles.push_back(determineCoordinates(row, col));
            xy_face_triangles.push_back(normal);

            xy_face_triangles.push_back(determineCoordinates(row+1, col+1));
            xy_face_triangles.push_back(normal);

            xy_face_triangles.push_back(determineCoordinates(row+1, col));
            xy_face_triangles.push_back(normal);
        }
    }

    for (int i = 0; i < xy_face_triangles.size(); i++){
        insertVec3(m_vertexData, xy_face_triangles[i]);
    }
}

void Sheet::updateVertexSet(){
    m_vertexData.clear();
    m_vertexData.reserve(6*pow(m_size, 2));

    for(auto it = m_Particles.begin(); it != m_Particles.end(); it++){
        it->updatePos();
    }

    for(int row = 0; row < m_size; row++){
        for(int col = 0; col < m_size; col++){
            Particle p1 = m_Particles.at(getIndex(row, col));
            Particle p2 = m_Particles.at(getIndex(row, col+1));
            Particle p3 = m_Particles.at(getIndex(row+1, col+1));
            Particle p4 = m_Particles.at(getIndex(row+1, col));

            glm::vec3 v12 = p2.m_Pos - p1.m_Pos;
            glm::vec3 v13 = p3.m_Pos - p1.m_Pos;
            glm::vec3 v14 = p4.m_Pos - p1.m_Pos;

            glm::vec3 n1 = getNormal(v12, v13);
            glm::vec3 n2 = getNormal(v13, v14);

            insertVec3(m_vertexData, p1.m_Pos);
            insertVec3(m_vertexData, n1);
            insertVec3(m_vertexData, p2.m_Pos);
            insertVec3(m_vertexData, n1);
            insertVec3(m_vertexData, p3.m_Pos);
            insertVec3(m_vertexData, n1);

            insertVec3(m_vertexData, p1.m_Pos);
            insertVec3(m_vertexData, n2);
            insertVec3(m_vertexData, p3.m_Pos);
            insertVec3(m_vertexData, n2);
            insertVec3(m_vertexData, p4.m_Pos);
            insertVec3(m_vertexData, n2);
        }
    }
    buildVAO();
    std::cout << "UpdateVertexSet called" << std::endl;
}

glm::vec3 Sheet::determineCoordinates(int row, int col){
    float offset = m_size/2.0f;
    glm::vec3 vec;
    vec.x = col-offset;
    vec.y = 0.5f;
    vec.z = row-offset;
    return vec;
}
