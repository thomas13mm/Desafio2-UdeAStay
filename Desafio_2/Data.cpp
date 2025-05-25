#include "Data.h"
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>
#include "huesped.h"
#include "alojamiento.h"
#include "anfitrion.h"
using namespace std;

SistemaReservaciones::SistemaReservaciones()
    : huespedes(nullptr), cantidadHuespedes(0), capacidadHuespedes(0),
    alojamientos(nullptr), cantidadAlojamientos(0), capacidadAlojamientos(0),
    anfitriones(nullptr), cantidadAnfitriones(0), capacidadAnfitriones(0),
    reservaciones(nullptr), cantidadReservaciones(0), capacidadReservaciones(0) {}

SistemaReservaciones::~SistemaReservaciones() {

    for (int i = 0; i < cantidadHuespedes; ++i) delete huespedes[i];
    delete[] huespedes;

    for (int i = 0; i < cantidadAlojamientos; ++i) delete alojamientos[i];
    delete[] alojamientos;

    for (int i = 0; i < cantidadAnfitriones; ++i) delete anfitriones[i];
    delete[] anfitriones;

    for (int i = 0; i < cantidadReservaciones; ++i) delete reservaciones[i];
    delete[] reservaciones;
}

void SistemaReservaciones::redimensionarHuespedes() {
    int nuevaCapacidad = (capacidadHuespedes == 0) ? 2 : capacidadHuespedes * 2;
    Huesped** nuevosHuespedes = new Huesped*[nuevaCapacidad];

    for (int i = 0; i < cantidadHuespedes; ++i) {
        nuevosHuespedes[i] = huespedes[i];
    }

    delete[] huespedes;
    huespedes = nuevosHuespedes;
    capacidadHuespedes = nuevaCapacidad;
}

void SistemaReservaciones::redimensionarAlojamientos() {
    int nuevaCapacidad = (capacidadAlojamientos == 0) ? 2 : capacidadAlojamientos * 2;
    Alojamiento** nuevosAlojamientos = new Alojamiento*[nuevaCapacidad];

    for (int i = 0; i < cantidadAlojamientos; ++i) {
        nuevosAlojamientos[i] = alojamientos[i];
    }

    delete[] alojamientos;
    alojamientos = nuevosAlojamientos;
    capacidadAlojamientos = nuevaCapacidad;
}

void SistemaReservaciones::redimensionarAnfitriones() {
    int nuevaCapacidad = (capacidadAnfitriones == 0) ? 2 : capacidadAnfitriones * 2;
    Anfitrion** nuevosAnfitriones = new Anfitrion*[nuevaCapacidad];

    for (int i = 0; i < cantidadAnfitriones; ++i) {
        nuevosAnfitriones[i] = anfitriones[i];
    }

    delete[] anfitriones;
    anfitriones = nuevosAnfitriones;
    capacidadAnfitriones = nuevaCapacidad;
}

void SistemaReservaciones::redimensionarReservaciones() {
    int nuevaCapacidad = (capacidadReservaciones == 0) ? 2 : capacidadReservaciones * 2;
    Reservacion** nuevasReservaciones = new Reservacion*[nuevaCapacidad];

    for (int i = 0; i < cantidadReservaciones; ++i) {
        nuevasReservaciones[i] = reservaciones[i];
    }

    delete[] reservaciones;
    reservaciones = nuevasReservaciones;
    capacidadReservaciones = nuevaCapacidad;
}

Huesped* SistemaReservaciones::buscarHuesped(const std::string& documento)const {
    for (int i = 0; i < cantidadHuespedes; ++i) {
        if (huespedes[i]->getDocumento() == documento) {
            return huespedes[i];
        }
    }
    return nullptr;
}

Alojamiento* SistemaReservaciones::buscarAlojamiento(const std::string& codigo) {
    for (int i = 0; i < cantidadAlojamientos; ++i) {
        if (alojamientos[i]->getCodigo() == codigo) {
            return alojamientos[i];
        }
    }
    return nullptr;
}

