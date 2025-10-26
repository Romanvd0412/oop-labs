#include "diode.h"
#include <iostream>

using namespace std;

DiodesCreator::DiodesCreator () {
    cout << "This is constructor of diodes creator, it can create " << DIODES_COUNT << " diodes." << endl;
}

DiodesCreator::~DiodesCreator () {
    cout << "Bye." << endl;
}

void DiodesCreator::addDiode() {
    float forwardVoltage, maxBackwardCurrent;
    string purpose;
    bool isAllValid = false;

    if (currentCount == DIODES_COUNT) {
        cout << "You have added all diodes!" << endl;
        return;
    }

    while (!isAllValid)
    {
        cout << "Enter values: forward voltage, max backward current, purpose" << endl;
        cin >> forwardVoltage >> maxBackwardCurrent >> purpose;

        if (forwardVoltage <= 0 || maxBackwardCurrent <= 0 || purpose.empty()) {
            cout << "Values must be filled!" << endl;
            continue;
        }

        isAllValid = true;
    }

    diodes[currentCount].forwardVoltage = forwardVoltage;
    diodes[currentCount].maxBackwardCurrent = maxBackwardCurrent;
    diodes[currentCount].purpose = purpose;
    
    currentCount++;
}

void DiodesCreator::setForwardVoltage(int diodeIndex, float forwardVoltage) {
    if (diodeIndex < 0 || diodeIndex >= currentCount) {
        cout << "Diode does not exist!" << endl;
        return;
    }


    if (forwardVoltage <= 0) {
        cout << "Value must be > 0!" << endl;
        return;
    }

    diodes[diodeIndex].forwardVoltage = forwardVoltage;
}

void DiodesCreator::printDiodes() {
    for (int i = 0; i < currentCount; i++) {
        cout << "Diode #" << i+1 << 
        ": forward voltage: " << diodes[i].forwardVoltage << 
        ", max backward current: " << diodes[i].maxBackwardCurrent << 
        ", purpose: " << diodes[i].purpose << endl;
    }
}
