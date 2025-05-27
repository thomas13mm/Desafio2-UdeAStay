#ifndef LOGIN_H
#define LOGIN_H

#include "Data.h"
#include "huesped.h"
#include "anfitrion.h"
#include <iostream>
#include <string>
void procesarOpcionHuesped(SistemaReservaciones& sistema, const std::string& documento);
void procesarOpcionAnfitrion(SistemaReservaciones& sistema, const std::string& documento);

inline void procesarLoginHuesped(SistemaReservaciones& sistema) {
    std::string documento, pin;

    std::cout << "Ingrese su documento: ";
    std::getline(std::cin, documento);

    std::cout << "Ingrese su PIN de 4 digitos: ";
    std::getline(std::cin, pin);

    Huesped* huesped = sistema.buscarHuesped(documento);
    if (!huesped || !huesped->verificarPin(pin)) {
        std::cout << "Documento o PIN incorrecto." << std::endl;
        return;
    }

    procesarOpcionHuesped(sistema, documento);
}

inline void procesarLoginAnfitrion(SistemaReservaciones& sistema) {
    std::string documento, pin;

    std::cout << "Ingrese su documento: ";
    std::getline(std::cin, documento);

    std::cout << "Ingrese su PIN de 4 digitos: ";
    std::getline(std::cin, pin);

    Anfitrion* anfitrion = sistema.buscarAnfitrion(documento);
    if (!anfitrion || !anfitrion->verificarPin(pin)) {
        std::cout << "Documento o PIN incorrecto." << std::endl;
        return;
    }

    procesarOpcionAnfitrion(sistema, documento);
}

#endif // LOGIN_H
