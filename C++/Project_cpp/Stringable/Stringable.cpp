#include <iostream>
#include <ctime>
#include <chrono>
#include "Stringable.h"

Stringable::Stringable(){
}

Stringable::~Stringable(){
}

ostream& operator<<(ostream &ostream, Stringable* p){
    auto now = std::chrono::system_clock::now();
    std::time_t now_time = std::chrono::system_clock::to_time_t(now);

     return ostream<<"\n[Matrix library log] - "<<ctime(&now_time)<<p->toString();
}
