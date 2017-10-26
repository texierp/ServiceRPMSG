#include "CRpmsgDevice.h"
#include <fcntl.h>
#include <termios.h>
#include <QFile>
#include <QDebug>
#include <QThread>
#include <QElapsedTimer>

#define MAX_DATA_SIZE 64

CRpmsgDevice::CRpmsgDevice(const QString deviceName) : m_deviceName(deviceName)
{
    m_rpmsgDevice = new QFile(deviceName);
}

CRpmsgDevice::~CRpmsgDevice()
{
    closeDevice();
    delete m_rpmsgDevice;
}

bool CRpmsgDevice::openDevice()
{
    if (m_rpmsgDevice->open(QIODevice::ReadWrite))
    {
        //récupération du handler
        int fd = m_rpmsgDevice->handle();

        //configuration du port
        struct termios cfg_tty;
        memset(&cfg_tty, 0, sizeof(cfg_tty));
        fcntl(fd, F_SETFL, 0);
        tcgetattr(fd, &cfg_tty);

        //mode canonique (lecture par ligne)
        cfg_tty.c_lflag = ICANON;
        //ignorer "BREAK condition"
        cfg_tty.c_iflag &= ~IGNBRK;
        cfg_tty.c_lflag = 0;
        cfg_tty.c_oflag = 0;

        if (tcsetattr(fd,TCSANOW, &cfg_tty) != 0)
        {
            qDebug() << "Problème mise à jour attributs";
            return false;
        }
        return true;
    }
    else
    {
        qDebug() << "Impossible d'ouvrir le port "<<m_deviceName;
        return false;
    }
}

void CRpmsgDevice::closeDevice()
{
    if (m_rpmsgDevice->isOpen())
        m_rpmsgDevice->close();
}

qint64 CRpmsgDevice::writeData(QByteArray command)
{
    qint64 status = m_rpmsgDevice->write(command);
    m_rpmsgDevice->flush();
    m_rpmsgDevice->readLine(MAX_DATA_SIZE);

    return status;
}

QByteArray CRpmsgDevice::readData(QByteArray command)
{
    m_rpmsgDevice->write(command);
    m_rpmsgDevice->flush();
    QByteArray array = m_rpmsgDevice->readLine(MAX_DATA_SIZE);
    return array;
}

