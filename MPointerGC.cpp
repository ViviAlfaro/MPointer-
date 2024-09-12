#include "MPointerGC.h"

MPointerGC* MPointerGC::instance = nullptr; //Inicializacion del puntero estatico

MPointerGC& MPointerGC::getInstance() { //Si instance es nullptr, se crea una nueva instancia de MPointerGC
    if (instance == nullptr) {
        instance = new MPointerGC();
    }
    return *instance;
}

int MPointerGC::registerPointer(void* ptr) { //Registra un nuevo puntero ptr y se le asigna un identificador
    static int currentID = 0;
    int id = ++currentID;
    pointers[id] = ptr;
    referenceCount[id] = 1;
    return id;
}

//Incrementa el numero de referencias para el puntero asociado con el id que se le da 

void MPointerGC::addReference(int id) { 
    if (referenceCount.find(id) != referenceCount.end()) {
        referenceCount[id]++; //Si id existe en referenceCOunt y lo encuentra, incrementa el contador
    }
}

//Decrementa el numero de referencias 

void MPointerGC::removeReference(int id) {
    if (referenceCount.find(id) != referenceCount.end()) {
        referenceCount[id]--;
        if (referenceCount[id] == 0) {
            delete static_cast<int*>(pointers[id]); // 
            pointers.erase(id);
            delete static_cast<int*>(pointers[it->first]);
            pointers.erase(it->first);
            it = referenceCount.erase(it);
            referenceCount.erase(id);
        }
    }
}