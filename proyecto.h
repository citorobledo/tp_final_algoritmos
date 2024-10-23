#ifndef PROYECTO_H // directiva de preprocesamiento para evitar que se incluya el archivo más de una vez
#define PROYECTO_H // defino la macro PROYECTO_H para que no de error al compilar

#include <string>

using namespace std;

class Proyecto {
private:
    string codigo_origen;
    string codigo_destino;
    float costo;
    float duracion;

public:
    Proyecto(); // Constructor por defecto
    void setDatos(string cod_origen, string cod_destino, float cost, float dur); // Método para establecer los datos
    string getCodigoOrigen() const;
    string getCodigoDestino() const;
    float getCosto() const;
    float getDuracion() const;
    void agregarProyecto(const Proyecto& proyecto);
};

#endif // PROYECTO_H