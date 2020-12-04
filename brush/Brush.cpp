/**
 * @file   Brush.cpp
 *
 * Implementation of common functionality of bitmap brushes.
 *
 * You should fill this file in while completing the Brush assignment.
 */

#include "Brush.h"
#include "Canvas2D.h"

#include <iostream>

static unsigned char lerp(unsigned char a, unsigned char b, float percent) {
    float fa = static_cast<float>(a) / 255.0f;
    float fb = static_cast<float>(b) / 255.0f;
    return static_cast<unsigned char>((fa + (fb - fa) * percent) * 255.0f + 0.5f);
}



Brush::Brush(RGBA color, int radius) :
    // Pro-tip: Initialize all variables in the initialization list
    m_color(color),
    m_radius(radius)
{
    // Pro-tip: By the time you get to the constructor body, all of the
    // member variables have already been initialized.
}


Brush::~Brush()
{
    // Pro-tip: The destructor (here) is where you free all the resources
    // you allocated during the lifetime of the class
    // Pro-tip: If you use std::unique_ptr or std::vector, you probabably
    // won't need to put anything in here.
}

int Brush::getAlpha() const {
    return m_color.a;
}

RGBA Brush::getRGBA() const {
    return m_color;
}

int Brush::getBlue() const {
    return m_color.b;
}

int Brush::getGreen() const {
    return m_color.g;
}

int Brush::getRadius() const {
    return m_radius;
}

int Brush::getRed() const {
    return m_color.r;
}

void Brush::setAlpha(int alpha) {
    m_color.a = alpha;
}

void Brush::setRGBA(const RGBA &rgba) {
    m_color = rgba;
}

void Brush::setBlue(int blue) {
    m_color.b = blue;
}

void Brush::setGreen(int green) {
    m_color.g = green;
}

void Brush::setRed(int red) {
    m_color.r = red;
}

void Brush::setRadius(int radius) {
    m_radius = radius;
    makeMask();
}





void Brush::brushDragged(int mouseX, int mouseY, Canvas2D* canvas) {

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
                    RGBA curr_pix = pix[pixel_index];
                    float a = m_color.a;
                    float r = lerp(m_color.r, curr_pix.r, 1 - m*a/255.0);
                    float g = lerp(m_color.g, curr_pix.g, 1 - m*a/255.0);
                    float b = lerp(m_color.b, curr_pix.b, 1 - m*a/255.0);

                    pix[pixel_index].r = r;
                    pix[pixel_index].g = g;
                    pix[pixel_index].b = b;
                }
            }
            mask_index++;
        }
    }
    canvas->update();
}
