#include <iostream>
#include <fstream>
#include <cmath>
#include <sstream>
#include <iomanip>
#include "centro.h"
#include "lista.h"

using namespace std;

//Lista centros; // = new Lista();

//Centro::Centro(const std::string& codigo, const std::string& nombre, const std::string& pais, float superficie, int laboratorios, int proyectos_nacionales, int proyectos_internacionales) {}

Centro::Centro() {
    // Constructor por defecto
    codigo = " ";
    nombre = " ";
    pais = " ";
    superficie = 0.0;
    laboratorios = 0;
    proyectos_nacionales = 0;
    proyectos_internacionales = 0;


}

string Centro::getCodigo() const {
    return codigo;
}

string Centro::getNombre() const {
    return nombre;
}

string Centro::getPais() const {
    return pais;
}

float Centro::getSuperficie() const {
    return superficie;
}

int Centro::getLaboratorios() const {
    return laboratorios;
}

int Centro::getProyectosNacionales() const {
    return proyectos_nacionales;
}

int Centro::getProyectosInternacionales() const {
    return proyectos_internacionales;
}

string Centro::leerLinea() {

    cout << "Leyendo linea..." << endl;
    ifstream archivo("../centros.txt");
    string linea;

    if (archivo.is_open()) {
        getline(archivo, linea);
        archivo.close();
        //cout << linea << endl;
    } else {
        cerr << "No se pudo abrir el archivo centros.txt" << endl;
    }
    return linea;
}

// condiciones para agregar un centro: el nombre es de 4 palabras, el pais es de 1 palabra, la superficie es un numero flotante, los laboratorios, proyectos nacionales e internacionales son enteros
// recibe un string con los datos de un centro y devuelve un objeto de tipo Centro   
Centro leerCentro(string linea) {
    string word;
    string cod, nom, pa;
    float sup;
    int lab, pro_nac, pro_int;
    istringstream ss(linea);
    //cout <<"cent :" << ss.str() << endl;
    for (int i = 0; i <= 9; i++) {
        ss >> word;
        switch (i) {
            case 0:
                cod = word;
                break;
            case 1:
                nom = word;
                break;
            case 2:
                nom += " " + word;
                break;
            case 3:
                nom += " " + word;
                break;
            case 4:
                nom += " " + word;
                break;
            case 5:
                pa = word;
                break;
            case 6:
                sup = stof(word);
                break;
            case 7:
                lab = stoi(word);
                break;
            case 8:
                pro_nac = stoi(word);
                break;
            case 9:
                pro_int = stoi(word);
                break;
        }
        //cout << word << endl;
    }

    Centro c;
    c.setDatos(cod, nom, pa, sup, lab, pro_nac, pro_int);
    return c;
}
/*
    condiciones para cargar centros: recibe una lista vacia y la direccion del archivo con los centros en formato arcivo.txt
    y agrega los centros a la lista enlazada.
*/
void leerCentros(Lista &centros, string ruta) {
    cout << "Leyendo centros..." << endl;
    ifstream archivo(ruta);
    string linea;
    int i = 1;

    if (archivo.is_open()) {
        while (getline(archivo, linea)) {
            //centros.push_back(leerCentro(linea));
            centros.alta(leerCentro(linea), i);
            i++;
        }
        archivo.close();
    } else {
        cerr << "No se pudo abrir el archivo centros.txt" << endl;
    } 
 }

string leerLineaNumero(int n) {
    cout << "Leyendo linea " << n << "..." << endl;
    ifstream archivo("../centros.txt");
    string linea;
    int i = 0;

    if (archivo.is_open()) {
        while (i != n) {
            i++;
            getline(archivo, linea);
        }
        archivo.close();
        //cout << linea << endl;
    } else {
        cerr << "No se pudo abrir el archivo centros.txt" << endl;
    }
    return linea;
}

string Centro::leerArchivo() {
    cout << "Leyendo archivo..." << endl;
    ifstream archivo("../centros.txt");
    string texto ;

    if (archivo.is_open()) {
        string linea;
        while (getline(archivo, linea)) {
            texto += linea + "\n";
        }
        archivo.close();
        //cout << texto << endl;
    } else {
        cerr << "No se pudo abrir el archivo centros.txt" << endl;
    }
    return texto;
}

