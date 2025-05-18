#include "reservaciones.h"
#include <iostream>
#include "fecha.h"

using namespace std;

Reservacion::Reservacion(string Codigo_A, string Codigo_I, Alojamiento* Alojamiento_, Huesped* Huesped_, Fecha Fecha_Entrada_, unsigned int Duracion_, string Mpago_, float Monto_, string Anotaciones_){
    Codigo_Reserva=Codigo_A;
    Codigo_Inmueble=Codigo_I;
    Alojamiento=Alojamiento_;
    Huesped=Huesped_;
    Fecha_Entrada=Fecha_Entrada_;
    Duracion=Duracion_;
    Mpago=Mpago_;
    Monto=Monto_;
    Anotaciones=Anotaciones_;
}

Reservacion::~Reservacion(){
    //Destructor de la clase
}

Reservacion::calcular_monto(float valor_noche, unsigned int cant_noches){
    return valor_noche*cant_noches;
}

Reservacion::Mostrar_comprobante(){
    cout<<"              UdeAStay"<<endl;
    cout<<"      Sistema de alojamientos S.A"<<endl;
    cout<<"Codigo de Reserva....... "<<Codigo_Reserva<<endl;
    cout<<"Reserva por........."<<Huesped<<endl;
    cout<<"Codigo de Alojamiento......."<<Alojamiento<<endl;
    cout<<"              Inicio         "<<endl;
    Fecha Fecha_Final = Fecha_Entrada.sumarDias(Duracion);
    cout<<Fecha_Entrada.getDiaSemana() <<" "<<Fecha_Entrada.getDia()<<" de "<<Fecha_Entrada.getNombreMes()<<" del "<<Fecha_Entrada.getAno()<<endl;
    cout<<"               Fin "<<endl;
    cout<<Fecha_Final.getDiaSemana() <<" "<<Fecha_Final.getDia()<<" de "<<Fecha_Final.getNombreMes()<<" del "<<Fecha_Final.getAno()<<endl;
    cout<<'\n'<<'\n'<<'\n'<<'\n'<<endl;
    cout<<"La empresa no se hace responsable de por el estado de los"<<'\n'<<"espacios, es totalmente responsabilidad del propietario"<<endl;
    cout<<"del inmueble."<<endl;
}

Reservacion::Validar_Disponibilidad(Reservacion* Reservas){
    unsigned int i=0;
    while(true){
        try {
            if(Reservas[i].getCodeInmueble()==Codigo_Inmueble){
                break;
            }
            i++;
        }
        catch(){
            cout<<"El inmueble seleccionado no existe"<<endl;
            return;
        }

    }
    Fecha FechaReservaI=Reservas[i].getFechaEntrada();//estas son como las fecha de entrada y duracion pero del objeto de reserva de la lista
    unsigned int DuracionI=Reservas[i].getDuracion();
    Fecha Fecha_FinalI=FechaReservaI.sumarDias(DuracionI);
    if(Fecha_Entrada.esMenor(Fecha_FinalI)){
        return true;
    }
    return false;
}