Anfitrion* SistemaReservaciones::buscarAnfitrion(const std::string& documento)const {
    for (int i = 0; i < cantidadAnfitriones; ++i) {
        if (anfitriones[i]->getDocumento() == documento) {
            return anfitriones[i];
        }
    }
    return nullptr;
}

std::string SistemaReservaciones::generarCodigoReserva() {
    if (cantidadReservaciones == 0) {
        return "00001";
    }


    int maxCodigo = 0;
    for (int i = 0; i < cantidadReservaciones; ++i) {
        string codigoStr = reservaciones[i]->getCodigoReserva();
        try {
            int codigo = stoi(codigoStr);
            if (codigo > maxCodigo) {
                maxCodigo = codigo;
            }
        } catch (...) {
            continue;
        }
    }


    int nuevoCodigo = maxCodigo + 1;
    stringstream ss;
    ss << setw(5) << setfill('0') << nuevoCodigo;
    return ss.str();
}

void SistemaReservaciones::cargarDatos(const std::string& archivoHuespedes,
                                       const std::string& archivoAlojamientos,
                                       const std::string& archivoReservaciones) {
    // Cargar huéspedes
    ifstream fileHuespedes(archivoHuespedes);
    if (fileHuespedes.is_open()) {
        string linea;
        while (getline(fileHuespedes, linea)) {
            stringstream ss(linea);
            string documento, nombre, reservasStr;
            int antiguedad;
            float puntuacion;

            getline(ss, documento, ',');
            getline(ss, nombre, ',');
            getline(ss, reservasStr, ',');
            ss >> antiguedad;
            ss.ignore();
            ss >> puntuacion;

            if (cantidadHuespedes >= capacidadHuespedes) {
                redimensionarHuespedes();
            }

            huespedes[cantidadHuespedes++] = new Huesped(documento, nombre, antiguedad, puntuacion);
        }
        fileHuespedes.close();
    }

    // Cargar alojamientos
    ifstream fileAlojamientos(archivoAlojamientos);
    if (fileAlojamientos.is_open()) {
        string linea;
        while (getline(fileAlojamientos, linea, '$')) {
            stringstream ss(linea);
            string tipo, departamento, municipio, direccion, amenidades, nombre, codigo;
            float precio;

            getline(ss, tipo, ',');
            getline(ss, departamento, ',');
            getline(ss, municipio, ',');
            getline(ss, direccion, ',');
            getline(ss, amenidades, ',');
            getline(ss, nombre, ',');
            getline(ss, codigo, ',');
            ss >> precio;

            if (cantidadAlojamientos >= capacidadAlojamientos) {
                redimensionarAlojamientos();
            }

            alojamientos[cantidadAlojamientos++] = new Alojamiento(
                nombre, codigo, departamento, municipio, tipo,
                direccion, precio, amenidades
                );


            string documentoAnfitrion = codigo.substr(0, codigo.find('-'));
            if (!buscarAnfitrion(documentoAnfitrion)) {
                if (cantidadAnfitriones >= capacidadAnfitriones) {
                    redimensionarAnfitriones();
                }
                anfitriones[cantidadAnfitriones++] = new Anfitrion(documentoAnfitrion);
            }


            Anfitrion* anfitrion = buscarAnfitrion(documentoAnfitrion);
            if (anfitrion) {
                anfitrion->agregarPropiedad(alojamientos[cantidadAlojamientos-1]);
            }
        }
        fileAlojamientos.close();
    }

    // Cargar reservaciones
    ifstream fileReservaciones(archivoReservaciones);
    if (fileReservaciones.is_open()) {
        string linea;
        while (getline(fileReservaciones, linea, '$')) {
            stringstream ss(linea);
            string codigoReserva, codigoInmueble, fechaStr, metodoPago, fechaPagoStr;
            float monto;

            getline(ss, codigoReserva, ',');
            getline(ss, codigoInmueble, ',');
            getline(ss, fechaStr, ',');
            getline(ss, metodoPago, ',');
            getline(ss, fechaPagoStr, ',');
            ss >> monto;

            Fecha fechaEntrada(fechaStr);
            Alojamiento* alojamiento = buscarAlojamiento(codigoInmueble);
            unsigned short duracion = 0;

            if (alojamiento && alojamiento->getPrecioPorNoche() > 0) {
                duracion = static_cast<unsigned short>(monto / alojamiento->getPrecioPorNoche());
            }

            if (cantidadReservaciones >= capacidadReservaciones) {
                redimensionarReservaciones();
            }

            if (alojamiento) {
                reservaciones[cantidadReservaciones] = new Reservacion(
                    codigoReserva, codigoInmueble, alojamiento,
                    fechaEntrada, duracion, metodoPago, monto, ""
                    );

                alojamiento->agregarReservacion(reservaciones[cantidadReservaciones]);
                cantidadReservaciones++;
            }
        }
        fileReservaciones.close();
    }
}

