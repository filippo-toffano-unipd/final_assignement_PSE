// cobot.h

#ifndef COBOT_H
#define COBOT_H

void get_piece_to_box_A(const char ID_cobot, uint conveyor_lenght, uint conveyor_speed, system_clock::time_point start_time);
void get_piece_to_box_B(const char ID_cobot, uint conveyor_lenght, uint conveyor_speed, system_clock::time_point start_time);

uint calc_new_min(uint total_time);
#endif