#ifndef STRINGABLE_H_
#define STRINGABLE_H_

#include <iostream>
#include <string>

using namespace std;

class Stringable{
public:
    Stringable(); // Default constructor
	virtual ~Stringable(); // Default destructor

    virtual string toString()=0; // String representation of this object

    /*
     * @brief provides an easy way to print an object to an output stream
     * @param out the output stream to write to
     * @param s the stringable object to be sent to the output stream
     */
    friend ostream& operator<<(ostream &ostream, Stringable* s);
};

#endif /*STRINGABLE_H_*/
