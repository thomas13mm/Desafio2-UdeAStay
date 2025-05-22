#ifndef DATA_H
#define DATA_H

#include<iostream>
#include<fstream>
#include<string>
#include"huesped.h"
#include"alojamiento.h"
#include"reservaciones.h"

using namespace std;


template <typename Arreglo>
void CargarObjetos(string fileName, Huesped* ptrK, const unsigned int &columnas);
void CargarObjetos(string fileName, Alojamiento* ptrK, const unsigned int &columnas);
void CargarObjetos(string fileName, Reservacion* ptrK, const unsigned int &columnas);
Huesped* CargarData(const unsigned int &columnas, string name);

Arreglo* CargarData(const unsigned int &columnas, string name) {
    /*
    Sinopsis:
        Funcion encargada de crear una matriz parcialmente dinamica de strings
    param:
        -(const unsigned int)columnas: cantidad de columnas de la matriz
        -(string)name: nombre del archivo que contiene la data
*/
    Arreglo* ArrObjects = new Arreglo*[columnas];
    CargarObjetos(name, ArrObjects, columnas);
    return ArrObjects;
}

void CargarObjetos(string fileName, Huesped* ptrK, const unsigned int &columnas) {
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
    string doc;
    string nombre;
    unsigned short int antiguedad;
    float puntuacion;
    string reservaciones;
    unsigned int i = 0;
    unsigned short int cast= 4;
    char c;

    while (Informacion.get(c)) {

        if (c == ',') {
            if (!temp.empty() && i < columnas ) {
                switch (cast) {
                case 1:
                    puntuacion = float(temp);
                    break;
                case 2:
                    antiguedad = unsigned short int(temp);
                    cast--;
                    break;
                case 3:
                    nombre = temp;
                    cast--;
                    break;
                default:
                    doc=temp;
                    cast--;
                    break;
                }
                temp = "";
            }
        } else if (c == '\n') {
            if (!temp.empty() && i < columnas) {
                reservaciones = temp;
                temp = "";
                ptrK[i]=Huesped::Huesped(doc,nombre,antiguedad,puntuacion,reservaciones);
                i++;
            }
        } else {
            temp += c;
        }
    }

    if (!temp.empty() && i < filas) {
        ptrK[i] = temp;
    }

    Informacion.close();
}

void CargarObjetos(string fileName, Alojamiento* ptrK, const unsigned int &columnas) {
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
    string doc;
    string nombre;
    unsigned short int antiguedad;
    float puntuacion;
    string reservaciones;
    unsigned int i = 0;
    unsigned short int cast= 7;
    char c;

    while (Informacion.get(c)) {

        if (c == ',') {
            if (!temp.empty() && i < columnas ) {
                switch (cast) {
                case 1:
                    CodigoInmueble = temp;
                    break;
                case 2:
                    Nombre =temp;
                    cast--;
                    break;
                case 3:
                    Amenidades =temp ;
                    cast--;
                    break;
                case 4:
                    Direccion=temp;
                    cast--;
                    break;
                case 5:
                    municipio=temp;
                    cast--;
                    break;
                case 6:
                    departamento=temp;
                    cast--;
                    break;
                default:
                    tipo=temp;
                    cast--;
                    break;
                }
                temp = "";
            }
        } else if (c == '\n' || c=='$') {
            if (!temp.empty() && i < columnas) {
                float ValorNoche = stof(temp);
                temp = "";
                ptrK[i]=Alojamiento::Alojamiento(Nombre,CodigoInmieble,departamento,municipio,tipo,Direccion,ValorNoche,Amenidades);
                i++;
            }
        } else {
            temp += c;
        }
    }

    Informacion.close();
}

void CargarObjetos(string fileName, Reservacion* ptrK, const unsigned int &columnas){
    ifstream Informacion(fileName);
    if (!Informacion.is_open()) {
        cout << "Error: No se pudo leer el archivo";
        return;
    }

    string temp = "";
    string doc;
    string nombre;
    unsigned short int antiguedad;
    float puntuacion;
    string reservaciones;
    unsigned int i = 0;
    unsigned short int cast= 7;
    char c;

    while (Informacion.get(c)) {

        if (c == ',') {
            if (!temp.empty() && i < columnas ) {
                switch (cast) {
                case 1:
                    FechaPago = temp;
                    break;
                case 2:
                    MetodoPago =temp;
                    cast--;
                    break;
                case 3:
                    fecha_entrada=temp ;
                    cast--;
                    break;
                case 4:
                    Codigo_Inmueble=temp.to_string;
                    cast--;
                    break;
                default:
                    CodigoReserva=temp.to_string();
                    cast--;
                    break;
                }
                temp = "";
            }
        } else if (c == '\n' || c=='$') {
            if (!temp.empty() && i < columnas) {
                float ValorNoche = stof(temp);
                temp = "";
                ptrK[i]=Alojamiento::Alojamiento(Nombre,CodigoInmieble,departamento,municipio,tipo,Direccion,ValorNoche,Amenidades);
                i++;
            }
        } else {
            temp += c;
        }
    }

    Informacion.close();
}

bool Pertenece(string** &matriz,string doc, const unsigned int &filas, unsigned int &i){
    for (i = 0; i < filas; ++i) {
        if (matriz[i].get == doc) {
            return true;
        }
    }
    i = 0;
    return false;

}





#endif // DATA_H
