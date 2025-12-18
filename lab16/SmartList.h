#ifndef SMARTLIST_H
#define SMARTLIST_H

#include "Diode.h"
#include <memory>

struct Node {
    Diode data;
    std::shared_ptr<Node> next;
    std::weak_ptr<Node> prev;

    Node(const Diode& d) : data(d), next(nullptr) {}
};

class SmartList {
private:
    std::shared_ptr<Node> head;
    std::shared_ptr<Node> tail;

public:
    SmartList();
    ~SmartList();

    void pushBack(const Diode& d);
    void pushFront(const Diode& d);
    void displayForward() const;
    void displayBackward() const;
};

#endif