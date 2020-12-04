#include "FilterBlur.h"
#include <math.h>

FilterBlur::FilterBlur(float raidus):
    m_radius(raidus)
{
}

FilterBlur::~FilterBlur()
{
}

void FilterBlur::Convolve1D_Horizontal(RGBA* data, int width, int height, const std::vector<float> &kernel, RGBA* outData){
    int dim = kernel.size();
    int offset = floor((float)dim/2);

    RGBA* current_pixel = data;

    for (int r = 0; r < height; r++) {

        for (int c = 0; c < width; c++) {
            size_t centerIndex = r * width + c;

            float red_acc = 0;
            float green_acc = 0;
            float blue_acc = 0;

            float weight_sum = 0;

            for (int kc = 0; kc < dim; kc++){
                float kernelVal = kernel[kc];

                int image_col = c + kc - offset;

                if (image_col < 0 | image_col >= width){
                    continue;
                }

                weight_sum += kernelVal;


                RGBA* pix = &data[r*width+image_col];

                red_acc = red_acc + kernelVal*((float)pix->r/255.0f);
                green_acc = green_acc + kernelVal*((float)pix->g/255.0f);
                blue_acc = blue_acc + kernelVal*((float)pix->b/255.0f);
            }


            RGBA pix = RGBA(REAL2byte(red_acc/(float)weight_sum), REAL2byte(green_acc/(float)weight_sum), REAL2byte(blue_acc/(float)weight_sum));

            outData[centerIndex] = pix;

        current_pixel++;
        }
    }
}

void FilterBlur::Convolve1D_Vertical(RGBA* data, int width, int height, const std::vector<float> &kernel, RGBA* outData){
    int dim = kernel.size();
    int offset = floor((float)dim/2);

    RGBA* current_pixel = data;

    for (int r = 0; r < height; r++) {

        for (int c = 0; c < width; c++) {
            size_t centerIndex = r * width + c;

            float red_acc = 0;
            float green_acc = 0;
            float blue_acc = 0;

            float weight_sum = 0;

            for (int kr = 0; kr < dim; kr++){
                float kernelVal = kernel[kr];

                int image_row = r + kr - offset;

                if (image_row < 0 | image_row >= height){
                    continue;
                }
                weight_sum += kernelVal;

                RGBA* pix = &data[image_row*width+c];

                red_acc = red_acc + kernelVal*((float)pix->r/255.0f);
                green_acc = green_acc + kernelVal*((float)pix->g/255.0f);
                blue_acc = blue_acc + kernelVal*((float)pix->b/255.0f);
            }

            RGBA pix = RGBA(REAL2byte(red_acc/(float)weight_sum), REAL2byte(green_acc/(float)weight_sum), REAL2byte(blue_acc/(float)weight_sum));

            outData[centerIndex] = pix;

        current_pixel++;
        }
    }
}

void FilterBlur::Apply(Canvas2D* canvas, int width, int height){
    std::vector<float> kernel;

    kernel.clear();
    kernel.resize(m_radius*2+1);

    float sigma = (m_radius*2+1)/3.0f;

    for(int i = 0; i < m_radius*2+1; i++){
      int j = i-m_radius;
      float val = exp(-1*(pow(j, 2))/((float)2*pow(sigma, 2)))/((float)sigma*sqrt(2*M_PI));
      kernel[i] = val;
    }

    float acc = 0;
    for(int j = 0; j < m_radius*2+1; j++){
       acc = acc+kernel[j];
    }

    for(int k = 0; k < m_radius*2+1; k++){
        kernel[k] = kernel[k]/(float)acc;
    }

    RGBA intermediateResult[width*height];
    Convolve1D_Horizontal(canvas->data(), width, height, kernel, intermediateResult);
    Convolve1D_Vertical(intermediateResult, width, height, kernel, canvas->data());
}
