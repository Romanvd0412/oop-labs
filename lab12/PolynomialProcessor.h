#ifndef POLYNOMIAL_PROCESSOR_H
#define POLYNOMIAL_PROCESSOR_H

#include "Polynomial.h"
#include <vector>
#include <iostream>

using namespace std;

class PolynomialProcessor {
public:
    PolynomialProcessor();
    ~PolynomialProcessor();

    void processPolynomials(vector<Polynomial*>& polynomials, double argument) const;
};

#endif