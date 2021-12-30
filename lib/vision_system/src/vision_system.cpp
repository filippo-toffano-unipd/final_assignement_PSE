#include <iostream>
using std::cerr;
using std::cout;
using std::endl;

#include <sstream>

#include <fstream>
using std::ifstream;

#include <vector>
using std::vector;

#include <string>
using std::string;

#include <queue>
using std::queue;

#include "vision_system.h"
#include "piece.h"
#include "piece_buffer.h"

PieceBuffer piece_queue_line1;

void vision_system_thread_main(string file_path){

    ifstream input_file_a(file_path); // file da cui estratte i dati di input linea 1

    for(int i = 0; i < 15; i++){
        string input_line1 = read_input_file(input_file_a);
        cout << "- " << input_line1 << endl;
        vector<string> split = split_input_element(input_line1);
        // Creazione della cosa
        Piece pezzo(static_cast<uint>(std::stoul(split[0])), static_cast<uint>(std::stoul(split[1])), split[2], std::stof(split[3]));
        piece_queue_line1.append_piece(pezzo);


        // Separazione degli elementi 
        for(uint i = 0; i < split.size(); i++)
            cout << split[i] << endl;
    }
    input_file_a.close();

}


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
