#include "Particle.h"

const float TIMESTEP = 5.0f;
Particle::Particle()
{
    m_Acc = glm::vec3(0, -0.002, 0);
    m_Movable = 1;
}

void Particle::updatePos(){
    if(m_Movable){
        glm::vec3 temp = m_Pos;
        m_Pos = m_Pos + (m_Pos-m_OldPos)*(0.5f) + m_Acc*TIMESTEP*TIMESTEP;
        m_OldPos = temp;
    }
}
