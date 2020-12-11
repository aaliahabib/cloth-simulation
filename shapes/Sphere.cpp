#include "Sphere.h"
#include <iostream>

Sphere::Sphere()
{
}

Sphere::Sphere(int param1, int param2) : Shape(param1, param2)
{
    if(m_param2 < 3){
        m_param2 = 3;
    }
    if(m_param1 < 2){
        m_param1 = 2;
    }
    buildVertexSet();
    buildVAO();
}

Sphere::Sphere(float radius, int param1, int param2) : Shape(param1, param2)
{
    if(m_param2 < 3){
        m_param2 = 3;
    }
    if(m_param1 < 2){
        m_param1 = 2;
    }
    m_radius = radius-0.01;
    buildVertexSet();
    buildVAO();
}

Sphere::~Sphere()
{
}

void Sphere::buildVertexSet(){
    m_vertexData.clear();
    m_vertexData.reserve(3*6*2*m_param1*m_param2);
    float section_theta = 2*M_PI/(float)m_param2;
    float theta1;
    float theta2;

    float section_phi = M_PI/(float)m_param1;
    float phi1;
    float phi2;

    for(int row = 0; row < m_param1; row++){

        phi1 = row*section_phi;
        phi2 = (row+1)*section_phi;


        for(int col = 0; col < m_param2; col++){

            theta1 = col*section_theta;
            theta2 = (col+1)*section_theta;

            glm::vec3 v1;
            v1.x = m_radius*sin(phi1)*cos(theta1);
            v1.y = m_radius*cos(phi1);
            v1.z = m_radius*sin(phi1)*sin(theta1);
            glm::vec3 normal1 = glm::vec3(cos(theta1)*sin(phi1), cos(phi1), sin(theta1)*sin(phi1));


            glm::vec3 v2;
            v2.x = m_radius*sin(phi1)*cos(theta2);
            v2.y = m_radius*cos(phi1);
            v2.z = m_radius*sin(phi1)*sin(theta2);
            glm::vec3 normal2 = glm::vec3(cos(theta2)*sin(phi1), cos(phi1), sin(theta2)*sin(phi1));


            glm::vec3 v3;
            v3.x = m_radius*sin(phi2)*cos(theta2);
            v3.y = m_radius*cos(phi2);
            v3.z = m_radius*sin(phi2)*sin(theta2);
            glm::vec3 normal3 = glm::vec3(cos(theta2)*sin(phi2), cos(phi2), sin(theta2)*sin(phi2));


            glm::vec3 v4;
            v4.x = m_radius*sin(phi2)*cos(theta1);
            v4.y = m_radius*cos(phi2);
            v4.z = m_radius*sin(phi2)*sin(theta1);
            glm::vec3 normal4 = glm::vec3(cos(theta1)*sin(phi2), cos(phi2), sin(theta1)*sin(phi2));


            insertVec3(m_vertexData, v1);
            insertVec3(m_vertexData, normal1);

            insertVec3(m_vertexData, v2);
            insertVec3(m_vertexData, normal2);

            insertVec3(m_vertexData, v3);
            insertVec3(m_vertexData, normal3);



            insertVec3(m_vertexData, v1);
            insertVec3(m_vertexData, normal1);

            insertVec3(m_vertexData, v3);
            insertVec3(m_vertexData, normal3);

            insertVec3(m_vertexData, v4);
            insertVec3(m_vertexData, normal4);

       }
    }
}
