#include "Huesped.h"
#include "Alojamiento.h"
#include "reservaciones.h"
#include "Fecha.h"

#include <iostream>

/**
 * Implementación de la clase Huesped para gestión de reservas
 */

Huesped::Huesped(const std::string& doc, const std::string& nom, int ant, float punt, const std::string& reservacionesStr)
    : documento(doc), nombre(nom), antiguedad(ant), puntuacion(punt) {
    reservaciones = nullptr;
    cantidadReservaciones = 0;

}

Huesped::~Huesped() {
    for (int i = 0; i < cantidadReservaciones; ++i) {
        delete reservaciones[i];
    }
    delete[] reservaciones;
}

bool Huesped::hacerReservacion(const std::string& codigoReserva, const std::string& codigoInmueble, Alojamiento* alojamiento,
                               const Fecha& fechaEntrada, unsigned short duracion, const std::string& metodoPago, float monto,
                               const std::string& anotaciones, Reservacion*& listaReservaciones) {

    Fecha fechaSalida = fechaEntrada + duracion;

    if (!alojamiento->estaDisponible(fechaEntrada, fechaSalida)) {
        return false;
    }

    if (listaReservaciones != nullptr) {
        Fecha otraEntrada = listaReservaciones->getFechaEntrada();
        Fecha otraSalida = otraEntrada + listaReservaciones->getDuracion();

        if (!(fechaSalida <= otraEntrada || fechaEntrada >= otraSalida)) {
            return false;
        }
    }

    listaReservaciones = new Reservacion(codigoReserva, codigoInmueble, alojamiento,
                                         fechaEntrada, duracion, metodoPago, monto, anotaciones);

    alojamiento->agregarReservacion(listaReservaciones);

    // Añadir al arreglo dinámico del huésped
    Reservacion** nuevaLista = new Reservacion*[cantidadReservaciones + 1];
    for (int i = 0; i < cantidadReservaciones; ++i) {
        nuevaLista[i] = reservaciones[i];
    }
    nuevaLista[cantidadReservaciones] = listaReservaciones;

    delete[] reservaciones;
    reservaciones = nuevaLista;
    cantidadReservaciones++;

    return true;
}

bool Huesped::cancelarReservacion(const std::string& codigoReservacion, Reservacion*& listaReservaciones) {
    if (listaReservaciones == nullptr) {
        return false;
    }

    if (listaReservaciones->getCodigoReserva() == codigoReservacion) {
        listaReservaciones->getInmueble()->eliminarReservacion(codigoReservacion);
        delete listaReservaciones;
        listaReservaciones = nullptr;
        return true;
    }

    return false;
}

void Huesped::mostrarReservaciones() const {
    if (cantidadReservaciones == 0) {
        std::cout << "No hay reservaciones registradas para este huésped." << std::endl;
        return;
    }

    std::cout << "Reservaciones del huésped con documento: " << documento << std::endl;
    std::cout << "----------------------------------------------" << std::endl;

    for (int i = 0; i < cantidadReservaciones; ++i) {
        std::cout << "Reservación #" << (i + 1) << ":" << std::endl;
        reservaciones[i]->Mostrar_comprobante();
        std::cout << "----------------------------------------------" << std::endl;
    }
}

