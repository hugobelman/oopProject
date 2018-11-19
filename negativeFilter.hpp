#ifndef NEGATIVEFILTER_HPP
#define NEGATIVEFILTER_HPP

#include "imageProcessor.hpp"
#include "filter.hpp"

class NegativeFilter : public Filter {
    public:
        NegativeFilter() { }

        void processPixel(Pixel& pixel) override;
    private:
        unsigned m_inverseFactor = 255; 
};

#endif