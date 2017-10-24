#include <QCoreApplication>

#include "CRpmsgInterface.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    new CRpmsgInterface();

    return a.exec();
}

