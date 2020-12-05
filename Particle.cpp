#include "Particle.h"

#include <glm.h>
#include "glm/ext.hpp"

const float TIMESTEP = 5.0f;

const glm::vec3 SphereCenter(0.5f, 0.0f, 0.0f);
const float SphereRadius = 0.3f;

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
//        SphereIntersect();
        m_Pos += SphereIntersect();
        m_OldPos += SphereIntersect(); //todo should these be summing or just resetting the value?
    }
}

glm::vec3 Particle::SphereIntersect() {
    glm::vec3 centerToParticle = m_Pos - SphereCenter;
    if (glm::length(centerToParticle) < SphereRadius) { //if particle is within ball
        glm::vec3 direction = glm::normalize(centerToParticle);
        float necessaryLength = SphereRadius - glm::length(centerToParticle);
//        m_Pos = SphereRadius * direction;
//        m_OldPos = SphereRadius * direction;
        glm::vec3 correction = necessaryLength * direction;
        return correction;
    }

    return glm::vec3();
}
