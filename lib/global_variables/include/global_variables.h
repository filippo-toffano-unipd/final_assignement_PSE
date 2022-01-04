// global_variables.h

#ifndef GLOBAL_VARIABLES_H
#define GLOBAL_VARIABLES_H

#include "vision_system.h"
#include "box.h"
#include "piece_buffer.h"
#include "store.h"
#include <mutex>
using std::mutex;

extern uint conveyor_width;
extern PieceBuffer piece_queue_line1;
extern PieceBuffer piece_queue_line2;
extern Box store_box;
extern uint const box_capacity;
extern bool end_file_A;
extern bool end_file_B;
extern Store storage;
extern bool cobotA_run;
extern bool cobotB_run;
extern mutex mutex_cout;
extern bool kill_system;
extern uint const SF; 
#endif