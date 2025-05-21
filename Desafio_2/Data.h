#ifndef DATA_H
#define DATA_H

#include<iostream>
#include<fstream>
#include<string>


using namespace std;

void CargarMatriz(string fileName, string** ptrK, const unsigned int &filas, const unsigned int &columnas);
string** CargarData(const unsigned int &filas, const unsigned int &columnas, string name);

string** CargarData(const unsigned int &filas, const unsigned int &columnas, string name) {
    /*
    Sinopsis:
        Funcion encargada de crear una matriz parcialmente dinamica de strings
    param:
        -(const unsigned int)filas: variable que almacena la cantidad de filas que va tener la matriz
        -(const unsigned int)columnas: cantidad de columnas de la matriz
        -(string)name: nombre del archivo que contiene la data
*/
    string** matx = new string*[filas];
    for (unsigned int i = 0; i < filas; i++) {
        matx[i] = new string[columnas];
    }
    CargarMatriz(name, matx, filas, columnas);
    return matx;
}

void CargarMatriz(const string fileName, string** ptrK, const unsigned int &filas, const unsigned int &columnas) {
    /*
    Sinopsis:
        Funcion encargada de cargar la estructura de datos llenando una matriz dinamica
    Param:
        -(const string)fileName: nombre del archivo
        -(string**)ptrK: Apuntador la matriz
        -(const unsigned int)filas: numero de filas de la matriz
        -(const unsigned int)columnas: numero de columnas de la matriz
*/

    ifstream Informacion(fileName);
    if (!Informacion.is_open()) {
        cout << "Error: No se pudo leer el archivo";
        return;
    }

    string temp = "";
    unsigned int i = 0, j = 0;
    char c;

    while (Informacion.get(c)) {

        if (c == ',') {
            if (!temp.empty() && i < filas && j < columnas) {
                ptrK[i][j] = temp;
                temp = "";
                ++j;
                if (j == columnas) {
                    j = 0;
                    ++i;
                }
            }
        } else if (c == '\n') {
            if (!temp.empty() && i < filas && j < columnas) {
                ptrK[i][j] = temp;
                temp = "";
                ++i;
                j = 0;
            }
        } else {
            temp += c;
        }
    }

    if (!temp.empty() && i < filas && j < columnas) {
        ptrK[i][j] = temp;
    }

    Informacion.close();
}

bool Pertenece(string** &matriz,string doc, const unsigned int &filas, unsigned int &i){
    for (i = 0; i < filas; ++i) {
        if (matriz[i][0] == doc) {
            return true;
        }
    }
    i = 0;
    return false;

}





#endif // DATA_H
