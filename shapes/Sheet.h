#ifndef SHEET_H
#define SHEET_H

#include "Shape.h"
#include "Particle.h"

class Sheet : public Shape
{
public:
    Sheet();
    Sheet(int param1, int param2);
    virtual ~Sheet();

    void updateVertexSet();
    int m_size;
    int m_constraints;

private:
    virtual void buildVertexSet();
    glm::vec3 determineCoordinates(int row, int col);
    int getIndex(int row, int col);
    void addParticlePair(Particle *p, int row, int col);
    void updateParticles();

    std::vector<Particle> m_Particles;
    std::vector<std::tuple<Particle*, Particle*, float>> m_ParticlePairs;
    std::vector<glm::vec3> m_Triangles;




};

#endif // SHEET_H
