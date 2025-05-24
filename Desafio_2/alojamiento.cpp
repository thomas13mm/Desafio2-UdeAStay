#include "Alojamiento.h"
#include <cstring>
#include <iostream>

// Constructor
Alojamiento::Alojamiento(const string& nombre, string codigo,
                         const string& departamento, const string& municipio,
                         const string& tipo, const string& direccion, float precio, string amenidadess)
    : nombre(nombre),
    codigo(codigo),
    departamento(departamento),
    municipio(municipio),
    tipo(tipo),
    direccion(direccion),
    precioPorNoche(precio),
    amenidades(amenidadess)
{

}


// Destructor
Alojamiento::~Alojamiento() {
}

/*bool Alojamiento::mostrarDisponibilidad(Fecha inicio, Fecha fin) {
    for (int i = 0; i < cantidadReservaciones; ++i) {
        if (reservaciones[i]->hayConflicto(inicio, fin)) {
            return false;
        }
    }                                                                //corregir
    return true;
}
*/

void Alojamiento::mostrarInformacion() {
    cout << "Nombre: " << nombre << endl;
    cout << "Codigo: " << codigo << endl;
    cout << "Departamento: " << departamento << endl;
    cout << "Municipio: " << municipio << endl;
    cout << "Tipo: " << tipo << endl;
    cout << "Direccion: " << direccion << endl;
    cout << "Precio por noche: " << precioPorNoche << endl;

    cout << "Amenidades: "<<amenidades; //aqui hacer un ciclo que separe el string por comas
    cout << endl;
    cout<<'\n';
}

float Alojamiento::getPrecioPorNoche(){
    return precioPorNoche;
}

string Alojamiento::getCodigoAlojamiento(){
    return codigo;
}
