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
    MPointer<Node<T>> current = head;
    while (current != nullptr) {
        MPointer<Node<T>> next = current->next;
        //El destructor de MPointer se encarga de liberar la memoria
        current = next;
    }
}

// Añadir elementos a la lista
template<typename T>
void LinkedList<T>::add(T value) {
    MPointer<Node<T>> newNode = MPointer<Node<T>>::New(); // Crear nodo con MPointer
    newNode->data = MPointer<T>::New();
    *newNode->data = value;

    if (head == nullptr) {
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

// Mostrar la lista
template<typename T>
void LinkedList<T>::display() {
    MPointer<Node<T>> current = head;
    while (current != nullptr) {
        std::cout << *current->data << " ";  // Acceder al valor usando MPointer
        current = current->next;
    }
    std::cout << std::endl;
}

// Obtener la cabeza de la lista
template<typename T>
Node<T>* LinkedList<T>::getHead() {
    std::cout << *current->data << " ";  // Acceder al valor usando MPointer
    current = current->next;
    return head.get();
}

// Obtener la cola de la lista
template<typename T>
Node<T>* LinkedList<T>::getTail() {
    return tail.get();
}