#include <iostream>
using std::cout;
using std::cerr;
using std::endl;

#include <chrono>
using namespace std::chrono;

#include "piece.h"
#include "box.h"
#include "cobot.h"
#include "vision_system.h"
#include "global_variables.h"

void get_piece_to_box(const char ID_cobot, float conveyor_lenght, float conveyor_speed, system_clock::time_point start_time){
    float sleep_time_cobot;
    
    while(cobotA_run || cobotB_run){
        Piece piece_to_box;

            switch(ID_cobot){
                case 'A':
                    piece_to_box = piece_queue_line1.take_piece();
                    cout << endl << conveyor_lenght << endl;
                    cout << conveyor_speed << endl;
                    mutex_cout.lock();
                    cout << "Cobot linea di trasporto " << ID_cobot << ": recuperato componente "<< piece_to_box.get_piece_type() << 
                    " al tempo " << piece_to_box.get_min() << "." << piece_to_box.get_sec() << " in posizione " <<
                    piece_to_box.get_pos() << endl;
                    mutex_cout.unlock();
                    break;

                case 'B':
                    piece_to_box = piece_queue_line2.take_piece();
                    cout << endl << conveyor_lenght << endl;
                    cout << conveyor_speed << endl;
                    mutex_cout.lock();
                    cout << "Cobot linea di trasporto " << ID_cobot << ": recuperato componente "<< piece_to_box.get_piece_type() << 
                    " al tempo " << piece_to_box.get_min() << "." << piece_to_box.get_sec() << " in posizione " <<
                    piece_to_box.get_pos() << endl;
                    mutex_cout.unlock();
                    break;

                default:
                    cerr << "ERROR SYSTEM!" << endl;
                    exit(EXIT_FAILURE);
                    break;
            }
      
        // spostamento nella scatola del pezzo afferato
        store_box.load_piece(piece_to_box);

        if(piece_queue_line1.is_empty() && end_file){
            cobotA_run = false;
            cout << "cobot OFF" << endl;
        }
    }
    store_box.last_piece();
    cout << "COBOT CHIUSA" << endl;
}
/*
float calc_sleep_time(float conveyor_lenght, float conveyor_speed){
    float tmp_time = conveyor_lenght / conveyor_speed;
}
*/