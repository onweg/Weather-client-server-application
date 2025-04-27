#ifndef SERVERHOST_H
#define SERVERHOST_H

#include <QString>

struct ServerHost
{
    QString ip;
    QString port;
    bool success = true;
    QString errorMessage;
};

#endif // SERVERHOST_H
