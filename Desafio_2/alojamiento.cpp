#include "Alojamiento.h"
#include "Reservaciones.h"
#include <iostream>
#include <string>

using namespace std;

Alojamiento::Alojamiento(const string& nombre, const string& codigo,
                         const string& departamento, const string& municipio,
                         const string& tipo, const string& direccion,
                         float precio, const string& amenidades)
    : nombre(nombre), codigo(codigo), departamento(departamento),
    municipio(municipio), tipo(tipo), direccion(direccion),
    precioPorNoche(precio), amenidades(amenidades),
    reservaciones(nullptr), cantidadReservaciones(0) {}

Alojamiento::~Alojamiento() {

    for (int i = 0; i < cantidadReservaciones; ++i) {
        delete reservaciones[i];
    }
    delete[] reservaciones;
}

void Alojamiento::mostrarInformacion() const {
    cout << "Nombre: " << nombre << endl;
    cout << "Código: " << codigo << endl;
    cout << "Departamento: " << departamento << endl;
    cout << "Municipio: " << municipio << endl;
    cout << "Tipo: " << tipo << endl;
    cout << "Dirección: " << direccion << endl;
    cout << "Precio por noche: " << precioPorNoche << endl;
    cout << "Amenidades: " << amenidades << endl;
    cout << "Reservaciones activas: " << cantidadReservaciones << endl;
}

float Alojamiento::getPrecioPorNoche() const {
    return precioPorNoche;
}

string Alojamiento::getCodigo() const {
    return codigo;
}

string Alojamiento::getNombre() const {
    return nombre;
}

string Alojamiento::getTipo() const {
    return tipo;
}

bool Alojamiento::estaDisponible(const Fecha& inicio, const Fecha& fin) const {
    for (int i = 0; i < cantidadReservaciones; ++i) {
        Fecha entradaExistente = reservaciones[i]->getFechaEntrada();
        Fecha salidaExistente = entradaExistente + reservaciones[i]->getDuracion();

        if (!(fin <= entradaExistente || inicio >= salidaExistente)) {
            return false;
        }
    }
    return true;
}

void Alojamiento::agregarReservacion(Reservacion* reserva) {

    Reservacion** nuevasReservaciones = new Reservacion*[cantidadReservaciones + 1];


    for (int i = 0; i < cantidadReservaciones; ++i) {
        nuevasReservaciones[i] = reservaciones[i];
    }


    nuevasReservaciones[cantidadReservaciones] = reserva;


    delete[] reservaciones;
    reservaciones = nuevasReservaciones;
    cantidadReservaciones++;
}

void Alojamiento::eliminarReservacion(const string& codigoReserva) {
    int indice = -1;

    // Buscar la reservación
    for (int i = 0; i < cantidadReservaciones; ++i) {
        if (reservaciones[i]->getCodigoReserva() == codigoReserva) {
            indice = i;
            break;
        }
    }

    if (indice == -1) return;


    Reservacion** nuevasReservaciones = new Reservacion*[cantidadReservaciones - 1];


    for (int i = 0, j = 0; i < cantidadReservaciones; ++i) {
        if (i != indice) {
            nuevasReservaciones[j++] = reservaciones[i];
        }
    }

    // Liberar memoria
    delete reservaciones[indice];
    delete[] reservaciones;


    reservaciones = nuevasReservaciones;
    cantidadReservaciones--;
}
