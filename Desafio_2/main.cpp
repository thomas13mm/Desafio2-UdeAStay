#include <iostream>
#include <string>
#include "Data.h"
#include "Fecha.h"

using namespace std;

void mostrarMenuPrincipal();
void mostrarMenuHuesped();
void mostrarMenuAnfitrion();
void procesarOpcionHuesped(SistemaReservaciones& sistema, const string& documento);
void procesarOpcionAnfitrion(SistemaReservaciones& sistema, const string& documento);

int main() {


    SistemaReservaciones sistema;

    string archivoHuespedes = "huespedes.txt";
    string archivoAlojamientos = "alojamientos.txt";
    string archivoReservaciones = "reservaciones.txt";

    sistema.cargarDatos(archivoHuespedes, archivoAlojamientos, archivoReservaciones);


    int opcion;
    string documento;

    do {
        mostrarMenuPrincipal();
        cout << "Ingrese su opcion: ";
        cin >> opcion;

        cin.ignore();

        switch(opcion) {
        case 1:
            cout << "Ingrese su documento: ";
            getline(cin, documento);
            procesarOpcionHuesped(sistema, documento);
            break;
        case 2:
            cout << "Ingrese su documento: ";
            getline(cin, documento);
            procesarOpcionAnfitrion(sistema, documento);
            break;
        case 3:
            cout << "Saliendo del sistema..." << endl;
            break;
        default:
            cout << "Opcion no valida. Intente nuevamente." << endl;
        }
    } while(opcion != 3);

    return 0;
}

void mostrarMenuPrincipal() {
    cout << "\n=== SISTEMA DE RESERVACIONES ===" << endl;
    cout << "1. Ingresar como Huesped" << endl;
    cout << "2. Ingresar como Anfitrion" << endl;
    cout << "3. Salir" << endl;
}

void mostrarMenuHuesped() {
    cout << "\n=== MENU HUESPED ===" << endl;
    cout << "1. Ver alojamientos disponibles" << endl;
    cout << "2. Hacer una reservacion" << endl;
    cout << "3. Cancelar reservacion" << endl;
    cout << "4. Ver mis reservaciones" << endl;
    cout << "5. Volver al menu principal" << endl;
}

void mostrarMenuAnfitrion() {
    cout << "\n=== MENU ANFITRION ===" << endl;
    cout << "1. Ver mis propiedades" << endl;
    cout << "2. Ver reservaciones activas" << endl;
    cout << "3. Cancelar reservacion" << endl;
    cout << "4. Actualizar historico" << endl;
    cout << "5. Volver al menu principal" << endl;
}

void procesarOpcionHuesped(SistemaReservaciones& sistema, const string& documento) {
    Huesped* huesped = sistema.buscarHuesped(documento);
    if (!huesped) {
        cout << "Huesped no registrado." << endl;
        return;
    }

    int opcion;
    do {
        mostrarMenuHuesped();
        cout << "Ingrese su opcion: ";
        cin >> opcion;
        cin.ignore();

        switch(opcion) {
        case 1: {
            string fechaInicioStr, fechaFinStr;
            cout << "Ingrese fecha de inicio (DD/MM/AAAA): ";
            getline(cin, fechaInicioStr);
            Fecha fechaInicio(fechaInicioStr);

            cout << "Ingrese fecha de fin (DD/MM/AAAA): ";
            getline(cin, fechaFinStr);
            Fecha fechaFin(fechaFinStr);

            sistema.mostrarAlojamientosDisponibles(fechaInicio, fechaFin);
            break;
        }
        case 2: {
            string codigoAlojamiento, metodoPago, anotaciones;
            string fechaStr;
            unsigned short duracion;

            cout << "Ingrese codigo de alojamiento: ";
            getline(cin, codigoAlojamiento);

            cout << "Ingrese fecha de entrada (DD/MM/AAAA): ";
            getline(cin, fechaStr);
            Fecha fechaEntrada(fechaStr);

            cout << "Ingrese duracion (noches): ";
            cin >> duracion;
            cin.ignore();

            cout << "Ingrese metodo de pago: ";
            getline(cin, metodoPago);

            cout << "Ingrese anotaciones: ";
            getline(cin, anotaciones);

            if (sistema.hacerReservacion(documento, codigoAlojamiento,
                                         fechaEntrada, duracion, metodoPago, anotaciones)) {
                cout << "Reservacion realizada con exito!" << endl;
            } else {
                cout << "No se pudo realizar la reservacion. Verifique disponibilidad." << endl;
            }
            break;
        }
        case 3: {
            string codigoReserva;
            cout << "Ingrese codigo de reserva a cancelar: ";
            getline(cin, codigoReserva);

            if (sistema.cancelarReservacion(codigoReserva)) {
                cout << "Reservacion cancelada con exito!" << endl;
            } else {
                cout << "No se encontro la reservacion." << endl;
            }
            break;
        }
        case 4:
            sistema.mostrarReservacionesHuesped(documento);
            break;
        case 5: // Volver
            cout << "Volviendo al menu principal..." << endl;
            break;
        default:
            cout << "Opcion no valida. Intente nuevamente." << endl;
        }
    } while(opcion != 5);
}

void procesarOpcionAnfitrion(SistemaReservaciones& sistema, const string& documento) {
    Anfitrion* anfitrion = sistema.buscarAnfitrion(documento);
    if (!anfitrion) {
        cout << "Anfitrion no registrado." << endl;
        return;
    }

    int opcion;
    do {
        mostrarMenuAnfitrion();
        cout << "Ingrese su opcion: ";
        cin >> opcion;
        cin.ignore();

        switch(opcion) {
        case 1:
            sistema.mostrarReservacionesAnfitrion(documento);
            break;
        case 2: {
            string fechaInicioStr, fechaFinStr;
            cout << "Ingrese fecha de inicio (DD/MM/AAAA): ";
            getline(cin, fechaInicioStr);
            Fecha fechaInicio(fechaInicioStr);

            cout << "Ingrese fecha de fin (DD/MM/AAAA): ";
            getline(cin, fechaFinStr);
            Fecha fechaFin(fechaFinStr);

            sistema.mostrarReservacionesAnfitrion(documento, fechaInicio, fechaFin);
            break;
        }
        case 3: {
            string codigoReserva;
            cout << "Ingrese codigo de reserva a cancelar: ";
            getline(cin, codigoReserva);

            if (sistema.cancelarReservacionAnfitrion(documento, codigoReserva)) {
                cout << "Reservacion cancelada con exito!" << endl;
            } else {
                cout << "No se encontro la reservacion o no tiene permisos." << endl;
            }
            break;
        }
        case 4: {
            string fechaCorteStr;
            cout << "Ingrese fecha de corte (DD/MM/AAAA): ";
            getline(cin, fechaCorteStr);
            Fecha fechaCorte(fechaCorteStr);

            sistema.actualizarHistoricoAnfitrion(documento, fechaCorte);
            break;
        }
        case 5: // Volver
            cout << "Volviendo al menu principal..." << endl;
            break;
        default:
            cout << "Opcion no valida. Intente nuevamente." << endl;
        }
    } while(opcion != 5);
}
