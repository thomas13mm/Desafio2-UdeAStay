#ifndef DATA_H
#define DATA_H

#include <iostream>
#include <fstream>
#include <string>
#include "huesped.h"
#include "alojamiento.h"
#include "reservaciones.h"

using namespace std;

template <typename T>
void CargarObjetos(const string& fileName, T* ptrK, const unsigned int& columnas);

template <typename T>
T* CargarData(const unsigned int& columnas, const string& name) {
    T* ArrObjects = new T[columnas];
    CargarObjetos(name, ArrObjects, columnas);
    return ArrObjects;
}

void CargarObjetos(const string& fileName, Huesped* ptrK, const unsigned int& columnas) {
    ifstream Informacion(fileName);
    if (!Informacion.is_open()) {
        cout << "Error: No se pudo leer el archivo" << endl;
        return;
    }

    string temp, doc, nombre, reservaciones;
    unsigned short int antiguedad;
    float puntuacion;
    unsigned int i = 0;
    unsigned short int cast = 4;
    char c;

    while (Informacion.get(c)) {
        if (c == ',') {
            if (!temp.empty() && i < columnas) {
                switch (cast) {
                case 1: puntuacion = stof(temp); break;
                case 2: antiguedad = static_cast<unsigned short>(stoi(temp)); cast--; break;
                case 3: nombre = temp; cast--; break;
                default: doc = temp; cast--; break;
                }
                temp = "";
            }
        } else if (c == '\n') {
            if (!temp.empty() && i < columnas) {
                reservaciones = temp;
                temp = "";
                ptrK[i] = Huesped(doc, nombre, antiguedad, puntuacion, reservaciones);
                i++;
                cast = 4;
            }
        } else {
            temp += c;
        }
    }

    Informacion.close();
}


void CargarObjetos(const string& fileName, Alojamiento* ptrK, const unsigned int& columnas) {
    ifstream Informacion(fileName);
    if (!Informacion.is_open()) {
        cout << "Error: No se pudo leer el archivo" << endl;
        return;
    }

    string temp;
    string CodigoInmueble, Nombre, Amenidades, Direccion, municipio, departamento, tipo;
    unsigned int i = 0;
    unsigned short int cast = 7;
    char c;

    while (Informacion.get(c)) {
        if (c == ',') {
            if (!temp.empty() && i < columnas) {
                switch (cast) {
                case 1: CodigoInmueble = temp; break;
                case 2: Nombre = temp; break;
                case 3: Amenidades = temp; break;
                case 4: Direccion = temp; break;
                case 5: municipio = temp; break;
                case 6: departamento = temp; break;
                default: tipo = temp; break;
                }
                cast--;
                temp = "";
            }
        } else if (c == '\n' || c == '$') {
            if (!temp.empty() && i < columnas) {
                float ValorNoche = stof(temp);
                temp = "";
                ptrK[i] = Alojamiento(Nombre, CodigoInmueble, departamento, municipio, tipo, Direccion, ValorNoche, Amenidades);
                i++;
                cast = 7;
            }
        } else {
            temp += c;
        }
    }

    Informacion.close();
}


void CargarObjetos(const string& fileName, Reservacion* ptrK, const unsigned int& columnas) {
    ifstream Informacion(fileName);
    if (!Informacion.is_open()) {
        cout << "Error: No se pudo leer el archivo" << endl;
        return;
    }

    string temp;
    string Codigo_Inmueble, FechaPago, MetodoPago, fecha_entrada, CodigoReserva;
    unsigned int i = 0;
    unsigned short int cast = 5;
    char c;

    while (Informacion.get(c)) {
        if (c == ',') {
            if (!temp.empty() && i < columnas) {
                switch (cast) {
                case 1: FechaPago = temp; break;
                case 2: MetodoPago = temp; break;
                case 3: fecha_entrada = temp; break;
                case 4: Codigo_Inmueble = temp; break;
                default: CodigoReserva = temp; break;
                }
                cast--;
                temp = "";
            }
        } else if (c == '\n' || c == '$') {
            if (!temp.empty() && i < columnas) {
                float Valor = stof(temp);
                temp = "";
                ptrK[i] = Reservacion(CodigoReserva, Codigo_Inmueble, nullptr, fecha_entrada, 1, MetodoPago, Valor, " ");


                i++;
                cast = 5;
            }
        } else {
            temp += c;
        }
    }

    Informacion.close();
}


bool Pertenece(string**& matriz, const string& doc, const unsigned int& filas, unsigned int& i) {
    for (i = 0; i < filas; ++i) {
        if (matriz[i][0] == doc) {
            return true;
        }
    }
    i = 0;
    return false;
}

#endif // DATA_H
