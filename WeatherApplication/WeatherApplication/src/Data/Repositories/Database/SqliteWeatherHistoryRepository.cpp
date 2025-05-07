#include "SqliteWeatherHistoryRepository.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QVariant>
#include <QDateTime>
#include <QDebug>

SqliteWeatherHistoryRepository::SqliteWeatherHistoryRepository(std::shared_ptr<IWeatherDatabaseInitializer> dbInitializer, std::shared_ptr<ISharedState> state)
    :sharedState_(std::move(state))
{
    dbInitializer->initialize();
    db_ = QSqlDatabase::database();
    if (!db_.isOpen()) {
        qWarning() << "База данных не открыта!";
    }
}

std::vector<WeatherHistoryItem> SqliteWeatherHistoryRepository::getAll() {
    std::vector<WeatherHistoryItem> results;
    QSqlQuery query("SELECT id, username, timestamp, city, date FROM weather_data");

    if (!query.exec()) {
        qDebug() << "Ошибка при получении данных:" << query.lastError();
        return results;
    }

    while (query.next()) {
        WeatherHistoryItem row;
        row.id = query.value("id").toInt();
        row.username = query.value("username").toString().toStdString();
        row.city = query.value("city").toString().toStdString();
        row.date = query.value("date").toString().toStdString();

        QDateTime timestamp = query.value("timestamp").toDateTime();
        row.timestamp = std::chrono::system_clock::from_time_t(static_cast<std::time_t>(timestamp.toMSecsSinceEpoch() / 1000));
        results.push_back(row);
    }

    return results;
}

void SqliteWeatherHistoryRepository::save(const std::string &city, const std::string &date) {
    QSqlQuery query;
    query.prepare("INSERT INTO weather_data (username, city, date) "
                      "VALUES (:username, :city, :date)");

    query.bindValue(":username", QString::fromStdString(sharedState_->getUsername()));
    query.bindValue(":city", QString::fromStdString(city));
    query.bindValue(":date", QString::fromStdString(date));

    if (!query.exec()) {
        qDebug() << "Ошибка при вставке:" << query.lastError();
    }
}
