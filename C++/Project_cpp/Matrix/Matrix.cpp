#ifndef MATRIX_CPP_
#define MATRIX_CPP_

#include "Matrix.h"


// ====================== INITIALIZER ================================

// Identy matrix 1 x 1 initialization
template<class T> Matrix<T>::Matrix(){
	// Setup of private field
    this->rows = 1;
    this->columns = 1;
    this->elements = new vector< vector<T>* >(this->rows); // Row allocation
    (*this->elements)[0] = new vector<T>(this->columns); // Column allocation
    (*this)(0,0) = 1; // Initialization of an 1 x 1 identity matrix
}

// Identity matrix rows x columns initialization
template<class T> Matrix<T>::Matrix(int rows, int columns){
    this->rows = rows;
    this->columns = columns;
    this->elements= new vector< vector<T>* >(this->rows); // Row allocation
    for(int row=0; row<rows; row++){
        (*this->elements)[row] = new vector<T>(this->columns);
        for(int column=0; column<columns; column++){
            T value = 0;
            if(row==column){
                value = 1; // Initialization of a identity matrix
            }
            (*this)(row, column) = value;
        }
    }
}

// Shallows of a matrix
template<class T> Matrix<T>::Matrix(Matrix* toCopy){
    this->rows = toCopy->rows;
    this->columns = toCopy->columns;
    this->elements = new vector< vector<T>* >(this->rows);
    for(int row=0; row<rows; row++){
        (*this->elements)[row] = new vector<T>(this->columns);
        for(int column=0; column<columns; column++){
            (*this)(row, column) = (*toCopy)(row, column);
        }
    }
}
// ===================================================================

// ======================== DEINITIALIZER ============================

template<class T> Matrix<T>::~Matrix(){
    typename vector< vector<T>* >::iterator rowsIterator = this->elements->begin();
    while (rowsIterator != this->elements->end()){
        delete *rowsIterator;
        rowsIterator++;
    }
    delete this->elements;
}

// ===================================================================



// ====================== GETTER & SETTER ============================

template<class T> void Matrix<T>::set(int row, int column, T value){
    (*(*this->elements)[row])[column] = value;
}

template<class T> T Matrix<T>::get(int row, int column){
    return (*(*this->elements)[row])[column];
}

// ===================================================================

// ====================== ALGEBRIC ================================

template<class T> Matrix<T>* Matrix<T>::add(Addable* number){
	Matrix<T>* matrix = (Matrix<T>*) number;
	if((this->rows != matrix->rows) || ((this->columns != matrix->columns))) {
		cout << "[add] - Matrix dimension mismatch" << endl;
		return this;
	}

    Matrix<T>* result = new Matrix<T>(matrix->rows, matrix->columns);
    for (int row=0; row<this->rows; row++){
        for (int column=0; column<this->columns; column++){
            (*result)(row,column) = (*matrix)(row, column) + (*this)(row, column);
        }
    }
    return result;
}

template<class T> Matrix<T>* Matrix<T>::subtract(Subtractable* number){
	Matrix<T>* matrix = (Matrix<T>*) number;
	if((this->rows != matrix->rows) || ((this->columns != matrix->columns))) {
		cout << "[subtract] - Matrix dimension mismatch" << endl;
		return this;
	}

	// sub = add of negate matrix
    return (Matrix<T>*) (*this+(*matrix * (-1) ));
}

template<class T> Matrix<T>* Matrix<T>::multiply(int k){
    Matrix<T>* result = new Matrix<T>(this);
    typename vector< vector<T>*>::iterator rowsIterator = result->elements->begin();
    while (rowsIterator != result->elements->end()){
        typename vector<T>::iterator columnsIterator = (*rowsIterator)->begin();
        while (columnsIterator != (*rowsIterator)->end()){
            *columnsIterator = *columnsIterator * k;
            columnsIterator++;
        }
        rowsIterator++;
    }
    return result;
}

// ===================================================================

// ====================== STRINGABLE =================================

template<class T> string Matrix<T>::toString(){
    string* result = new string();

    for(int row=0; row<this->rows; row++){
    	result->append("|");
        for(int column=0; column<this->columns; column++){
            stringstream s;
            s<<(*(*this->elements)[row])[column];
            result->append(s.str());
            if(column != (this->columns - 1)) {
            	result->append(" ");
            }
        }
        result->append("|\n");
    }

    return *result;
}
// ===================================================================

// ====================== STL ALGORITHM =================================

template<class T> double Matrix<T>::getMean(){
    AverageCalculator ac;
    typename vector<vector<T>*>::iterator rowsIterator = this->elements->begin();
    while (rowsIterator != this->elements->end()){
        ac = for_each((*rowsIterator)->begin(), (*rowsIterator)->end(), ac);
        rowsIterator++;
    }
    return ac.getMean();
}

template<class T> T Matrix<T>::getMax(){
    list<T>* elements = this->toList();
    T result = *max_element(elements->begin(), elements->end());
    delete elements;
    return result;
}

// ===================================================================

// ================ OPERATORS ========================================

template<class T> T& Matrix<T>::operator() (int row, int column) const{
    return (*(*this->elements)[row])[column];
}

template<class T> T& Matrix<T>::operator() (int row, int column){
    return (*(*this->elements)[row])[column];
}

template<class T> Matrix<T>* Matrix<T>::operator* (int k){
    return this->multiply(k);
}

// ===================================================================


template<class T> list<T>* Matrix<T>::toList(){
    list<T>* result = new list<T>();
    typename vector<vector<T>*>::iterator rowsIterator = this->elements->begin();
    while (rowsIterator != this->elements->end()){
        typename vector<T>::iterator columnsIterator = (*rowsIterator)->begin();
        while (columnsIterator != (*rowsIterator)->end()){
            result->push_back(*columnsIterator);
            columnsIterator++;
        }
        rowsIterator++;
    }
    return result;
}

template<class T> template<class F> Matrix<T>* Matrix<T>::apply(F f){
    Matrix<T>* result = new Matrix<T>(this);
    typename vector<vector<T>*>::iterator rowsIterator = result->elements->begin();
    while (rowsIterator != result->elements->end()){
        typename vector<T>::iterator columnsIterator = (*rowsIterator)->begin();
        while (columnsIterator != (*rowsIterator)->end()){
            *columnsIterator = f(*columnsIterator);
            columnsIterator++;
        }
        rowsIterator++;
    }
    return result;
}

#endif /*MATRIX_CPP_*/
