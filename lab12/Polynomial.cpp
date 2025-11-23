#include "Polynomial.h"

Polynomial::Polynomial(const vector<double>& coeffs) {
    setCoefficients(coeffs);
    cout << "Polynomial object created." << endl;
}

void Polynomial::displayInfo() const {
    cout << "Polynomial Info: P(x) = ";
    if (coefficients.empty()) {
        cout << "0";
    } else {
        for (int i = degree; i >= 0; --i) {
            cout << coefficients[i] << "x^" << i;
            if (i > 0 && coefficients[i-1] >= 0) cout << " + ";
            else if (i > 0) cout << " "; 
        }
    }
    cout << endl;
}

void Polynomial::setCoefficients(const vector<double>& coeffs) {
    if (!coeffs.empty()) {
        coefficients = coeffs;
        degree = coefficients.size() - 1;
        while (degree > 0 && coefficients[degree] == 0) {
            degree--;
        }
    } else {
        cout << "Error: Coefficients cannot be empty. Setting to {0}." << endl;
        coefficients = {0.0};
        degree = 0;
    }
}

int Polynomial::getDegree() const {
    return degree;
}

bool Polynomial::operator>=(const Polynomial& other) const {
    int maxDeg = max(this->degree, other.degree);

    for (int i = maxDeg; i >= 0; --i) {
        double coeff1 = (i <= this->degree) ? this->coefficients[i] : 0.0;
        double coeff2 = (i <= other.degree) ? other.coefficients[i] : 0.0;

        if (coeff1 != coeff2) {
            return coeff1 > coeff2;
        }
    }
    return true;
}

double Polynomial::operator*=(double argument) const {
    double result = 0.0;
    for (int i = degree; i >= 0; --i) {
        result = result * argument + coefficients[i];
    }
    return result;
}