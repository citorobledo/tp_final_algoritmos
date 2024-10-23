#include <iostream>
#include "centro.h"
#include "centro.cpp"
#include "proyecto.h"
#include "proyectos.cpp"

using namespace std;

int main() {
    Centro c;
    Centro a;
    c.setDatos("CEN", "Centro de Investigacion", "pais", 100.34, 10, 5, 3);
    cout << c.leerArchivo();
    cout << "Archivo leido." << endl;
    cout << c.leerLinea() << endl;
    cout << c.leerLineaNumero(3) << endl;
    a = leerCentro(c.leerLineaNumero(1));
    cout << a.getDatos() << endl;
    //c.agregarCentro("AST", "Centro de paradise", "argelia", 10.334, 15, 15, 13);
    //cout << c.getDatos() << endl;
    //system("pause");

    // Leer proyectos existentes
    vector<Proyecto> proyectos = leerProyectos("proyectos.txt");
    cout << "Proyectos de Colaboracion:" << endl;

    // Mostrar detalles de los proyectos
    for (const Proyecto& proy : proyectos) {
        cout << "Origen: " << proy.getCodigoOrigen() 
             << ", Destino: " << proy.getCodigoDestino()
             << ", Costo: " << proy.getCosto() 
             << ", Duracion: " << proy.getDuracion() << endl;
    }

    // Solicitar detalles del nuevo proyecto al usuario
    string codigoOrigen, codigoDestino;
    float costo, duracion;

    cout << "Ingrese el codigo del centro de origen: ";
    cin >> codigoOrigen;
    cout << "Ingrese el codigo del centro de destino: ";
    cin >> codigoDestino;
    cout << "Ingrese el costo: ";
    cin >> costo;
    cout << "Ingrese la duracion: ";
    cin >> duracion;

    // Crear un nuevo proyecto y agregarlo
    Proyecto nuevoProyecto;
    nuevoProyecto.setDatos(codigoOrigen, codigoDestino, costo, duracion);
    nuevoProyecto.agregarProyecto(nuevoProyecto);

    cout << "Proyecto agregado." << endl;

    return 0;
}