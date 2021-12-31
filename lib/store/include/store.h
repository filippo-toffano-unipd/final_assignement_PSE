// store.h

#ifndef STORE_H
#define STORE_H

#include "piece.h"
#include "box.h"
#include "global_variables.h"

#include <string>
using std::string;

#include <list>
using std::list;

#include <mutex> 
using std::mutex;

class Store{
    public:
        void append_box(const Box box_to_store);
        Box take_box();
    
    private:
        list<Box> box_in_store_;
        mutex mtx_store_;
};

#endif

