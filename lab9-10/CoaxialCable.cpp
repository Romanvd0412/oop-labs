#include "CoaxialCable.h"

CoaxialCable::CoaxialCable(const string& man, double len, double maxFreq, double imp, const string& shield)
    : SignalConductor(man, len, maxFreq) {
    setImpedance(imp);
    setShieldType(shield);
    cout << "CoaxialCable object created." << endl;
}

void CoaxialCable::displayInfo() const {
    cout << "\nCoaxial Cable (Derived Class):" << endl;
    SignalConductor::displayInfo();
    cout << "Impedance: " << impedance << " Ohms" << endl;
    cout << "Shield Type: " << shieldType << endl;
}

void CoaxialCable::setImpedance(double imp) {
    if (imp > 0) {
        impedance = imp;
    } else {
        cout << "Error: Invalid impedance. Setting to 50 Ohms." << endl;
        impedance = 50.0;
    }
}

void CoaxialCable::setShieldType(const string& shield) {
    if (!shield.empty()) {
        shieldType = shield;
    } else {
        cout << "Error: Shield type cannot be empty." << endl;
        shieldType = "Unknown";
    }
}