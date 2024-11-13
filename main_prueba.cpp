#include <iostream>
#include "lista.h"
#include "lista.cpp"
#include "centro.h"
#include "centro.cpp"
#include "nodo.h"
#include "nodo.cpp"
#include "hash.h"
#include "hash.cpp"

using namespace std;

void mostrarMenu()
{
    cout << "\n Menu de opciones:\n" << endl;
    cout << "1. Consultar por un centro de investigacion en particular\n";
    cout << "2. Agregar un nuevo centro de investigacion\n";
    cout << "3. Eliminar un centro de investigacion\n";
    cout << "4. Mostrar todos los centros de investigacion\n";
    cout << "5. Ordenar centros\n";
    cout << "6. Salir\n";
}

void menuOrden()
{
    cout << "\n Opciones de orden :\n" << endl;
    cout << "1. Codigo\n";
    cout << "2. Nombre\n";
    cout << "3. Pais\n";
    cout << "4. Superficie\n";
    cout << "5. Laboratorios\n";
    cout << "6. Proyectos nacionales\n";
    cout << "7. Proyectos internacionales\n";
    cout << "Seleccione el atributo por el cual desea ordenar los centros: ";
}

int main()
{

    Lista centros; // = new centros();

    leerCentros(centros, "../centros.txt");
    // leerCentros(centros, "centros.txt");

    double loadFactor = 0.7;
    int capacity = centros.obtener_largo() / loadFactor; // implementar el proximo primo para calcular la capacidad

    Lista table; // lista indexada pos hash
    for (int i = 1; i <= capacity; i++)
    {
        Centro *c = new Centro();
        table.alta(*c, i);
    }

    for (int i = 1; i <= centros.obtener_largo(); i++)
    {
        guardar_centro(centros.consulta(i), table);
    }

    Centro c;
    string codigo, nombre, pais;
    float superficie;
    int laboratorios, proyectosNacionales, proyectosInternacionales, atributo, opcion;
    Lista table2 = table.clonar();

    do
    {
        mostrarMenu();
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            cout << "Ingrese el codigo del centro a consultar: ";
            cin >> codigo;
            cout << buscar_centro(codigo, table) << endl;
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
            guardar_centro(c, table);
            cout << "Centro agregado.\n";
            break;

        case 3:
            cout << "Ingrese el codigo del centro a eliminar : ";
            cin >> codigo;
            borrar_centro(codigo, table);
            cout << "eliminado " << endl;
            break;

        case 4:
            cout << "Centros : " << endl;
            table.mostrar();
            break;

        case 5:
            menuOrden();

            cin >> atributo;

            switch (atributo)
            {
            case 1:
                cout << "Ordenando por codigo...\n";

                table2.ordenarCentros(1);
                table2.mostrar();
                break;
            case 2:
                cout << "Ordenando por nombre...\n";
                table2.ordenarCentros(2);
                table2.mostrar();
                break;
            case 3:
                cout << "Ordenando por pais...\n";
                table2.ordenarCentros(3);
                table2.mostrar();
                break;
            case 4:
                cout << "Ordenando por superficie...\n";
                table2.ordenarCentros(4);
                table2.mostrar();
                break;
            case 5:
                cout << "Ordenando por laboratorios...\n";
                table2.ordenarCentros(5);
                table2.mostrar();
                break;
            case 6:
                cout << "Ordenando por proyectos nacionales...\n";
                table2.ordenarCentros(6);
                table2.mostrar();
                break;
            case 7:
                cout << "Ordenando por proyectos internacionales...\n";
                table2.ordenarCentros(7);
                table2.mostrar();
                break;
            default:
                cout << "ingrese una opcion correcta\n";
                break;
            }
            break; // fin case 5

        case 6:
            cout << "Saliendo...\n";
            exit(EXIT_SUCCESS);
            break;

        default:
            cout << "Opcion invalida. Por favor, intente de nuevo.\n";
            break;
        } // fin switch opcion
    } while (opcion != 6);
    return 0;
}
