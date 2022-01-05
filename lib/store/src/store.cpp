#include <string>
using std::string;

#include <list> 

#include <mutex>
using std::mutex;
using std::unique_lock;

#include <iostream>
using std::cout;
using std::endl;

#include "box.h"
#include "store.h"
#include "global_variables.h"

void Store::append_box(){
    // AGV che trasferisce la scatola in magazzino
    unique_lock<mutex> mlock(mtx_store_);
    box_in_store_.push_back(store_box.clear_box());
    cout << "\033[36m" << "AGV transport: collect BOX n."<< store_box.box_ID() << " --> bring to store" << "\033[39m" << endl;
    mlock.unlock();
}

void agv_transport(){
    bool agv_run = true;
    while(agv_run){
        storage.append_box();
        if(!(cobotA_run || cobotB_run) && store_box.is_empty())
            agv_run = false;
    }
}