#ifndef DIODE_H
#define DIODE_H

#include <string>
#include <iostream>

using namespace std;

class Diode {
private:
    float forwardVoltage;
    float maxBackwardCurrent;
    string purpose;

public:
    Diode(float fv, float mbc, const string& p);
    void displayInfo() const;
    void setPurpose(const string& newPurpose);
    void setForwardVoltage(float fv);
    void setMaxBackwardCurrent(float mbc);
};

void changeDiodePurposeByReference(Diode& diode, const string& newPurpose);

#endif