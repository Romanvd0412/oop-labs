#include "diode.h"
#include <iostream>

using namespace std;

int main() {
    Diode myDiode(0.7, 0.001, "Straighter");

    cout << "Initial diode info:" << endl;
    myDiode.displayInfo();

    changeDiodePurposeByReference(myDiode, "Zener Diode");

    cout << "\nUpdated diode info:" << endl;
    myDiode.displayInfo();

    return 0;

}
    