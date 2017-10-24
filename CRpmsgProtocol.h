#ifndef CRPMSGPROTOCOL_H
#define CRPMSGPROTOCOL_H

class CRpmsgDevice;

class CRpmsgProtocol
{
public:
    CRpmsgProtocol();
    ~CRpmsgProtocol();


private:
    CRpmsgDevice    *m_device;
};

#endif // CRPMSGPROTOCOL_H
