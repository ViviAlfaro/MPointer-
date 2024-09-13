#include "LinkedList.h"
#include <iostream>

// Constructor
template<typename T>
LinkedList<T>::LinkedList() {
    head = nullptr;
    tail = nullptr;
}

// Destructor
template<typename T>
LinkedList<T>::~LinkedList() {
    while (current != nullptr) {
        MPointer<Node<T>> next = current->next;
        // El destructor de MPointer se encarga de liberar la memoria
        current = next;
    }
}
