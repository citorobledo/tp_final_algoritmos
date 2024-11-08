#ifndef NODO_H
#define NODO_H

#include "centro.h"

class Nodo {
public:
    Centro* centro;  // Puntero a Estacion

    // Constructor de la clase Nodo
    Nodo(Centro* centro);
};

#endif