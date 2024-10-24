#include <iostream>
#include <fstream>
#include <cmath>
#include <sstream>
#include <iomanip>
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

void Centro::agregarCentro(string cod= " ", string nom= " ", string pa= " ", float sup= 0.0, int lab= 0, int pro_nac= 0, int pro_int= 0) {
    cout << "Agregando centro..." << endl;
    ofstream archivo("../centros.txt", ios::app); // ios::app para agregar al final del archivo
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

Centro leerCentro(string linea) {
    string word;
    string cod, nom, pa;
    float sup;
    int lab, pro_nac, pro_int;
    istringstream ss(linea);
    cout <<"cent :" << ss.str() << endl;
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