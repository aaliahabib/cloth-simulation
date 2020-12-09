#include "Particle.h"

#include <glm.h>
#include "glm/ext.hpp"
#include <iostream>

const float TIMESTEP = 5.0f;

const glm::vec3 SphereCenter(0.0f, 0.0f, 0.0f);

Particle::Particle() :
    m_Acc(glm::vec3(0, -0.002, 0)),
    m_Movable(1)
{
}

void Particle::updatePos(){
    if (m_Movable) {
        glm::vec3 temp = m_Pos;
        m_Pos = m_Pos + (m_Pos-m_OldPos)*(0.5f) + m_Acc*TIMESTEP*TIMESTEP;
        m_OldPos = temp;
    }
}

glm::vec3 Particle::SphereIntersect(float radius) {
    glm::vec3 centerToParticle = m_Pos - SphereCenter;
    if (glm::length(centerToParticle) < radius) { //if particle is within ball
        glm::vec3 direction = glm::normalize(centerToParticle);
        float necessaryLength = radius - glm::length(centerToParticle);
//        m_Pos = SphereRadius * direction + SphereCenter;
//        m_OldPos = SphereRadius * direction + SphereCenter;
        glm::vec3 correction = necessaryLength * direction;
//        return correction;

        m_Pos += correction;
    }

    return glm::vec3();
}

void Particle::HoleIntersect(float radius) {
    float planeY = 0.0f;
    float height = 0.2f;
    //float holeRadius = 0.4f;
    if ((m_Pos.y <= planeY) && (m_Pos.y >= planeY - height) && (pow(m_Pos.x, 2.0f) + pow(m_Pos.z, 2.0f) > pow(radius, 2.0f))) {
//        glm::vec3 distToSurface = planeY - m_Pos.y;
        m_Pos = glm::vec3(m_Pos.x, planeY, m_Pos.z);
    }
//    if ((m_Pos.y <= planeY) && (m_Pos.y >= planeY - height) && (m_Pos.x < 0.1f) && (m_Pos.z < 0.1f)) {
////        glm::vec3 distToSurface = planeY - m_Pos.y;
//        m_Pos = glm::vec3(m_Pos.x, planeY, m_Pos.z);
//    }
}

void Particle::FloorIntersect() {
    float floorY = -1.0f;
    if (m_Pos.y <= floorY) {
        m_Pos = glm::vec3(m_Pos.x, floorY, m_Pos.z);
    }
}