bool SistemaReservaciones::hacerReservacion(const std::string& documentoHuesped,
                                            const std::string& codigoAlojamiento,

                                            const Fecha& fechaEntrada,
                                            unsigned short duracion,
                                            const std::string& metodoPago,
                                            const std::string& anotaciones) {
    Huesped* huesped = buscarHuesped(documentoHuesped);
    Alojamiento* alojamiento = buscarAlojamiento(codigoAlojamiento);

    if (!huesped || !alojamiento) {
        return false;
    }


    Fecha fechaSalida = fechaEntrada + duracion;
    if (!alojamiento->estaDisponible(fechaEntrada, fechaSalida)) {
        return false;
    }


    string nuevoCodigoReserva = generarCodigoReserva();


    float monto = alojamiento->getPrecioPorNoche() * duracion;


    if (cantidadReservaciones >= capacidadReservaciones) {
        redimensionarReservaciones();
    }

    reservaciones[cantidadReservaciones] = new Reservacion(
        nuevoCodigoReserva, codigoAlojamiento, alojamiento,
        fechaEntrada, duracion, metodoPago, monto, anotaciones
        );


    alojamiento->agregarReservacion(reservaciones[cantidadReservaciones]);
    huesped->hacerReservacion(reservaciones[cantidadReservaciones]);
    cantidadReservaciones++;

    return true;
}

bool SistemaReservaciones::cancelarReservacion(const std::string& codigoReserva) {
    for (int i = 0; i < cantidadReservaciones; ++i) {
        if (reservaciones[i]->getCodigoReserva() == codigoReserva) {
            // Eliminar de alojamiento
            Alojamiento* alojamiento = reservaciones[i]->getInmueble();
            if (alojamiento) {
                alojamiento->eliminarReservacion(codigoReserva);
            }

            // Eliminar reservación
            delete reservaciones[i];

            // Mover las demás reservaciones
            for (int j = i; j < cantidadReservaciones - 1; ++j) {
                reservaciones[j] = reservaciones[j + 1];
            }
            cantidadReservaciones--;

            return true;
        }
    }
    return false;
}

bool SistemaReservaciones::cancelarReservacionAnfitrion(const std::string& documentoAnfitrion,
                                                        const std::string& codigoReserva) {
    Anfitrion* anfitrion = buscarAnfitrion(documentoAnfitrion);
    if (!anfitrion) {
        return false;
    }

    for (int i = 0; i < cantidadReservaciones; ++i) {
        if (reservaciones[i]->getCodigoReserva() == codigoReserva) {

            Alojamiento* alojamiento = reservaciones[i]->getInmueble();
            if (alojamiento) {
                bool propiedadDelAnfitrion = false;
                for (int j = 0; j < anfitrion->getCantidadPropiedades(); ++j) {
                    if (anfitrion->getPropiedad(j) == alojamiento) {
                        propiedadDelAnfitrion = true;
                        break;
                    }
                }

                if (!propiedadDelAnfitrion) {
                    return false;
                }

                // Eliminar reservación
                alojamiento->eliminarReservacion(codigoReserva);
                delete reservaciones[i];

                // Mover las demás reservaciones
                for (int j = i; j < cantidadReservaciones - 1; ++j) {
                    reservaciones[j] = reservaciones[j + 1];
                }
                cantidadReservaciones--;

                return true;
            }
        }
    }
    return false;
}

