#include "CRpmsgInterface.h"
#include "CRpmsgProtocol.h"
#include <QDebug>
#include <QDataStream>

CRpmsgInterface::CRpmsgInterface()
{
    //création d'une clé pour la mémoire partagée
    this->setKey("rpmsgValues");
    //initialisation de la mémoire partagée
    this->create(5, QSharedMemory::ReadWrite);

    //Création du protocol
    m_protocol = new CRpmsgProtocol;

    //Création d'un timer
    m_timer = new QTimer;

    //Connexion à la fonction SLOT
    connect(m_timer, &QTimer::timeout, this, &CRpmsgInterface::readData);

    //Démarrage du Timer
    m_timer->start(100);
}

CRpmsgInterface::~CRpmsgInterface()
{
    m_timer->stop();
    delete m_timer;

    delete m_protocol;
}

void CRpmsgInterface::setLed(bool value)
{
    m_protocol->setLED(value);
}

quint32 CRpmsgInterface::getCO2()
{
    return m_protocol->co2();
}

quint32 CRpmsgInterface::getTVOC()
{
    return m_protocol->tvoc();
}

quint32 CRpmsgInterface::getStatus()
{
    return m_protocol->status();
}

void CRpmsgInterface::readData()
{
    //lecture des valeurs sur la mémoire partagée
    m_protocol->readAllValues();

    //récupération des données du air Quality
    quint16 co2 = m_protocol->co2();
    quint16 tvoc = m_protocol->tvoc();
    quint8 status = m_protocol->status();

    //mise à jour de la mémoire partagée
    if (this->isAttached())
    {
        QByteArray sharedData;
        QDataStream stream(&sharedData, QIODevice::WriteOnly);
        stream << co2;
        stream << tvoc;
        stream << status;

        this->lock();
        char *to = (char*)this->data();
        memcpy(to, sharedData.data(), qMin(this->size(), (qint32)sharedData.size()));
        this->unlock();
    }
    else
        this->attach();
}

