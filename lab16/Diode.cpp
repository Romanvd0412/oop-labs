#include "Diode.h"

Diode::Diode() : forwardVoltage(0), maxReverseCurrent(0), purpose("Unknown") {}

Diode::Diode(double volt, double curr, string purp) 
    : forwardVoltage(volt), maxReverseCurrent(curr), purpose(purp) {}

Diode::~Diode() {
    cout << "Diode destroyed: " << purpose << endl; 
}

ostream& operator<<(ostream& os, const Diode& d) {
    os << "Diode [Purpose: " << d.purpose 
       << ", Voltage: " << d.forwardVoltage 
       << "V, Max Current: " << d.maxReverseCurrent << "A]";
    return os;
}

bool Diode::operator==(const Diode& other) const {
    return (forwardVoltage == other.forwardVoltage) &&
           (maxReverseCurrent == other.maxReverseCurrent) &&
           (purpose == other.purpose);
}