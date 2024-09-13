#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "MPointer.h"  // Incluir MPointer

template<typename T>
class Node {
public:
    MPointer<T> data; // MPointer para el dato
    MPointer<Node<T>> next; // MPointer para el siguiente nodo
    MPointer<Node<T>> prev;        // MPointer para el nodo anterior

    Node(T value) {
        data = MPointer<T>::New();      // Inicializar MPointer
        *data = value;                  // Asignar valor al dato
        next = nullptr;                 // Inicializar punteros a null
        prev = nullptr;
    }
};