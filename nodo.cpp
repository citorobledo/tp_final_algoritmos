#include "nodo.h"
#include "centro.h"
#include <iostream>


Nodo::Nodo(Centro d)
{
    dato = d;
    siguiente = 0;
}

void Nodo::cambiar_dato(Centro d)
{
    dato = d;
}

void Nodo::cambiar_siguiente(Nodo* s)
{
    siguiente = s;
}

Centro Nodo::obtener_dato()
{
    return dato;
}

Nodo* Nodo::obtener_siguiente()
{
    return siguiente;
}
