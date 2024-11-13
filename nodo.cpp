#include "nodo.h"
#include "centro.h"
#include <iostream>


Nodo::Nodo(Centro d)
{
    dato = d;
    siguiente = nullptr;
    ocupado = false;
    borrado = false;
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

bool Nodo::esta_ocupado()
{
    return ocupado;
}

void Nodo::marcar_ocupado()
{
    ocupado = true;
}

void Nodo::marcar_desocupado()
{
    ocupado = false;
}

bool Nodo::esta_borrado()
{
    return borrado;
}

void Nodo::marcar_borrado()
{
    borrado = true;
}

void Nodo::marcar_no_borrado()
{
    borrado = false;
}