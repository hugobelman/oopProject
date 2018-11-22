#ifndef BRIGHTFILTER_HPP
#define BRIGHTFILTER_HPP

#include "filter.hpp"

class BrightFilter : public Filter {
    public:
        BrightFilter(int plusBright) : m_plusBright(plusBright) { }

        void processPixel(Pixel& pixel);
    private:
        int m_plusBright;
};

#endif