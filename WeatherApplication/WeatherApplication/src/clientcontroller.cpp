#include "clientcontroller.h"

ClientController::ClientController(QObject *parent) : QObject(parent)
{

}

void ClientController::getDataFromQML(const QString &data)
{
    qDebug() << "Полученная строка: " << data;
    QStringList parts = data.split('*');
    QStringList words = parts[0].split(' ');
    countryCode = words[0];
    zipCode = parts[1];
    emit countryChange(zipCode, countryCode);
}

void ClientController::slotRecivedJsonData(const QJsonObject &jsonObj)
{
    QJsonDocument doc(jsonObj);
    qDebug() << doc;
}
