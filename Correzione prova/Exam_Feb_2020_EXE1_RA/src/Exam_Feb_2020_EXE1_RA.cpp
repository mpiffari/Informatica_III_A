//============================================================================
// Name        : Exam_Feb_2020_EXE1_RA.cpp
// Author      : Michele Piffari
// Version     :
// Copyright   : No copyright
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int K = 0;

int p(int* z) {
	return *z + K;
}

int f(int x, int &y) {
	if(p(&x) >= y) {
		int h = ++y;
		cout << "y " << y << endl;
		return f(x,h);
	} else {
		return x * y;
	}
}

int main() {
	int i = 0;
	cout << f(i, i) << endl;
	cout << "Fine: " << i << endl;

	cout << "No greetings" << endl; // prints No greetings
	return 0;
}
