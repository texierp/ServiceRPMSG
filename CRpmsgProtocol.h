#ifndef CRPMSGPROTOCOL_H
#define CRPMSGPROTOCOL_H

#include <QObject>

class CRpmsgDevice;

class CRpmsgProtocol
{
public:
    CRpmsgProtocol();
    ~CRpmsgProtocol();

public:
    typedef enum {
        IAQCORE_STATUS_OK       = 0x00,
        IAQCORE_STATUS_RUNING   = 0x10,
        IAQCORE_STATUS_BUSY     = 0x01,
        IAQCORE_STATUS_ERROR    = 0x80
    }Status;

public:
    //getters
    quint16 co2() const;
    quint16 tvoc() const;
    quint8 status() const;

    //setters
    void setLED(bool value);

    //action
    void readAllValues();

private:
    CRpmsgDevice    *m_device;
    quint16         m_co2;
    quint16         m_tvoc;
    quint8          m_status;
};

#endif // CRPMSGPROTOCOL_H
