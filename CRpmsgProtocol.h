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
    quint16 getCO2();
    quint16 getTVOC();
    Status  getStatus();

    //setters
    void setLED(bool value);

private:
    CRpmsgDevice    *m_device;
};

#endif // CRPMSGPROTOCOL_H
