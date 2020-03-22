#ifndef AVERAGECALCULATOR_H_
#define AVERAGECALCULATOR_H_

#include <iostream>

using namespace std;

// Class used to compute average of generic element; it was thought to be used with STl algoritmh "for each"
class AverageCalculator {
public:
	AverageCalculator(); // Default constructor
	~AverageCalculator(); // Default destructor

	void operator() (int element); // Operator redefinition: update of the mean with a new element
	double getMean(); // Return current mean
private:
    double mean; // Actual mean
    int n; // Number of element used to update last step the mean
};

#endif /* AVERAGECALCULATOR_H_ */
