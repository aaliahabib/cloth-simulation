#include "Sheet.h"
#include "glm/ext.hpp"
#include "Particle.h"
#include <iostream>
#include "Settings.h"

inline glm::vec3 getNormal(glm::vec3 v1, glm::vec3 v2) {
    return glm::cross(v2, v1);
}

inline void satisfyConstraint(Particle *p1, Particle *p2, float rest_distance){
    glm::vec3 v12 = p2->m_Pos - p1->m_Pos;
    float dist = glm::length(v12);
    glm::vec3 offset = 0.5f*v12*(1.0f-(rest_distance/(float)dist));
//    glm::vec3 offset = 0.9f * v12*(1.0f-(rest_distance/(float)dist));


    if (p1->m_Movable && !p2->m_Movable){
        p1->m_Pos += 2.0f*offset;
    }
    else if (p2->m_Movable && !p1->m_Movable){
        p2->m_Pos -= 2.0f*offset;
    }
    if (p1->m_Movable && p2->m_Movable){
        p1->m_Pos += offset;
        p2->m_Pos -= offset;
    }
}

Sheet::Sheet()
{
}

Sheet::Sheet(int param1, int param2) : Shape(param1, param2), m_size(param1), m_constraints(param2)
{
    if (m_size < 10){
        m_size = 10;
    }
    if (m_constraints < 2){
        m_constraints = 2;
    }
    buildVertexSet();
    buildVAO();
}

Sheet::~Sheet()
{
}

int Sheet::getIndex(int row, int col) {
    return row*(m_size+1)+col;
}

void Sheet::addParticlePair(Particle* p, int row, int col){
    int i = getIndex(row, col);
    if (row <= m_size && col <= m_size){
        Particle* p1 = &m_Particles.at(i);
        float length = glm::length(p->m_Pos - p1->m_Pos);
        m_ParticlePairs.push_back(std::tuple<Particle*, Particle*, float>(p, p1, length));
    }
}

void Sheet::buildVertexSet(){
    m_vertexData.clear();
    m_vertexData.reserve(8*pow(m_size, 2));

    glm::vec3 normal = glm::vec3(0.0f, 1.0f, 0.0f);

    for(int row = 0; row <= m_size; row++){
        for(int col = 0; col <= m_size; col++){
            Particle p;
            p.m_Pos = glm::vec3(determineCoordinates(row, col));
            p.m_OldPos = glm::vec3(determineCoordinates(row, col));

            if (settings.clipLeftCorner){
                if (row == 0 && col < 4) {
                    p.m_Movable = 0;
                }
            }
            if (settings.clipRightCorner){
                if (row == 0 && col > m_size - 4) {
                    p.m_Movable = 0;
                }
            }

            m_Particles.push_back(p);
        }
    }

    for(int row = 0; row <= m_size; row++){
        for(int col = 0; col <= m_size; col++){
            Particle *p = &m_Particles.at(getIndex(row, col));

            for(int i = 1; i <= m_constraints; i++){
                addParticlePair(p, row+i, col);
                addParticlePair(p, row, col+i);

                //shear constraints
                addParticlePair(p, row+i, col+i);
            }
        }
    }

    for(int row = 0; row < m_size; row++){
        for(int col = 0; col < m_size; col++){
            insertVec3(m_vertexData, determineCoordinates(row, col));
            insertVec3(m_vertexData, normal);
            m_vertexData.push_back(0.0f);
            m_vertexData.push_back(0.0f);

            insertVec3(m_vertexData, determineCoordinates(row, col+1));
            insertVec3(m_vertexData, normal);
            m_vertexData.push_back(0.0f);
            m_vertexData.push_back(0.0f);

            insertVec3(m_vertexData, determineCoordinates(row+1, col+1));
            insertVec3(m_vertexData, normal);
            m_vertexData.push_back(0.0f);
            m_vertexData.push_back(0.0f);

            insertVec3(m_vertexData, determineCoordinates(row, col));
            insertVec3(m_vertexData, normal);
            m_vertexData.push_back(0.0f);
            m_vertexData.push_back(0.0f);

            insertVec3(m_vertexData, determineCoordinates(row+1, col+1));
            insertVec3(m_vertexData, normal);
            m_vertexData.push_back(0.0f);
            m_vertexData.push_back(0.0f);

            insertVec3(m_vertexData, determineCoordinates(row+1, col));
            insertVec3(m_vertexData, normal);
            m_vertexData.push_back(0.0f);
            m_vertexData.push_back(0.0f);
        }
    }
}

void Sheet::updateVertexSet(){
    m_vertexData.clear();
    m_vertexData.reserve(8*pow(m_size, 2));


    const int constraintIterations = 50;

    for (int i = 0; i < constraintIterations; i++) {
        for(auto it = m_ParticlePairs.begin(); it != m_ParticlePairs.end(); it++){
            satisfyConstraint(std::get<0>(*it), std::get<1>(*it), std::get<2>(*it));
            switch(settings.intersectionType){
                case SPHERE:
                   std::get<0>(*it)->SphereIntersect(settings.intersectionRadius);
                break;
                case HOLE:
                    std::get<0>(*it)->HoleIntersect(settings.intersectionRadius);
                break;
                default:
                break;
            }
            std::get<0>(*it)->FloorIntersect();
        }
    }

    for(auto it = m_Particles.begin(); it != m_Particles.end(); it++){
        it->updatePos();
        switch(settings.intersectionType){
            case SPHERE:
               it->SphereIntersect(settings.intersectionRadius);
            break;
            case HOLE:
                it->HoleIntersect(settings.intersectionRadius);
            break;
            default:
            break;
        }
        it->FloorIntersect();
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
            m_vertexData.push_back(0.0f);
            m_vertexData.push_back(0.0f);

            insertVec3(m_vertexData, p2.m_Pos);
            insertVec3(m_vertexData, n1);
            m_vertexData.push_back(0.0f);
            m_vertexData.push_back(0.0f);

            insertVec3(m_vertexData, p3.m_Pos);
            insertVec3(m_vertexData, n1);
            m_vertexData.push_back(0.0f);
            m_vertexData.push_back(0.0f);

            insertVec3(m_vertexData, p1.m_Pos);
            insertVec3(m_vertexData, n2);
            m_vertexData.push_back(0.0f);
            m_vertexData.push_back(0.0f);

            insertVec3(m_vertexData, p3.m_Pos);
            insertVec3(m_vertexData, n2);
            m_vertexData.push_back(0.0f);
            m_vertexData.push_back(0.0f);

            insertVec3(m_vertexData, p4.m_Pos);
            insertVec3(m_vertexData, n2);
            m_vertexData.push_back(0.0f);
            m_vertexData.push_back(0.0f);
        }
    }
    buildVAO();
}

glm::vec3 Sheet::determineCoordinates(int row, int col){
    float offset = m_size/2.0f;
    glm::vec3 vec;
    vec.x = (col-offset)/m_size; //was /0.5f
    vec.y = 0.5f;
    vec.z = (row-offset)/m_size; //was /0.5f
    return vec;
}
