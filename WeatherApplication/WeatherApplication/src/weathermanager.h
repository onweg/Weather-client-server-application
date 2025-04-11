#ifndef WEATHERMANAGER_H
#define WEATHERMANAGER_H

#include <QObject>
#include <QDate>
#include <QJsonObject>
#include <QDebug>
#include <QDateTime>
#include "weatherapiclient.h"
#include "weathercache.h"
#include "clientcontroller.h"
#include "dataeditor.h"

class WeatherManager : public QObject
{
    Q_OBJECT
public:
    explicit WeatherManager(QObject *parent = nullptr);

private:
    QString desiredCity;
    QDate desiredDate;

    WeatherApiClient api;
    WeatherCache cache;
    DataEditor dataEditor;

public slots:
    void slotFindWeatherData(const QString &city, const QDate &date); //
    void slotRecivedWeatherDataFromAPI(const QJsonObject &jsonObj); //

private slots:

signals:
    void sendWeatherDataToController(const QJsonObject &jsonObj); //
    void submitCompletedWeatherDataSearchRequest(const QString &user, const QDateTime &timestamp, const QString &city, const QDate &date, const QJsonObject &jsonObj); //

};

#endif // WEATHERMANAGER_H
