#include "Huesped.h"
#include "Reservaciones.h"
#include "alojamiento.h"
#include <iostream>

Huesped::Huesped(const std::string& doc, const std::string& nom,
                 int ant, float punt)
    : documento(doc), nombre(nom), antiguedad(ant), puntuacion(punt),
    reservaciones(nullptr), capacidadReservaciones(0), cantidadReservaciones(0) {}

Huesped::~Huesped() {
    for (int i = 0; i < cantidadReservaciones; ++i) {
        delete reservaciones[i];
    }
    delete[] reservaciones;
}

void Huesped::redimensionarReservaciones() {
    int nuevaCapacidad = (capacidadReservaciones == 0) ? 2 : capacidadReservaciones * 2;
    Reservacion** nuevasReservaciones = new Reservacion*[nuevaCapacidad];

    for (int i = 0; i < cantidadReservaciones; ++i) {
        nuevasReservaciones[i] = reservaciones[i];
    }

    delete[] reservaciones;
    reservaciones = nuevasReservaciones;
    capacidadReservaciones = nuevaCapacidad;
}

std::string Huesped::getDocumento() const { return documento; }
std::string Huesped::getNombre() const { return nombre; }
int Huesped::getAntiguedad() const { return antiguedad; }
float Huesped::getPuntuacion() const { return puntuacion; }

bool Huesped::hacerReservacion(Reservacion* reserva) {
    if (cantidadReservaciones >= capacidadReservaciones) {
        redimensionarReservaciones();
    }
    reservaciones[cantidadReservaciones++] = reserva;
    return true;
}

bool Huesped::cancelarReservacion(const std::string& codigoReservacion) {
    int indice = -1;
    for (int i = 0; i < cantidadReservaciones; ++i) {
        if (reservaciones[i]->getCodigoReserva() == codigoReservacion) {
            indice = i;
            break;
        }
    }

    if (indice == -1) return false;

    Alojamiento* alojamiento = reservaciones[indice]->getInmueble();
    if (alojamiento) {
        alojamiento->eliminarReservacion(codigoReservacion);
    }

    delete reservaciones[indice];

    for (int i = indice; i < cantidadReservaciones - 1; ++i) {
        reservaciones[i] = reservaciones[i + 1];
    }

    cantidadReservaciones--;
    return true;
}

void Huesped::mostrarReservaciones() const {
    if (cantidadReservaciones == 0) {
        std::cout << "No hay reservaciones registradas para este huésped." << std::endl;
        return;
    }

    std::cout << "Reservaciones del huésped " << nombre << " (" << documento << "):" << std::endl;
    std::cout << "----------------------------------------------" << std::endl;

    for (int i = 0; i < cantidadReservaciones; ++i) {
        std::cout << "Reservación #" << (i + 1) << ":" << std::endl;
        reservaciones[i]->mostrarComprobante();
    }
}

int Huesped::getCantidadReservaciones() const {
    return cantidadReservaciones;
}

Reservacion* Huesped::getReservacion(int index) const {
    if (index < 0 || index >= cantidadReservaciones) return nullptr;
    return reservaciones[index];
}
