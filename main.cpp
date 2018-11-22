#include <iostream>
#include <string>
#include "processor.hpp"
#include "image.hpp"
#include "pixel.hpp"
#include "grayScaleFilter.hpp"
#include "negativeFilter.hpp"
#include "blackAndWhiteFilter.hpp"

using namespace std;

int main(int argc, char const *argv[])
{  
    const char *nameInputFile = nullptr;
    const char *nameOutputFile = "output.png";

    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-i") == 0 && (i+1) < argc) nameInputFile = argv[i+1];
        if (strcmp(argv[i], "-o") == 0 && (i+1) < argc) nameOutputFile = argv[i+1];

        if (nameInputFile != nullptr && strcmp(nameOutputFile, "output.png") != 0) break;
    }

    if (nameInputFile != nullptr) {
        try {
            Image image(nameInputFile);
            
            Processor processor(argv, argc);
            processor.process(image);

            image.save(nameOutputFile);
        } catch (...) {
            cout << "Archivo no valido" << endl;
        }
    } else {
        cout << "Error: Falta archivo de entrada" << endl;
    }


    return 0;
}
