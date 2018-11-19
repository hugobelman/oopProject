#include "negativeFilter.hpp"

void NegativeFilter::processPixel(Pixel& pixel) {
    pixel = Pixel(m_inverseFactor - pixel.r, m_inverseFactor - pixel.g, m_inverseFactor - pixel.b);
}