#ifndef CLIENTCONTROLLER_H
#define CLIENTCONTROLLER_H

// взаимодействие между пользовательским интерфейсом и WeatherManager

#include <QObject>
#include <QString>
#include <QJsonObject>
#include <QJsonDocument>
#include <QDebug>

class ClientController : public QObject
{
    Q_OBJECT
public:
    explicit ClientController(QObject *parent = nullptr);
    Q_INVOKABLE void getDataSearchCity(const QString &data);

public slots:
    void slotWeatherData(const QJsonObject &jsonObj);

private:
    QString zipCode, countryCode;

signals:
    void cityChange(const QString &city);
};

#endif // CLIENTCONTROLLER_H
