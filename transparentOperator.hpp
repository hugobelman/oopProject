#ifndef TRANSPARENTOPERATOR_HPP
#define TRANSPARENTOPERATOR_HPP

#include "imageProcessor.hpp"
#include <iostream>

class TransparentOperator : public ImageProcessor {
    public:
        TransparentOperator(int radius);
        void applyOn(Image& image) override;
    private:
        // Color a eliminar
        const Pixel m_color = Pixel(Color::WHITE);
        // Radio de similitud entre pixeles
        unsigned m_radius;
};

#endif