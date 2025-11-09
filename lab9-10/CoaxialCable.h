#ifndef COAXIAL_CABLE_H
#define COAXIAL_CABLE_H

#include "SignalConductor.h"

class CoaxialCable : public SignalConductor {
private:
    double impedance;
    string shieldType;

public:
    CoaxialCable(const string& man, double len, double maxFreq, double imp, const string& shield);
    void displayInfo() const override;

    void setImpedance(double imp);
    void setShieldType(const string& shield);
};

#endif