#include "filter.hpp"

Filter::Filter() {

}

// Metodo para recorrer una imagen pixel por pixel realizando la acción contenida en processPixel
void Filter::applyOn(Image& image) {
    for (unsigned i = 0; i < image.width(); i++) 
        for (unsigned j = 0; j < image.height(); j++) processPixel(image(i,j));
}