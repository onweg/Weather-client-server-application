#ifndef WEATHERCACHE_H
#define WEATHERCACHE_H

// хранит данные о погоде
// если данные хрнаятся больше 1 час, то чистим

// возможность найти данные по городу
// возможность найти данные по городу на определенный день
// возможность добавлять новые данные
// возможность проверять акутальность данных в кеш по городу
// возможность удалять кеш по городу


#include <QObject>
#include <QJsonObject>
#include <QJsonArray>
#include <QDate>
#include <QDateTime>
#include <QMap>
#include <QString>

class WeatherCache : public QObject
{
    Q_OBJECT
public:
    explicit WeatherCache(QObject *parent = nullptr);
    bool hasValidData();
    static const int CACHE_EXPIRATION_TIME = 3600;

    bool hasValidData(const QString &city);
    QJsonObject getData(const QString &city, const QDate &date = QDate::currentDate());
    void addData(const QString &city, const QJsonObject &data);
    void removeData(const QString &city);

private:
    struct WeatherData{
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
    struct CacheEntry{
        QJsonObject data;
        QDateTime timestamp;
    };
    QMap<QString, CacheEntry> cache;

public slots:


signals:

};

#endif // WEATHERCACHE_H
