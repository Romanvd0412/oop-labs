#include <iostream>
#include "DoublyLinkedList.h"
#include "Diode.h"

using namespace std;

int main() {
    DoublyLinkedList list;

    list.pushBack(Diode(0.7, 1.0, "Rectifier"));
    list.pushBack(Diode(5.1, 0.05, "Zener"));
    list.pushFront(Diode(0.3, 0.5, "Schottky"));

    cout << "Forward List:" << endl;
    list.displayForward();

    Diode target(0.7, 1.0, "Rectifier");
    Diode newDiode(1.2, 3.0, "Power");
    list.insertAfter(target, newDiode);

    cout << "Backward List:" << endl;
    list.displayBackward();

    list.popFront();
    list.popBack();
    list.removeByValue(Diode(1.2, 3.0, "Power"));

    cout << "Final List:" << endl;
    list.displayForward();

    return 0;
}