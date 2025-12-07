#include <iostream>
#include <vector>
#include <algorithm>
#include "SignalConductor.h"
#include "CoaxialCable.h"
#include "OpticalFiber.h"
#include "FileManager.h"

using namespace std;

int main() {
    vector<SignalConductor*> conductors;
    string filename = "conductors_data.bin";

    try {
        cout << "=== Creating Objects with Exception Handling ===" << endl;
        
        conductors.push_back(new CoaxialCable("RG-6", 100.0, 0.5, 75.0));
        conductors.push_back(new OpticalFiber("SingleMode-G652", 500.0, 1.2, 1, "Single"));
        conductors.push_back(new CoaxialCable("RG-59", 50.0, 0.3, 50.0));

        cout << "\n=== Original List ===" << endl;
        for (const auto* item : conductors) {
            item->displayInfo();
        }

        sort(conductors.begin(), conductors.end(), [](SignalConductor* a, SignalConductor* b) {
            return *a < *b;
        });

        cout << "\n=== Sorted List (by Total Price) ===" << endl;
        for (const auto* item : conductors) {
            item->displayInfo();
        }

        cout << "\n=== Saving to File ===" << endl;
        FileManager::saveList(conductors, filename);

        cout << "\n=== Clearing Memory and Vector ===" << endl;
        for (auto* item : conductors) delete item;
        conductors.clear();

        cout << "\n=== Loading from File ===" << endl;
        FileManager::loadList(conductors, filename);

        cout << "\n=== Restored List ===" << endl;
        for (const auto* item : conductors) {
            item->displayInfo();
        }

    } 
    catch (const ConductorException& e) {
        cerr << "Caught Custom Exception: " << e.what() << endl;
    }
    catch (const exception& e) {
        cerr << "Caught Standard Exception: " << e.what() << endl;
    }
    catch (...) {
        cerr << "Unknown error occurred!" << endl;
    }

    for (auto* item : conductors) delete item;
    conductors.clear();

    return 0;
}