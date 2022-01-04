// cobot.h

#ifndef COBOT_H
#define COBOT_H
#include "box.h"
#include "global_variables.h"

void get_piece_to_box(const char ID_cobot, uint conveyor_lenght, uint conveyor_speed, system_clock::time_point start_time);

// Funzione per il calcolo del tempo di simulazione del cobot:
uint calc_sleep_time(uint conveyor_lenght, uint conveyor_speed);
#endif