#include "AverageCalculator.h"

AverageCalculator::AverageCalculator(){
    this->mean = 0;
    this->n = 0;
}

AverageCalculator::~AverageCalculator(){
}

void AverageCalculator::operator() (int element){
    double sum = this->mean * (double)this->n;
    this->mean = (sum + (double)element)/((double)this->n + 1);
    this->n++;
}

double AverageCalculator::getMean(){
    return this->mean;
}


