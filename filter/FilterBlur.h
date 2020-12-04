#ifndef FILTERBLUR_H
#define FILTERBLUR_H

#include "Canvas2D.h"
#include "Filter.h"

class FilterBlur :
        public Filter
{
public:
    FilterBlur(float radius);
    ~FilterBlur();

    void Apply(Canvas2D* canvas, int width, int height);

private:
    float m_radius;

    void Convolve1D_Vertical(RGBA* data, int width, int height, const std::vector<float> &kernel, RGBA* outData);
    void Convolve1D_Horizontal(RGBA* data, int width, int height, const std::vector<float> &kernel, RGBA* outData);
};

#endif // FILTERBLUR_H
