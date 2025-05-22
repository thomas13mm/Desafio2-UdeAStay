#ifndef ALOJAMIENTO_H
#define ALOJAMIENTO_H

#include "Fecha.h"
#include <string>


class Reservacion;

class Alojamiento {
private:
    std::string nombre;
    std::string codigo;
    std::string departamento;
    std::string municipio;
    std::string tipo;
    std::string direccion;
    float precioPorNoche;
    std::string amenidades;
    Reservacion** reservaciones;
    int cantidadReservaciones;

public:
    Alojamiento(const std::string& nombre, const std::string& codigo,
                const std::string& departamento, const std::string& municipio,
                const std::string& tipo, const std::string& direccion,
                float precio, const std::string& amenidades);
    ~Alojamiento();


    void mostrarInformacion() const;
    float getPrecioPorNoche() const;
    std::string getCodigo() const;
    std::string getNombre() const;
    std::string getTipo() const;


    bool estaDisponible(const Fecha& inicio, const Fecha& fin) const;
    void agregarReservacion(Reservacion* reserva);
    void eliminarReservacion(const std::string& codigoReserva);
};

#endif
