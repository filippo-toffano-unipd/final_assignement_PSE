#include <string>
using std::string;
#include <list> 
#include <mutex>
using std::mutex;
using std::unique_lock;

#include <iostream>

#include "box.h"
#include "store.h"
#include "global_variables.h"

void Store::append_box(){
    // AGV che trasferisce la scatola in magazzino
    unique_lock<mutex> mlock(mtx_store_);
    box_in_store_.push_back(store_box.clear_box());
    std::cout << "AGV" << std::endl;
    mlock.unlock();
}

void agv_transport(){
    bool agv_run = true;
    while(agv_run){
        storage.append_box();
        if(!(cobotA_run || cobotB_run) && store_box.is_empty())
            agv_run = false;
    }
    std::cout << "AGV CHIUSA" << std::endl;
}