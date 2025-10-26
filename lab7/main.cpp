#include <iostream>
#include "diode.h"

using namespace std;

int main () {
    DiodesCreator MyDiodes;

    for (int i = 0; i < 3; i++) {
        MyDiodes.addDiode();
    }

    MyDiodes.setForwardVoltage(0, 14);

    cout << endl;
    MyDiodes.printDiodes();
    
    MyDiodes.setForwardVoltage(4, 14); 

    cout << endl;
    MyDiodes.insertDiode(1);
    
    cout << endl;
    MyDiodes.printDiodes(); 

    cout << endl;
    MyDiodes.swapDiodes(1, 3);
    
    cout << endl;
    MyDiodes.printDiodes();

    cout << endl;
    MyDiodes.removeDiode(0);
    
    cout << endl;
    MyDiodes.printDiodes(); 

    cout << endl;
    MyDiodes.clearDiodes();
    
    cout << endl;
    MyDiodes.printDiodes(); 

    return 0;
}