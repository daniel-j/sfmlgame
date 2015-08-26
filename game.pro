TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
CONFIG += c++11

LIBS += -lsfml-audio -lsfml-graphics -lsfml-network -lsfml-window -lsfml-system

SOURCES += main.cpp \
    stage.cpp \
    tileset.cpp \
    engine.cpp

#include(deployment.pri)
#qtcAddDeployment()

HEADERS += \
    stage.h \
    tileset.h \
    engine.h \
    game.h

