#ifndef REMOVECOLORFILTER_HPP
#define REMOVECOLORFILTER_HPP

#include "filter.hpp"

class RemoveColorFiler : public Filter {
    public:
        RemoveColorFiler(unsigned radius);

        void processPixel(Pixel &pixel) override;
    private:
        // Radio de similitud entre pixeles
        unsigned m_radius;
        // Color a eliminar
        const Pixel m_color = Pixel(Color::WHITE);
};

#endif