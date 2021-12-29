/*  Libreria per la lettura da file dei dati dei pezzi da movimentare
    I dati contenuti sono:
    MM SS tipo_pezzo posizione
*/
#ifndef READ_FILE_H
#define READ_FILE_H

#include <fstream>
using std::ifstream;

#include <string>
using std::string;

#include <vector>
using std::vector; 

#include <string>
using std::string; 

// Funzione lettura dati input linea 1
string read_input_file(ifstream &input_file);

#endif