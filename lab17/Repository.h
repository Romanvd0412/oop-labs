#ifndef REPOSITORY_H
#define REPOSITORY_H

#include <iostream>
#include "Diode.h"

using namespace std;

template <class T>
class Repository {
private:
    T data;
public:
    Repository(T val) : data(val) {}

    void display() {
        cout << "Generic Template: " << data << endl;
    }
};

template <class T>
class Repository<T*> {
private:
    T* data;
public:
    Repository(T* val) : data(val) {}

    void display() {
        cout << "Partial Specialization (Pointer): ";
        if (data) {
            cout << *data << endl;
        } else {
            cout << "nullptr" << endl;
        }
    }
};

template <>
class Repository<Diode> {
private:
    Diode data;
public:
    Repository(Diode val) : data(val) {}

    void display() {
        cout << "Full Specialization (Diode):" << endl;
        cout << "   Purpose: " << data.getPurpose() << endl;
        cout << "   Voltage: " << data.getVoltage() << " V" << endl;
        cout << "   Current: " << data.getCurrent() << " A" << endl;
    }
};

#endif