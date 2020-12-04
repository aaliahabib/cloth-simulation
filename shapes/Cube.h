#ifndef CUBE_H
#define CUBE_H

#include "Shape.h"


class Cube : public Shape
{
public:
    Cube();
    Cube(int param1, int param2);
    virtual ~Cube();

private:
    virtual void buildVertexSet();
    glm::vec3 determineCoordinates(int row, int col);
};

#endif // CUBE_H
