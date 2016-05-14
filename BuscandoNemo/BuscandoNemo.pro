TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    lecturaarchivo.cpp \
    entorno.cpp \
    amplitud.cpp \
    temp.cpp \
    nodo.cpp \
    costouniforme.cpp \
    nodo2.cpp \
    amplitud2.cpp \
    nodo3.cpp \
    amplitud3.cpp

DISTFILES += \
    entorno.txt \
    prueba1.txt

HEADERS += \
    entorno.h \
    amplitud.h \
    nodo.h \
    costouniforme.h \
    nodo2.h \
    amplitud2.h \
    nodo3.h \
    amplitud3.h
