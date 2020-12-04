#include "FilterEdge.h"
#include <math.h>

inline unsigned char RGBAToGray(const RGBA &pixel) {
    return 0.299*pixel.r + 0.587*pixel.g + 0.114*pixel.b;
}

FilterEdge::FilterEdge(float sensitivity):
    m_sensitivity(sensitivity)

{
    m_kernel = {-1, 0, 1, -2, 0, 2, -1, 0, 1};
}

FilterEdge::~FilterEdge()
{
}

void FilterEdge::Grayscale(RGBA* data, int width, int height){

    for(int r = 0; r < height; r++){
        for(int c = 0; c < width; c++){
            RGBA *current_pixel = &data[r*width+c];
            float val = RGBAToGray(*current_pixel);
            current_pixel->r = val;
            current_pixel->g = val;
            current_pixel->b = val;
        }
    }
}

void FilterEdge::Convolve2D(RGBA* data, int width, int height, const std::vector<float> &kernel, float* outData) {
    int dim = sqrt(kernel.size());
    int offset = floor((float)dim/2);

    RGBA* current_pixel = data;

    for (int r = 0; r < height; r++) {

        for (int c = 0; c < width; c++) {
            size_t centerIndex = r * width + c;


            float val = 0;

            for (int kr = 0; kr < dim; kr++){
                for (int kc = 0; kc < dim; kc++){

                    float kernelVal = kernel[kr*dim+kc];

                    int image_row = r + kr - offset;
                    int image_col = c + kc - offset;

                    if (image_row < 0) {
                        image_row = 0;
                    } if (image_row >= height) {
                        image_row = height-1;
                    } if (image_col < 0) {
                        image_col = 0;
                    } if (image_col >= width){
                        image_col = width-1;
                    }


                    RGBA* pix = &data[image_row*width+image_col];

                    val = val + kernelVal*((float)pix->r/255.0f);

                }
            }
            outData[centerIndex] = val;

        current_pixel++;
        }
    }
}

void FilterEdge::Apply(Canvas2D *canvas, int width, int height){
   Grayscale(canvas->data(), width, height);

   float xData[width*height];
   float yData[width*height];

   std::vector<float> x_kernel = {-1, 0, 1, -2, 0, 2, -1, 0, 1};
   std::vector<float> y_kernel = {-1, -2, -1, 0, 0, 0, 1, 2, 1};

   Convolve2D(canvas->data(), width, height, x_kernel, xData);
   Convolve2D(canvas->data(), width, height, y_kernel, yData);

   RGBA* curr_pixel = canvas->data();

   for(int r = 0; r < height; r++){
       for(int c = 0; c < width; c++){

           int centerIndex = r*width+c;

           float val = sqrt(pow(xData[centerIndex], 2) + pow(yData[centerIndex], 2));

           val = m_sensitivity*val;

           val = std::min(val, 1.0f);

           curr_pixel->r = REAL2byte(val);
           curr_pixel->g = REAL2byte(val);
           curr_pixel->b = REAL2byte(val);

           curr_pixel++;
       }
   }
}


