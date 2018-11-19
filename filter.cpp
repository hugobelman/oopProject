#include "filter.hpp"

void Filter::applyOn(Image& image) {
    for (unsigned i = 0; i < image.width(); i++) 
        for (unsigned j = 0; j < image.height(); j++) processPixel(image(i,j));
}