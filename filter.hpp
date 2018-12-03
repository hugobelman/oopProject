#ifndef FILTER_HPP
#define FILTER_HPP

#include "imageProcessor.hpp"

class Filter : public ImageProcessor {
    public:
        Filter();

        void applyOn(Image& image) override;
    protected:
        virtual void processPixel(Pixel& pixel) = 0;
};

#endif