#include <iostream>
#include <fstream>
#include <cmath>
#include "centro.h"

using namespace std;

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

string Centro::leerLineaNumero(int n) {
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

void Centro::agregarCentro() {
    cout << "Agregando centro..." << endl;
    ofstream archivo("../centros.txt", ios::app);
    string linea;

    if (archivo.is_open()) {
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

        linea = codigo + " " + nombre + " " + pais + " " + to_string (superficie) + " " + to_string(laboratorios) + " " + to_string(proyectos_nacionales) + " " + to_string(proyectos_internacionales);
        archivo << endl << linea ;
        archivo.close();
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
    string datos = "Codigo: " + codigo + "\nNombre: " + nombre + "\nPais: " + pais + "\nSuperficie: " + to_string(superficie) + "\nLaboratorios: " + to_string(laboratorios) + "\nProyectos nacionales: " + to_string(proyectos_nacionales) + "\nProyectos internacionales: " + to_string(proyectos_internacionales) + "\n";
    return datos;
}