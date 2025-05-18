#include "Fecha.h"
#include <iostream>
////
using namespace std;

Fecha::Fecha() {
    dia = 0;
    mes = 0;
    ano = 0;
}

Fecha::Fecha(unsigned short int d, unsigned short int m, unsigned int a) {
    dia = d;
    mes = m;
    ano = a;
}

unsigned short int Fecha::getDia() {
    return dia;
}

unsigned short int Fecha::getMes() {
    return mes;
}

unsigned int Fecha::getAno() {
    return ano;
}

const char* Fecha::getNombreMes() {
    const char* nombres[] = {
        "Enero", "Febrero", "Marzo", "Abril", "Mayo", "Junio",
        "Julio", "Agosto", "Septiembre", "Octubre", "Noviembre", "Diciembre"
    };
    if (mes >= 1 && mes <= 12) {
        return nombres[mes - 1];
    }
    return "Mes inválido";
}

bool Fecha::esMenor(Fecha otra) {
    if (ano < otra.ano) return true;
    if (ano == otra.ano && mes < otra.mes) return true;
    if (ano == otra.ano && mes == otra.mes && dia < otra.dia) return true;
    return false;
}

void Fecha::sumarDias(unsigned int dias) {
    static const unsigned short diasMesNormal[] = {
        31, 28, 31, 30, 31, 30,
        31, 31, 30, 31, 30, 31
    };

    while (dias > 0) {
        unsigned short diasEnMes = diasMesNormal[mes - 1];
        if (mes == 2 && ((ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0))) {
            diasEnMes = 29;
        }

        unsigned short restantes = diasEnMes - dia;

        if (dias <= restantes) {
            dia += dias;
            dias = 0;
        } else {
            dias -= (restantes + 1);
            dia = 1;
            mes++;
            if (mes > 12) {
                mes = 1;
                ano++;
            }
        }
    }
}

int Fecha::getDiaSemana() {
    int d = dia;
    int m = mes;
    int a = ano;

    if (m < 3) {
        m += 12;
        a -= 1;
    }

    int k = a % 100;
    int j = a / 100;

    int h = (d + 13 * (m + 1) / 5 + k + k / 4 + j / 4 + 5 * j) % 7;

    return (h + 6) % 7;
}

bool Fecha::CompararFecha(Fecha otra) {
    return dia == otra.dia && mes == otra.mes && ano == otra.ano;
}

bool Fecha::VerificacionFecha() {
    if (dia == 0 || mes == 0 || ano == 0) {
        cout << "Error: La fecha no puede tener ceros.\n";
        return false;
    }

    if (mes < 1 || mes > 12) {
        cout << "Error: Mes inválido.\n";
        return false;
    }

    unsigned short diasMes;
    switch (mes) {
    case 1: case 3: case 5: case 7: case 8: case 10: case 12:
        diasMes = 31;
        break;
    case 4: case 6: case 9: case 11:
        diasMes = 30;
        break;
    case 2:
        if ((ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0)) {
            diasMes = 29;
        } else {
            diasMes = 28;
        }
        break;
    default:
        cout << "Error: Mes inválido.\n";
        return false;
    }

    if (dia < 1 || dia > diasMes) {
        cout << "Error: Día inválido para el mes.\n";
        return false;
    }

    return true;
}

void Fecha::mostrar() {
    cout << (dia < 10 ? "0" : "") << dia << "/"
         << (mes < 10 ? "0" : "") << mes << "/"
         << ano << endl;
}
