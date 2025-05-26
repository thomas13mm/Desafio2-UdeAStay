#include "Anfitrion.h"
#include <fstream>
#include <iostream>
#include <iomanip>
Anfitrion::Anfitrion(const std::string& doc)
    : documento(doc), propiedades(nullptr),
    cantidadPropiedades(0), capacidadPropiedades(0) {}

Anfitrion::~Anfitrion() {
    delete[] propiedades;
}

void Anfitrion::redimensionarPropiedades() {
    int nuevaCapacidad = (capacidadPropiedades == 0) ? 2 : capacidadPropiedades * 2;
    Alojamiento** nuevasPropiedades = new Alojamiento*[nuevaCapacidad];

    for (int i = 0; i < cantidadPropiedades; ++i) {
        nuevasPropiedades[i] = propiedades[i];
    }

    delete[] propiedades;
    propiedades = nuevasPropiedades;
    capacidadPropiedades = nuevaCapacidad;
}

void Anfitrion::agregarPropiedad(Alojamiento* propiedad) {
    if (cantidadPropiedades >= capacidadPropiedades) {
        redimensionarPropiedades();
    }
    propiedades[cantidadPropiedades++] = propiedad;
}

bool Anfitrion::cancelarReservacion(const std::string& codigoReserva) {
    for (int i = 0; i < cantidadPropiedades; ++i) {
        if (propiedades[i]->eliminarReservacion(codigoReserva)) {
            return true;
        }
    }
    return false;
}

void Anfitrion::consultarReservacionesActivas(const Fecha& fechaInicio, const Fecha& fechaFin) const {
    std::cout << "\nReservaciones activas para el anfitrion " << documento << " entre ";
    fechaInicio.mostrar();
    std::cout << " y ";
    fechaFin.mostrar();
    std::cout << ":\n";

    bool encontradas = false;

    for (int i = 0; i < cantidadPropiedades; ++i) {
        Alojamiento* propiedad = propiedades[i];
        for (int j = 0; j < propiedad->getCantidadReservaciones(); ++j) {
            Reservacion* reserva = propiedad->getReservacion(j);
            if (reserva) {
                Fecha fechaEntrada = reserva->getFechaEntrada();
                Fecha fechaSalida = fechaEntrada + reserva->getDuracion();

                if (!(fechaSalida < fechaInicio) && !(fechaFin < fechaEntrada)) {
                    encontradas = true;
                    std::cout << "\nReserva #" << i + 1 << ":\n";
                    std::cout << "Codigo: " << reserva->getCodigoReserva() << "\n";
                    std::cout << "Inmueble: " << propiedad->getNombre() << "\n";
                    std::cout << "Fecha Entrada: ";
                    fechaEntrada.mostrar();
                    std::cout << "\nFecha Salida: ";
                    fechaSalida.mostrar();
                    std::cout << "\n--------------------------------\n";
                }
            }
        }
    }

    if (!encontradas) {
        std::cout << "No se encontraron reservaciones activas en el rango especificado.\n";
    }
}

void Anfitrion::actualizarHistorico(const Fecha& fechaCorte) {
    std::ofstream archivo("historico_" + documento + ".txt", std::ios::app);
    if (!archivo.is_open()) {
        std::cerr << "Error al abrir/crear el archivo historico\n";
        return;
    }

    int reservasMovidas = 0;

    for (int i = 0; i < cantidadPropiedades; ++i) {
        Alojamiento* propiedad = propiedades[i];
        for (int j = 0; j < propiedad->getCantidadReservaciones(); ) {
            Reservacion* reserva = propiedad->getReservacion(j);
            if (reserva) {
                Fecha fechaEntrada = reserva->getFechaEntrada();

                if (fechaEntrada < fechaCorte) {
                    // Escribir en el histórico
                    archivo << "codigoReserva: " << reserva->getCodigoReserva() << "\n";
                    archivo << "Código Inmueble: " << propiedad->getCodigo() << "\n";
                    archivo << "Fecha Entrada: " << fechaEntrada.toString() << "\n";
                    archivo << "Duracion " << reserva->getDuracion() << " noches\n";
                    archivo << "Monto: " << std::fixed << std::setprecision(2) << reserva->getMonto() << "\n";
                    archivo << "--------------------------------\n";


                    propiedad->eliminarReservacion(reserva->getCodigoReserva());
                    reservasMovidas++;

                } else {
                    j++;
                }
            }
        }
    }

    archivo.close();
    std::cout << "Se movieron " << reservasMovidas << " reservaciones al histórico.\n";
}

std::string Anfitrion::getDocumento() const {
    return documento;
}

int Anfitrion::getCantidadPropiedades() const {
    return cantidadPropiedades;
}

Alojamiento* Anfitrion::getPropiedad(int index) const {
    if (index < 0 || index >= cantidadPropiedades) return nullptr;
    return propiedades[index];
}
