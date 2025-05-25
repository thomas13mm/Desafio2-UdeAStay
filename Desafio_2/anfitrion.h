#ifndef ANFITRION_H
#define ANFITRION_H

#include <string>
#include "Alojamiento.h"
#include "Fecha.h"
#include "Reservaciones.h"

class Anfitrion {
private:
    std::string documento;
    Alojamiento** propiedades;
    int cantidadPropiedades;
    int capacidadPropiedades;

    void redimensionarPropiedades();

public:
    Anfitrion(const std::string& documento);
    ~Anfitrion();

    void agregarPropiedad(Alojamiento* propiedad);
    bool cancelarReservacion(const std::string& codigoReserva);
    void consultarReservacionesActivas(const Fecha& fechaInicio, const Fecha& fechaFin) const;
    void actualizarHistorico(const Fecha& fechaCorte);

    std::string getDocumento() const;
    int getCantidadPropiedades() const;
    Alojamiento* getPropiedad(int index) const;
};

#endif
