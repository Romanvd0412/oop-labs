#include <iostream>
#include <vector>
#include "Polynomial.h"
#include "PolynomialProcessor.h"

using namespace std;

int main() {
    vector<Polynomial*> polynomials;
    double argumentValue;

    cout << "Creating objects..." << endl;

    polynomials.push_back(new Polynomial({1.0, 2.0, 3.0}));
    polynomials.push_back(new Polynomial({1.0, 1.0, 5.0}));
    polynomials.push_back(new Polynomial({5.0, 2.0}));
    polynomials.push_back(new Polynomial({0.0, 2.0, 3.0}));

    cout << "\nOriginal List:" << endl;
    for (const auto* poly : polynomials) {
        poly->displayInfo();
    }

    cout << "\nEnter argument value for calculation (x): ";
    cin >> argumentValue;

    cout << "\nProcessing data with Friend Class..." << endl;
    PolynomialProcessor processor;
    processor.processPolynomials(polynomials, argumentValue);

    cout << "\nCleaning up memory..." << endl;
    for (auto* poly : polynomials) {
        delete poly;
    }
    polynomials.clear();

    return 0;
}