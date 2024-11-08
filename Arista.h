#ifndef ARISTA_H
#define ARISTA_H

#include <string>
#include "Centro.h"  // Incluir la clase Centro para usar punteros a Centro

class Arista {
private:
    Centro* origen;      // Puntero al centro origen
    Centro* destino;     // Puntero al centro destino
    float costo;         // Costo del viaje
    float duracion;      // Duración del viaje

public:
    Arista(Centro* origen, Centro* destino, float costo, float duracion);
    Centro* getOrigen() const;     // Método para obtener el nodo de origen
    Centro* getDestino() const;    // Método para obtener el nodo destino
    float getCosto() const;        // Método para obtener el costo
    float getDuracion() const;     // Método para obtener la duración
};

#endif // ARISTA_H
