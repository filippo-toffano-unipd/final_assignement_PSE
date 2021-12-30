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

#include "vision_system.h"
#include "piece.h"

// Global Variable:
queue <Piece> piece_queue_line2;

int main(){
    // Estrazione contenuti da input files
    const string file_a{"../arrivi_linea_a.txt"};
    const string file_b{"../arrivi_linea_b.txt"};

    vision_system_thread_main(file_b);
/*
    thread thread_line1{};
    thread thread_line2{};
*/

}