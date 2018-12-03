#include <iostream>
#include <string>
#include "processor.hpp"
#include "image.hpp"

using namespace std;

void printInfo();

int main(int argc, char const *argv[])
{  
    const char *nameInputFile = nullptr;
    const char *nameOutputFile = "output.png";

    // Busca y almacena los nombres de archivo de entrada y salida
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
            printInfo();
        }
    } else {
        printInfo();
    }

    return 0;
}

void printInfo() {
    cout << "Procesador de imagenes v0.1a" << endl << endl;
    cout << "main [-i inputFile] [-o outputFile] [filters] [operations]" << endl << endl;
    cout << "Filtros:" << endl;
    cout << "-gs\t Escala de grises" << endl;
    cout << "-bw\t Blanco y negro" << endl;
    cout << "-n\t Negativo" << endl << endl;;

    cout << "Operaciones:" << endl;
    cout << "[-b -10 a 10]\tModifica el brillo" << endl;
    cout << "[-rb 0 a 255] \tRemueve el fondo blanco" << endl;
    cout << "[-t  0 a 255]\tRemueve el color blanco" << endl;
}
