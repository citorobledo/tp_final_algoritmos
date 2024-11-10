#ifndef ARISTA_H
#define ARISTA_H

#include "Vertice.h"  

class Arista {
private:
    Vertice* origen;  
    Vertice* destino; 
    int costoDeViaje;
    double horasViaje;

public:
    // Constructor de la clase Arista
    Arista(Vertice* src, Vertice* dest, int w, double h);

    // Getters para acceder a los atributos
    Vertice* getOrigen() const { return origen; }  
    Vertice* getDestino() const { return destino; }  
    int getCosto() const { return costoDeViaje; }
    double getDuracion() const { return horasViaje; }
};

#endif // ARISTA_H