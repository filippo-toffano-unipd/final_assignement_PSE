#include <iostream>
using std::cerr;
using std::endl;

#include <string>
using std::string;

#include <mutex>
using std::mutex;
using std::unique_lock;
#include <condition_variable>

#include "piece.h"
#include "box.h"
#include "global_variables.h"

Box::Box()
    :   box_ID_{0}
{}

Box::Box(uint box_ID)
    :   box_ID_{box_ID}
{}

Box::Box(const Box &box_to_copy)
    :   box_ID_{box_to_copy.box_ID_},
        output_box_{box_to_copy.output_box_}
{}

void Box::load_piece(const Piece &object_box){
    // Oprazione di mutua esclusione
    unique_lock<mutex> mlock(mtx_box_);
    while(output_box_.size() >= box_capacity){
        box_is_full_.notify_one();
        box_not_full_.wait(mlock);
    }
    output_box_.push_back(object_box);
    mlock.unlock(); 
}

// Pulizia della scatola dopo essere stata messa in magazzino:
Box Box::clear_box(){ 
    unique_lock<mutex> mlock(mtx_box_);
    while(output_box_.size() < box_capacity && (cobotA_run || cobotB_run)){
        box_is_full_.wait(mlock);
    }
    Box tmp_box{*this};
    box_ID_ ++;
    output_box_.clear();
    box_not_full_.notify_one();
    return tmp_box;
}

bool Box::is_empty(){
    return output_box_.empty();
}
