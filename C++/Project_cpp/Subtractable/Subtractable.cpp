#include "Subtractable.h"

Subtractable::Subtractable(){
}

Subtractable::~Subtractable(){
}

Subtractable* Subtractable::operator-(Subtractable* rhs){
    return this->subtract(rhs);
}
