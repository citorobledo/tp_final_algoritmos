#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "proyecto.h"

using namespace std;

// Constructor por defecto
Proyecto::Proyecto() : costo(0.0), duracion(0.0) {}

// Método para establecer los datos
void Proyecto::setDatos(string cod_origen, string cod_destino, float cost, float dur) {
    codigo_origen = cod_origen;
    codigo_destino = cod_destino;
    costo = cost;
    duracion = dur;
}

string Proyecto::getCodigoOrigen() const {
    return codigo_origen;
}

string Proyecto::getCodigoDestino() const {
    return codigo_destino;
}

float Proyecto::getCosto() const {
    return costo;
}

float Proyecto::getDuracion() const {
    return duracion;
}