#include "Stringable.h"

Stringable::Stringable(){
}

Stringable::~Stringable(){
}

ostream& operator<<(ostream &ostream, Stringable* p){
     return ostream<<p->toString();
}
