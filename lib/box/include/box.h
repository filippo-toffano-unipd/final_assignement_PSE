// box.h

#ifndef BOX_H
#define BOX_H

#include <vector>
using std::vector;

#include <mutex>
using std::mutex;

#include "piece.h"

uint const box_capacity = 10;

class Box{
    public:
        Box();  // default constructor 
        Box(uint box_ID); // class constructor
        Box(const Box &box_to_copy);
        uint box_ID() const { return box_ID_; }
        void load_piece(const Piece &object_box);

    private:
        uint box_ID_;       // box identifier
        vector<Piece> output_box_;
        mutex mtx_box_;
};

#endif

