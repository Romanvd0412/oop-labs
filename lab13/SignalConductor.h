#ifndef SIGNAL_CONDUCTOR_H
#define SIGNAL_CONDUCTOR_H

#include <string>
#include <iostream>
#include <fstream>
#include "ConductorException.h"

using namespace std;

class SignalConductor {
protected:
    string name;
    double length;
    double pricePerMeter;

public:
    SignalConductor();
    SignalConductor(string n, double l, double p);
    virtual ~SignalConductor() {}

    virtual void displayInfo() const = 0;
    virtual void saveToFile(ofstream& out) const;
    virtual void loadFromFile(ifstream& in);
    virtual string getType() const = 0;

    double getPrice() const;

    bool operator<(const SignalConductor& other) const;
};

#endif