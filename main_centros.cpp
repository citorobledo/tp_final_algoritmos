#include <iostream>
#include "centro.h"
#include "centro.cpp"
#include "proyecto.h"
#include "proyectos.cpp"
#include "lista.h"
#include "nodo.h"
#include "nodo.cpp"
#include "lista.cpp"
#include <vector>

using namespace std;



int main() {
    //Centro centros;
    Lista centros; // = new Lista();
    
    Centro c;
    string b = "CIT Centro de Innovacion Tecnologica Mexico 5.4 6 8 10";
    Centro a;
    c.setDatos("CEN", "Centro de Investigacion", "pais", 100.34, 10, 5, 3);
    cout << c.leerArchivo();
    cout << "Archivo leido." << endl;
    cout << c.leerLinea() << endl;
    cout << leerLineaNumero(3) << endl;
    a = leerCentro( b);
    cout << c.getDatos() << endl;
    cout << a.getDatos() << endl;
    //c.agregarCentro("AST", "Centro de paradise", "argelia", 10.334, 15, 15, 13);
    //cout << c.getDatos() << endl;
    //system("pause");
    leerCentros(centros, "../centros.txt");
    //cout << centros[0].getNombre() << endl;
    //cout << centros[1].getCodigo() << endl;
    //cout << centros[6].getPais() << endl;
    //cout << centros.size() << endl;
    //ordenarCentros();
    //cout << centros[0].getNombre() << endl;
    //cout << centros[1].getCodigo() << endl;
    centros.mostrar();

    ordenarCentros(centros, 2);

    centros.mostrar();

    //cout << consultarCentro("CPI", centros) << endl;

    //Lista lista;
    //lista.alta(centros[0], 1);
    //lista.alta(centros[1], 2);
    //lista.alta(centros[2], 3);
    //lista.alta(a, 4);

    //cout << lista.consulta(1).getNombre() << endl;
    //cout << lista.consulta(2).getNombre() << endl;
    //cout << lista.consulta(3).getNombre() << endl;
    //cout << lista.consulta(4).getNombre() << endl;

    //lista.mostrar();
//
    //lista.baja(2);
//
    //lista.mostrar();

    centros.obtener_largo();


  return 0;
}