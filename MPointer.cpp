MPointer.cpp:

#include "MPointer.h"

template<typename T> //Constructor por defecto, asigna dinamicamente la memoria para un objeto tipo T
MPointer<T>::MPointer() {
    ptr = new T();
    id = MPointerGC::getInstance().registerPointer(this);
}

template<typename T> //Crea y retorna una nueva instancia de MPointer<T>.
MPointer<T> MPointer<T>::New() {
    return MPointer<T>();
}

template<typename T> //Constructor de copia permite crear un nuevo MPointer copiando otro. Copia el puntero (ptr) y el identificador (id) del MPointer original
MPointer<T>::MPointer(const MPointer& other) {
    ptr = other.ptr;
    id = other.id;
    MPointerGC::getInstance().addReference(id);
}


template<typename T> // Sobrecarga del operador de asignacion
MPointer<T>& MPointer<T>::operator=(const MPointer& other) {
    if (this != &other) {
        MPointerGC::getInstance().removeReference(id);
        ptr = other.ptr;
        id = other.id;
        MPointerGC::getInstance().addReference(id);
    }
    return *this;
}

template<typename T>
MPointer<T>::~MPointer() {
    MPointerGC::getInstance().removeReference(id); //El destructor elimina la referencia al puntero en el recolector de basura mediante removeReference(id)
}

template<typename T> //Sobrecarga del operador de dereferencia (MPointer<T>::operator*)
T& MPointer<T>::operator*() {
    return *ptr;
}

template<typename T> //Sobrecarga del operador de dirección (MPointer<T>::operator&)
T* MPointer<T>::operator&() {
    return ptr;
}

template<typename T> //Obtener el valor del objeto apuntado por ptr. La palabra clave const indica que no modifica el estado interno del objeto.
T MPointer<T>::getValue() const {
    return *ptr;
}
