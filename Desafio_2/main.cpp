#include <iostream>
#include <string>
#include "reservaciones.h"
#include "Data.h"
#include "alojamiento.h"
#include "Letreros.h"

using namespace std;

int main(){
    unsigned short int ReservasValidas=0;
    const unsigned int CantidadAlojamiento=7;
    const unsigned int CantidadReservas=7;
    const string FileNameReservaciones="Reservaciones.txt";
    const string FileNameAlojamiento="Inmuebles.txt";
    string name= "Juan";

    Alojamiento* Inmuebles = CargarObjetos(FileNameAlojamiento, CantidadAlojamiento, ReservasValidas);
    for(int i=0; i<CantidadAlojamiento ;i++){
        Inmuebles[i].mostrarInformacion();
    }
    Reservacion* Reservaciones= CargarObjetos(FileNameReservaciones, CantidadReservas, ReservasValidas, Inmuebles);
    for(int i=0; i<CantidadAlojamiento ;i++){
        Reservaciones[i].Mostrar_comprobante(name);
    }

    //Bienvenida();


    //string ID=MenuLoggin();

    /*unsigned int iterador=0;
    bool ban=true;
    while(ban){
        if(Pertenece(Anfitriones,ID,filasA,iterador)){
            cout<<"Bienvenido "<<Anfitriones[iterador][1];
            ban=false;
        }
        else if(Pertenece(Huespedes,ID,filasH,iterador)){
            cout<<"Bienvenido "<<Huespedes[iterador][1];
            ban=false;
        }
        else{
            cout<<"Lo sentimos, actualmente no estas registrado"<<'\n'
                <<"Por ahora no admitimos nuevos usuarios"<<endl;
            cout<<"---------------------------------------------------------------------------------"<<endl;
            string ID=MenuLoggin();

        }
    }
*/
    cin.get();
    return 0;
}

