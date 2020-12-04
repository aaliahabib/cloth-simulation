#ifndef FILTEREDGE_H
#define FILTEREDGE_H

#include "Canvas2D.h"
#include "Filter.h"


class FilterEdge :
        public Filter
{
public:
    FilterEdge(float sensitivity);
    ~FilterEdge();

    void Apply(Canvas2D* canvas, int width, int height);

private:
    std::vector<float> m_kernel;
    float m_sensitivity;

    void Grayscale(RGBA* data, int width, int height);
    void Convolve2D(RGBA* data, int width, int height, const std::vector<float> &kernel, float* outData);
};

#endif // FILTEREDGE_H
