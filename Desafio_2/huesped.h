#ifndef HUESPED_H
#define HUESPED_H

#include "reservaciones.h"
#include "alojamiento.h"
#include "fecha.h"
#include <string>

/**
 *  Huesped
 *  Representa un huésped del sistema de reservaciones
 *
 * Gestiona:
 * - Información personal (documento, antigüedad, puntuación)
 * - Lista dinámica de reservaciones
 * - Operaciones básicas de reservación
 */
class Huesped {
private:
    std::string documento;
    int antiguedad;
    float puntuacion;
    Reservacion* reservaciones;

public:
    Huesped(const std::string& doc, int antiguedad, float puntuacion);
    ~Huesped();

    bool hacerReservacion(const std::string& codigoReserva,const std::string& codigoInmueble, Alojamiento* alojamiento,
                          const Fecha& fechaEntrada, unsigned short duracion, const std::string& metodoPago, float monto,
                          const std::string& anotaciones,Reservacion*& listaRervaciones );

    bool cancelarReservacion(const std::string& codigoReservacion, Reservacion*& listaReservaciones);

    void mostrarReservaciones() const;


};

#endif
