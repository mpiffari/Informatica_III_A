#include "Subtractable.h"
#include <sstream>
#include <iostream>

using namespace std;

Subtractable::Subtractable(){
}

Subtractable::~Subtractable(){
	cout<<"Deleted subtractable"<<endl;
}

Subtractable* Subtractable::operator-(Subtractable* rhs){
    return this->subtract(rhs);
}
