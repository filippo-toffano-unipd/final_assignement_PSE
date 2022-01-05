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

void get_piece_to_box(const char ID_cobot, uint conveyor_lenght, uint conveyor_speed, system_clock::time_point start_time)
{
    
    do{
        Piece piece_to_box;
        uint sleep_time{0};
            // Presa pezzo dal conveyor:
            if (ID_cobot == 'A')
                    piece_to_box = piece_queue_line1.take_piece();
            else if(ID_cobot == 'B')
                    piece_to_box = piece_queue_line2.take_piece();

            // Simulation:
            uint time_piece = 1000 * (get_total_sec(piece_to_box.get_min(), piece_to_box.get_sec()) + (conveyor_lenght / conveyor_speed)) / SF;
            auto istant_time = high_resolution_clock::now();
            milliseconds gap_time = duration_cast<milliseconds>(istant_time - start_time);
                    
                if(time_piece >= gap_time.count()){
                    sleep_time = time_piece - gap_time.count();
                }
                else{
                    cerr << "ERROR SYNC TIME" << endl;
                }
                
            std::this_thread::sleep_for(std::chrono::milliseconds(sleep_time));

            // Posizionamento del pezzo nella scatola:
            switch(ID_cobot){
                case 'A':
                    mutex_cout.lock();
                    cout << "Cobot linea di trasporto " << ID_cobot << ": recuperato componente "<< piece_to_box.get_piece_type() << 
                    " al tempo " << piece_to_box.get_min() << ":" << piece_to_box.get_sec() << " in posizione " <<
                    piece_to_box.get_pos() << endl;
                    mutex_cout.unlock();
                    
                    if(piece_queue_line1.is_empty() && end_file_A && cobotA_run){
                        mutex_cout.lock();
                        cobotA_run = false;
                        cout << "COBOT "<< ID_cobot << " go to OFF" << endl;
                        mutex_cout.unlock();
                    }
                    break;

                case 'B':
                    mutex_cout.lock();
                    cout << "Cobot linea di trasporto " << ID_cobot << ": recuperato componente "<< piece_to_box.get_piece_type() << 
                    " al tempo " << piece_to_box.get_min() << ":" << piece_to_box.get_sec() << " in posizione " <<
                    piece_to_box.get_pos() << endl;
                    mutex_cout.unlock();

                    if(piece_queue_line2.is_empty() && end_file_B && cobotB_run){
                        cobotB_run = false;
                        mutex_cout.lock();
                        cout << "COBOT "<< ID_cobot << " go to OFF" << endl;
                        mutex_cout.unlock();
                    }
                    break;

                default:
                    cerr << "ERROR SYSTEM!" << endl;
                    exit(EXIT_FAILURE);
                    break;
            }
      
        // spostamento nella scatola del pezzo afferato
        store_box.load_piece(piece_to_box);
        mutex_cout.lock();
        cout << piece_to_box.get_piece_type() << "\t inserito nella BOX" << endl;
        mutex_cout.unlock();

    }while(cobotA_run || cobotB_run);

    store_box.last_piece();
    cout << "COBOT CHIUSA" << endl;
}