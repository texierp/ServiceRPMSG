#ifndef CRPMSGDEVICE_H
#define CRPMSGDEVICE_H

#include <QString>
#include <QFile>

class CRpmsgDevice
{
public:
    CRpmsgDevice(const QString deviceName);
    ~CRpmsgDevice();

public:
    bool openDevice();
    void closeDevice();
    qint64 writeData(QByteArray command);
    QByteArray readData(QByteArray command);

private:
    QFile   *m_rpmsgDevice;
    QString m_deviceName;
};

#endif // CRPMSGDEVICE_H
