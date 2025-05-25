#ifndef FECHA_H
#define FECHA_H

#include <iostream>
#include <string>

class Fecha {
private:
    unsigned short int dia;
    unsigned short int mes;
    unsigned int ano;

public:
    Fecha();
    Fecha(unsigned short int d, unsigned short int m, unsigned int a);
    Fecha(const std::string& fechaTexto);

    unsigned short int getDia() const;
    unsigned short int getMes() const;
    unsigned int getAno() const;

    const char* getNombreMes() const;
    int getDiaSemana() const;
    bool VerificacionFecha() const;
    void mostrar() const;

    bool operator==(const Fecha& otra) const;
    bool operator!=(const Fecha& otra) const;
    bool operator<(const Fecha& otra) const;
    bool operator<=(const Fecha& otra) const;
    bool operator>(const Fecha& otra) const;
    bool operator>=(const Fecha& otra) const;

    void sumarDias(unsigned int dias);
    Fecha operator+(unsigned int dias) const;
};

#endif
