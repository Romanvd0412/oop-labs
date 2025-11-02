#include "diode.h"

using namespace std;

Diode::Diode(float fv, float mbc, const string& p) {
    setForwardVoltage(fv);
    setMaxBackwardCurrent(mbc);
    setPurpose(p);
    cout << "Diode object created." << endl;
}

void Diode::displayInfo() const {
    cout << "--- Diode Info ---" << endl;
    cout << "Forward Voltage: " << forwardVoltage << "V" << endl;
    cout << "Max Backward Current: " << maxBackwardCurrent << "A" << endl;
    cout << "Purpose: " << purpose << endl;
    cout << "--------------------" << endl;
}

void Diode::setPurpose(const string& newPurpose) {
    if (!newPurpose.empty()) {
        purpose = newPurpose;
    } else {
        cout << "Error: Purpose cannot be empty." << endl;
    }
}

void Diode::setForwardVoltage(float fv) {
    if (fv > 0) {
        forwardVoltage = fv;
    } else {
        cout << "Invalid forward voltage." << endl;
    }
}

void Diode::setMaxBackwardCurrent(float mbc) {
    if (mbc > 0) {
        maxBackwardCurrent = mbc;
    } else {
        cout << "Invalid max backward current." << endl;
    }
}

void changeDiodePurposeByReference(Diode& diode, const string& newPurpose) {
    cout << "\nChanging diode's purpose using a reference..." << endl;
    diode.setPurpose(newPurpose);
}