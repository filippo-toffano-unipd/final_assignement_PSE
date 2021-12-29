#include <iostream>
using std::cerr;
using std::endl;

#include <fstream>
using std::ifstream;

#include <string>
using std::string;

#include <vector>
using std::vector;

#include "vision_system.h"



// Funzione lettura dati di input della linea 1:
string read_input_file( ifstream &input_file ){
    
    //vector<string> input_line;      // vettore contenete i dati estratti
    string line;                    // linea estratta da input file

    // Controllo di sicurezza:
    if(!input_file.is_open()){
        cerr << "Impossibile aprire il file " << endl;
        exit(EXIT_FAILURE);
    }

    // lettura riga per riga
    getline(input_file, line);
    //input_line.push_back(line);


    
    return line;
}
