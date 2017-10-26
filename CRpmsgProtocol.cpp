#include "CRpmsgProtocol.h"
#include "CRpmsgDevice.h"
#include <QDebug>
#include <QDataStream>

#define RPMSG_PORT "/dev/ttyRPMSG"

#define GET_VALUES     "?getAirQuality"
#define SET_LED         "!out_LED:"

quint16 dataToUin16(QByteArray array)
{
    quint16 value;
    QDataStream str(array);
    str.setByteOrder(QDataStream::BigEndian);
    str >> value;
    return value;
}

quint8 dataToUin8(QByteArray array)
{
    quint8 value;
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

void CRpmsgProtocol::readAllValues()
{
    QByteArray array = m_device->readData(GET_VALUES);
    if (array.length() != 6)
        qDebug() << array.length() << array[array.length()-1];
    QDataStream str(array);
    str.setByteOrder(QDataStream::BigEndian);
    str >> m_co2
        >> m_tvoc
        >> m_status;
}

void CRpmsgProtocol::setLED(bool value)
{
    QString command = SET_LED + QString("%1").arg(value);
    m_device->writeData(command.toLatin1().data());
}

quint16 CRpmsgProtocol::co2() const
{
    return m_co2;
}

quint16 CRpmsgProtocol::tvoc() const
{
    return m_tvoc;
}

quint8 CRpmsgProtocol::status() const
{
    return m_status;
}
