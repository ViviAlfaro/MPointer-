#include "MPointerGC.h"

MPointerGC* MPointerGC::instance = nullptr; //Inicializacion del puntero estatico

MPointerGC& MPointerGC::getInstance() { //Si instance es nullptr, se crea una nueva instancia de MPointerGC
    if (instance == nullptr) {
        instance = new MPointerGC();
    }
    return *instance;
}

int MPointerGC::registerPointer(void* ptr) { //Registra un nuevo puntero ptr y se le asigna un identificador unico
    pointers[id] = ptr;
    referenceCount[id] = 1;
    static int currentID = 0;
    int id = ++currentID;
    
    return id;
}