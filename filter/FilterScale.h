#ifndef FILTERSCALE_H
#define FILTERSCALE_H

#include "Canvas2D.h"
#include "Filter.h"


class FilterScale :
        public Filter
{
public:
    FilterScale(float xScaleFactor, float yScaleFactor);
    ~FilterScale();

    void Apply(Canvas2D* canvas, int width, int height);

private:
    float m_Xscale;
    float m_Yscale;


    float determineRadius(float scaleFactor);
    float getTriangleHeight(float x, float radius);

    void filterHorizontal(RGBA* data, int width, int height, RGBA* outData);
    void filterVertical(RGBA* data, int width, int height, RGBA* outData);
};

#endif // FILTERSCALE_H
