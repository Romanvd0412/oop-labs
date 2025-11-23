#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

class PolynomialProcessor;

class Polynomial {
protected:
    vector<double> coefficients;
    int degree;

public:
    Polynomial(const vector<double>& coeffs);
    virtual ~Polynomial() {}

    virtual void displayInfo() const;

    void setCoefficients(const vector<double>& coeffs);
    int getDegree() const;

    bool operator>=(const Polynomial& other) const;
    double operator*=(double argument) const;

    friend class PolynomialProcessor;
};

#endif