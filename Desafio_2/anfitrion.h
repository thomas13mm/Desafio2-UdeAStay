#ifndef ANFITRION_H
#define ANFITRION_H

#include <string>
#include "Alojamiento.h"
#include "Fecha.h"
#include "reservaciones.h"

class Anfitrion {
private:
    std::string documento;
    Alojamiento* propiedades;
    unsigned int cantidadPropiedades;

public:
    Anfitrion(std::string documento, Alojamiento* propiedades, unsigned int cantidad);
    ~Anfitrion();

    bool cancelarReservacion(std::string codigoReserva, Reservacion** reservaciones, unsigned int totalReservaciones);

    void consultarReservacionesActivas(Reservacion** reservaciones, unsigned int totalReservaciones,
                                       Fecha fechaInicio, Fecha fechaFin);

    void actualizarHistorico(Fecha fechaCorte, Reservacion** reservaciones, unsigned int& totalReservaciones);
};

#endif
