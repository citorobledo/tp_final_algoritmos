#ifndef NODO_H_INCLUDED
#define NODO_H_INCLUDED

#include <iostream>
#include "centro.h"

//typedef int Centro; // tipo de dato que se almacena en el nodo

class Nodo
{
private:
    // atributos
    Centro dato;
    Nodo* siguiente;

public:
    // metodos
    // constructor
    // PRE:
    // POS: crea un nodo con dato = d y siguiente = 0
    Nodo(Centro d);

    void cambiar_dato(Centro d);

    void cambiar_siguiente(Nodo* s);

    Centro obtener_dato();

    Nodo* obtener_siguiente();
};

#endif // NODO_H_INCLUDED