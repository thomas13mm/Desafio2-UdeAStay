#include "Fecha.h"
#include <iostream>

using namespace std;


Fecha::Fecha() : dia(0), mes(0), ano(0) {}

Fecha::Fecha(unsigned short int d, unsigned short int m, unsigned int a)
    : dia(d), mes(m), ano(a) {}


unsigned short int Fecha::getDia() const { return dia; }
unsigned short int Fecha::getMes() const { return mes; }
unsigned int Fecha::getAno() const { return ano; }


const char* Fecha::getNombreMes() const {
    static const char* nombres[] = {
        "Enero", "Febrero", "Marzo", "Abril", "Mayo", "Junio",
        "Julio", "Agosto", "Septiembre", "Octubre", "Noviembre", "Diciembre"
    };
    return (mes >= 1 && mes <= 12) ? nombres[mes - 1] : "Mes inválido";
}

bool Fecha::esMenor(const Fecha& otra) const {
    return (ano < otra.ano) ||
          (ano == otra.ano && mes < otra.mes) ||
          (ano == otra.ano && mes == otra.mes && dia < otra.dia);
}

int Fecha::getDiaSemana() const {
    int m = mes;
    int y = ano;

    if (m < 3) {
        m += 12;
        y -= 1;
    }

    int k = y % 100;
    int j = y / 100;
    return (dia + 13 * (m + 1) / 5 + k + k / 4 + j / 4 + 5 * j) % 7;
}

bool Fecha::CompararFecha(const Fecha& otra) const {
    return dia == otra.dia && mes == otra.mes && ano == otra.ano;
}

bool Fecha::VerificacionFecha() const {
    if (dia == 0 || mes == 0 || ano == 0) return false;
    if (mes > 12) return false;

    unsigned short diasMes;
    switch (mes) {
        case 4: case 6: case 9: case 11: diasMes = 30; break;
        case 2:
            diasMes = ((ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0) ? 29 : 28);
            break;
        default: diasMes = 31;
    }

    return dia <= diasMes;
}

void Fecha::mostrar() const {
    cout << (dia < 10 ? "0" : "") << dia << "/"
         << (mes < 10 ? "0" : "") << mes << "/"
         << ano;
}


void Fecha::sumarDias(unsigned int dias) {
    *this = *this + dias;
}

Fecha Fecha::operator+(unsigned int dias) const {
    Fecha resultado = *this;
    static const unsigned short diasMes[] = {31,28,31,30,31,30,31,31,30,31,30,31};

    while (dias > 0) {
        unsigned short diasEnMes = diasMes[resultado.mes - 1];
        if (resultado.mes == 2 && ((resultado.ano % 4 == 0 && resultado.ano % 100 != 0) ||
                                  (resultado.ano % 400 == 0))) {
            diasEnMes = 29;
        }

        unsigned short disponibles = diasEnMes - resultado.dia;
        if (dias <= disponibles) {
            resultado.dia += dias;
            break;
        } else {
            dias -= disponibles + 1;
            resultado.dia = 1;
            if (++resultado.mes > 12) {
                resultado.mes = 1;
                resultado.ano++;
            }
        }
    }
    return resultado;
}
