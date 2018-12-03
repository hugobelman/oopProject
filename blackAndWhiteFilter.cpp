#include "blackAndWhiteFilter.hpp"

// Metodo que intercambia un pixel de color por blanco y negro usando el mismo escalado en grises
void BlackAndWhiteFilter::processPixel(Pixel& pixel) {
    // Se usa el metodo ya desarrollado del filtro de escalado de grises para procesar el pixel
    GrayScaleFilter grayScaleFilter;
    grayScaleFilter.processPixel(pixel);

    if (pixel.r > m_blackFactor) pixel = Pixel(Color::BLACK);
    else pixel = Pixel(Color::WHITE);
}