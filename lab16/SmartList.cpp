#include "SmartList.h"
#include <iostream>

SmartList::SmartList() : head(nullptr), tail(nullptr) {}

SmartList::~SmartList() {}

void SmartList::pushBack(const Diode& d) {
    std::shared_ptr<Node> newNode = std::make_shared<Node>(d);

    if (!head) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

void SmartList::pushFront(const Diode& d) {
    std::shared_ptr<Node> newNode = std::make_shared<Node>(d);

    if (!head) {
        head = tail = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}

void SmartList::displayForward() const {
    std::cout << "List (Forward):" << std::endl;
    std::shared_ptr<Node> current = head;
    while (current) {
        std::cout << current->data << std::endl;
        current = current->next;
    }
    std::cout << "----------------" << std::endl;
}

void SmartList::displayBackward() const {
    std::cout << "List (Backward):" << std::endl;
    std::shared_ptr<Node> current = tail;
    while (current) {
        std::cout << current->data << std::endl;
        current = current->prev.lock(); 
    }
    std::cout << "----------------" << std::endl;
}