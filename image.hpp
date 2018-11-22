#ifndef IMAGE_HPP
#define IMAGE_HPP

#include <vector>
#include "pixel.hpp"
#include "libraries/lodepng.h"

class Image {
    public:
        Image();
        Image(const char *filename);

        // Getters
        unsigned width() const;
        unsigned height() const;
        const Pixel& at(int x, int y) const;
        const Pixel& operator()(int x, int y) const; 

        // Setters
        Pixel& at(int x, int y);
        Pixel& operator()(int x, int y);

        // Interface
        void save(const char *filename);

    private:
        // Helpers
        void decode(const char *filename);

        std::vector<Pixel> m_pixels;
        unsigned m_width, m_height;
};

#endif