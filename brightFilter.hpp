#ifndef BRIGHTFILTER_HPP
#define BRIGHTFILTER_HPP

#include "filter.hpp"

class BrightFilter : public Filter {
    public:
        BrightFilter(int brightScale);

        void processPixel(Pixel& pixel);
    private:
        // Luz que se debe aplicar en cada pixel
        int m_brightness;
};

#endif