#include "brightFilter.hpp"

// Convertidor de escala de -10 a 10 a la luz que se debe agrgegar o quitar
BrightFilter::BrightFilter(int brightScale) {
   if (brightScale > 10 || brightScale < -10) throw "Bad scale";

   m_brightness = brightScale * 25.5;
}

// Metodo que agrega o quita la luz del pixel
void BrightFilter::processPixel(Pixel& pixel) {
   int s = pixel.r + m_brightness;

   // Comprobacion para evitar desbordamiento de variables
   if (s > 255) pixel.r = 255;
   else if (s <= 0) pixel.r = 0;
   else pixel.r = s;

   s = pixel.g + m_brightness;

   // Comprobacion para evitar desbordamiento de variables
   if (s > 255) pixel.g = 255;
   else if (s <= 0) pixel.g = 0;
   else pixel.g = s;

   s = pixel.b + m_brightness;

   // Comprobacion para evitar desbordamiento de variables
   if (s > 255) pixel.b = 255;
   else if (s <= 0) pixel.b = 0;
   else pixel.b = s;
}