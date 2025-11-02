#include "diode.h"
#include <iostream>
#include <algorithm> 
#include <limits>

using namespace std;

DiodesCreator::DiodesCreator () {
    cout << "This is constructor of diodes creator, it can create unlimited count of diodes." << endl;
}

DiodesCreator::~DiodesCreator () {
    cout << "Bye." << endl;
}

diode DiodesCreator::getNewDiodeFromUser() {
    float forwardVoltage, maxBackwardCurrent;
    string purpose;
    bool isAllValid = false;

    while (!isAllValid)
    {
        cout << "Enter values: forward voltage, max backward current" << endl;
        cin >> forwardVoltage >> maxBackwardCurrent;
        cout << "Enter purpose" << endl;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, purpose);

        if (forwardVoltage <= 0 || maxBackwardCurrent <= 0 || purpose.empty()) {
            cout << "Values must be filled!" << endl;
            continue;
        }

        isAllValid = true;
    }

    diode newDiode;
    newDiode.forwardVoltage = forwardVoltage;
    newDiode.maxBackwardCurrent = maxBackwardCurrent;
    newDiode.purpose = purpose;

    return newDiode;
}

void DiodesCreator::addDiode() {
    diode newDiode = getNewDiodeFromUser();
    diodes.push_back(newDiode);
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
    if (currentCount == 0) {
        cout << "Diode list is empty." << endl;
        return;
    }

    for (int i = 0; i < currentCount; i++) {
        cout << "Diode #" << i+1 << 
        ": forward voltage: " << diodes[i].forwardVoltage << 
        ", max backward current: " << diodes[i].maxBackwardCurrent << 
        ", purpose: " << diodes[i].purpose << endl;
    }
}

void DiodesCreator::insertDiode(int diodeIndex) {
    if (diodeIndex < 0 || diodeIndex > currentCount) {
        cout << "Invalid index for insertion!" << endl;
        return;
    }

    diode newDiode = getNewDiodeFromUser();
    
    diodes.insert(diodes.begin() + diodeIndex, newDiode);
    
    currentCount++;
    
    cout << "Diode inserted at index " << diodeIndex << "." << endl;
}

void DiodesCreator::removeDiode(int diodeIndex) {
    if (diodeIndex < 0 || diodeIndex >= currentCount) {
        cout << "Diode does not exist!" << endl;
        return;
    }

    diodes.erase(diodes.begin() + diodeIndex);
    
    currentCount--;

    cout << "Diode at index " << diodeIndex << " removed." << endl;
}

void DiodesCreator::swapDiodes(int firstIndex, int secondIndex) {
    if (firstIndex < 0 || firstIndex >= currentCount) {
        cout << "First diode index does not exist!" << endl;
        return;
    }

    if (secondIndex < 0 || secondIndex >= currentCount) {
        cout << "Second diode index does not exist!" << endl;
        return;
    }
    
    if (firstIndex == secondIndex) {
        cout << "Indices are the same, no swap needed." << endl;
        return;
    }

    swap(diodes[firstIndex], diodes[secondIndex]);

    cout << "Swapped diodes at indices " << firstIndex << " and " << secondIndex << "." << endl;
}

void DiodesCreator::clearDiodes() {
    diodes.clear();
    currentCount = 0;
    cout << "All diodes have been cleared." << endl;
}
