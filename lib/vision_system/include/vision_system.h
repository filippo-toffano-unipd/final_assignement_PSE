/*  Libreria per la lettura da file dei dati dei pezzi da movimentare
    I dati contenuti sono:
    MM SS tipo_pezzo posizione
*/
#ifndef VISION_SYSTEM_H
#define VISION_SYSTEM_H

#include <fstream>
using std::ifstream;

#include<vector>
using std::vector;

#include <string>
using std::string; 

#include <chrono>
using namespace std::chrono;

#include "piece_buffer.h"
#include "global_variables.h"


// Thread main program
void vision_system_thread_main(string file_path, system_clock::time_point start_time, char ID_line);

// Funzione lettura dati input linea 
string read_input_file(ifstream &input_file);

// Funzione per separare gli elementi estratti dai file di input
vector<string> split_input_element(string string_to_split);

// Funzione di arresto impianto:
void halt_system();
#endif