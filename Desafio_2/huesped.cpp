#include "Huesped.h"
#include <iostream>
/**
 *  Huesped.cpp
 *  Implementación de la clase Huesped para gestión de reservas de hotel
 * Maneja la creación, cancelación y visualización de reservas con validación
 * de fechas y capacidad dinámica. Integra con Alojamiento y Reservacion.

 */
Huesped::Huesped(const std::string& doc, int ant, float punt)
    : documento(doc), antiguedad(ant), puntuacion(punt) {

}

Huesped::~Huesped() {
    //destructor
}



bool Huesped::hacerReservacion(const std::string& codigoReserva, const std::string& codigoInmueble,Alojamiento* alojamiento,
                               const Fecha& fechaEntrada,unsigned short duracion,const std::string& metodoPago, float monto,
                               const std::string& anotaciones, Reservacion*& listaReservaciones) {

    Fecha fechaSalida = fechaEntrada.sumarDias(duracion);


    if (!alojamiento->mostrarDisponibilidad(fechaEntrada, fechaSalida)) {
        return false;
    }

    if (listaReservaciones != nullptr) {
        Fecha otraEntrada = listaReservaciones->getFechaEntrada();
        Fecha otraSalida = otraEntrada.sumarDias(listaReservaciones->getDuracion());

        if (!(fechaSalida <= otraEntrada || fechaEntrada >= otraSalida)) {
            return false;
        }
    }

    listaReservaciones = new Reservacion(codigoReserva, codigoInmueble, alojamiento,
                                         fechaEntrada, duracion, metodoPago, monto, anotaciones);

    alojamiento->agregarReservacion(listaReservaciones);

    return true;
}

bool Huesped::cancelarReservacion(const std::string& codigoReservacion, Reservacion*& listaReservaciones) {

    if (listaReservaciones == nullptr) {
        return false;
    }


    if (listaReservaciones->getCodigoReserva() == codigoReservacion) {

        listaReservaciones->getAlojamiento()->eliminarReservacion(codigoReservacion);


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


