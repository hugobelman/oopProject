#include "blackAndWhiteFilter.hpp"

void BlackAndWhiteFilter::processPixel(Pixel& pixel) {
    GrayScaleFilter grayScaleFilter;
    grayScaleFilter.processPixel(pixel);

    if (pixel.r > m_blackFactor) pixel = Pixel(Color::BLACK);
    else pixel = Pixel(Color::WHITE);
}