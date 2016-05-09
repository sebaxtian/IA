TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    lecturaarchivo.cpp \
    entorno.cpp \
    amplitud.cpp

DISTFILES += \
    entorno.txt \
    prueba1.txt

HEADERS += \
    entorno.h \
    amplitud.h
