#ifndef DATA_H
#define DATA_H

#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include"alojamiento.h"
#include"reservaciones.h"

using namespace std;

Alojamiento* CargarObjetos(const string fileName, const unsigned int &CantidadAlojamientos, unsigned short int &i) {


    ifstream Informacion(fileName);
    if (!Informacion.is_open()) {
        cout << "Error: No se pudo leer el archivo";
        return nullptr;
    }
    Alojamiento* ptrK = new Alojamiento[CantidadAlojamientos];

    string temp = "";
    string Amenidades;
    string Nombre;
    string municipio;
    string departamento;
    string tipo;
    string Direccion;
    string CodigoInmueble;
    float ValorNoche;
    unsigned short int cast= 7;
    char c;

    while (Informacion.get(c)) {

        if (c == ',' || c=='$') {
            if (!temp.empty() && cast >= 1 ) {
                switch (cast) {
                case 1:
                    CodigoInmueble = temp;
                    cast--;
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
        } else if (c == '\n') {
            if (!temp.empty() ) {
                ValorNoche = stof(temp);
                temp = "";
                ptrK[i]=Alojamiento(Nombre,CodigoInmueble,departamento,municipio,tipo,Direccion,ValorNoche,Amenidades);
                i++;
                cast=7;
            }
        } else {
            temp += c;
        }
    }
    if (!temp.empty()) {
        ValorNoche = stof(temp);
        ptrK[i] = Alojamiento(Nombre, CodigoInmueble, departamento, municipio, tipo, Direccion, ValorNoche, Amenidades);
    }
    i++;
    Informacion.close();
    return ptrK;
}

Reservacion* CargarObjetos(const string fileName, const unsigned int &CantidadReservaciones, unsigned short int &ReservacionesValidas, Alojamiento* Alojamientos){

    ifstream Informacion(fileName);
    if (!Informacion.is_open()) {
        cout << "Error: No se pudo leer el archivo";
        return nullptr;
    }
    Reservacion* ptrK = new Reservacion[CantidadReservaciones];

    string temp = "";
    string CodigoReserva;
    Alojamiento* AlojamientoReservado;
    Fecha FechaEntrada;
    unsigned short int Duracion;
    string MetodoPay;
    Fecha FechaPago;
    float montoCancelado;
    string Anotaciones;

    unsigned int i = 0;
    unsigned short int cast= 7;
    char c;

    while (Informacion.get(c)) {

        if (c == ',') {
            if (!temp.empty() && cast >= 1 ) {
                switch (cast) {
                case 1:
                    montoCancelado = stof(temp);
                    cast--;
                    break;
                case 2:
                    FechaPago =temp;
                    cast--;
                    break;
                case 3:
                    MetodoPay =temp ;
                    cast--;
                    break;
                case 4:{
                    stringstream ss(temp);
                    ss>>Duracion;
                    cast--;
                    break;
                }
                case 5:
                    FechaEntrada=temp;
                    cast--;
                    break;
                case 6:
                    for(unsigned int i =0; i<ReservacionesValidas; i++){
                        if((Alojamientos[i].getCodigoAlojamiento()) == temp){
                            AlojamientoReservado= &Alojamientos[i];
                            break;
                        }
                        else{
                            AlojamientoReservado=nullptr;
                        }
                    }
                    cast--;
                    break;
                default:
                    CodigoReserva=temp;
                    cast--;
                    break;
                }
                temp = "";
            }
        } else if (c == '\n') {
            if (!temp.empty() ) {
                Anotaciones = temp;
                temp = "";
                ptrK[i]=Reservacion(CodigoReserva,AlojamientoReservado,FechaEntrada,Duracion,MetodoPay,montoCancelado,Anotaciones);
                i++;
                cast=7;
            }
        } else {
            temp += c;
        }
    }
    if (!temp.empty()) {
        Anotaciones = temp;
        ptrK[i] =  Reservacion(CodigoReserva,AlojamientoReservado,FechaEntrada,Duracion,MetodoPay,montoCancelado,Anotaciones);
    }

    Informacion.close();
    return ptrK;
}

#endif
