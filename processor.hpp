#ifndef PROCESSOR_HPP
#define PROCESSOR_HPP

#include <vector>
#include <string>
#include "imageProcessor.hpp"
#include "grayScaleFilter.hpp"
#include "blackAndWhiteFilter.hpp"
#include "negativeFilter.hpp"
#include "brightFilter.hpp"
#include "transparentOperator.hpp"
#include "removeColorFilter.hpp"

// Basado en patrón de diseño Command
class Processor {
    public:
        Processor(const char *args[], int n);
        ~Processor();

        // Metodo para ejecutar la acción en la imagen
        void process(Image& image); 
    private:
        std::vector<ImageProcessor*> processes;
};

#endif