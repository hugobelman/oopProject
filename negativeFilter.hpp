#ifndef NEGATIVEFILTER_HPP
#define NEGATIVEFILTER_HPP

#include "filter.hpp"

class NegativeFilter : public Filter {
    public:
        NegativeFilter() { }

        void processPixel(Pixel& pixel) override;
    private:
        // Valor maximo de color de un pixel
        const unsigned m_inverseFactor = 255; 
};

#endif