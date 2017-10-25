#ifndef CRPMSGINTERFACE_H
#define CRPMSGINTERFACE_H

#include <QTimer>

class CRpmsgProtocol;

class CRpmsgInterface : public QObject
{
    Q_OBJECT
public:
    CRpmsgInterface();
    ~CRpmsgInterface();

protected slots:
    void readData();

private:
    CRpmsgProtocol  *m_protocol;
    QTimer          *m_timer;
};

#endif // CRPMSGINTERFACE_H
