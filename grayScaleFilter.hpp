#ifndef GRAYSCALEFILTER_HPP
#define GRAYSCALEFILTER_HPP

#include "imageProcessor.hpp"
#include "filter.hpp"

class GrayScaleFilter : public Filter {
    public:
        GrayScaleFilter() { }

        void processPixel(Pixel& pixel) override;
};

#endif