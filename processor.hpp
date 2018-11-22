#ifndef PROCESSOR_HPP
#define PROCESSOR_HPP

#include <vector>
#include <string>
#include "imageProcessor.hpp"
#include "grayScaleFilter.hpp"
#include "blackAndWhiteFilter.hpp"
#include "negativeFilter.hpp"
#include "brightFilter.hpp"


#include <iostream>

class Processor {
    public:
        Processor(const char *args[], int n);

        void process(Image& image); 
    private:
        std::vector<ImageProcessor*> processes;
};

#endif