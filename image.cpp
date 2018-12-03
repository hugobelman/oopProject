#include "image.hpp"

// Decodifica la imagen para su proxima manipulación
Image::Image(const char *filename) {
    std::vector<unsigned char> image;
    
    unsigned error = lodepng::decode(image, m_width, m_width, filename);
    if (error) throw "Wrong file name";

    m_pixels.clear();
    m_pixels.resize(m_width * m_width, Pixel(Color::CLEAR));
    
    unsigned k = 0;
    for (unsigned i = 0; i < m_width * m_height; i++) {
        m_pixels[i].r = image[k++];
        m_pixels[i].g = image[k++];
        m_pixels[i].b = image[k++];
        m_pixels[i].a = image[k++];
    }
}

unsigned Image::width() const {
    return m_width;
}
    
unsigned Image::height() const {
    return m_height;
}
    
const Pixel& Image::operator()(int x, int y) const {
    return m_pixels[m_width*y+x];
} 
    
Pixel& Image::operator()(int x, int y ) {
    return m_pixels[m_width*y+x];
}

// Codifica la imagen y la guarda en el disco
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
