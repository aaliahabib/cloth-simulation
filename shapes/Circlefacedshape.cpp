#include "Circlefacedshape.h"

CircleFacedShape::CircleFacedShape()
{
}

CircleFacedShape::CircleFacedShape(int param1, int param2) : Shape(param1, param2)
{
    if(m_param2 < 3){
        m_param2 = 3;
    }
    m_section_theta = 2*M_PI/(float)m_param2;
    m_width = (float)1/m_param1;
}

CircleFacedShape::~CircleFacedShape()
{
}

void CircleFacedShape::buildCircularFace(int level){

    float t1;
    float t2;

    float y = level*0.5;
    glm::vec3 normal = glm::vec3(0, level, 0);
    glm::vec3 center = glm::vec3(0, y, 0);

    for(int i=0; i < m_param2; i++){
        t1 = i*m_section_theta;
        t2 = (i+level)*m_section_theta;

        float v1_x = 0.5*cos(t1);
        float v1_z = 0.5*sin(t1);

        float v2_x = 0.5*cos(t2);
        float v2_z = 0.5*sin(t2);

        insertVec3(m_vertexData, glm::vec3(v2_x, y, v2_z));
        insertVec3(m_vertexData, normal);

        insertVec3(m_vertexData, glm::vec3(v1_x, y, v1_z));
        insertVec3(m_vertexData, normal);

        insertVec3(m_vertexData, center);
        insertVec3(m_vertexData, normal);
    }

    //set up sines and cosines lists so as to not repeatedly compute
    m_sines.reserve(m_param2+1);
    m_cosines.reserve(m_param2+1);
    for(int i = 0; i <= m_param2; i++){
        t1 = i*m_section_theta;
        m_sines[i] = sin(t1);
        m_cosines[i] = cos(t1);
    }
}

void CircleFacedShape::buildBarrel(){
    for(int row = 0; row < m_param1; row++){
        for(int col = 0; col < m_param2; col++){
            glm::vec3 v1;
            glm::vec3 normal1;
            getVertexAndNormal(row, col, v1, normal1);

            glm::vec3 v2;
            glm::vec3 normal2;
            getVertexAndNormal(row, col+1, v2, normal2);

            glm::vec3 v3;
            glm::vec3 normal3;
            getVertexAndNormal(row+1, col+1, v3, normal3);

            glm::vec3 v4;
            glm::vec3 normal4;
            getVertexAndNormal(row+1, col, v4, normal4);

            insertVec3(m_vertexData, v2);
            insertVec3(m_vertexData, normal2);

            insertVec3(m_vertexData, v1);
            insertVec3(m_vertexData, normal1);

            insertVec3(m_vertexData, v3);
            insertVec3(m_vertexData, normal3);


            insertVec3(m_vertexData, v3);
            insertVec3(m_vertexData, normal2);

            insertVec3(m_vertexData, v1);
            insertVec3(m_vertexData, normal1);

            insertVec3(m_vertexData, v4);
            insertVec3(m_vertexData, normal4);

       }
    }
}


