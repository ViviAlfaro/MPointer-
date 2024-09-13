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
    return head.get();
}

// Obtener la cola de la lista
template<typename T>
Node<T>* LinkedList<T>::getTail() {
    return tail.get();
}

// Implementación de QuickSort

template<typename T>
Node<T>* LinkedList<T>::partition(Node<T>* low, Node<T>* high) {
    T pivot = *high->data; // Valor del último elemento
    Node<T>* i = low->prev.get(); //Se inicializa el puntero i para rastrear 

    for (Node<T>* j = low; j != high; j = j->next.get()) {
        if (*j->data <= pivot) {
            i = (i == nullptr) ? low : i->next.get();
            std::swap(*i->data, *j->data);
        }
    }

    i = (i == nullptr) ? low : i->next.get();
    std::swap(*i->data, *high->data);
    return i;
}

template<typename T>
void LinkedList<T>::quickSort(Node<T>* low, Node<T>* high) {
    if (high != nullptr && low != high && low != high->next.get()) {
        Node<T>* p = partition(low, high);
        quickSort(low, p->prev.get());
        quickSort(p->next.get(), high);
    }
}

template<typename T>
void LinkedList<T>::quickSort() {
    quickSort(getHead(), getTail());
}
