#ifndef SUBTRACTABLE_H_
#define SUBTRACTABLE_H_

#include "../Number/Number.h"

// Object that can be substracted, using Number interface; it's requested the implementation of method Add.
class Subtractable: virtual public Number {
public:
	Subtractable(); // Default constructor
	virtual ~Subtractable(); // Default destructor

	// Pure virtual method that need to be implemented by all object that conform to Substractable interface
	virtual Subtractable* subtract(Subtractable* n) = 0;
	virtual Subtractable* operator- (Subtractable* rhs); // Minus operator redefinition
};

#endif /* SUBTRACTABLE_H_ */
