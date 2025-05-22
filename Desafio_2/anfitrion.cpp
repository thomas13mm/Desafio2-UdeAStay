#include "Anfitrion.h"
#include <fstream>
#include <iostream>

Anfitrion::Anfitrion(std::string documento, Alojamiento* propiedades, unsigned int cantidad)
    : documento(documento), propiedades(propiedades), cantidadPropiedades(cantidad) {}

Anfitrion::~Anfitrion() {
    delete[] propiedades;
}

bool Anfitrion::cancelarReservacion(std::string codigoReserva, Reservacion** reservaciones, unsigned int totalReservaciones) {
    for (unsigned int i = 0; i < totalReservaciones; i++) {
        if (reservaciones[i] != nullptr && reservaciones[i]->getCodigoReserva() == codigoReserva) {
            for (unsigned int j = 0; j < cantidadPropiedades; j++) {
                if (reservaciones[i]->getCodeInmueble() == propiedades[j].getCodigo()) {
                    delete reservaciones[i];
                    reservaciones[i] = nullptr;
                    return true;
                }
            }
        }
    }
    return false;
}

void Anfitrion::consultarReservacionesActivas(Reservacion** reservaciones, unsigned int totalReservaciones,
                                              Fecha fechaInicio, Fecha fechaFin) {
    std::cout << "\nReservaciones activas para el anfitrión " << documento << " entre ";
    fechaInicio.mostrar();
    std::cout << " y ";
    fechaFin.mostrar();
    std::cout << ":\n";

    bool encontradas = false;

    for (unsigned int i = 0; i < totalReservaciones; i++) {
        if (reservaciones[i] == nullptr) continue;

        for (unsigned int j = 0; j < cantidadPropiedades; j++) {
            if (reservaciones[i]->getCodeInmueble() == propiedades[j].getCodigo()) {
                Fecha fechaEntrada = reservaciones[i]->getFechaEntrada();
                Fecha fechaSalida = fechaEntrada + reservaciones[i]->getDuracion();

                if (!(fechaSalida < fechaInicio) && !(fechaFin < fechaEntrada)) {
                    encontradas = true;
                    std::cout << "\nReserva #" << i + 1 << ":\n";
                    std::cout << "Código: " << reservaciones[i]->getCodigoReserva() << "\n";
                    std::cout << "Inmueble: " << propiedades[j].getNombre() << "\n";
                    std::cout << "Fecha Entrada: ";
                    fechaEntrada.mostrar();
                    std::cout << "\nFecha Salida: ";
                    fechaSalida.mostrar();
                    std::cout << "\n--------------------------------\n";
                }
                break;
            }
        }
    }

    if (!encontradas) {
        std::cout << "No se encontraron reservaciones activas en el rango especificado.\n";
    }
}

void Anfitrion::actualizarHistorico(Fecha fechaCorte, Reservacion** reservaciones, unsigned int& totalReservaciones) {
    std::ofstream archivo("historico_" + documento + ".txt", std::ios::app);
    if (!archivo.is_open()) {
        std::cerr << "Error al abrir el archivo histórico\n";
        return;
    }

    unsigned int reservasMovidas = 0;

    for (unsigned int i = 0; i < totalReservaciones; i++) {
        if (reservaciones[i] == nullptr) continue;

        for (unsigned int j = 0; j < cantidadPropiedades; j++) {
            if (reservaciones[i]->getCodeInmueble() == propiedades[j].getCodigo()) {
                Fecha fechaEntrada = reservaciones[i]->getFechaEntrada();

                if (fechaEntrada < fechaCorte) {
                    archivo << "Código Reserva: " << reservaciones[i]->getCodigoReserva() << "\n";
                    archivo << "Código Inmueble: " << propiedades[j].getCodigo() << "\n";
                    archivo << "Fecha Entrada: ";
                    fechaEntrada.mostrar();
                    archivo << "\nDuración: " << reservaciones[i]->getDuracion() << " noches\n";
                    archivo << "--------------------------------\n";

                    delete reservaciones[i];
                    reservaciones[i] = nullptr;
                    reservasMovidas++;
                }
                break;
            }
        }
    }

    archivo.close();


    unsigned int nuevoIndice = 0;
    for (unsigned int i = 0; i < totalReservaciones; i++) {
        if (reservaciones[i] != nullptr) {
            if (i != nuevoIndice) {
                reservaciones[nuevoIndice] = reservaciones[i];
                reservaciones[i] = nullptr;
            }
            nuevoIndice++;
        }
    }

    totalReservaciones = nuevoIndice;

    std::cout << "Se movieron " << reservasMovidas << " reservaciones al histórico.\n";
    std::cout << "Quedan " << totalReservaciones << " reservaciones activas.\n";
}
