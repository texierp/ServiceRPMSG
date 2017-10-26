QT += core serialport dbus
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

dbus-etc.files = dbus/iot.service.rpmsg.conf
dbus-etc.path = /etc/dbus-1/system.d/

dbus-usr.files = dbus/iot.service.rpmsg.service
dbus-usr.path = /usr/share/dbus-1/system-services/

target.path= /usr/bin

INSTALLS += target dbus-etc dbus-usr
