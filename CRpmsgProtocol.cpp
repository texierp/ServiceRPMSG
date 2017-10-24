#include "CRpmsgProtocol.h"
#include "CRpmsgDevice.h"

#define RPMSG_PORT "/dev/ttyRPMSG"

#define GET_CO2
#define GET_STATUS
#define GET_TVOC
#define SET_LED


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


