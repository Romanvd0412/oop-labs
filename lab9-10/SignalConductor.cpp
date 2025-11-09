#include "SignalConductor.h"

using namespace std;

SignalConductor::SignalConductor(const string& man, double len, double maxFreq) {
    setManufacturer(man);
    setLength(len);
    setMaxFrequency(maxFreq);
    cout << "SignalConductor object created." << endl;
}

void SignalConductor::displayInfo() const {
    cout << "Signal Conductor Info:" << endl;
    cout << "Manufacturer: " << manufacturer << endl;
    cout << "Length: " << length << " m" << endl;
    cout << "Max Frequency: " << maxFrequency / 1e9 << " GHz" << endl;
}

void SignalConductor::setManufacturer(const string& man) {
    if (!man.empty()) {
        manufacturer = man;
    } else {
        cout << "Error: Manufacturer name cannot be empty." << endl;
        manufacturer = "Unknown";
    }
}

void SignalConductor::setLength(double len) {
    if (len > 0) {
        length = len;
    } else {
        cout << "Error: Invalid length. Setting to 1m." << endl;
        length = 1.0;
    }
}

void SignalConductor::setMaxFrequency(double maxFreq) {
    if (maxFreq > 0) {
        maxFrequency = maxFreq;
    } else {
        cout << "Error: Invalid max frequency. Setting to 1 GHz." << endl;
        maxFrequency = 1e9;
    }
}

string SignalConductor::getManufacturer() const { return manufacturer; }
double SignalConductor::getLength() const { return length; }
double SignalConductor::getMaxFrequency() const { return maxFrequency; }