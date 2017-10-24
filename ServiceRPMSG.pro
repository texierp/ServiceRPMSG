QT += core serialport
QT -= gui

TARGET = ServiceRPMSG
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    CRpmsgInterface.cpp \
    CRpmsgDevice.cpp \
    CRpmsgProtocol.cpp

HEADERS += \
    CRpmsgInterface.h \
    CRpmsgDevice.h \
    CRpmsgProtocol.h

target.path = /usr/bin

INSTALLS+= target
