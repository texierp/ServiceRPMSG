#include "CRpmsgInterface.h"
#include <QCoreApplication>
#include <QDBusConnection>
#include <QDebug>

#define SERVICE_NAME    "iot.service.rpmsg"
#define PROPERTY_PATH   "/"
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    /**
      * Création de l'interface
      **/
    CRpmsgInterface* interface = new CRpmsgInterface();

    /**
      * DBUS INIT
      **/
    if (!QDBusConnection::systemBus().isConnected())
    {
        qDebug() << "DBUS not started !";
    }
    if (!QDBusConnection::systemBus().registerService(SERVICE_NAME))
    {
        qDebug() << " Already Registered !";
    }
    QDBusConnection::systemBus().registerObject(PROPERTY_PATH,
                                               interface,
                                               QDBusConnection::ExportAllInvokables);

    return a.exec();
}

