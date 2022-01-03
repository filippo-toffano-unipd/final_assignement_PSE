#include <iostream>
using std::cerr;
using std::endl;

#include <string>
using std::string;

#include "piece.h"
#include "global_variables.h"

Piece::Piece()
    :   min_{00},
        sec_{00},
        piece_type_{"?"},
        pos_{0.0}
{}

Piece::Piece(uint min, uint sec, string piece_type, float pos)
    :   min_{min},
        sec_{sec},
        piece_type_{piece_type},
        pos_{pos}
{
    if(!is_pos(pos)){ 
            cerr << "La posizione insierita non è valida." << endl << "Possibile guasto del sistema di visione!" << endl;
            exit(EXIT_FAILURE);
        }
}

bool is_pos(uint position){
    if(position <= conveyor_width)
        return true;
    else
        return false;
}

uint get_total_sec(uint min, uint sec){
    uint total_sec = (min * 60) + sec;
    return total_sec;
}