#ifndef PIXEL_HPP
#define PIXEL_HPP

enum Color { CLEAR, WHITE, SILVER, GRAY, BLACK, RED, MAROON, YELLOW, OLIVE,
                 LIME, GREEN, AQUA, CYAN, TEAL, BLUE, NAVY, FUCHSIA, MAGENTA,
                 PURPLE };

struct Pixel {
    unsigned short r, g, b, a;

    Pixel(Color colorName);
    Pixel(unsigned char gray);
    Pixel(unsigned char r, unsigned char g, unsigned char b);
    Pixel(unsigned char r, unsigned char g, unsigned char b, unsigned char a);
    
    bool operator ==(Pixel b);
    bool isCloseTo(Pixel color, unsigned radius);
};

#endif