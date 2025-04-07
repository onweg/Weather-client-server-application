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
    Q_INVOKABLE void getDataFromQML(const QString &data);

public slots:
    void slotRecivedJsonData(const QJsonObject &jsonObj);

private:
    QString zipCode, countryCode;

signals:
    void countryChange(const QString &zipCode, const QString &countryCode);
};

#endif // CLIENTCONTROLLER_H
