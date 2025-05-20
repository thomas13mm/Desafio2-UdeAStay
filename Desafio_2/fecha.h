#ifndef FECHA_H
#define FECHA_H

#include <iostream>

class Fecha {
private:
    unsigned short int dia;
    unsigned short int mes;
    unsigned int ano;

public:

    Fecha();
    Fecha(unsigned short int d, unsigned short int m, unsigned int a);

    // Getters (const)
    unsigned short int getDia() const;
    unsigned short int getMes() const;
    unsigned int getAno() const;


    const char* getNombreMes() const;
    bool esMenor(const Fecha& otra) const;
    int getDiaSemana() const;
    bool CompararFecha(const Fecha& otra) const;
    bool VerificacionFecha() const;
    void mostrar() const;


    void sumarDias(unsigned int dias);
    Fecha operator+(unsigned int dias) const;
};

#endif
