#ifndef MATRIX_H_
#define MATRIX_H_

#include <sstream>
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>

#include "../Average/AverageCalculator.h"
#include "../Addable/Addable.h"
#include "../Subtractable/Subtractable.h"
#include "../Stringable/Stringable.h"
#include "../Number/Number.h"

using namespace std;

/**
 * Matrix composed by generics elements
 */
template<class T> class Matrix: public Addable, public Subtractable, public Stringable {
	private:
    	int rows;
    	int columns;
    	vector< vector<T>* >* elements; // Elements container

    public:
        // Constructors (overrloaded)
		Matrix(); // Identity matrix 1 x 1
        Matrix(int rows, int columns); // Identity matrix rows x columns
        Matrix(Matrix<T>* toCopy); // Copy a matrix

        virtual ~Matrix(); // Default destructor

        // Setter and getter
        void set(int row, int column, T value); // Change a value in matrix in a specific position
        T get(int row, int column); // Get element in a specific position

        // Algebraic operations
        Matrix<T>* add(Addable* number); // Sum at each element the other value number
        Matrix<T>* subtract(Subtractable* number); // Substract at each element the other value number
        Matrix<T>* multiply(int k); // Multiply each element for a constant k

        virtual string toString(); // String rapresentation of a matrix

        double getMean(); // Mean of matrix element
        T getMax(); // Maximum element between all matrix's elements

        // Operators redefinition
        T& operator() (int row, int column) const;
        T& operator() (int row, int column);
        Matrix<T>* operator* (int k);

        list<T>* toList(); // List with matrix elements
        template<class F> Matrix<T>* apply(F f); // Transform all matrix's elements using a generic function f
};

// l'implementazione della classe è qui per una limitazione del compilatore.
#include "Matrix.cpp"

#endif /*MATRIX_H_*/
