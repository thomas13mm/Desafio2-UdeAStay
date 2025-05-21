#include <iostream>
#include <string>
#include "Data.h"
#include "alojamiento.h"
#include "Fecha.h"
#include "huesped.h"
#include "reservaciones.h"
#include "Letreros.h"

using namespace std;

int main(){
    const unsigned int columnasA=5;
    const unsigned int filasA=10;
    const unsigned int columnasH=5;
    const unsigned int filasH=100;
    const unsigned int columnasI=5;
    const unsigned int filasI=200;
    const unsigned int columnasR=6;
    const unsigned int filasR=400;

    string** Anfitriones=CargarData(filasA,columnasA,"Anfitriones.txt");
    string** Huespedes=CargarData(filasH,columnasH, "Huespedes.txt");
    //string** Inmuebles=CargarData(filasI, columnasI, "Inmuebles.txt");
    //string** Reservas=CargarData(filasR,columnasR,"Reservaciones.txt");

    Bienvenida();
    string ID=MenuLoggin();

    unsigned int iterador=0;
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

    cin.get();
    return 0;
}

