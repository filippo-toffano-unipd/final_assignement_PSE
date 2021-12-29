#include <iostream>
using std::cerr;
using std::endl;

#include <sstream>

#include <fstream>
using std::ifstream;

#include <vector>
using std::vector;

#include <string>
using std::string;

#include "vision_system.h"



// Funzione lettura dati di input della linea 1:
string read_input_file( ifstream &input_file ){
    
    string line;                    // linea estratta da input file

    // Controllo di sicurezza:
    if(!input_file.is_open()){
        cerr << "Impossibile aprire il file " << endl;
        exit(EXIT_FAILURE);
    }

    // lettura riga per riga
    getline(input_file, line);
    
    return line;
}

vector<string> split_input_element(string line_to_split){

    std::istringstream stream_line{line_to_split};
    vector<string> split_line;
    string line;
    split_line.reserve(4);

    for(int i = 0; i < 4; i++){
        getline(stream_line, line, ' ');
        split_line.push_back(line);
    }

    return split_line;
}
