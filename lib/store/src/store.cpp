#include <string>
using std::string;
#include <list> 
#include <mutex>
using std::mutex;
using std::unique_lock;

#include "box.h"
#include "store.h"

void Store::append_box(const Box box_to_store){
    // Cobot che trasferisce la scatola in magazzino
    unique_lock<mutex> mlock(mtx_store_);
    box_in_store_.push_back(box_to_store);
    mlock.unlock();
}