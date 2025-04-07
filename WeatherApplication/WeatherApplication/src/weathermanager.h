#ifndef WEATHERMANAGER_H
#define WEATHERMANAGER_H

#include <QObject>
#include <QJsonObject>
#include <QDebug>

class WeatherManager : public QObject
{
    Q_OBJECT
public:
    explicit WeatherManager(QObject *parent = nullptr);

private:

public slots:
    void slotCountryChange(const QString &zipCode, const QString &countryCode);
    void slotRecivedJsonData(const QJsonObject &jsonObj);

private slots:

signals:
    void countryChange(const QString &zipCode, const QString &countryCode);
    void sendJsonDataFromAPI(const QJsonObject &jsonObj);

};

#endif // WEATHERMANAGER_H
