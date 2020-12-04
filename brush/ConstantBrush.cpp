/**
 * @file   ConstantBrush.cpp
 *
 * Implementation of a brush with a constant mask distribution.
 *
 * You should fill this file in while completing the Brush assignment.
 */

#include "ConstantBrush.h"
#include "Canvas2D.h"

#include <math.h>

ConstantBrush::ConstantBrush(RGBA color, int radius)
    : Brush(color, radius)
{
    // @TODO: [BRUSH] You'll probably want to set up the mask right away.
    m_radius = radius;
    makeMask();
}


ConstantBrush::~ConstantBrush()
{
}

void ConstantBrush::makeMask() {
    // @TODO: [BRUSH] Set up the mask for your Constant brush here...

    m_mask.clear();
    for (int row = -1*m_radius; row <= m_radius; row++){
        for(int col = -1*m_radius; col <= m_radius; col++){
            int dist = pow(row, 2) + pow(col, 2);
            if(dist <= pow(m_radius, 2)){
                m_mask.push_back(1);
            } else {
                m_mask.push_back(0);
            }
        }
    }

}


