#include "processor.hpp"

// Constructor que analiza las flags introducidas, obtiene los datos y agrega a la cola de procesos
Processor::Processor(const char *args[], int n) {
    for (int i = 1; i < n; i++) {
         std::string param = args[i];
         
         if (param.compare("-i") == 0) {
            i++;
         } else if (param.compare("-gs") == 0) {
            processes.push_back(new GrayScaleFilter());
         } else if (param.compare("-bw") == 0) { 
            processes.push_back(new BlackAndWhiteFilter());
         } else if (param.compare("-n") == 0) {
            processes.push_back(new NegativeFilter());
         } else if (param.compare("-b") == 0 && (i+1) < n) {
            int brightScale = std::atoi(args[++i]);
            processes.push_back(new BrightFilter(brightScale));
         } else if (param.compare("-rb") == 0) {
            int radius = (i+1) < n ? std::atoi(args[++i]) : 5;
            processes.push_back(new TransparentOperator(radius));
         } else if (param.compare("-t") == 0) {
            int radius = (i+1) < n ? std::atoi(args[++i]) : 5;
            processes.push_back(new RemoveColorFiler(radius));
         } else {
            throw "Not match";
         }
    }
}

// Uso de polimorfismo
void Processor::process(Image& image) {
    for (auto process : processes) process->applyOn(image);
}

// Destructor que libera memoria dinamica
Processor::~Processor() {
   for (auto process : processes) delete process;
}