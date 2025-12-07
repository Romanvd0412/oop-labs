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

    friend ostream& operator<<(ostream& os, const Diode& d);
    bool operator==(const Diode& other) const;
};

#endif