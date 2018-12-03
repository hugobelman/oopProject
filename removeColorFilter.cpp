#include "removeColorFilter.hpp"

RemoveColorFiler::RemoveColorFiler(unsigned radius) {
    // Comprueba que el radio sea correcto
    if (radius < 0 && radius > 255) throw "Bad radius";
    m_radius = radius;
}

// Metodo que verifica si un pixel es similar al color, si este es así se vuelve transparente
void RemoveColorFiler::processPixel(Pixel &pixel) {
    if (pixel.a != 0 && pixel.isCloseTo(m_color, m_radius)) pixel.a = 0;
}