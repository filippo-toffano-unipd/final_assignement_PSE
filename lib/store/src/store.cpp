#include <string>
using std::string;
#include <list> 
#include <mutex>
using std::mutex;
using std::unique_lock;

#include "box.h"
#include "store.h"
#include "global_variables.h"

void Store::append_box(){
    // Cobot che trasferisce la scatola in magazzino
    unique_lock<mutex> mlock(mtx_store_);
    box_in_store_.push_back(store_box);
    store_box.clear_box();
    mlock.unlock();
}