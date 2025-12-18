#ifndef DIODE_H
#define DIODE_H

#include <string>
#include <iostream>

using namespace std;

class Diode {
private:
    double forwardVoltage;
    double maxReverseCurrent;
    string purpose;

public:
    Diode();
    Diode(double volt, double curr, string purp);

    double getVoltage() const;
    double getCurrent() const;
    string getPurpose() const;

    friend ostream& operator<<(ostream& os, const Diode& d);
};

#endif