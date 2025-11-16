#ifndef COAXIAL_CABLE_H
#define COAXIAL_CABLE_H

#include "SignalConductor.h"

class ConductorProcessor;

class CoaxialCable : public SignalConductor {
protected:
    double impedance;
    string shieldType;

public:
    CoaxialCable(const string& man, double len, double maxFreq, double imp, const string& shield);
    void displayInfo() const override;

    void setImpedance(double imp);
    void setShieldType(const string& shield);

    friend class ConductorProcessor;
};

#endif