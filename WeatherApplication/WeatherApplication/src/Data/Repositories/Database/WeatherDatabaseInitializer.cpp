#include "WeatherDatabaseInitializer.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

bool WeatherDatabaseInitializer::initialize() {
    if (!connectToDatabase()) return false;
    if (!createTableIfNotExists()) return false;
    return true;
}

bool WeatherDatabaseInitializer::connectToDatabase() {
    if (QSqlDatabase::contains()) {
        return true;
    }
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(DB_PATH);
    if (!db.open()) {
        qDebug() << "Ошибка подключения к БД:" << db.lastError();
        return false;
    }
    return true;
}

bool WeatherDatabaseInitializer::createTableIfNotExists() {
    QSqlQuery query;
    bool ok = query.exec(
                "CREATE TABLE IF NOT EXISTS weather_data ("
            "id INTEGER PRIMARY KEY AUTOINCREMENT, "
            "username TEXT, "
            "timestamp DATETIME DEFAULT CURRENT_TIMESTAMP, "
            "city TEXT, "
            "date TEXT)"
        );
    if (!ok) {
        qDebug() << "Ошибка при создании таблицы:" << query.lastError();
    }
    return ok;
}
