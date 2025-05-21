#include "reservaciones.h"
#include <iostream>
#include "fecha.h"
#include "alojamiento.h"

using namespace std;

Reservacion::Reservacion(string Codigo_A, string Codigo_I, Alojamiento* Alojamiento_, Fecha Fecha_Entrada_, unsigned short Duracion_, string Mpago_, float Monto_, string Anotaciones_){
    Codigo_Reserva=Codigo_A;
    Codigo_Inmueble=Codigo_I;
    Inmueble=Alojamiento_;
    Fecha_Entrada=Fecha_Entrada_;
    Duracion=Duracion_;
    Mpago=Mpago_;
    Monto=Monto_;
    Anotaciones=Anotaciones_;
}

Reservacion::~Reservacion(){
    //Destructor de la clase
}

string Reservacion::getCodigoReserva(){
    return Codigo_Reserva;
}

string Reservacion::getCodeInmueble(){
    return Codigo_Inmueble;

}

unsigned int Reservacion::getDuracion(){
    return Duracion;
}

Fecha Reservacion::getFechaEntrada(){
    return Fecha_Entrada;
}
float Reservacion::calcular_monto(float valor_noche, unsigned short cant_noches){
    return valor_noche*cant_noches;
}

void Reservacion::Mostrar_comprobante(){
    cout<<"              UdeAStay"<<endl;
    cout<<"      Sistema de alojamientos S.A"<<endl;
    cout<<"Codigo de Reserva....... "<<Codigo_Reserva<<endl;
    cout<<"Reserva por........."<<endl;
    cout<<"Codigo de Alojamiento......."<<Inmueble<<endl;
    cout<<"              Inicio         "<<endl;
    Fecha Fecha_Final = Fecha_Entrada + Duracion;
    cout<<Fecha_Entrada.getDiaSemana() <<" "<<Fecha_Entrada.getDia()<<" de "<<Fecha_Entrada.getNombreMes()<<" del "<<Fecha_Entrada.getAno()<<endl;
    cout<<"               Fin "<<endl;
    cout<<Fecha_Final.getDiaSemana() <<" "<<Fecha_Final.getDia()<<" de "<<Fecha_Final.getNombreMes()<<" del "<<Fecha_Final.getAno()<<endl;
    cout<<'\n'<<'\n'<<'\n'<<'\n'<<endl;
    cout<<"La empresa no se hace responsable de por el estado de los"<<'\n'<<"espacios, es totalmente responsabilidad del propietario"<<endl;
    cout<<"del inmueble."<<endl;
}

 bool Reservacion::Validar_Disponibilidad(Reservacion* Reservas){
    unsigned int i=0;
    while(true){
        try {
            if(Reservas[i].getCodeInmueble()==Codigo_Inmueble){
                throw runtime_error("El inmueble seleccionado no existe");
                break;
            }
            i++;
        }
        catch(const runtime_error){
            return false;
        }
    }
    Fecha FechaReservaI=Reservas[i].getFechaEntrada();//estas son como las fecha de entrada y duracion pero del objeto de reserva de la lista
    unsigned short DuracionI=Reservas[i].getDuracion();
    Fecha Fecha_FinalI=FechaReservaI+DuracionI;
    if(Fecha_Entrada.esMenor(Fecha_FinalI)){
        return true;
    }
    return false;
}

