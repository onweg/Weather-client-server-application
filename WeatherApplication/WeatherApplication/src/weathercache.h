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
#include <QDebug>

class WeatherCache : public QObject
{
    Q_OBJECT
public:
    explicit WeatherCache(QObject *parent = nullptr);

    enum CacheStatus {
        Valid,
        CityNotFound,
        DateNotFound,
        Expired
    };
    Q_ENUM(CacheStatus)

    static const int CACHE_EXPIRATION_TIME = 3600;
    CacheStatus hasValidData(const QString &city, const QDate &date = QDate::currentDate()); // 0 - успех 1 - нет города 2 - есть город, но нет даты 3 - данные устарели
    QJsonObject getData(const QString &city, const QDate &date = QDate::currentDate());
    void addData(const QString &city, const QJsonObject &data);
    void removeData(const QString &city);
    void clearExpired();

private:

    struct CacheEntry{
        QJsonObject data;
        QDateTime timestamp;
    };
    QMap<QString, CacheEntry> cache;
};

#endif // WEATHERCACHE_H