void agregarCentro(string cod= " ", string nom= " ", string pa= " ", float sup= 0.0, int lab= 0, int pro_nac= 0, int pro_int= 0, string ruta = "") {
    cout << "Centro agregado..." << endl;
    ofstream archivo(ruta, ios::app); // ios::app para agregar al final del archivo
    string linea;

    if (archivo.is_open()) {
        ostringstream ss;
        ss << fixed << setprecision(1) << sup; // redondeo a 1 decimal
        linea = cod + " " + nom + " " + pa + " " + ss.str() + " " + to_string(lab) + " " + to_string(pro_nac) + " " + to_string(pro_int);
        archivo << endl << linea ;
        archivo.close();
    } else {
        cerr << "No se pudo abrir el archivo centros.txt" << endl;
    }
    /*
    cout << "Ingrese los datos del centro de investigacion: " << endl;
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
        cin >> proyectos_nacionales;
        cout << "Proyectos internacionales: ";
        cin >> proyectos_internacionales;
    */
}

void eliminarCentro(string cod, string ruta) {
    cout << "Centro eliminado..." << endl;
    ifstream archivo(ruta);
    ofstream temp("../temp.txt");
    string linea;

    if (archivo.is_open() && temp.is_open()) {
        while (getline(archivo, linea)) {
            if (linea.substr(0, 3) != cod) {
                temp << linea << endl;
            }
        }
        archivo.close();
        temp.close();
        remove(ruta.c_str());
        rename("../temp.txt", ruta.c_str());
        
    } else {
        cerr << "No se pudo abrir el archivo centros.txt" << endl;
    }
}

void Centro::setDatos(string cod= " ", string nom= " ", string pa= " ", float sup= 0.0, int lab= 0, int pro_nac= 0, int pro_int= 0) { // valores por defecto
    codigo = cod;
    nombre = nom;
    pais = pa;
    superficie = roundf(sup * 10) / 10;
    laboratorios = lab;
    proyectos_nacionales = pro_nac;
    proyectos_internacionales = pro_int;
}

string Centro::getDatos() {
    ostringstream ss;
    ss << fixed << setprecision(1) << superficie; // redondeo a 1 decimal
    string datos = "Codigo: " + codigo + "\nNombre: " + nombre + "\nPais: " + pais + "\nSuperficie: " + ss.str() + "\nLaboratorios: " + to_string(laboratorios) + "\nProyectos nacionales: " + to_string(proyectos_nacionales) + "\nProyectos internacionales: " + to_string(proyectos_internacionales) + "\n";
    return datos;
}

int buscarPosicion(Lista centros, string codigo) {
    cout << "Buscando posicion del centro " << codigo << endl;
    int pos = 0;
    for (int i = 1; i < centros.obtener_largo()+1; i++) {
        if (centros.consulta(i).getCodigo() == codigo) {
            pos = i;
        }
    }
    return pos;
}

string consultarCentro(string cod, Lista centros) {
    cout << "Consultando centro " << cod << endl;
    string centro = "Centro no encontrado.";
    for (int i = 1; i < centros.obtener_largo()+1; i++) {
        if (centros.consulta(i).getCodigo() == cod ) {
            centro = centros.consulta(i).getDatos();
        }
    }
    return centro;
}

string consultarAtributo(Lista centros, int pos, int atributo) {
    //cout << "Consultando atributo " << atributo << " del centro " << pos << endl;
    string atributo_str = "Atributo no encontrado.";
    switch (atributo) {
        case 1:
            atributo_str = centros.consulta(pos).getCodigo();
            break;
        case 2:
            atributo_str = centros.consulta(pos).getNombre();
            break;
        case 3:
            atributo_str = centros.consulta(pos).getPais();
            break;
        case 4:
            atributo_str = to_string(centros.consulta(pos).getSuperficie());
            break;
        case 5:
            atributo_str = to_string(centros.consulta(pos).getLaboratorios());
            break;
        case 6:
            atributo_str = to_string(centros.consulta(pos).getProyectosNacionales());
            break;
        case 7:
            atributo_str = to_string(centros.consulta(pos).getProyectosInternacionales());
            break;
    }
    return atributo_str;
}

void ordenarCentros(Lista &centros, int at) {
    //cout << "Ordenando centros... :" << endl;
    // ordenar por nombre
    for (int i = 0; i < centros.obtener_largo(); i++) {
        for (int j = 0; j < centros.obtener_largo() ; j++) {
            
            // implementar un switch para ordenar por cualquier atributo
            if (consultarAtributo(centros, j, at) > consultarAtributo(centros, j+1, at)) {
                //cout << "Intercambiando " << centros.consulta(j).getCodigo() << " con " << centros.consulta(j + 1).getCodigo() << endl;
                Centro temp = centros.consulta(j);
                // aca tengo que hacer un intercambio de los nodos en la lista entre j y j+1 
                //cout << temp.getCodigo() << endl;
                //centros.consulta(j) = centros.consulta(j + 1);
                //centros.consulta(j + 1) = temp;
                centros.baja(j);
                centros.alta(temp, j + 1);
            }
            //cout << "Intercambiados " << centros.consulta(j).getCodigo() << " con " << centros.consulta(j + 1).getCodigo() << endl;

        }
    }
}
