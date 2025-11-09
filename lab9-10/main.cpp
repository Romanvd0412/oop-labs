#include <iostream>
#include <vector>
#include "SignalConductor.h"
#include "CoaxialCable.h"
#include "OpticalFiber.h"

using namespace std;

int main() {
    vector<SignalConductor*> conductors;

    cout << "Creating objects..." << endl;
    
    conductors.push_back(new SignalConductor("Generic", 10.0, 1e9));
    conductors.push_back(new CoaxialCable("CommScope", 100.0, 3e9, 75.0, "Quad-shield"));
    conductors.push_back(new OpticalFiber("Corning", 5000.0, 200e12, "Single-mode", 9.0));

    conductors[0]->setLength(25.5);
    conductors[2]->setMaxFrequency(2500);
    conductors[1]->setManufacturer("User Manufactured");


    
    cout << "\nDisplaying Info:" << endl;
    
    for (const auto* conductor : conductors) {
        cout << "\n"; 
        conductor->displayInfo();
    }

    cout << "\nCleaning up memory..." << endl;
    for (auto* conductor : conductors) {
        delete conductor;
    }
    conductors.clear();

    return 0;
}