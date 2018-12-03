#ifndef IMAGEPROCESSOR_HPP
#define IMAGEPROCESSOR_HPP

#include "image.hpp"

class ImageProcessor {
    public:
        ImageProcessor();
        virtual ~ImageProcessor() { }

        // Interface
        virtual void applyOn(Image& image) = 0;
};

#endif