#include "Diode.h"

Diode::Diode() : forwardVoltage(0), maxReverseCurrent(0), purpose("") {}

Diode::Diode(double volt, double curr, string purp) 
    : forwardVoltage(volt), maxReverseCurrent(curr), purpose(purp) {}

double Diode::getVoltage() const { return forwardVoltage; }
double Diode::getCurrent() const { return maxReverseCurrent; }
string Diode::getPurpose() const { return purpose; }

ostream& operator<<(ostream& os, const Diode& d) {
    os << "Diode [" << d.purpose << ", " << d.forwardVoltage << "V, " << d.maxReverseCurrent << "A]";
    return os;
}