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

/*  COUT << COLOR CODE:     FONT        BACKGROUNG (not use)
*   black                   \033[30m    \033[40m
*   red                     \033[31m    \033[41m
*   green                   \033[32m    \033[42m
*   orange                  \033[33m    \033[43m
*   blue                    \033[34m    \033[44m
*   magenta                 \033[35m    \033[45m
*   cyan                    \033[36m    \033[46m
*   default                 \033[39m    \033[49m
*/

int main(int argc, char* argv[]){

    if( argc < 5){
        cerr << "ERROR PARAMETERS INSERT" << endl;
        exit(EXIT_FAILURE);
    }
    // Locazione dei file di input:
    const string file_a{"../input_file/arrivi_linea_a.txt"};
    const string file_b{"../input_file/arrivi_linea_b.txt"};

    // Acquisizione start time per simulazione:
    auto start_time = high_resolution_clock::now();

    /*  Identifier vision system line:          *   Identifier cobot system line: 
    *   line A --> A;                           *   line A --> A;
    *   line B --> B;                           *   line B --> B;
    *                                           */
    // THREAD:
    thread vision_A {vision_system_thread_main, file_a, start_time, 'A'};
    thread vision_B {vision_system_thread_main, file_b, start_time, 'B'};
    thread cobot_A {get_piece_to_box_A, 'A', static_cast<uint>(stoul(argv[1])), static_cast<uint>(stoul(argv[2])), start_time};
    thread cobot_B {get_piece_to_box_B, 'B', static_cast<uint>(stoul(argv[3])), static_cast<uint>(stoul(argv[4])), start_time};
    thread agv_storage{agv_transport};
    thread stop_system{halt_system};
    
    // Lancio delle thread:
    vision_A.join();
    mutex_cout.lock();
    cout << "\033[32m" << "VISION A CORRECT CLOSE" << "\033[39m" << endl;
    mutex_cout.unlock();

    vision_B.join();
    mutex_cout.lock();
    cout << "\033[32m" << "VISION B CORRECT CLOSE" << "\033[39m" << endl;
    mutex_cout.unlock();

    cobot_A.join();
    mutex_cout.lock();
    cout << "\033[32m" << "COBOT SYSTEM A CORRECT CLOSE" << "\033[39m" << endl;
    mutex_cout.unlock();

    cobot_B.join();
    mutex_cout.lock();
    cout << "\033[32m" << "COBOT SYSTEM B CORRECT CLOSE" << "\033[39m" << endl;
    mutex_cout.unlock();

    agv_storage.join();
    mutex_cout.lock();
    cout << "\033[32m" << "AGV SYSTEM CORRECT CLOSE" << "\033[39m" << endl;
    mutex_cout.unlock();

    stop_system.join();

    exit(EXIT_SUCCESS);
}