void SistemaReservaciones::mostrarHuespedes() const {
    cout << "\n=== LISTA DE HUESPEDES ===" << endl;
    for (int i = 0; i < cantidadHuespedes; ++i) {
        cout << "Documento: " << huespedes[i]->getDocumento() << endl;
        cout << "Nombre: " << huespedes[i]->getNombre() << endl;
        cout << "Antigüedad: " << huespedes[i]->getAntiguedad() << " meses" << endl;
        cout << "Puntuación: " << huespedes[i]->getPuntuacion() << "/5" << endl;
        cout << "------------------------" << endl;
    }
}

void SistemaReservaciones::mostrarAlojamientos() const {
    cout << "\n=== LISTA DE ALOJAMIENTOS ===" << endl;
    for (int i = 0; i < cantidadAlojamientos; ++i) {
        alojamientos[i]->mostrarInformacion();
        cout << "------------------------" << endl;
    }
}

void SistemaReservaciones::mostrarAlojamientosDisponibles(const Fecha& inicio, const Fecha& fin) const {
    cout << "\n=== ALOJAMIENTOS DISPONIBLES ===" << endl;
    cout << "Entre ";
    inicio.mostrar();
    cout << " y ";
    fin.mostrar();
    cout << ":\n";

    bool disponibles = false;
    for (int i = 0; i < cantidadAlojamientos; ++i) {
        if (alojamientos[i]->estaDisponible(inicio, fin)) {
            alojamientos[i]->mostrarInformacion();
            cout << "------------------------" << endl;
            disponibles = true;
        }
    }

    if (!disponibles) {
        cout << "No hay alojamientos disponibles en el rango de fechas especificado." << endl;
    }
}

void SistemaReservaciones::mostrarReservaciones() const {
    cout << "\n=== LISTA DE RESERVACIONES ===" << endl;
    for (int i = 0; i < cantidadReservaciones; ++i) {
        reservaciones[i]->mostrarComprobante();
        cout << "------------------------" << endl;
    }
}

void SistemaReservaciones::mostrarReservacionesHuesped(const std::string& documentoHuesped) const {
    Huesped* huesped = buscarHuesped(documentoHuesped);
    if (huesped) {
        huesped->mostrarReservaciones();
    } else {
        cout << "Huésped no encontrado." << endl;
    }
}

void SistemaReservaciones::mostrarReservacionesAnfitrion(const std::string& documentoAnfitrion) const {
    Anfitrion* anfitrion = buscarAnfitrion(documentoAnfitrion);
    if (anfitrion) {
        cout << "\n=== PROPIEDADES DEL ANFITRION ===" << endl;
        for (int i = 0; i < anfitrion->getCantidadPropiedades(); ++i) {
            anfitrion->getPropiedad(i)->mostrarInformacion();
            cout << "------------------------" << endl;
        }
    } else {
        cout << "Anfitrión no encontrado." << endl;
    }
}

void SistemaReservaciones::mostrarReservacionesAnfitrion(const std::string& documentoAnfitrion,
                                                         const Fecha& fechaInicio,
                                                         const Fecha& fechaFin) const {
    Anfitrion* anfitrion = buscarAnfitrion(documentoAnfitrion);
    if (anfitrion) {
        anfitrion->consultarReservacionesActivas(fechaInicio, fechaFin);
    } else {
        cout << "Anfitrión no encontrado." << endl;
    }
}

void SistemaReservaciones::actualizarHistoricoAnfitrion(const std::string& documentoAnfitrion,
                                                        const Fecha& fechaCorte) {
    Anfitrion* anfitrion = buscarAnfitrion(documentoAnfitrion);
    if (anfitrion) {
        anfitrion->actualizarHistorico(fechaCorte);
    } else {
        cout << "Anfitrión no encontrado." << endl;
    }
}

void SistemaReservaciones::mostrarAnfitriones() const {
    cout << "\n=== LISTA DE ANFITRIONES ===" << endl;
    for (int i = 0; i < cantidadAnfitriones; ++i) {
        cout << "Documento: " << anfitriones[i]->getDocumento() << endl;
        cout << "Propiedades: " << anfitriones[i]->getCantidadPropiedades() << endl;
        cout << "------------------------" << endl;
    }
}
