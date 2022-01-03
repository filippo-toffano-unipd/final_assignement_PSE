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

#include <chrono>
using namespace std::chrono;

#include <thread>
using std::thread;

#include <csignal>

#include "vision_system.h"
#include "piece.h"
#include "piece_buffer.h"
#include "global_variables.h"

void vision_system_thread_main(string file_path, system_clock::time_point start_time){

    ifstream input_file(file_path); // file da cui estratte i dati di input linea 1

    do{
        string input_line = read_input_file(input_file);
        auto time = high_resolution_clock::now();
        // Separazione degli elementi:
        vector<string> split = split_input_element(input_line);
        // Creazione pezzo:
        Piece pezzo(static_cast<uint>(std::stoul(split[0])), static_cast<uint>(std::stoul(split[1])), split[2], std::stof(split[3]));
        uint time_piece = get_total_sec(pezzo.get_min(), pezzo.get_sec());
        seconds diff_time = duration_cast<seconds>(time - start_time) ;
        uint sleep_time = time_piece - diff_time.count();
        std::this_thread::sleep_for(std::chrono::seconds(sleep_time));
        piece_queue_line1.append_piece(pezzo); // aggiunta del pezzo alla coda dei pezzi (conveyor della linea)
        mutex_cout.lock();
        cout << "Rilevato pezzo e posto in coda" << endl;
        mutex_cout.unlock();
        
    }while(!(input_file.eof() || kill_system));

    // Chiusura input file:
    cout << "VISION CHIUSA" << endl;
    input_file.close();
    end_file = true;
}


// Funzione lettura dati di input della linea:
string read_input_file( ifstream &input_file ){
    
    string line;    // linea estratta da input file

    // Controllo di sicurezza:
    if(!input_file.is_open()){
        cerr << "Impossibile aprire il file " << endl;
        exit(EXIT_FAILURE);
    }

    // lettura riga per riga
    getline(input_file, line);
    
    return line;
}

// Funzione che divide i dati del pezzo letto:
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

void halt_system(){
    signal(SIGINT, [](int){
        cout << "    GRACEFUL DEGRADATION" << endl;
        kill_system = true;});
}
