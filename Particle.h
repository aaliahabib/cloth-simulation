#ifndef PARTICLE_H
#define PARTICLE_H

#include "glm/ext.hpp"


class Particle
{
public:

    Particle();

    void updatePos();
    glm::vec3 m_Pos;
    glm::vec3 m_OldPos;

private:


    glm::vec3 m_Acc;
    int m_Movable;


};

#endif // PARTICLE_H
