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
    reservaciones(nullptr), capacidadReservaciones(0), cantidadReservaciones(0) {}

Alojamiento::~Alojamiento() {
    for (int i = 0; i < cantidadReservaciones; ++i) {
        delete reservaciones[i];
    }
    delete[] reservaciones;
}

void Alojamiento::redimensionarReservaciones() {
    int nuevaCapacidad = (capacidadReservaciones == 0) ? 2 : capacidadReservaciones * 2;
    Reservacion** nuevasReservaciones = new Reservacion*[nuevaCapacidad];

    for (int i = 0; i < cantidadReservaciones; ++i) {
        nuevasReservaciones[i] = reservaciones[i];
    }

    delete[] reservaciones;
    reservaciones = nuevasReservaciones;
    capacidadReservaciones = nuevaCapacidad;
}

void Alojamiento::mostrarInformacion() const {
    cout << "Nombre: " << nombre << endl;
    cout << "Código: " << codigo << endl;
    cout << "Ubicación: " << departamento << ", " << municipio << endl;
    cout << "Dirección: " << direccion << endl;
    cout << "Tipo: " << tipo << endl;
    cout << "Precio por noche: $" << precioPorNoche << endl;
    cout << "Amenidades: " << amenidades << endl;
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

string Alojamiento::getDepartamento() const {
    return departamento;
}

string Alojamiento::getMunicipio() const {
    return municipio;
}

string Alojamiento::getDireccion() const {
    return direccion;
}

string Alojamiento::getAmenidades() const {
    return amenidades;
}

bool Alojamiento::estaDisponible(const Fecha& inicio, const Fecha& fin) const {
    for (int i = 0; i < cantidadReservaciones; ++i) {
        Fecha inicioReserva = reservaciones[i]->getFechaEntrada();
        Fecha finReserva = inicioReserva + reservaciones[i]->getDuracion();


        if (!(fin < inicioReserva || inicio > finReserva)) {
            return false;
        }
    }
    return true;
}
void Alojamiento::agregarReservacion(Reservacion* reserva) {
    if (cantidadReservaciones >= capacidadReservaciones) {
        redimensionarReservaciones();
    }
    reservaciones[cantidadReservaciones++] = reserva;
}

bool Alojamiento::eliminarReservacion(const std::string& codigo) {
    for (int i = 0; i < cantidadReservaciones; ++i) {
        if (reservaciones[i] && reservaciones[i]->getCodigoReserva() == codigo) {
            // Solo eliminamos la referencia, no el objeto
            for (int j = i; j < cantidadReservaciones - 1; ++j) {
                reservaciones[j] = reservaciones[j + 1];
            }
            cantidadReservaciones--;
            return true;
        }
    }
    return false;
}

int Alojamiento::getCantidadReservaciones() const {
    return cantidadReservaciones;
}

Reservacion* Alojamiento::getReservacion(int index) const {
    if (index < 0 || index >= cantidadReservaciones) return nullptr;
    return reservaciones[index];
}
