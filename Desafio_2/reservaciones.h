#ifndef RESERVACIONES_H
#define RESERVACIONES_H

#include <string>;
#include <>;

class Reservacion{
    private:
        string Codigo_Reserva;//agregar esto al diagrama de clase(cambie el nombre Codigo)
        string Codigo_Inmueble;//agragar esto al diagrama de clase
        Alojamiento* Alojamiento;
        Huesped* Huesped;
        Fecha Fecha_Entrada;//cambiar el tipo de dato en el diagrama de clase (unsigned int por fecha)
        unsigned int Duracion;
        string Mpago;
        float Monto;
        string Anotaciones;
    public:
        Reservacion(string, string, Alojamiento*, Huesped*, Fecha, unsigned int, string, float, string);
        //string getCodeReserva();
        Fecha getFechaEntrada();
        string getCodeInmueble();
        unsigned int getDuracion();
        float calcular_monto();
        void Mostrar_comprobante();
        bool Validar_Disponibilidad();
};

#endif // RESERVACIONES_H
