#ifndef BLACKANDWHITEFILTER_HPP
#define BLACKANDWHITEFILTER_HPP

#include "imageProcessor.hpp"
#include "grayScaleFilter.hpp"
#include "pixel.hpp"
#include "filter.hpp"

class BlackAndWhiteFilter : public Filter {
    public:
        BlackAndWhiteFilter() { }

        void processPixel(Pixel& pixel);
    private:
        unsigned m_blackFactor = 127.5;
};

#endif