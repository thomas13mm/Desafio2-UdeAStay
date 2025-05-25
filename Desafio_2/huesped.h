#ifndef HUESPED_H
#define HUESPED_H

#include <string>
#include "Reservaciones.h"

class Huesped {
private:
    std::string documento;
    std::string nombre;
    int antiguedad;
    float puntuacion;
    Reservacion** reservaciones;
    int capacidadReservaciones;
    int cantidadReservaciones;

    void redimensionarReservaciones();

public:
    Huesped(const std::string& doc, const std::string& nombre,
            int antiguedad, float puntuacion);
    ~Huesped();

    std::string getDocumento() const;
    std::string getNombre() const;
    int getAntiguedad() const;
    float getPuntuacion() const;

    bool hacerReservacion(Reservacion* reserva);
    bool cancelarReservacion(const std::string& codigoReservacion);
    void mostrarReservaciones() const;
    int getCantidadReservaciones() const;
    Reservacion* getReservacion(int index) const;
};

#endif
