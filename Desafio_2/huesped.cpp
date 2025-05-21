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



/*bool Huesped::hacerReservacion(Alojamiento* alojamiento, Fecha fechaEntrada, int duracion, const std::string& metodoPago) {
                                                                                                           corregir
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
*/
