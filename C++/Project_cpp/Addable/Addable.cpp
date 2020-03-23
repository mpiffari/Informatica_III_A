#include "Addable.h"
#include <sstream>
#include <iostream>

using namespace std;

Addable::Addable(){
}

Addable::~Addable(){
	cout<<"Deleted addable"<<endl;
}

Addable* Addable::operator+ (Addable* rhs){
    return this->add(rhs);
}
