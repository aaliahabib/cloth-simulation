#include "Cube.h"
#include "glm/ext.hpp"
#include <iostream>

Cube::Cube()
{
}

Cube::Cube(int param1, int param2) : Shape(param1, param2)
{
    /**
     * We build in vertex data for a cube, in this case they are handwritten.
     * You'll want to expand upon or refactor this code heavily to take advantage
     * of polymorphism, vector math/glm library, and utilize good software design
     *
     */
    buildVertexSet();
    /** build the VAO so that the shape is ready to be drawn */
    buildVAO();
}

Cube::~Cube()
{
}

void Cube::buildVertexSet(){
    m_vertexData.clear();
    m_vertexData.reserve(3*6*2*3*(2*pow(m_param1, 2)));

    std::vector<glm::vec3> xy_face_triangles;
    glm::vec3 normal = glm::vec3(0.0f, 0.0f, 1.0f);

    for(int row = 0; row < m_param1; row++){
        for(int col = 0; col < m_param1; col++){

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

    for (int j = 1; j < 4; j++){
        for (int i = 0; i < xy_face_triangles.size(); i++){
            glm::vec3 rotated = glm::rotateY(xy_face_triangles[i], j*(float)M_PI/2);
            insertVec3(m_vertexData, rotated);
        }
    }

    for (int j = -1; j < 2; j=j+2){
        for (int i = 0; i < xy_face_triangles.size(); i++){
            glm::vec3 rotated = glm::rotateX(xy_face_triangles[i], j*(float)M_PI/2);
            insertVec3(m_vertexData, rotated);
        }
    }
}

glm::vec3 Cube::determineCoordinates(int row, int col){
    float square_width = (float)1/m_param1;
    glm::vec3 vec;
    vec.x = -0.5+col*square_width;
    vec.y = -0.5+row*square_width;
    vec.z = 0.5;
    return vec;
}


