
#ifndef CENTROS_H // directiva de preprocesamiento para evitar que se incluya el archivo más de una vez
#define CENTROS_H // defino la macro CENTROS_H para que no de error al compilar

#include <string>
#include <fstream>
#include <iostream>

using namespace std;

class Centro {
private:
    string codigo;
    string nombre;
    string pais;
    float superficie;
    int laboratorios;
    int proyectos_nacionales;
    int proyectos_internacionales;

public:
    Centro();
    string getCodigo();
    void setCodigo(string cod);
    string getNombre();
    string getPais();
    float getSuperficie();
    int getLaboratorios();
    int getProyectosNacionales();
    int getProyectosInternacionales();
    string leerArchivo();
    string leerLinea();
    string leerLineaNumero(int n); // leer la linea n del archivo
    Centro leerCentro(string linea);
    void agregarCentro(string cod, string nom, string pa, float sup, int lab, int pro_nac, int pro_int);
    void setDatos(string cod, string nom, string pa, float sup, int lab, int pro_nac, int pro_int);
    string getDatos();
    void leerCentros();
    string consultarCentro(string cod);

    void ordenarCentros();
};

#endif // CENTROS_H // para que no se repita el codigo en el archivo evita errores de compilacion
