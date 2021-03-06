// store.h

#ifndef STORE_H
#define STORE_H

#include "piece.h"
#include "box.h"

#include <string>
using std::string;

#include <list>
using std::list;

#include <mutex> 
using std::mutex;

class Store{
    public:
        void append_box();
        Box take_box();
    
    private:
        list<Box> box_in_store_;
        mutex mtx_store_;
};

void agv_transport();
#endif

