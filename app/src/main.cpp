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
    
    // THREAD:
    thread vision_A {vision_system_thread_main, file_a, start_time};
    thread cobot_A {get_piece_to_box, 1};
    thread agv_storage{agv_transport};
    thread stop_system{halt_system};
    //thread vision_B {vision_systrem_thread_main, file b, start_time};
    vision_A.join();
    cobot_A.join();
    agv_storage.join();
    stop_system.join();
    //vision_B.join();
    
    
}