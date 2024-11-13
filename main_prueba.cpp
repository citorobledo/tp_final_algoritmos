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

//int hashFunction(string key, int table) {
//    int hash = 0;
//    for (char ch : key) {
//        //hash = (31 * hash + ch) % table.size();
//        hash += ch;
//    }
//    return (hash % table);
//}
//
//int quadraticProbing(int hash, int i, int table) { 
//    if ((hash + i * i) % table == 0) {
//        return 1;
//    }
//    
//    return ((hash + i * i) % table);
//    }

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
    //leerCentros(centros, "centros.txt");

    double loadFactor = 0.7;
    int capacity = centros.obtener_largo() / loadFactor;//implementar el proximo primo para calcular la capacidad
   


    Lista table ; // lista indexada pos hash
    for (int i = 1; i <= capacity; i++) {
        Centro *c = new Centro();
        table.alta(*c, i);
    }

    for (int i = 1; i <= centros.obtener_largo(); i++) {
        guardar_centro(centros.consulta(i), table);
    }
    


   //for (int i = 1; i <= centros.obtener_largo(); i++) {
   //    int hash = hashFunction(centros.consulta(i).getCodigo(), table.obtener_largo()) +1;
   //    if(!table.pos_ocupada(hash)){
   //        table.alta(centros.consulta(i), hash);
   //    }
   //    else
   //    {
   //        cout << "Colision en la posicion " << hash << endl;
   //        int j = 1;
   //        do {
   //            int colision = quadraticProbing(hash, j, table.obtener_largo());
   //            if(!table.pos_ocupada(colision)){
   //                table.alta(centros.consulta(i), colision);
   //                break;
   //            }
   //            cout << "Colision en la posicion " << colision << endl;
   //            j++;
   //        }
   //        while (j <= table.obtener_largo());
   //    }
   //}

    //guardar_centro(centros.consulta(1), table);
    //cout << buscar_centro("CAN", table).getDatos() << endl;
    


    //Centro c = Centro();
    //Centro c1 = Centro(); 
    //Centro c2 = Centro();
    //Centro c3 = Centro();
    //c.setDatos("CSI", "Centro Cientifico de Innovacion", "España", 12.5, 15, 23, 12);
    //c1.setDatos("2", "Centro 2", "Brasil", 200.0, 20, 10, 6);
    //c2.setDatos("3", "Centro 3", "Argentina", 300.0, 30, 15, 9);
    //c3.setDatos("LAT", "Laboratorio Avanzado de Tecnologia", "Brasil", 8.7, 8, 12, 18);
//
//
   //
   // // Insertar elementos de ejemplo
   // int hash2 = hashFunction(c.getCodigo(), table.obtener_largo());
   // table.alta(c, quadraticProbing(hash2, 0, table.obtener_largo())); // inserta el centro c en la posicion 1 de la lista l
   // table.alta(c1, 2);
   // table.alta(c2, 4);
   // int hash = hashFunction(c3.getCodigo(), table.obtener_largo());
   // table.alta(c3, quadraticProbing(hash, 1, table.obtener_largo()));
//
   // table.obtener_largo();
   // int pos = 1;
    
    //table.baja(3);
    //table.mostrar();


    //Lista centros; // = new centros();
    
//
    //leerCentros(centros, "../centros.txt");
    Centro c;
    string codigo, nombre, pais;
    float superficie;
    int laboratorios, proyectosNacionales, proyectosInternacionales, pos, atributo, opcion;
    Lista table2 = table.clonar();

    do {
        mostrarMenu();
        cout << "Seleccione una opcion: " ;
        cin >> opcion;

        switch(opcion) {
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
                cout << "Ingrese el codigo del centro a eliminar: ";
                cin >> codigo;
                //pos = centros.buscarPosicion(codigo);
                borrar_centro(codigo, table);
                cout << "eliminado " << endl;
                break;

            case 4:
                table.mostrar();
                break;  

            case 5:
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
                break;// fin case 5

            case 6:
                cout << "Saliendo...\n";
                break;

            default:
                cout << "Opcion invalida. Por favor, intente de nuevo.\n";
                break;
        }// fin switch opcion
    } while(opcion != 6);
    system("pause");

  return 0;
}
