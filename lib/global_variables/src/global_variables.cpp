#include "global_variables.h"
#include "box.h"
#include "piece_buffer.h"

uint conveyor_width{10}; //larghezza conveyor: supposta uguale per entrambi i conveyor delle 2 linee
PieceBuffer piece_queue_line1;
PieceBuffer piece_queue_line2;
Box store_box{};
bool end_file_A = false ;
bool end_file_B = false;
uint const box_capacity = 10;
Store storage{};
bool cobotA_run = true;
bool cobotB_run = true;
mutex mutex_cout;
bool kill_system = false;

// Settaggio scale factor per velocizzare l'esecuzione del programma:
uint const SF = 100; 
