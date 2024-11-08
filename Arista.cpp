#include "Arista.h"

Arista::Arista(Centro* origen, Centro* destino, float costo, float duracion)
    : origen(origen), destino(destino), costo(costo), duracion(duracion) {}

Centro* Arista::getOrigen() const {
    return origen;  // Devuelve el puntero al nodo origen
}

Centro* Arista::getDestino() const {
    return destino; // Devuelve el puntero al nodo destino
}

float Arista::getCosto() const {
    return costo;
}

float Arista::getDuracion() const {
    return duracion;
}
