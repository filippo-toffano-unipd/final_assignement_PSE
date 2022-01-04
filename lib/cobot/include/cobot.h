// cobot.h

#ifndef COBOT_H
#define COBOT_H
#include "box.h"
#include "global_variables.h"

void get_piece_to_box(const char ID_cobot, float conveyor_lenght, float conveyor_speed, system_clock::time_point start_time);

// Funzione per il calcolo del tempo di simulazione del cobot:
float calc_sleep_time(float conveyor_lenght, float conveyor_speed);
#endif