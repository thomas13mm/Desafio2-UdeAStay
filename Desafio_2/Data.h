#ifndef DATA_H
#define DATA_H

#include <string>
#include "Fecha.h"

class Huesped;
class Alojamiento;
class Anfitrion;
class Reservacion;

class SistemaReservaciones {
private:

    Huesped** huespedes;
    int cantidadHuespedes;
    int capacidadHuespedes;

    Alojamiento** alojamientos;
    int cantidadAlojamientos;
    int capacidadAlojamientos;

    Anfitrion** anfitriones;
    int cantidadAnfitriones;
    int capacidadAnfitriones;

    Reservacion** reservaciones;
    int cantidadReservaciones;
    int capacidadReservaciones;

    void guardarReservacionesActivas();

    void redimensionarHuespedes();
    void redimensionarAlojamientos();
    void redimensionarAnfitriones();
    void redimensionarReservaciones();
    std::string generarCodigoReserva();

public:
    SistemaReservaciones();
    ~SistemaReservaciones();


    Huesped* buscarHuesped(const std::string& documento)const;
    Alojamiento* buscarAlojamiento(const std::string& codigo);
    Anfitrion* buscarAnfitrion(const std::string& documento)const;


    void cargarDatos(const std::string& archivoHuespedes,
                     const std::string& archivoAlojamientos,
                     const std::string& archivoReservaciones);


    bool hacerReservacion(const std::string& docHuesped,
                          const std::string& codigoAlojamiento,
                          const Fecha& fechaEntrada,
                          unsigned short duracion,
                          const std::string& metodoPago,
                          const std::string& anotaciones);


    bool cancelarReservacion(const std::string& codigoReserva);
    bool cancelarReservacionAnfitrion(const std::string& documentoAnfitrion,
                                      const std::string& codigoReserva);


    void mostrarHuespedes() const;
    void mostrarAlojamientos() const;
    void mostrarAlojamientosDisponibles(const Fecha& inicio, const Fecha& fin) const;
    void mostrarReservaciones() const;
    void mostrarReservacionesHuesped(const std::string& documentoHuesped) const;
    void mostrarReservacionesAnfitrion(const std::string& documentoAnfitrion) const;
    void mostrarReservacionesAnfitrion(const std::string& documentoAnfitrion,
                                       const Fecha& fechaInicio,
                                       const Fecha& fechaFin) const;
    void mostrarAnfitriones() const;


    void actualizarHistoricoAnfitrion(const std::string& documentoAnfitrion,
                                      const Fecha& fechaCorte);
};

#endif // DATA_H
