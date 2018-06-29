#include <iostream>

#include "lock_ptr.hpp"


template <class P> void println(P p) {
    std::cout << *p << std::endl;
}


int main() {

    int i = 0;
    std::shared_timed_mutex mtx;  // or shared_mutex with C++17


    // unique_lock_ptr
    {
        unique_lock_ptr<int> ulp(&i, mtx);
        *ulp = 1;

        // unique_lock_ptr<int> ulp2(&i, mtx);  // deadlock
        // shared_lock_ptr<int> slp(&i, mtx);  // deadlock
    }
    {
        println(unique_lock_ptr<int>(&i, mtx));  // movable

        // unique_lock_ptr<int> ulp(&i, mtx);
        // unique_lock_ptr<int> ulp2 = ulp;  // non-copyable
    }


    // shared_lock_ptr
    {
        shared_lock_ptr<int> slp(&i, mtx);
        int j = *slp;
        // *i = 2;  // forbidden

        shared_lock_ptr<int> slp2(&i, mtx);  // OK
        // unique_lock_ptr<int> ulp(&i, mtx);  // deadlock

        println(shared_lock_ptr<int>(&i, mtx));  // movable

        // shared_lock_ptr<int> slp3 = slp;  // non-copyable
    }


    return 0;
}
