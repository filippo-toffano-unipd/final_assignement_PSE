#include <iostream>
using std::cout;
using std::cerr;
using std::endl;

#include <chrono>
using namespace std::chrono;

#include <thread>

#include "piece.h"
#include "box.h"
#include "cobot.h"
#include "vision_system.h"
#include "global_variables.h"

void get_piece_to_box_A(const char ID_cobot, uint conveyor_lenght, uint conveyor_speed, system_clock::time_point start_time)
{ 
    uint add_time = conveyor_lenght / conveyor_speed;

    while(cobotA_run){
        Piece piece_to_box;
        uint sleep_time{0};
        // Presa pezzo dal conveyor:
        piece_to_box = piece_queue_line1.take_piece();

        // Simulation:
        uint time_piece = get_total_sec(piece_to_box.get_min(), piece_to_box.get_sec()) + add_time;
        auto istant_time = high_resolution_clock::now();
        milliseconds gap_time = duration_cast<milliseconds>(istant_time - start_time);
        sleep_time = 1000 * time_piece / SF - gap_time.count();
        std::this_thread::sleep_for(std::chrono::milliseconds(sleep_time));

        // Posizionamento del pezzo nella scatola:
        mutex_cout.lock();
        cout << "\033[1;35m" << "Cobot linea di trasporto " << ID_cobot << ": recuperato componente "<< piece_to_box.get_piece_type() << 
        " al tempo " << calc_new_min(time_piece) << ":" << time_piece % 60 << " in posizione " <<
        piece_to_box.get_pos() << "\033[0;39m" << endl;
        mutex_cout.unlock();

        // Spostamento nella scatola del pezzo afferato
        store_box.load_piece(piece_to_box);
        mutex_cout.lock();
        cout << piece_to_box.get_piece_type() << "\t inserito nella BOX" << endl;
        mutex_cout.unlock();

        // SPegnimento cobot:
        if(piece_queue_line1.is_empty() && end_file_A){
            mutex_cout.lock();
            cout << "\033[31m" << "COBOT "<< ID_cobot << " go to OFF" << "\033[39m" << endl;
            mutex_cout.unlock();
            cobotA_run = false;
        }
    }

    // Riporre in magazzino l'ultima scatola finiti i pezzi sulconveyor:
    store_box.last_piece();
}

void get_piece_to_box_B(const char ID_cobot, uint conveyor_lenght, uint conveyor_speed, system_clock::time_point start_time)
{ 
    uint add_time = conveyor_lenght / conveyor_speed;
    while(cobotB_run){
        Piece piece_to_box;
        uint sleep_time{0};
        // Presa pezzo dal conveyor:
        piece_to_box = piece_queue_line2.take_piece();

        // Simulation:
        uint time_piece = get_total_sec(piece_to_box.get_min(), piece_to_box.get_sec()) + add_time;
        auto istant_time = high_resolution_clock::now();
        milliseconds gap_time = duration_cast<milliseconds>(istant_time - start_time);
        sleep_time = 1000 * time_piece / SF - gap_time.count();
        std::this_thread::sleep_for(std::chrono::milliseconds(sleep_time));

        // Posizionamento del pezzo nella scatola:       
        mutex_cout.lock();
        cout << "\033[1;34m" << "Cobot linea di trasporto " << ID_cobot << ": recuperato componente "<< piece_to_box.get_piece_type() << 
        " al tempo " << calc_new_min(time_piece) << ":" << time_piece % 60 << " in posizione " <<
        piece_to_box.get_pos() << "\033[0;39m"  << endl;
        mutex_cout.unlock();
    
        // spostamento nella scatola del pezzo afferato
        store_box.load_piece(piece_to_box);
        mutex_cout.lock();
        cout << piece_to_box.get_piece_type() << "\t inserito nella BOX" << endl;
        mutex_cout.unlock();

        // Spegnimento cobot:
        if(piece_queue_line2.is_empty() && end_file_B){
            mutex_cout.lock();
            cout << "\033[31m" << "COBOT "<< ID_cobot << " go to OFF" << "\033[39m" << endl;
            mutex_cout.unlock();
            cobotB_run = false;
        }
    }

    // Riporre in magazzino l'ultima scatola finiti i pezzi sulconveyor:
    store_box.last_piece();
}

// Funzione per l'aggiornamento di presa dei pezzi:
uint calc_new_min(uint total_time){
    uint new_min = total_time / 60;
    return new_min; 
}

