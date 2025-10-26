#include <iostream>
#include "diode.h"

using namespace std;

int main () {
    DiodesCreator MyDiodes;

    for (int i = 0; i < 3; i++) {
        MyDiodes.addDiode();
    }

    MyDiodes.setForwardVoltage(0, 14);

    MyDiodes.setForwardVoltage(4, 14);

    MyDiodes.printDiodes();

    return 0;
}