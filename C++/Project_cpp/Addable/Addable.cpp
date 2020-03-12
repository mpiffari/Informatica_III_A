#include "Addable.h"

Addable::Addable(){
}

Addable::~Addable(){
}

Addable* Addable::operator+ (Addable* rhs){
    return this->add(rhs);
}
