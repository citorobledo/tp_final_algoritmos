


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
*/

#ifndef CENTROS_H // directiva de preprocesamiento para evitar que se incluya el archivo más de una vez
#define CENTROS_H // defino la macro CENTROS_H para que no de error al compilar

#include <string>
#include <fstream>
#include <iostream>

using namespace std;

class Centro {
public:
    Centro();
    void leerArchivo();
};

#endif // CENTROS_H // para que no se repita el codigo en el archivo evita errores de compilacion
