#include "FilterScale.h"
#include <math.h>

inline float backmap(int val, float scale){
    return val/(float)scale + (1-scale)/(float)(2*scale);
}

FilterScale::FilterScale(float xScaleFactor, float yScaleFactor):
    m_Xscale(xScaleFactor),
    m_Yscale(yScaleFactor)
{
}

FilterScale::~FilterScale()
{}


float FilterScale::determineRadius(float scaleFactor){
    float radius = 1;
    if (scaleFactor < 1){
        radius = 1.0f/scaleFactor;
    }

    return radius;
}

float FilterScale::getTriangleHeight(float x, float radius){
    if (fabs(x) > radius){
        return 0;
    }
    return (1-fabs(x)/(float)radius)/(float)radius;
}

void FilterScale::filterHorizontal(RGBA *data, int width, int height, RGBA *outData){

    int targetWidth = m_Xscale*width;
    float radius = determineRadius(m_Xscale);

    for (int r = 0; r < height; r++) {
        for (int c = 0; c < targetWidth; c++) {
            size_t centerIndex = r * targetWidth + c;

            float backmapped_col = backmap(c, m_Xscale);
            int min = floor(backmapped_col-radius);
            int max = ceil(backmapped_col+radius);

            float red_acc = 0;
            float green_acc = 0;
            float blue_acc = 0;
            float weight_sum = 0;

            for(int image_col = min; image_col <= max; image_col++){

                if (image_col < 0 | image_col >= width){
                    continue;
                }

                float weight = getTriangleHeight(backmapped_col-image_col, radius);
                weight_sum = weight_sum+weight;

                RGBA* pix = &data[r*width+image_col];

                red_acc = red_acc + weight*((float)pix->r/255.0f);
                green_acc = green_acc + weight*((float)pix->g/255.0f);
                blue_acc = blue_acc + weight*((float)pix->b/255.0f);

            }
            red_acc = (float)red_acc/weight_sum;
            green_acc = (float)green_acc/weight_sum;
            blue_acc = (float)blue_acc/weight_sum;

            RGBA pix = RGBA(REAL2byte(red_acc), REAL2byte(green_acc), REAL2byte(blue_acc));
            outData[centerIndex] = pix;
        }
    }
}

void FilterScale::filterVertical(RGBA *data, int width, int height, RGBA *outData){

    int targetHeight = m_Yscale*height;
    float radius = determineRadius(m_Yscale);

    for (int c = 0; c < width; c++) {
        for (int r = 0; r < targetHeight; r++) {
            size_t centerIndex = r * width + c;

            float backmapped_row = backmap(r, m_Yscale);
            int min = floor(backmapped_row-radius);
            int max = ceil(backmapped_row+radius);

            float red_acc = 0;
            float green_acc = 0;
            float blue_acc = 0;
            float weight_sum = 0;

            for(int image_row = min; image_row <= max; image_row++){
                if (image_row < 0 | image_row >= height){
                    continue;
                }

                float weight = getTriangleHeight(backmapped_row-image_row, radius);
                weight_sum = weight_sum+weight;

                RGBA* pix = &data[image_row*width+c];

                red_acc = red_acc + weight*((float)pix->r/255.0f);
                green_acc = green_acc + weight*((float)pix->g/255.0f);
                blue_acc = blue_acc + weight*((float)pix->b/255.0f);

            }
            red_acc = (float)red_acc/weight_sum;
            green_acc = (float)green_acc/weight_sum;
            blue_acc = (float)blue_acc/weight_sum;

            RGBA pix = RGBA(REAL2byte(red_acc), REAL2byte(green_acc), REAL2byte(blue_acc));
            outData[centerIndex] = pix;
        }
    }
}

void FilterScale::Apply(Canvas2D *canvas, int width, int height){
    int new_width = m_Xscale*width;
    int new_height = m_Yscale*height;

    std::vector<RGBA> horizontally_stretched;
    horizontally_stretched.resize(new_width*height);

    filterHorizontal(canvas->data(), width, height, horizontally_stretched.data());

    std::vector<RGBA> vertically_stretched;
    vertically_stretched.resize(new_width*new_height);

    filterVertical(horizontally_stretched.data(), new_width, height, vertically_stretched.data());

    canvas->resize(new_width, new_height);
    memcpy(canvas->data(), vertically_stretched.data(), new_width*new_height*sizeof(RGBA));

}


