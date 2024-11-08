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
    cout << "5. Ordenar centros\n";
    cout << "6. Salir\n";
}


int main() {
    Lista centros; // = new centros();
    leerCentros(centros, "../centros.txt");
    
    int opcion;
    string codigo, nombre, pais;
    float superficie;
    int laboratorios, proyectosNacionales, proyectosInternacionales, pos;

    do {
        mostrarMenu();
        cout << "Seleccione una opcion: " ;
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
                int atributo;
                cout << "Opciones" << endl;
                cout << "1. Codigo\n";
                cout << "2. Nombre\n";
                cout << "3. Pais\n";
                cout << "4. Superficie\n";
                cout << "5. Laboratorios\n";
                cout << "6. Proyectos nacionales\n";
                cout << "7. Proyectos internacionales\n";
                cout << "Seleccione el atributo por el cual desea ordenar los centros: ";
                
                cin >> atributo;
                switch (atributo)
                {
                case 1:
                    cout << "Ordenando por codigo...\n";
                    ordenarCentros(centros, 1);
                    break;
                case 2:
                    cout << "Ordenando por nombre...\n";
                    ordenarCentros(centros, 2);
                    break;
                case 3:
                    cout << "Ordenando por pais...\n";
                    ordenarCentros(centros, 3);
                    break;
                case 4:
                    cout << "Ordenando por superficie...\n";
                    ordenarCentros(centros, 4);
                    break;
                case 5:
                    cout << "Ordenando por laboratorios...\n";
                    ordenarCentros(centros, 5);
                    break;
                case 6:
                    cout << "Ordenando por proyectos nacionales...\n";
                    ordenarCentros(centros, 6);
                    break;
                case 7:
                    cout << "Ordenando por proyectos internacionales...\n";
                    ordenarCentros(centros, 7);
                    break;
                default:
                    break;
                }
                break;

            case 6:
                cout << "Saliendo...\n";
                break;

            default:
                cout << "Opcion invalida. Por favor, intente de nuevo.\n";
                break;
        }
    } while(opcion != 6);
    system("pause");

  return 0;
}