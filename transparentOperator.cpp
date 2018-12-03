#include "transparentOperator.hpp"

TransparentOperator::TransparentOperator(int radius) {
    // Comprueba que el radio sea correcto
    if (radius < 0 && radius > 255) throw "Bad radius";
    m_radius = radius;
}

// Metodo que quita el fondo de la imagen 
void TransparentOperator::applyOn(Image& image) {
    unsigned x_f;
    unsigned x_l;

    for (unsigned y = 0; y < image.height(); y++) {
        x_f = image.width() - 1;
        x_l = 0;

        for (unsigned x = 0; x < image.width(); x++ ){
            Pixel &px = image(x,y);
             
             if (!px.isCloseTo(m_color, m_radius)) {
                if (x_f == (image.width() - 1)) x_f = x;
                x_l = x;
             }
        }
    
        for (unsigned x = 0; x < image.width(); x++ ){
            if (x <= x_f || x >= x_l) image(x,y).a = 0;
        }
    }
}