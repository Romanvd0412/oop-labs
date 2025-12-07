#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include "Diode.h"
#include <stdexcept>

struct Node {
    Diode data;
    Node* next;
    Node* prev;

    Node(Diode d) : data(d), next(nullptr), prev(nullptr) {}
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList();
    ~DoublyLinkedList();

    bool isEmpty() const;
    void pushFront(const Diode& d);
    void pushBack(const Diode& d);
    void insertAfter(const Diode& target, const Diode& newData);
    void popFront();
    void popBack();
    void removeByValue(const Diode& val);
    void displayForward() const;
    void displayBackward() const;
};

#endif