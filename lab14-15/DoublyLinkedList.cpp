#include "DoublyLinkedList.h"
#include <iostream>

DoublyLinkedList::DoublyLinkedList() : head(nullptr), tail(nullptr) {}

DoublyLinkedList::~DoublyLinkedList() {
    while (!isEmpty()) {
        popFront();
    }
}

bool DoublyLinkedList::isEmpty() const {
    return head == nullptr;
}

void DoublyLinkedList::pushFront(const Diode& d) {
    Node* newNode = new Node(d);
    if (isEmpty()) {
        head = tail = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}

void DoublyLinkedList::pushBack(const Diode& d) {
    Node* newNode = new Node(d);
    if (isEmpty()) {
        head = tail = newNode;
    } else {
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }
}

void DoublyLinkedList::insertAfter(const Diode& target, const Diode& newData) {
    if (isEmpty()) return;

    Node* current = head;
    while (current != nullptr) {
        if (current->data == target) {
            if (current == tail) {
                pushBack(newData);
            } else {
                Node* newNode = new Node(newData);
                newNode->prev = current;
                newNode->next = current->next;
                current->next->prev = newNode;
                current->next = newNode;
            }
            return;
        }
        current = current->next;
    }
}

void DoublyLinkedList::popFront() {
    if (isEmpty()) return;

    Node* temp = head;
    if (head == tail) {
        head = tail = nullptr;
    } else {
        head = head->next;
        head->prev = nullptr;
    }
    delete temp;
}

void DoublyLinkedList::popBack() {
    if (isEmpty()) return;

    Node* temp = tail;
    if (head == tail) {
        head = tail = nullptr;
    } else {
        tail = tail->prev;
        tail->next = nullptr;
    }
    delete temp;
}

void DoublyLinkedList::removeByValue(const Diode& val) {
    if (isEmpty()) return;

    Node* current = head;
    while (current != nullptr) {
        if (current->data == val) {
            if (current == head) {
                popFront();
            } else if (current == tail) {
                popBack();
            } else {
                current->prev->next = current->next;
                current->next->prev = current->prev;
                delete current;
            }
            return;
        }
        current = current->next;
    }
}

void DoublyLinkedList::displayForward() const {
    if (isEmpty()) {
        std::cout << "List is empty." << std::endl;
        return;
    }
    Node* current = head;
    while (current != nullptr) {
        std::cout << current->data << std::endl;
        current = current->next;
    }
    std::cout << "----------------" << std::endl;
}

void DoublyLinkedList::displayBackward() const {
    if (isEmpty()) {
        std::cout << "List is empty." << std::endl;
        return;
    }
    Node* current = tail;
    while (current != nullptr) {
        std::cout << current->data << std::endl;
        current = current->prev;
    }
    std::cout << "----------------" << std::endl;
}