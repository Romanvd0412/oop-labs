#ifndef OPTICAL_FIBER_H
#define OPTICAL_FIBER_H

#include "SignalConductor.h"

class ConductorProcessor;

class OpticalFiber : public SignalConductor {
protected:
    string mode;
    double coreDiameter;

public:
    OpticalFiber(const string& man, double len, double maxFreq, const string& m, double diameter);
    void displayInfo() const override;

    void setMode(const string& m);
    void setCoreDiameter(double diameter);

    friend class ConductorProcessor;
};

#endif