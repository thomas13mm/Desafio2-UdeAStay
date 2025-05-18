#ifndef ALOJAMIENTO_H
#define ALOJAMIENTO_H

#include "Anfitrion.h"
#include "Reservacion.h"
#include "Fecha.h"
#include <string>

using namespace std;

class Alojamiento {
private:
    string nombre;
    const char codigo;
    Anfitrion* anfitrion;

    string departamento;
    string municipio;
    string tipo;
    string direccion;

    float precioPorNoche;


    string* amenidades;
    int cantidadAmenidades;
    int capacidadAmenidades;


    Reservacion** reservaciones;
    int cantidadReservaciones;
    int capacidadReservaciones;

    void expandirAmenidades();
    void expandirReservaciones();

public:
    Alojamiento(const string& nombre, char codigo, Anfitrion* anfitrion,
                const string& departamento, const string& municipio,
                const string& tipo, string direccion, float precio);

    ~Alojamiento();

    bool mostrarDisponibilidad(Fecha inicio, Fecha fin);
    void agregarReservacion(Reservacion* r);
    bool eliminarReservacion(const char* codigoReservacion);
    void mostrarInformacion();

    void agregarAmenidad(const string& amenidad);
};

#endif
