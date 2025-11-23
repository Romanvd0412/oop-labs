#include "PolynomialProcessor.h"
#include <iomanip>

PolynomialProcessor::PolynomialProcessor() {
    cout << "PolynomialProcessor (Friend Class) created." << endl;
}

PolynomialProcessor::~PolynomialProcessor() {
    cout << "PolynomialProcessor (Friend Class) destroyed." << endl;
}

void PolynomialProcessor::processPolynomials(vector<Polynomial*>& polynomials, double argument) const {
    if (polynomials.empty()) {
        cout << "\nNo polynomials to process." << endl;
        return;
    }

    cout << "\n--- Processing Polynomials (Friend Class) ---" << endl;
    cout << "Sorting polynomials by coefficients (descending)..." << endl;

    for (size_t i = 0; i < polynomials.size() - 1; ++i) {
        for (size_t j = 0; j < polynomials.size() - i - 1; ++j) {
            if (*polynomials[j+1] >= *polynomials[j]) {
                swap(polynomials[j], polynomials[j+1]);
            }
        }
    }

    cout << "\nResults after sorting and calculation (x = " << argument << "):" << endl;
    cout << "----------------------------------------------------" << endl;

    for (const auto* poly : polynomials) {
        poly->displayInfo();
        
        double value = (*poly *= argument);
        
        cout << "Value at x=" << argument << ": " << fixed << setprecision(2) << value << endl;
        cout << "----------------------------------------------------" << endl;
    }
}