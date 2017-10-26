#ifndef CRPMSGINTERFACE_H
#define CRPMSGINTERFACE_H

#include <QTimer>
#include <QSharedMemory>

class CRpmsgProtocol;

class CRpmsgInterface : public QSharedMemory
{
    Q_OBJECT
public:
    CRpmsgInterface();
    ~CRpmsgInterface();

    //setters
    Q_INVOKABLE void setLed(bool value);

    //getters
    Q_INVOKABLE quint32 getCO2();
    Q_INVOKABLE quint32 getTVOC();
    Q_INVOKABLE quint32 getStatus();

protected slots:
    void readData();

private:
    CRpmsgProtocol  *m_protocol;
    QTimer          *m_timer;
};

#endif // CRPMSGINTERFACE_H
