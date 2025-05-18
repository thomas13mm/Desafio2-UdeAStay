#ifndef HUESPED_H
#define HUESPED_H

#include "reservaciones.h"
#include <string>

class Huesped {
private:
    std::string documento;
    int antiguedad;
    float puntuacion;

    Reservacion** reservaciones;
    int cantidadReservaciones;
    int capacidadReservaciones;

    void expandirReservaciones();

public:
    Huesped(const std::string& doc, int antiguedad, float puntuacion);
    ~Huesped();

    bool hacerReservacion(Alojamiento* alojamiento, Fecha fechaEntrada, int duracion, const std::string& metodoPago);
    bool cancelarReservacion(const std::string& codigoReservacion);
    void mostrarReservaciones();
    bool validarSuperposicionFechas(Fecha inicio, Fecha fin);


};

#endif
