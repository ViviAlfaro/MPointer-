#ifndef MPOINTERGC_H
#define MPOINTERGC_H

#include <iostream> //Inclusión de bibliotecas
#include <unordered_map>

class MPointerGC { //Definicion de la clase
private:
    static MPointerGC* instance; //Puntero estático que apunta a la única instancia de la clase 
    std::unordered_map<int, int> referenceCount; //Almacena el conteo de referencias de cada puntero
    std::unordered_map<int, void*> pointers; 
    std::unordered_map<int, void*>;

    MPointerGC() = default;

}

