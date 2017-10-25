#include "CRpmsgInterface.h"
#include "CRpmsgProtocol.h"
#include <QDebug>

CRpmsgInterface::CRpmsgInterface()
{
    //Création du protocol
    m_protocol = new CRpmsgProtocol;
    //Création d'un timer
    m_timer = new QTimer;
    //Connexion à la fonction SLOT
    connect(m_timer, &QTimer::timeout, this, &CRpmsgInterface::readData);
    //Démarrage du Timer
    m_timer->start(500);
}

CRpmsgInterface::~CRpmsgInterface()
{
    m_timer->stop();
    delete m_timer;

    delete m_protocol;
}

void CRpmsgInterface::readData()
{
    quint16 co2 = m_protocol->getCO2();
    quint16 tvoc = m_protocol->getTVOC();
    quint8 status = m_protocol->getStatus();

    qDebug() << co2 << tvoc << status;
}

