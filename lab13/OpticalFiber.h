#ifndef OPTICAL_FIBER_H
#define OPTICAL_FIBER_H

#include "SignalConductor.h"

class OpticalFiber : public SignalConductor {
private:
    int fibersCount;
    string modeType;

public:
    OpticalFiber();
    OpticalFiber(string n, double l, double p, int count, string mode);

    void displayInfo() const override;
    void saveToFile(ofstream& out) const override;
    void loadFromFile(ifstream& in) override;
    string getType() const override { return "OpticalFiber"; }
};

#endif