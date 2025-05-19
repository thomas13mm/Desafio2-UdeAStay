#ifndef DATA_H
#define DATA_H

#include<iostream>
#include<fstream>
#include<string>

using namespace std;

void CargarData(const string fileName, string** ptrK){
    /*
    Sinopsis:
        Funcion encargada de abrir un archivo y cargar la estructura de datos
    Param:
    -(const char)&fileName: Argumento que almacena la direccion de memoria de donde se almacena el nombre del archivo de la
    base de datos.
    -(string*)&ptrK: Apuntador a la direccion de memoria de un apuntador de apuntadores
    */
    ifstream Informacion;
    try{
        Informacion.open(fileName);
        if(!Informacion.is_open()){
            throw runtime_error("Error: No se pudo leer el archivo ");
        }
        string Line;
        getline(Informacion, Line);
        for(unsigned int i=0; i<Line.size(); i++){
            if(Line[i]!=","){

            }
        }
   }

    catch(const runtime_error ){
        cout<<"Error: No se pudo leer el archivo";
    }

}

#endif // DATA_H
