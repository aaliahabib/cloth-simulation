#include "Filter.h"
#include <math.h>



Filter::Filter()
{
}

Filter::~Filter()
{
}

unsigned char Filter::REAL2byte(float f) {
    f = fabs(f);
    int i = static_cast<int>((f * 255.0 + 0.5));
    return (i < 0) ? 0 : (i > 255) ? 255 : i;
}
