#include <iostream>
#include <memory>
#include "Diode.h"
#include "SmartList.h"

using namespace std;

struct ChildB;

struct ChildA {
    shared_ptr<ChildB> b_ptr;
    ~ChildA() { cout << "ChildA destroyed" << endl; }
};

struct ChildB {
    weak_ptr<ChildA> a_ptr; 
    ~ChildB() { cout << "ChildB destroyed" << endl; }
};

void demoUniquePtr() {
    cout << "\n=== TASK 2: std::unique_ptr ===" << endl;
    
    unique_ptr<Diode> item1 = make_unique<Diode>(0.7, 1.0, "Unique Rectifier");
    
    unique_ptr<Diode> item2 = move(item1);
    
    if (item1 == nullptr) {
        cout << "item1 is nullptr." << endl;
    }
    
    if (item2) {
        cout << "item2 owns object: " << *item2 << endl;
    }
}

void demoSharedPtr() {
    cout << "\n=== TASK 3: std::shared_ptr ===" << endl;
    
    shared_ptr<Diode> ptr1 = make_shared<Diode>(5.1, 0.05, "Shared Zener");
    cout << "Count: " << ptr1.use_count() << endl;

    {
        shared_ptr<Diode> ptr2 = ptr1;
        cout << "Count (inner): " << ptr1.use_count() << endl;
        
        shared_ptr<Diode> ptr3 = ptr2;
        cout << "Count (inner 2): " << ptr1.use_count() << endl;
    }

    cout << "Count (outer): " << ptr1.use_count() << endl;
}

void demoWeakPtr() {
    cout << "\n=== TASK 4: std::weak_ptr ===" << endl;
    
    auto a = make_shared<ChildA>();
    auto b = make_shared<ChildB>();

    a->b_ptr = b;
    b->a_ptr = a;

    cout << "ChildA count: " << a.use_count() << endl;
    cout << "ChildB count: " << b.use_count() << endl;
}

int main() {
    demoUniquePtr();
    demoSharedPtr();
    demoWeakPtr();

    cout << "\n=== TASK 5: Smart List ===" << endl;
    SmartList list;

    list.pushBack(Diode(0.7, 1.0, "Rectifier List"));
    list.pushBack(Diode(5.1, 0.05, "Zener List"));
    list.pushFront(Diode(0.3, 0.5, "Schottky List"));

    list.displayForward();
    list.displayBackward();

    return 0;
}