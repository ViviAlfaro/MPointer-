#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "MPointer.h"  // Incluir MPointer

template<typename T>
class Node {
public:
    MPointer<T> data; // MPointer para el dato
    MPointer<Node<T>> next;// MPointer para el siguiente nodo
    MPointer<Node<T>> prev;// MPointer para el nodo anterior

    Node(T value) {
        data = MPointer<T>::New();// Inicializar MPointer
        *data = value;// Asignar valor al dato
        next = nullptr;// Inicializar punteros a null
        prev = nullptr;
    }
};

template<typename T>
class LinkedList {
private:
    MPointer<Node<T>> head;// MPointer para la cabeza de la lista
    MPointer<Node<T>> tail;// MPointer para la cola de la lista

public:
    LinkedList();
    ~LinkedList();

    void add(T value);// Añadir elementos
    void remove(T value);// Eliminar elementos
    void display();// Mostrar elementos

    Node<T>* getHead();// Obtener el nodo head
    Node<T>* getTail();// Obtener el nodo tail

    // Algoritmos de ordenamiento
    void quickSort();
    void bubbleSort();
    void insertionSort();

    }