#ifndef RESERVACIONES_H
#define RESERVACIONES_H

#include <string>
#include "Fecha.h"

class Alojamiento;

class Reservacion {
private:
    std::string Codigo_Reserva;
    std::string Codigo_Inmueble;
    Alojamiento* Inmueble;
    Fecha Fecha_Entrada;
    unsigned short Duracion;
    std::string Mpago;
    float Monto;
    std::string Anotaciones;

public:
    Reservacion(const std::string& codigoReserva,
                const std::string& codigoInmueble,
                Alojamiento* alojamiento,
                const Fecha& fechaEntrada,
                unsigned short  duracion,
                const std::string& metodoPago,
                float monto,
                const std::string& anotaciones);

    ~Reservacion();


    std::string getCodigoReserva() const;
    std::string getCodeInmueble() const;
    Fecha getFechaEntrada() const;
    unsigned short getDuracion() const;
    Alojamiento* getInmueble() const;
    float getMonto() const;


    static float calcular_monto(float valor_noche, unsigned short cant_noches);
    void Mostrar_comprobante() const;
    bool Validar_Disponibilidad(Reservacion* reservas, int cantidad) const;
};

#endif
