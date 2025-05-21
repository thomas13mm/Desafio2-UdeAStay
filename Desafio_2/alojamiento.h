#ifndef ALOJAMIENTO_H
#define ALOJAMIENTO_H

#include "Fecha.h"
#include <string>

using namespace std;

class Alojamiento {
private:
    string nombre;
    const char codigo;
    string departamento;
    string municipio;
    string tipo;
    string direccion;
    float precioPorNoche;
    string* amenidades;

public:
    Alojamiento(const string& nombre, char codigo,
                const string& departamento, const string& municipio,
                const string& tipo, const string& direccion, float precio, string* &amenidades);

    ~Alojamiento();

    //bool mostrarDisponibilidad(Fecha inicio, Fecha fin);
    void mostrarInformacion();
    float getPrecioPorNoche();
};

#endif
