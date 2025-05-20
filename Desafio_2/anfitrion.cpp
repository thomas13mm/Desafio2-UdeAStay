#include "anfitrion.h"
#include "fecha.h"
#include "reservaciones.h"
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

Anfitrion::Anfitrion(string Documento_, unsigned short int Antiguedad_, float Puntuacion_, Alojamiento* Propiedades_){
    Documento=Documento_;
    Antiguedad=Antiguedad_;
    Puntuacion=Puntuacion_;
    Propiedades=Propiedades_;
}

Anfitrion::~Anfitrion(){

}

Anfitrion::getDocumento(){
    return Documento;
}

Anfitrion::ActualizarHistorico(Fecha Fecha_Corte, Reservacion** reservaciones){
    try{
        ofstream Linea("Historico.txt");
        for(unsigned int i=0; i<365; i++){
            Huesped* documento;
            documento=reservaciones[i].getHuespeds();


            if (reservaciones[i].getFechaEntrada().esMenor(Fecha_Corte) &&
                !reservaciones[i].Validar_Disponibilidad(reservaciones)) {

                Linea << "Reserva: " << (reservaciones[i].getCodeInmueble()).to_string()<<'\n';
                Linea << "Propiedad de: " << (reservaciones[i])
                Linea << " Reservado por: "<<documento;
                Linea << " Fecha Entrada: "<<(reservaciones[i].getFechaEntrada()).to_string()<<'\n';
                Linea << " Fecha Salida: "<<(reservaciones[i].getFechaEntrada()).sumarDias((reservaciones[i].getDuracion()))<<'\n';
                Linea << endl;
            }
        }
    }
    catch(){
        cout<<"No se encontro el archivo historico.";
    }
}

Anfitrion::ConsultarReservas(string** reservas, const unsigned int &filas){
    const unsigned int ColumnaDoc=0;
    for(unsigned int i=0;  i<filas; i++){
        if((reservas[i][ColumnaDoc]) == getDocumento()){
            while((reservas[i][ColumnaDoc+1])!=){

            }
        }
}

