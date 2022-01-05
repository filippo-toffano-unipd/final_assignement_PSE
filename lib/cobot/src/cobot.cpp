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
    while(cobotA_run){
        Piece piece_to_box;
        uint sleep_time{0};
            // Presa pezzo dal conveyor:
            piece_to_box = piece_queue_line1.take_piece();

            // Simulation:
            uint time_piece = 1000 * (get_total_sec(piece_to_box.get_min(), piece_to_box.get_sec()) + (conveyor_lenght / conveyor_speed)) / SF;
            auto istant_time = high_resolution_clock::now();
            milliseconds gap_time = duration_cast<milliseconds>(istant_time - start_time);
            sleep_time = time_piece - gap_time.count();
            std::this_thread::sleep_for(std::chrono::milliseconds(sleep_time));

            // Posizionamento del pezzo nella scatola:
        
            mutex_cout.lock();
            cout << "Cobot linea di trasporto " << ID_cobot << ": recuperato componente "<< piece_to_box.get_piece_type() << 
            " al tempo " << piece_to_box.get_min() << ":" << piece_to_box.get_sec() << " in posizione " <<
            piece_to_box.get_pos() << endl;
            mutex_cout.unlock();
                    
      
        // spostamento nella scatola del pezzo afferato
        store_box.load_piece(piece_to_box);
        mutex_cout.lock();
        cout << piece_to_box.get_piece_type() << "\t inserito nella BOX" << endl;
        mutex_cout.unlock();

        if(piece_queue_line1.is_empty() && end_file_A){
            mutex_cout.lock();
            cout << "COBOT "<< ID_cobot << " go to OFF" << endl;
            mutex_cout.unlock();
            cobotA_run = false;
        }

    }
        store_box.last_piece();

    cout << "COBOT A CHIUSA" << endl;
}

void get_piece_to_box_B(const char ID_cobot, uint conveyor_lenght, uint conveyor_speed, system_clock::time_point start_time)
{ 
    while(cobotB_run){
        Piece piece_to_box;
        uint sleep_time{0};
            // Presa pezzo dal conveyor:
            piece_to_box = piece_queue_line2.take_piece();

            // Simulation:
            uint time_piece = 1000 * (get_total_sec(piece_to_box.get_min(), piece_to_box.get_sec()) + (conveyor_lenght / conveyor_speed)) / SF;
            auto istant_time = high_resolution_clock::now();
            milliseconds gap_time = duration_cast<milliseconds>(istant_time - start_time);
            sleep_time = time_piece - gap_time.count();
            std::this_thread::sleep_for(std::chrono::milliseconds(sleep_time));

            // Posizionamento del pezzo nella scatola:
        
                    mutex_cout.lock();
                    cout << "Cobot linea di trasporto " << ID_cobot << ": recuperato componente "<< piece_to_box.get_piece_type() << 
                    " al tempo " << piece_to_box.get_min() << ":" << piece_to_box.get_sec() << " in posizione " <<
                    piece_to_box.get_pos() << endl;
                    mutex_cout.unlock();
                    
      
        // spostamento nella scatola del pezzo afferato
        store_box.load_piece(piece_to_box);
        mutex_cout.lock();
        cout << piece_to_box.get_piece_type() << "\t inserito nella BOX" << endl;
        mutex_cout.unlock();

        if(piece_queue_line2.is_empty() && end_file_B){
            mutex_cout.lock();
            cout << "COBOT "<< ID_cobot << " go to OFF" << endl;
            mutex_cout.unlock();
            cobotB_run = false;
        }
    }

    store_box.last_piece();
    cout << "COBOT A CHIUSA" << endl;
}
