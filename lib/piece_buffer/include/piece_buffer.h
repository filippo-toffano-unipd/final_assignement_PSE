#ifndef PIECE_BUFFER_H
#define PIECE_BUFFER_H

#include <vector>
using std::vector;

#include <string>
using std::string;

#include <queue>
using std::queue;

#include <mutex>
using std::mutex;

#include <condition_variable>
using std::condition_variable;

#include "piece.h"

class PieceBuffer{

    public:
        void append_piece(const Piece &piece);
        Piece take_piece();

    private:
        queue<Piece> output_queue_;
        mutex mtx_;
        condition_variable not_empty_;

};

#endif