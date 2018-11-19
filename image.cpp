#include "image.hpp"

Image::Image() : m_width(0), m_height(0) {}

Image::Image(const char *filename) : Image() {
    decode(filename);
}

unsigned Image::width() const {
    return m_width;
}
    
unsigned Image::height() const {
    return m_height;
}
    
const Pixel& Image::at( int x, int y ) const {
    return m_pixels[m_width*y+x];
}
    
const Pixel& Image::operator()(int x, int y) const {
    return m_pixels[m_width*y+x];
} 
    
Pixel& Image::at( int x, int y ) {
    return m_pixels[m_width*y+x];
}
    
Pixel& Image::operator()(int x, int y ) {
    return m_pixels[m_width*y+x];
}

void Image::save(const char *filename) {
    std::vector<unsigned char> image;

    for (unsigned i = 0; i < m_width*m_height; i++) {
       image.push_back( m_pixels[i].r );
       image.push_back( m_pixels[i].g );
       image.push_back( m_pixels[i].b );
       image.push_back( m_pixels[i].a );
    }

    unsigned error = lodepng::encode(filename, image, m_width, m_height);

    if ( error ) throw "Cannot save the file";
}   

void Image::decode(const char *filename) {
    std::vector<unsigned char> pixels;
    unsigned width, height;
    
    unsigned error = lodepng::decode(pixels, width, height, filename);
    if ( error ) throw "Wrong file name";
    
    m_width = width;
    m_height = height;

    m_pixels.clear();
    m_pixels.resize(width * height, Pixel(Color::CLEAR));
    
    unsigned k = 0;
    for (unsigned i = 0; i < m_width * m_height; i++) {
        m_pixels[i].r = pixels[k++];
        m_pixels[i].g = pixels[k++];
        m_pixels[i].b = pixels[k++];
        m_pixels[i].a = pixels[k++];
     }
}

