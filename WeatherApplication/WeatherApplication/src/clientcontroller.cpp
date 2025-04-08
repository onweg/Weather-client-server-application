#include "clientcontroller.h"

ClientController::ClientController(QObject *parent) : QObject(parent)
{

}

void ClientController::getDataSearchCity(const QString &data)
{
    qDebug() << "Полученная строка: " << data;
    emit cityChange(data);
}

void ClientController::slotWeatherData(const QJsonObject &jsonObj)
{
    QJsonDocument doc(jsonObj);
    qDebug() << doc;
}
