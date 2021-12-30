#include <iostream>
using std::cerr;
using std::endl;

#include <string>
using std::string;

#include <mutex>
using std::mutex;
using std::unique_lock;

#include "piece.h"
#include "box.h"



Box::Box()
    :   box_ID_{0}
{}

Box::Box(uint box_ID)
    :   box_ID_{box_ID}
{
}

void Box::load_piece(const Piece &object_box){
    // Oprazione di mutua esclusione
    unique_lock<mutex> mlock(mtx_box_);
    output_box_.push_back(object_box);
    mlock.unlock();
}
