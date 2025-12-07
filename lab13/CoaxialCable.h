#ifndef COAXIAL_CABLE_H
#define COAXIAL_CABLE_H

#include "SignalConductor.h"

class CoaxialCable : public SignalConductor {
private:
    double impedance;

public:
    CoaxialCable();
    CoaxialCable(string n, double l, double p, double imp);

    void displayInfo() const override;
    void saveToFile(ofstream& out) const override;
    void loadFromFile(ifstream& in) override;
    string getType() const override { return "CoaxialCable"; }
};

#endif