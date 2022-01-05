#include <iostream>
using std::cout;
using std::cerr;
using std::endl;
using std::stoul;

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

/*  COUT << COLOR:
*   black           \033[30m    \033[40m
*   red             \033[31m    \033[41m
*   green           \033[32m    \033[42m
*   orange          \033[33m    \033[43m
*   blue            \033[34m    \033[44m
*   magenta         \033[35m    \033[45m
*   cyan            \033[36m    \033[46m
*   light grey      \033[37m    \033[47m
*   default         \033[39m    \033[49m
*/

int main(int argc, char* argv[]){

    if( argc < 5){
        cerr << "ERROR PARAMETERS INSERT" << endl;
        exit(EXIT_FAILURE);
    }
    // Locazione dei file di input:
    const string file_a{"../arrivi_linea_a.txt"};
    const string file_b{"../arrivi_linea_b.txt"};

    // Acquisizione start time per simulazione:
    auto start_time = high_resolution_clock::now();

    /*  Identifier vision system line:          *   Identifier cobot system line: 
    *   line A --> A;                           *   line A --> A;
    *   line B --> B;                           *   line B --> B;
    *                                           */
    // THREAD:
    thread vision_A {vision_system_thread_main, file_a, start_time, 'A'};
    thread vision_B {vision_system_thread_main, file_b, start_time, 'B'};
    thread cobot_A {get_piece_to_box, 'A', static_cast<uint>(stoul(argv[1])), static_cast<uint>(stoul(argv[2])), start_time};
    thread cobot_B {get_piece_to_box, 'B', static_cast<uint>(stoul(argv[3])), static_cast<uint>(stoul(argv[1])), start_time};
    thread agv_storage{agv_transport};
    // thread stop_system{halt_system};
    
    // Lancio delle thread:
    vision_A.join();
    cout << "CHIUSA VISION A fine" << endl;
    cobot_A.join();
    cout << "CHIUSA COBOT A fine" << endl;
    vision_B.join();
    cout << "CHIUSA VISION B fine" << endl;
    cobot_B.join();
    cout << "CHIUSA COBOT B fine" << endl;
    agv_storage.join();
    cout << "CHIUSA AGV fine" << endl;
    // stop_system.join();

    return 0;
}