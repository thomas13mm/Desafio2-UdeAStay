#include "Huesped.h"
#include <iostream>

Huesped::Huesped(const std::string& doc, int ant, float punt)
    : documento(doc), antiguedad(ant), puntuacion(punt) {
    capacidadReservaciones = 5;
    cantidadReservaciones = 0;
    reservaciones = new Reservacion*[capacidadReservaciones];
}

Huesped::~Huesped() {
    for (int i = 0; i < cantidadReservaciones; ++i) {
        delete reservaciones[i];
    }
    delete[] reservaciones;
}

void Huesped::expandirReservaciones() {
    int nuevaCapacidad = capacidadReservaciones * 2;
    Reservacion** nuevo = new Reservacion*[nuevaCapacidad];
    for (int i = 0; i < cantidadReservaciones; ++i) {
        nuevo[i] = reservaciones[i];
    }
    delete[] reservaciones;
    reservaciones = nuevo;
    capacidadReservaciones = nuevaCapacidad;
}

bool Huesped::validarSuperposicionFechas(Fecha inicio, Fecha fin) {
    for (int i = 0; i < cantidadReservaciones; ++i) {
        Fecha rInicio = reservaciones[i]->getFechaEntrada();
        Fecha rFin = rInicio.sumarDias(reservaciones[i]->getDuracion());

        if (!(fin < rInicio || inicio > rFin)) {
            return true;
        }
    }
    return false;
}

bool Huesped::hacerReservacion(Alojamiento* alojamiento, Fecha fechaEntrada, int duracion, const std::string& metodoPago) {
    Fecha fechaSalida = fechaEntrada.sumarDias(duracion);
    if (!alojamiento->mostrarDisponibilidad(fechaEntrada, fechaSalida)) {
        return false;
    }

    if (validarSuperposicionFechas(fechaEntrada, fechaSalida)) {
        return false;
    }

    float monto = alojamiento->getPrecioPorNoche() * duracion;
    Fecha fechaPago = Fecha::obtenerFechaActual();
    std::string codigo = "R" + std::to_string(cantidadReservaciones + 1);

    Reservacion* nueva = new Reservacion(codigo, alojamiento, this, fechaEntrada, duracion, metodoPago, fechaPago, monto, "");
    if (cantidadReservaciones == capacidadReservaciones) {
        expandirReservaciones();
    }
    reservaciones[cantidadReservaciones++] = nueva;
    alojamiento->agregarReservacion(nueva);
    return true;
}

bool Huesped::cancelarReservacion(const std::string& codigoReservacion) {
    for (int i = 0; i < cantidadReservaciones; ++i) {
        if (reservaciones[i]->getCodigo() == codigoReservacion) {
            reservaciones[i]->getAlojamiento()->eliminarReservacion(codigoReservacion);
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

void Huesped::mostrarReservaciones() {
    for (int i = 0; i < cantidadReservaciones; ++i) {
        reservaciones[i]->mostrarComprobante();
        std::cout << "--------------------------\n";
    }
}
