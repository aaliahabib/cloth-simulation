#include "ImplicitShape.h"
#include <algorithm>

ImplicitShape::ImplicitShape()
{

}

ImplicitShape::~ImplicitShape(){

}

float ImplicitShape::checkPlaneIntersection(float p, float d, float planeLoc){
    return (planeLoc-p)/(float)d;
}

float ImplicitShape::applyQuad(float a, float b, float c){
    float disc =(b*b - 4*a*c);

    if (disc < 0){
        return INFINITY;
    }

    float sum = (-1.0f*b+sqrt(disc)) / (2.0f*a);
    float sub = (-1.0f*b-sqrt(disc)) / (2.0f*a);

    if (sum > 0){
        if (sub > 0){
            return std::min(sum, sub);
        }
        else {
            return sum;
        }
    } else {
        if (sub > 0){
            return sub;
        }
    }
    return INFINITY;
}
