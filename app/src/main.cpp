#include <iostream>
using std::cin;
using std::cerr;
using std::cout;
using std::endl;

#include <fstream> 
using std::ifstream;

#include <string>
using std::string;

#include <vector>
using std::vector;

#include <thread>
using std::thread;

#include <queue>
using std::queue;

#include "piece_buffer.h"
#include "vision_system.h"
#include "piece.h"

// Global Variable:
PieceBuffer piece_queue_line1;

int main(){
    // Estrazione contenuti da input files
    const string file_a{"../arrivi_linea_a.txt"};
    const string file_b{"../arrivi_linea_b.txt"};


    vision_system_thread_main(file_b);
    cout << endl;
    for(int i = 0; i < 15; i++){
        //cout << "- " << piece_queue_line1.take_piece().get_min();
        //cout << " " << piece_queue_line1.take_piece().get_sec();
        //cout << " " << piece_queue_line1.take_piece().get_piece_type();
        cout << " " << piece_queue_line1.take_piece().get_pos() << endl;
    }

/*
    thread thread_line1{};
    thread thread_line2{};
*/

}