TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp\
        alojamiento.cpp\
        reservaciones.cpp\
        fecha.cpp\
        huesped.cpp

HEADERS += \
    Letreros.h \
    alojamiento.h\
    reservaciones.h\
    fecha.h\
    huesped.h\
    Data.h

