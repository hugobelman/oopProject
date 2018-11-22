#include "brightFilter.hpp"

void BrightFilter::processPixel(Pixel& pixel) {
   if (pixel.r + m_plusBright > 255) pixel.r = 255;
   else if (pixel.r + m_plusBright <= 0) pixel.r = 0;
   else pixel.r += m_plusBright;

   if (pixel.g + m_plusBright > 255) pixel.g = 255;
   else if (pixel.g + m_plusBright <= 0) pixel.g = 0;
   else pixel.g += m_plusBright;

   if (pixel.b + m_plusBright > 255) pixel.b = 255;
   else if (pixel.b + m_plusBright <= 0) pixel.b = 0;
   else pixel.b += m_plusBright;
}