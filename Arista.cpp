#include "Arista.h"

// Implementación del constructor de la clase Aristas
Arista::Arista(Vertice* src, Vertice* dest, int w, double h)
    : origen(src), destino(dest), costoDeViaje(w), horasViaje(h) {
}