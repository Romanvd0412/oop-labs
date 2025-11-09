#ifndef SIGNAL_CONDUCTOR_H
#define SIGNAL_CONDUCTOR_H

#include <string>
#include <iostream>

using namespace std;

class SignalConductor {
private:
    string manufacturer;
    double length;
    double maxFrequency;

public:
    SignalConductor(const string& man, double len, double maxFreq);
    virtual ~SignalConductor() {}
    virtual void displayInfo() const;

    void setManufacturer(const string& man);
    void setLength(double len);
    void setMaxFrequency(double maxFreq);

    string getManufacturer() const;
    double getLength() const;
    double getMaxFrequency() const;
};

#endif