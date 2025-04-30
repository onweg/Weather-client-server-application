#include "DatabaseManager.h"

DatabaseManager::DatabaseManager(QObject *parent) : QObject(parent)
{
    db = QSqlDatabase::database();
    if (!db.isOpen()) {
        qDebug() << "База данных не открыта. Убедитесь, что DatabaseCreator был инициализирован.";
    }
}

QList<WeatherHistoryItem> DatabaseManager::getAllWeatherData()
{
    QList<WeatherHistoryItem> results;
    QSqlQuery query("SELECT id, username, timestamp, city, date FROM weather_data");
    if (!query.exec()) {
        qDebug() << "Ошибка при получении данных:" << query.lastError();
        return results;
    }

    while (query.next()) {
        WeatherHistoryItem row;
        row.id = query.value("id").toInt();
        row.username = query.value("username").toString();
        row.timestamp = query.value("timestamp").toDateTime();
        row.city = query.value("city").toString();
        row.date = query.value("date").toDate();
        results.append(row);
    }
    return results;
}

void DatabaseManager::insertWeatherData(const WeatherHistoryItem &item)
{
    QSqlQuery query;
    query.prepare("INSERT INTO weather_data (username, city, date) "
                  "VALUES (:username, :city, :date)");
    query.bindValue(":username", item.username);
    query.bindValue(":city", item.city);
    query.bindValue(":date", item.date);

    if (!query.exec()) {
        qDebug() << "Ошибка при вставке данных:" << query.lastError();
    } else {
        qDebug() << "Данные успешно добавлены в базу данных";
    }
}

void DatabaseManager::slotSubmitCompletedWeatherDataSearchRequest(const WeatherHistoryItem &item)
{
    insertWeatherData(item);
}
