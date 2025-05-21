#ifndef RESERVACIONES_H
#define RESERVACIONES_H

#include <string>
#include "fecha.h"
#include "alojamiento.h"


using namespace std;

class Reservacion{
    /*
    Clase:
        Reservacion es una clase que permite el manejo de un sistema para hacer reservas, de forma dinamica evitanto
    la clonacion de reservas y usando de forma eficiente la memoria.
    */

    private:
        string Codigo_Reserva;
        string Codigo_Inmueble;
        Alojamiento* Inmueble;
        Fecha Fecha_Entrada;
        unsigned short Duracion;
        string Mpago;
        float Monto;
        string Anotaciones;
    public:
    /*
    Constructor:
        La reservacion para un objeto de esta clase esta dada por:
    Param:
        -(string)Codigo_Reserva: string que almacena el codigo de 5 digitos de la reserva
        -(string)Codigo_Inmueble: string que almacena el codigo alfa-numerico de 4 digitos del inmueble
        -(Alojamiento*)Alojamiento: Apuntador a un objeto del tipo alojamiento
        -(Huesped*)Huesped: Apuntador a un objeto del tipo Huesped
        -(Fecha)Fecha_Entrada: Fecha que almacena la fecha de ingreso del huesped al hospedaje
        -(unsigned int)Duracion: numero que guarda la cantidad de noches que va permanecer el huesped en la propiedad
        -(string)Mpago: string que contiene el metodo de pago del huesped PSE o TCredito
        -(float)Monto: numero real que guarda el monto pagado por el ususario
        -(string)Anotaciones: string que guarda los comentarios del huesped para el hospedaje
*/

        Reservacion(string, string, Alojamiento*, Fecha, unsigned int, string, float, string);
        ~Reservacion();
        string getCodigoReserva();
        Fecha getFechaEntrada();
        string getCodeInmueble();
        unsigned int getDuracion();
        float calcular_monto(float valor_noche, unsigned short cant_noches);
        void Mostrar_comprobante();
        bool Validar_Disponibilidad(Reservacion* Reservas);
};

#endif // RESERVACIONES_H
