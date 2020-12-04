#ifndef FILTER_H
#define FILTER_H

#include "Canvas2D.h"


class Filter
{

public:
    Filter();
    ~Filter();

    virtual void Apply(Canvas2D* canvas, int width, int height){}

protected:
    unsigned char REAL2byte(float f);
};

#endif // FILTER_H
