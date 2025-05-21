#ifndef LETREROS_H
#define LETREROS_H

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void Bienvenida(){

    fstream Contenido;
    Contenido.open("bienvenida.txt",fstream::in);
    string linea;
    while (getline(Contenido, linea)) {
        cout << linea << endl;
    }

    Contenido.close();
}

string MenuLoggin(){
    string cedula;
    cout<<"Documento I.D: ";
    cin>>cedula;
    return cedula;
}

#endif // LETREROS_H
