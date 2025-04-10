#ifndef CLIENTCONTROLLER_H
#define CLIENTCONTROLLER_H

// взаимодействие между пользовательским интерфейсом и WeatherManager

#include <QObject>
#include <QString>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonValueRef>
#include <QDebug>
#include <QDate>
#include <QDateTime>

// обработка кнопки поиска города и отправить менеджеру запрос о том, что бы он нашел данный город и принять только нужные данные о погоде на текущий день (нельзя хранить мусор)
// обработать кнопки следующего дня и предыдущего отправить менеджеру запрос о новых данных с другой датой и получить только нужные дангные без мусора

class ClientController : public QObject
{
    Q_OBJECT
public:
    explicit ClientController(QObject *parent = nullptr);
    Q_INVOKABLE void getDataSearchCity(const QString &data);
    Q_INVOKABLE QString getCity();
    Q_INVOKABLE QString getDate();
    Q_INVOKABLE QString getDescription();
    Q_INVOKABLE QString getTemp();
    Q_INVOKABLE QString getFeelsLike();
    Q_INVOKABLE QString getTempMax();
    Q_INVOKABLE QString getTempMin();
    Q_INVOKABLE QString getWindSpeed();
    Q_INVOKABLE QString getHumidity();
    Q_INVOKABLE QString getPressure();

public slots:
    void slotWeatherData(const QJsonObject &jsonObj);
    void clickNextDayButton();
    void clickPrevDayButton();

private:
    struct WeatherData{
        double lat;
        double lon;
        QString city;
        QDate date;
        QString description;
        double temp;
        double feels_like;
        double temp_max;
        double temp_min;
        double wind_speed;
        int humidity;
        int pressure;
    };
    WeatherData weatherData;
    void setData(const QJsonObject &jsonObj); // переделать так как json будет зранить только нужные проверенные данные
signals:
    void findCity(const QString &city);
    void dataUpdated();
};

#endif // CLIENTCONTROLLER_H
