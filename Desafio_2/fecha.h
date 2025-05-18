#ifndef FECHA_H
#define FECHA_H
////
class Fecha {
private:
    unsigned short int dia;
    unsigned short int mes;
    unsigned int ano;

public:
    Fecha();
    Fecha(unsigned short int d, unsigned short int m, unsigned int a);

    unsigned short int getDia();
    unsigned short int getMes();
    unsigned int getAno();
    const char* getNombreMes();
    bool esMenor(Fecha otra);
    void sumarDias(unsigned int dias);
    int getDiaSemana();
    bool CompararFecha(Fecha otra);
    bool VerificacionFecha();

    void mostrar();
};

#endif
