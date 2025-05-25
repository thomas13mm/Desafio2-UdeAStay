#include "Reservaciones.h"
#include "Alojamiento.h"
#include <iostream>

Reservacion::Reservacion(const std::string& codigoReserva,
                         const std::string& codigoInmueble,
                         Alojamiento* alojamiento,
                         const Fecha& fechaEntrada,
                         unsigned short duracion,
                         const std::string& metodoPago,
                         float monto,
                         const std::string& anotaciones)
    : Codigo_Reserva(codigoReserva), Codigo_Inmueble(codigoInmueble),
    Inmueble(alojamiento), Fecha_Entrada(fechaEntrada),
    Duracion(duracion), Mpago(metodoPago), Monto(monto),
    Anotaciones(anotaciones) {}

Reservacion::~Reservacion() {}

std::string Reservacion::getCodigoReserva() const { return Codigo_Reserva; }
std::string Reservacion::getCodeInmueble() const { return Codigo_Inmueble; }
Fecha Reservacion::getFechaEntrada() const { return Fecha_Entrada; }
unsigned short Reservacion::getDuracion() const { return Duracion; }
Alojamiento* Reservacion::getInmueble() const { return Inmueble; }
float Reservacion::getMonto() const { return Monto; }
std::string Reservacion::getMetodoPago() const { return Mpago; }
std::string Reservacion::getAnotaciones() const { return Anotaciones; }

float Reservacion::calcularMonto(float valorNoche, unsigned short cantNoches) {
    return valorNoche * cantNoches;
}

void Reservacion::mostrarComprobante() const {
    std::cout << "----- Comprobante de Reservación -----" << std::endl;
    std::cout << "Código Reserva: " << Codigo_Reserva << std::endl;
    std::cout << "Código Inmueble: " << Codigo_Inmueble << std::endl;
    if (Inmueble) {
        std::cout << "Nombre Inmueble: " << Inmueble->getNombre() << std::endl;
    }
    std::cout << "Fecha de Entrada: ";
    Fecha_Entrada.mostrar();
    std::cout << std::endl;
    std::cout << "Duración: " << Duracion << " noches" << std::endl;
    std::cout << "Método de Pago: " << Mpago << std::endl;
    std::cout << "Monto Total: $" << Monto << std::endl;
    std::cout << "Anotaciones: " << Anotaciones << std::endl;
    std::cout << "-------------------------------------" << std::endl;
}
