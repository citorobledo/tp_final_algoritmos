


/*

Centros de Investigación
La información sobre los centros de investigación estará almacenada en un archivo de texto llamado
centros.txt, que deberá ser leído al iniciar la aplicación.
En cada línea del archivo estará la información de un centro de investigación, separada por
espacios:

- código (tres letras que identifican a cada centro),
- nombre del centro,
- ciudad y país donde se encuentra,
- superficie del centro en kilómetros cuadrados (número flotante),
- #laboratorios (cantidad de laboratorios con los que cuenta),
- #proyectos_nacionales (cantidad de proyectos nacionales que maneja),
- #proyectos_internacionales (cantidad de proyectos internacionales que maneja).

## Menú de Opciones

La aplicación deberá mostrar un menú que permita al usuario realizar las siguientes acciones:

- Consultar por un centro de investigación en particular.
- Agregar un nuevo centro de investigación.
- Eliminar un centro de investigación.
- Mostrar todos los centros de investigación (ordenados por cualquiera de los atributos: nombre, país, superficie, etc.).

## Consideraciones:
- El archivo estará bien formado.
- La implementación deberá usar una tabla de hashing para almacenar y gestionar los centros de investigación.
- Se debe diseñar una función de hashing que asegure una buena dispersión de los datos.
*/

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
