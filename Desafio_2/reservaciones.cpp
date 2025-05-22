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


float Reservacion::calcular_monto(float valor_noche, unsigned short cant_noches) {
    return valor_noche * cant_noches;
}


void Reservacion::Mostrar_comprobante() const {
    std::cout << "----- Comprobante de Reservacion -----" << std::endl;
    std::cout << "Codigo Reserva: " << Codigo_Reserva << std::endl;
    std::cout << "Codigo Inmueble: " << Codigo_Inmueble << std::endl;
    std::cout << "Fecha de Entrada: ";
    Fecha_Entrada.mostrar();
    std::cout << std::endl;
    std::cout << "Duracion: " << Duracion << " noches" << std::endl;
    std::cout << "Metodo de Pago: " << Mpago << std::endl;
    std::cout << "Monto Total: $" << Monto << std::endl;
    std::cout << "Anotaciones: " << Anotaciones << std::endl;
    std::cout << "-------------------------------------" << std::endl;
}


bool Reservacion::Validar_Disponibilidad(Reservacion* reservas, int cantidad) const {
    for (int i = 0; i < cantidad; i++) {
        if (reservas[i].getCodeInmueble() == Codigo_Inmueble) {
            Fecha inicioExistente = reservas[i].getFechaEntrada();
            unsigned short durExistente = reservas[i].getDuracion();

            Fecha finExistente = inicioExistente + durExistente;
            Fecha finNueva = Fecha_Entrada + Duracion;

            if (!(finNueva <= inicioExistente || Fecha_Entrada >= finExistente)) {
                return false;
            }
        }
    }
    return true;
}

