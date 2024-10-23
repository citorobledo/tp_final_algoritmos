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

// Función para leer proyectos desde un archivo
vector<Proyecto> leerProyectos(const string& filename) {
    vector<Proyecto> proyectos;
    ifstream archivo(filename);
    string linea;

    if (archivo.is_open()) {
        while (getline(archivo, linea)) {
            string cod_origen, cod_destino;
            float costo, duracion;
            istringstream ss(linea);
            ss >> cod_origen >> cod_destino >> costo >> duracion;

            Proyecto p; // Crear objeto de Proyecto usando el constructor por defecto
            p.setDatos(cod_origen, cod_destino, costo, duracion); // Establecer los datos
            proyectos.push_back(p);
        }
        archivo.close();
    } else {
        cerr << "No se pudo abrir el archivo " << filename << endl;
    }

    return proyectos;
}

// Función para agregar un proyecto
void Proyecto::agregarProyecto(const Proyecto& proyecto) {
    ofstream archivo("proyectos.txt", ios::app);
    if (archivo.is_open()) {
         if (archivo.tellp() != 0) { 
            archivo << endl; // Agregar un salto de línea si ya hay contenido
        }
        archivo << proyecto.getCodigoOrigen() << " "
                << proyecto.getCodigoDestino() << " "
                << proyecto.getCosto() << " "
                << proyecto.getDuracion() << endl;
        archivo.close();
    } else {
        cerr << "No se pudo abrir el archivo para agregar el proyecto." << endl;
    }
}