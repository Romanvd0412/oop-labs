#include <iostream>
#include "Repository.h"
#include "Diode.h"

using namespace std;

int main() {
    Repository<int> r1(123);
    r1.display();

    Repository<string> r2("Template Test");
    r2.display();

    Diode d(0.7, 5.0, "Rectifier");
    Repository<Diode> r3(d);
    r3.display();

    Repository<Diode*> r4(&d);
    r4.display();

    int x = 99;
    Repository<int*> r5(&x);
    r5.display();

    return 0;
}