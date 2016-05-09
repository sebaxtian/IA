TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    lecturaarchivo.cpp \
    temp.cpp \
    nodo.cpp

DISTFILES += \
    entorno.txt

HEADERS += \
    nodo.h
