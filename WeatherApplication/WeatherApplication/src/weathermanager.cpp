#include "weathermanager.h"

WeatherManager::WeatherManager(QObject *parent) : QObject(parent)
{
    QJsonObject jsonObj = wac.getWeatherJsonData();
    QJsonDocument jsonDoc(jsonObj);
    qDebug() << jsonDoc.toJson(QJsonDocument::Indented);

}
