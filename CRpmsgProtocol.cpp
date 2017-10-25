#include "CRpmsgProtocol.h"
#include "CRpmsgDevice.h"
#include <QDebug>
#include <QDataStream>

#define RPMSG_PORT "/dev/ttyRPMSG"

#define GET_CO2     "?co2"
#define GET_STATUS  "?status"
#define GET_TVOC    "?tvoc"
#define SET_LED     "!out_LED:"

quint16 retrieveData(QByteArray array)
{
    quint16 value;
    QDataStream str(array);
    str.setByteOrder(QDataStream::BigEndian);
    str >> value;
    return value;
}

CRpmsgProtocol::CRpmsgProtocol()
{
    //création du device
    m_device = new CRpmsgDevice(RPMSG_PORT);

    //ouverture du port
    m_device->openDevice();
}

CRpmsgProtocol::~CRpmsgProtocol()
{
    delete m_device;
}

quint16 CRpmsgProtocol::getCO2()
{
    QByteArray array = m_device->readData(GET_CO2, 3);
    return retrieveData(array);
}

quint16 CRpmsgProtocol::getTVOC()
{
    QByteArray array = m_device->readData(GET_TVOC, 3);
    return retrieveData(array);
}

CRpmsgProtocol::Status CRpmsgProtocol::getStatus()
{
    QByteArray array = m_device->readData(GET_STATUS, 2);
    return (CRpmsgProtocol::Status)array.toInt();
}

void CRpmsgProtocol::setLED(bool value)
{
    QString command = SET_LED + QString("%1").arg(value);
    m_device->writeData(command.toLatin1().data());
}


