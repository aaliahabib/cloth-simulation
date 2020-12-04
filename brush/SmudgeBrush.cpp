/**
 * @file   Brush.cpp
 *
 * Implementation of a brush that smudges the image on the canvas as the mouse is dragged.
 *
 * You should fill this file in for the Brush assignment.
 */

#include "SmudgeBrush.h"
#include <iostream>
#include "Canvas2D.h"
#include "math.h"

static unsigned char lerp(unsigned char a, unsigned char b, float percent) {
    float fa = static_cast<float>(a) / 255.0f;
    float fb = static_cast<float>(b) / 255.0f;
    return static_cast<unsigned char>((fa + (fb - fa) * percent) * 255.0f + 0.5f);
}

SmudgeBrush::SmudgeBrush(RGBA color, int radius) :
    QuadraticBrush(color, radius)
{
    // @TODO: [BRUSH] Initialize any memory you are going to use here. Hint - you are going to
    //       need to store temporary image data in memory. Remember to use automatically managed memory!

    m_radius = radius;
    makeMask();
    m_buffer.reserve(pow(m_radius*2+1, 2));

}


SmudgeBrush::~SmudgeBrush()
{
    // @TODO: [BRUSH] Be sure not to leak memory!  If you're using automatic memory management everywhere,
    //       this will be empty.
}

void SmudgeBrush::setRadius(int radius) {
    m_radius = radius;
    makeMask();
    m_buffer.reserve(pow(m_radius*2+1, 2));
}


void SmudgeBrush::brushUp(int x, int y, Canvas2D* canvas) {
}


void SmudgeBrush::brushDown(int x, int y, Canvas2D *canvas) {
    pickUpPaint(x, y, canvas);
}

//! Picks up paint from the canvas before drawing begins.
void SmudgeBrush::pickUpPaint(int x, int y, Canvas2D* canvas) {

    RGBA *pix = canvas->data();
    int width = canvas->width();
    int height = canvas->height();

    // @TODO: [BRUSH] Perform the "pick up paint" step described in the assignment handout here.
    //        In other words, you should store the "paint" under the brush mask in a temporary
    //        buffer (which you'll also have to figure out where and how to allocate). Then,
    //        in the paintOnce() method, you'll paste down the paint that you picked up here.
    //

    int mask_index = 0;
    for (int row = y-m_radius; row < y+m_radius+1; row++){
        for (int col = x-m_radius; col < x+m_radius+1; col++){
            int pixel_index = row*width + col;
            if (!(row < 0 && row > height && col < row && col > width)){
                m_buffer[mask_index] = pix[pixel_index];
            }
            mask_index++;
        }
    }
}

void SmudgeBrush::brushDragged(int mouseX, int mouseY, Canvas2D* canvas) {
    // @TODO: [BRUSH] Here, you'll need to paste down the paint you picked up in
    //        the previous method. Be sure to take the mask into account! You can
    //        ignore the alpha parameter, but you can also use it (smartly) if you
    //        would like to.

    RGBA *pix = canvas->data();
    int width = canvas->width();
    int height = canvas->height();

    int mask_index = 0;
    for (int row = mouseY-m_radius; row < mouseY+m_radius+1; row++){
        for (int col = mouseX-m_radius; col < mouseX+m_radius+1; col++){
            int pixel_index = row*width + col;
            if (row >= 0 && row < height && col >= 0 && col < width){
                float m = m_mask[mask_index];
                if (m != 0){

                    RGBA temp = m_buffer[mask_index];
                    RGBA original_value = pix[pixel_index];

                    pix[pixel_index].r = lerp(temp.r, original_value.r, 1-m);
                    pix[pixel_index].g = lerp(temp.g, original_value.g, 1-m);
                    pix[pixel_index].b = lerp(temp.b, original_value.b, 1-m);

                    //m_buffer[mask_index] = original_value;
                }
            }
            mask_index++;
        }
    }

    // now pick up paint again...
    pickUpPaint(mouseX, mouseY, canvas);

}


