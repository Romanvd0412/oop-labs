#include "OpticalFiber.h"

OpticalFiber::OpticalFiber(const string& man, double len, double maxFreq, const string& m, double diameter)
    : SignalConductor(man, len, maxFreq) {
    setMode(m);
    setCoreDiameter(diameter);
    cout << "OpticalFiber object created." << endl;
}

void OpticalFiber::displayInfo() const {
    cout << "\nOptical Fiber (Derived Class)" << endl;
    SignalConductor::displayInfo();
    cout << "Mode: " << mode << endl;
    cout << "Core Diameter: " << coreDiameter << " um" << endl;
}

void OpticalFiber::setMode(const string& m) {
    if (!m.empty()) {
        mode = m;
    } else {
        mode = "Unknown";
    }
}

void OpticalFiber::setCoreDiameter(double diameter) {
    if (diameter > 0) {
        coreDiameter = diameter;
    } else {
        cout << "Error: Invalid core diameter. Setting to 9um." << endl;
        coreDiameter = 9.0;
    }
}