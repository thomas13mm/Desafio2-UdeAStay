#ifndef HUESPED_H
#define HUESPED_H

#include "reservaciones.h"
#include "alojamiento.h"
#include "fecha.h"
#include <string>

/**
 *  Huesped
 *  Representa un huésped del sistema de reservaciones
 */
class Huesped {
private:
    std::string documento;
    std::string nombre;
    int antiguedad;
    float puntuacion;
    Reservacion** reservaciones;
    int cantidadReservaciones;

public:
    Huesped(const std::string& doc, const std::string& nombre, int antiguedad, float puntuacion, const std::string& reservacionesStr);
    ~Huesped();

    bool hacerReservacion(const std::string& codigoReserva, const std::string& codigoInmueble, Alojamiento* alojamiento,
                          const Fecha& fechaEntrada, unsigned short duracion, const std::string& metodoPago, float monto,
                          const std::string& anotaciones, Reservacion*& listaReservaciones);

    bool cancelarReservacion(const std::string& codigoReservacion, Reservacion*& listaReservaciones);

    void mostrarReservaciones() const;
};

#endif
