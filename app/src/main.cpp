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

#include <chrono>
using namespace std::chrono;

#include "piece_buffer.h"
#include "vision_system.h"
#include "piece.h"
#include "cobot.h"
#include "store.h"

int main(int argc, char* argv[]){
    // Locazione dei file di input:
    const string file_a{"../arrivi_linea_a.txt"};
    const string file_b{"../arrivi_linea_b.txt"};

    // Acquisizione start time per simulazione:
    auto start_time = high_resolution_clock::now();
    /*  Identifier vision system line:  
    *   line A --> A;
    *   line B --> B;
    */
    // THREAD:
    thread vision_A {vision_system_thread_main, file_a, start_time, 'A'};
    thread vision_B {vision_system_thread_main, file_b, start_time, 'B'};
    thread cobot_A {get_piece_to_box, 1};
    // thread cobot_B {get_piece_to_box, 2};
    thread agv_storage{agv_transport};
    thread stop_system{halt_system};
    
    // Lancio delle thread:
    vision_A.join();
    vision_B.join();
    cobot_A.join();
    // cobot_B.join();
    agv_storage.join();
    stop_system.join();
}