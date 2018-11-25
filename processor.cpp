#include "processor.hpp"

Processor::Processor(const char *args[], int n) {
    for (int i = 1; i < n; i++) {
         std::string s = args[i];
         
         if (s.compare("-gs") == 0) {
            processes.push_back(new GrayScaleFilter());
         } else if (s.compare("-bw") == 0) { 
            processes.push_back(new BlackAndWhiteFilter());
         } else if (s.compare("-n") == 0) {
            processes.push_back(new NegativeFilter());
         } else if (s.compare("-b") == 0 && (i+1) < n) {
            int bright = std::atoi(args[i+1]);
            processes.push_back(new BrightFilter(bright));
         }
    }
}

Processor::~Processor() {
   for (auto process : processes) delete process;
}

void Processor::process(Image& image) {
    for (auto process : processes) process->applyOn(image);
}