TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    signalgenerator.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    signalgenerator.h

