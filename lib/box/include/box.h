// box.h

#ifndef BOX_H
#define BOX_H

#include <vector>
using std::vector;

#include <mutex>
using std::mutex;

#include <condition_variable>
using std::condition_variable;

#include "piece.h"

class Box{
    public:
        Box();  // default constructor 
        Box(uint box_ID); // class constructor
        Box(const Box &box_to_copy);
        uint box_ID() const { return box_ID_; }
        void load_piece(const Piece &object_box);
        bool is_empty();
        void last_piece(){ box_is_full_.notify_one(); }
        Box clear_box();

    private:
        uint box_ID_;       // box identifier
        vector<Piece> output_box_;
        mutex mtx_box_;
        condition_variable box_not_full_;
        condition_variable box_is_full_;
};

#endif

