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

void vision_system_thread_main(string file_path, system_clock::time_point start_time, char ID_line){

    ifstream input_file(file_path); // file da cui estratte i dati di input linea 1

    do{
        string input_line = read_input_file(input_file);
        auto time = high_resolution_clock::now();
        // Separazione degli elementi:
        vector<string> split = split_input_element(input_line);
        // Creazione pezzo:
        Piece pezzo(static_cast<uint>(std::stoul(split[0])), static_cast<uint>(std::stoul(split[1])), split[2], std::stof(split[3]));
        uint time_piece = 1000 * (get_total_sec(pezzo.get_min(), pezzo.get_sec())) / SF;
        milliseconds diff_time = duration_cast<milliseconds>(time - start_time);
        uint sleep_time = time_piece - diff_time.count();
        std::this_thread::sleep_for(std::chrono::milliseconds(sleep_time));
        
        // Smistamento pezzi nelle corrispondenti code (conveyor delle linee):
        switch (ID_line)
        {
            case 'A':
                piece_queue_line1.append_piece(pezzo); // aggiunta del pezzo alla coda dei pezzi della line 1 (conveyor della linea 1)
                break;
            
            case 'B':                
                piece_queue_line2.append_piece(pezzo); // aggiunta del pezzo alla coda dei pezzi della line 1 (conveyor della linea 1)
                break;
                
            default:
                cerr << "ERROR SYSTEM!" << endl;
                exit(EXIT_FAILURE);
                break;
        }
    }while(!(input_file.eof() || kill_system));

    // Chiusura input file:
    mutex_cout.lock();
    cout << "VISION " << ID_line << " CHIUSA" << endl;
    mutex_cout.unlock();
    switch (ID_line)
    {
        case 'A':
            end_file_A = true;
            break;
        
        case 'B':
            end_file_B = true;
            break;

        default:
            cerr << "ERROR SYSTEM";
            exit(EXIT_FAILURE);
            break;
    }
    input_file.close();
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
        mutex_cout.lock();
        cout << "    GRACEFUL DEGRADATION" << endl;
        mutex_cout.unlock();
        kill_system = true;});
}
