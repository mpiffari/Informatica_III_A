#ifndef ADDABLE_H_
#define ADDABLE_H_

#include "../Number/Number.h"


// Object that can be added, using Number interface; it's requested the implementation of method Add.
class Addable: virtual public Number {
public:
	Addable(); // Default constructor
	virtual ~Addable(); // Default destructor

	// Pure virtual method that need to be implemented by all object that conform to Addable interface
	virtual Addable* add(Addable* n) = 0;
	virtual Addable* operator+ (Addable* rhs); // Plus operator redefinition
};

#endif /*ADDABLE_H_*/
