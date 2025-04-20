#include "weatherdatareader.h"

WeatherDataReader::WeatherDataReader(QObject *parent) : QObject(parent)
{
    // База уже должна быть открыта в другом месте
}

QVariantList WeatherDataReader::getAllWeatherData()
{
    QVariantList results;
    QSqlQuery query("SELECT id, username, timestamp, city, date FROM weather_data");

    if (!query.exec()) {
        qDebug() << "Ошибка при получении данных: " << query.lastError();
        return results;
    }

    while (query.next()) {
        QVariantMap row;
        row["id"] = query.value("id");
        row["username"] = query.value("username");
        row["timestamp"] = query.value("timestamp");
        row["city"] = query.value("city");
        row["date"] = query.value("date");
        results.append(row);
    }

    return results;
}
