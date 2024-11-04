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

void mostrarMenu() {
    cout << "Menu de opciones:\n";
    cout << "1. Consultar por un centro de investigacion en particular\n";
    cout << "2. Agregar un nuevo centro de investigacion\n";
    cout << "3. Eliminar un centro de investigacion\n";
    cout << "4. Mostrar todos los centros de investigacion\n";
    cout << "5. Salir\n";
}


int main() {
    Lista centros; // = new centros();
    leerCentros(centros, "../centros.txt");
    //Centro c;
    //string b = "CIT Centro de Innovacion Tecnologica Mexico 5.4 6 8 10";
    //Centro a;
    //c.setDatos("CEN", "Centro de Investigacion", "pais", 100.34, 10, 5, 3);
    //cout << c.leerArchivo();
    //cout << "Archivo leido." << endl;
    //cout << c.leerLinea() << endl;
    //cout << leerLineaNumero(3) << endl;
    //a = leerCentro( b);
    //cout << c.getDatos() << endl;
    //cout << a.getDatos() << endl;
    //c.agregarCentro("AST", "Centro de paradise", "argelia", 10.334, 15, 15, 13);
    //cout << c.getDatos() << endl;
    //system("pause");
    //cout << centros[0].getNombre() << endl;
    //cout << centros[1].getCodigo() << endl;
    //cout << centros[6].getPais() << endl;
    //cout << centros.size() << endl;
    //ordenarCentros();
    //cout << centros[0].getNombre() << endl;
    //cout << centros[1].getCodigo() << endl;
    //ordenarCentros(centros, 2);

    //centros.mostrar();

    //cout << consultarCentro("CPI", centros) << endl;
    
    //centros.alta(c, 1);
    //centros.alta(centros[1], 2);
    //centros.alta(centros[2], 3);
    //centros.alta(a, 4);

    //cout << centros.consulta(1).getNombre() << endl;
    //cout << centros.consulta(2).getNombre() << endl;
    //cout << centros.consulta(3).getNombre() << endl;
    //cout << centros.consulta(4).getNombre() << endl;

    //centros.mostrar();
//
    //centros.baja(2);
//
    //centros.mostrar();
    int opcion;
    string codigo, nombre, pais;
    float superficie;
    int laboratorios, proyectosNacionales, proyectosInternacionales, pos;

    do {
        mostrarMenu();
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        Centro c;

        switch(opcion) {
            case 1:
                cout << "Ingrese el codigo del centro a consultar: ";
                cin >> codigo;
                cout << consultarCentro(codigo, centros) << endl;
                break;

            case 2:
                cout << "Ingrese los datos del nuevo centro: " << endl;
                cout << "Codigo: ";
                cin >> codigo;
                cout << "Nombre: ";
                cin.ignore();
                getline(cin, nombre);
                cout << "Pais: ";
                cin >> pais;
                cout << "Superficie: ";
                cin >> superficie;
                cout << "Laboratorios: ";
                cin >> laboratorios;
                cout << "Proyectos nacionales: ";
                cin >> proyectosNacionales;
                cout << "Proyectos internacionales: ";
                cin >> proyectosInternacionales;
                c.setDatos(codigo, nombre, pais, superficie, laboratorios, proyectosNacionales, proyectosInternacionales);
                centros.alta(c , centros.obtener_largo()+1);
                agregarCentro(codigo, nombre, pais, superficie, laboratorios, proyectosNacionales, proyectosInternacionales, "../centros.txt");
                break;

            case 3:
                cout << "Ingrese el codigo del centro a eliminar: ";
                cin >> codigo;
                pos = buscarPosicion(centros, codigo);
                centros.baja(pos);
                eliminarCentro(codigo, "../centros.txt");
                break;

            case 4:
                centros.mostrar();
                break;

            case 5:
                cout << "Saliendo...\n";
                break;

            default:
                cout << "Opcion invalida. Por favor, intente de nuevo.\n";
                break;
        }
    } while(opcion != 5);

  return 0;
}