/*#include <iostream>
using std::cerr;
using std::endl;

#include <string>
using std::string;

#include "piece.h"
#include "box.h"

Box::Box()
    :   box_ID_{0},
        piece_{piece{}},
        capacity_{0}
{}

Box::Box(uint box_ID, Piece piece_info, uint capacity)
    :   box_ID_{box_ID},
        piece_{piece},
        capacity_{capacity}
{
    if(box_ID < 0){
        cerr << "ERROR BOX" << endl;
        exit(EXIT_FAILURE);
    }

    if(capacity > 10){
        cerr << "ERROR CONTENT BOX" << endl;
        exit(EXIT_FAILURE);
    }
}
*/