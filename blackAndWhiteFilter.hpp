#ifndef BLACKANDWHITEFILTER_HPP
#define BLACKANDWHITEFILTER_HPP

#include "grayScaleFilter.hpp"
#include "pixel.hpp"
#include "filter.hpp"

class BlackAndWhiteFilter : public Filter {
    public:
        BlackAndWhiteFilter() { }

        void processPixel(Pixel& pixel);
    private:
        // A partir de que valor se concidera un pixel negro
        const unsigned m_blackFactor = 127.5;
};

#endif