#include "grayScaleFilter.hpp"

void GrayScaleFilter::processPixel(Pixel& pixel) {
    pixel = Pixel((pixel.r + pixel.g + pixel.b) / 3);
}