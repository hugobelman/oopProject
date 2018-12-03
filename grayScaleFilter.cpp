#include "grayScaleFilter.hpp"

// Metodo que saca el promedio de un pixel para convertirlo en gris
void GrayScaleFilter::processPixel(Pixel& pixel) {
    pixel = Pixel((pixel.r + pixel.g + pixel.b) / 3);
}