#include "pixel.hpp"

Pixel::Pixel(Color colorName) {
    switch (colorName) {
        case CLEAR:   r = 0x00; g = 0x00; b = 0x00; a = 0x00; break;
        case WHITE:   r = 0xFF; g = 0xFF; b = 0xFF; a = 0xFF; break;
        case SILVER:  r = 0xC0; g = 0xC0; b = 0xC0; a = 0xFF; break;
        case GRAY:    r = 0x80; g = 0x80; b = 0x80; a = 0xFF; break;
        case BLACK:   r = 0x00; g = 0x00; b = 0x00; a = 0xFF; break;
        case RED:     r = 0xFF; g = 0x00; b = 0x00; a = 0xFF; break;
        case MAROON:  r = 0x80; g = 0x00; b = 0x00; a = 0xFF; break;
        case YELLOW:  r = 0xFF; g = 0xFF; b = 0x00; a = 0xFF; break;
        case OLIVE:   r = 0x80; g = 0x80; b = 0x00; a = 0xFF; break;
        case LIME:    r = 0x00; g = 0xFF; b = 0x00; a = 0xFF; break;
        case GREEN:   r = 0x00; g = 0x80; b = 0x00; a = 0xFF; break;
        case AQUA:
        case CYAN:    r = 0x00; g = 0xFF; b = 0xFF; a = 0xFF; break;
        case TEAL:    r = 0x00; g = 0x80; b = 0x80; a = 0xFF; break;
        case BLUE:    r = 0x00; g = 0x00; b = 0xFF; a = 0xFF; break;
        case NAVY:    r = 0x00; g = 0x00; b = 0x80; a = 0xFF; break;
        case FUCHSIA:
        case MAGENTA: r = 0xFF; g = 0x00; b = 0xFF; a = 0xFF; break;
        case PURPLE:  r = 0x80; g = 0x00; b = 0x80; a = 0xFF; break;
    }
}

bool Pixel::operator ==(Pixel b) {
    return (this->r == b.r && this->g == b.g && this->b == b.b);
}

// Metodo que evalua si un cierto pixel se parece a otro en base a un radio
bool Pixel::isCloseTo(Pixel color, unsigned radius) {
    int positiveLimit = color.r + radius;
    int negativeLimit = color.r - radius;

    if (!(this->r <= positiveLimit && this->r >= negativeLimit)) return false;
    if (!(this->g <= positiveLimit && this->g >= negativeLimit)) return false;
    if (!(this->b <= positiveLimit && this->b >= negativeLimit)) return false;

    return true;
}

Pixel::Pixel(unsigned char gray) : r(gray), g(gray), b(gray), a(0xFF) {}

Pixel::Pixel(unsigned char r, unsigned char g, unsigned char b) : r(r), g(g), b(b), a(0xFF) {}

Pixel::Pixel(unsigned char r, unsigned char g, unsigned char b, unsigned char a) : r(r), g(g), b(b), a(a) {}