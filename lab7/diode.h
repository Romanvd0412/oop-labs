#ifndef DIODE_H

#define DIODE_H

#include <string>
#include <vector>

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
    vector<diode> diodes;
    int currentCount = 0;
    
    diode getNewDiodeFromUser();

public:
    DiodesCreator();
    ~DiodesCreator();
    void addDiode ();
    void printDiodes();
    void setForwardVoltage(int diodeIndex, float forwardVoltage);
    void insertDiode(int diodeIndex);
    void removeDiode(int diodeIndex);
    void swapDiodes(int firstIndex, int secondIndex);
    void clearDiodes();
};

#endif