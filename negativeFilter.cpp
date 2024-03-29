#include "negativeFilter.hpp"

// Metodo que invierte un pixel
void NegativeFilter::processPixel(Pixel& pixel) {
    pixel.r = m_inverseFactor - pixel.r;
    pixel.g = m_inverseFactor - pixel.g;
    pixel.b = m_inverseFactor - pixel.b;
}