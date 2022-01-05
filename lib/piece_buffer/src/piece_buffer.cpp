#include <string>
using std::string;

#include <queue>
using std::queue;

#include <mutex>
using std::mutex;
using std::unique_lock;

#include <condition_variable>
using std::condition_variable;
#include <iostream>
#include "global_variables.h"
#include "piece_buffer.h"
#include "piece.h"

void PieceBuffer::append_piece(const Piece &object){
    // Oprazione di mutua esclusione
    unique_lock<mutex> mlock(mtx_);
    output_queue_.push(object);
    mlock.unlock();
    not_empty_.notify_one();
}

Piece PieceBuffer::take_piece(){

    unique_lock<mutex> mlock(mtx_);
    while(output_queue_.empty()){
        not_empty_.wait(mlock);
    }
    
    Piece output = output_queue_.front();   // estraggo il primo pezzo dalla coda
    output_queue_.pop();                    // tolgo il primo pezzo dalla coda dopo averlo estratto
    return output;                          // ritorno il pezzo estratto
}

