#include "Alojamiento.h"
#include <cstring>
#include <iostream>

// Constructor
Alojamiento::Alojamiento(const string& nombre, char codigo, Anfitrion* anfitrion,
                         const string& departamento, const string& municipio,
                         const string& tipo, const string& direccion, float precio) :
    nombre(nombre),
    codigo(codigo),
    anfitrion(anfitrion),
    departamento(departamento),
    municipio(municipio),
    tipo(tipo),
    direccion(direccion),
    precioPorNoche(precio),
    cantidadAmenidades(0),
    capacidadAmenidades(5),
    cantidadReservaciones(0),
    capacidadReservaciones(10)
{
    amenidades = new string[capacidadAmenidades];
    reservaciones = new Reservacion*[capacidadReservaciones];
}

// Destructor
Alojamiento::~Alojamiento() {
    delete[] amenidades;

    for (int i = 0; i < cantidadReservaciones; ++i) {
        delete reservaciones[i];
    }
    delete[] reservaciones;
}

void Alojamiento::expandirAmenidades() {
    capacidadAmenidades *= 2;
    string* nuevoArray = new string[capacidadAmenidades];

    for (int i = 0; i < cantidadAmenidades; ++i) {
        nuevoArray[i] = amenidades[i];
    }

    delete[] amenidades;
    amenidades = nuevoArray;
}

void Alojamiento::expandirReservaciones() {
    capacidadReservaciones *= 2;
    Reservacion** nuevoArray = new Reservacion*[capacidadReservaciones];

    for (int i = 0; i < cantidadReservaciones; ++i) {
        nuevoArray[i] = reservaciones[i];
    }

    delete[] reservaciones;
    reservaciones = nuevoArray;
}

void Alojamiento::agregarAmenidad(const string& amenidad) {
    if (cantidadAmenidades == capacidadAmenidades) {
        expandirAmenidades();
    }
    amenidades[cantidadAmenidades++] = amenidad;
}

bool Alojamiento::mostrarDisponibilidad(Fecha inicio, Fecha fin) {
    for (int i = 0; i < cantidadReservaciones; ++i) {
        if (reservaciones[i]->hayConflicto(inicio, fin)) {
            return false;
        }
    }
    return true;
}

void Alojamiento::agregarReservacion(Reservacion* r) {
    if (cantidadReservaciones == capacidadReservaciones) {
        expandirReservaciones();
    }
    reservaciones[cantidadReservaciones++] = r;
}

bool Alojamiento::eliminarReservacion(const char* codigoReservacion) {
    for (int i = 0; i < cantidadReservaciones; ++i) {
        if (strcmp(reservaciones[i]->getCodigo(), codigoReservacion) == 0) {
            delete reservaciones[i];

            for (int j = i; j < cantidadReservaciones - 1; ++j) {
                reservaciones[j] = reservaciones[j + 1];
            }

            cantidadReservaciones--;
            return true;
        }
    }
    return false;
}

void Alojamiento::mostrarInformacion() {
    cout << "Nombre: " << nombre << endl;
    cout << "Código: " << codigo << endl;
    cout << "Departamento: " << departamento << endl;
    cout << "Municipio: " << municipio << endl;
    cout << "Tipo: " << tipo << endl;
    cout << "Dirección: " << (int)direccion << endl;
    cout << "Precio por noche: " << precioPorNoche << endl;

    cout << "Amenidades: ";
    for (int i = 0; i < cantidadAmenidades; ++i) {
        cout << amenidades[i];
        if (i < cantidadAmenidades - 1) cout << ", ";
    }
    cout << endl;

    cout << "Reservaciones: " << cantidadReservaciones << endl;
}
