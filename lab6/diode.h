#ifndef DIODE_H

#define DIODE_H

#include <string>
#include <array>

using namespace std;

struct diode
{
    float forwardVoltage;
    float maxBackwardCurrent;
    string purpose;
};

class DiodesCreator
{
private:
    static const int DIODES_COUNT = 5;
    array<diode, DIODES_COUNT> diodes;
    int currentCount = 0;
public:
    DiodesCreator();
    ~DiodesCreator();
    void addDiode ();
    void printDiodes();
    void setForwardVoltage(int diodeIndex, float forwardVoltage);
};

#endif