#ifndef ANFITRION_H
#define ANFITRION_H

#include <string>

class Anfitrion{
    /*
    Clase:
        Clase para la creacion de objetos que simulan un administrador de propiedades
    en el programa.
*/
    private:
        string Documento;
        unsigned short int Antiguedad;
        float Puntuacion;
        Alojamiento* Propiedades;

    public:
    /*
    Constructor:
        Inicializa los objetos del tipo Anfitrion con sus respectivas caracteristicas
    Param:
        -(string)Documento: Cadena de texto que incluye el documento que identifica la persona
        -(unsigned short int)Antiguedad: Numero que contiene la cantidad de tiempo que lleva en
        la aplicacion (en meses)
        -(float)Puntuacion: numero de 0.0 a 5.0 de la calificacion como anfitrion de la propiedad
        -(Alojamiento*)Propiedades: Apuntador a un arreglo de Alojamientos, que pertenecen a un anfitrion

*/
        Anfitrion(string, unsigned short int, float, Alojamiento*);
        ~Anfitrion();
        bool CancelarReservas();
        void ConsultarReservas();
        void ActualizarHistorico();

};

#endif // ANFITRION_H
