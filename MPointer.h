#ifndef MPOINTER_H //Encabezado de protección contra múltiples inclusiones
#define MPOINTER_H

#include <iostream> //Inclusión de bibliotecas
#include "MPointerGC.h"

template<typename T> //Permite que MPointer maneje diferentes tipos de objetos
class MPointer {
private: 
    T* ptr; //Puntero a un objeto de tipo T, que almacena la dirección del objeto al que apunta.
    int id; //Identificador único asociado a este puntero, que es utilizado por MPointerGC para gestionar las referencias

public:
    static MPointer<T> New(); //Declara un método estático que se utiliza para crear una nueva instancia de MPointer

    MPointer(); 
    MPointer(const MPointer& other);
    MPointer& operator=(const MPointer& other); //Sobrecarga del operador de asignación. 
    ~MPointer();


    T& operator*();// Sobrecarga del operador *
    T* operator&();   // Sobrecarga del operador &
    T* operator->() {// Sobrecarga del operador ->
        return ptr;       // Retorna el puntero interno
    }

    void setValue(T value);
    T getValue() const;
};


#include "MPointer.cpp"
#endif