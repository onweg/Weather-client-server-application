#include "WeatherDatabaseInitializer.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

bool WeatherDatabaseInitializer::initialize() {
    QSqlDatabase db;
    if (!QSqlDatabase::contains()) {
        db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName(DB_PATH);

        if (!db.open()) {
            qDebug() << "Ошибка подключения:" << db.lastError();
            return false;
        }
    } else {
        db = QSqlDatabase::database();
    }

    QSqlQuery query;
    if (!query.exec("CREATE TABLE IF NOT EXISTS weather_data ("
                    "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                    "username TEXT, "
                    "timestamp DATETIME DEFAULT CURRENT_TIMESTAMP, "
                    "city TEXT, "
                    "date TEXT)")) {
        qDebug() << "Ошибка при создании таблицы:" << query.lastError();
        return false;
    }

    return true;
}
