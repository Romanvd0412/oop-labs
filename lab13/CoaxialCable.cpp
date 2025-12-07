#include "CoaxialCable.h"

CoaxialCable::CoaxialCable() : SignalConductor(), impedance(0) {}

CoaxialCable::CoaxialCable(string n, double l, double p, double imp) 
    : SignalConductor(n, l, p) {
    if (imp <= 0) throw ConductorException("Impedance must be positive!");
    impedance = imp;
}

void CoaxialCable::displayInfo() const {
    cout << "[Coaxial Cable] Name: " << name 
         << ", Length: " << length << "m"
         << ", Price: " << getPrice() << "$"
         << ", Impedance: " << impedance << " Ohms" << endl;
}

void CoaxialCable::saveToFile(ofstream& out) const {
    int type = 1; 
    out.write((char*)&type, sizeof(type));
    
    SignalConductor::saveToFile(out);
    
    out.write((char*)&impedance, sizeof(impedance));
}

void CoaxialCable::loadFromFile(ifstream& in) {
    SignalConductor::loadFromFile(in);
    in.read((char*)&impedance, sizeof(impedance));
}