// piece.h

#ifndef PIECE_H
#define PIECE_H

#include <string>
using std::string;

class Piece{
    public:
        Piece();    // default constructor
        Piece(uint min, uint sec, string piece_type, float pos); // class constructor
        uint get_min() const { return min_; }
        uint get_sec() const { return sec_; }
        string get_piece_type() const { return piece_type_; }
        float get_pos() const { return pos_; }
                
    private:
        uint min_;
        uint sec_;
        string piece_type_;
        float pos_;
};

bool is_pos(uint position);
uint get_total_sec(uint min, uint sec);

#endif
