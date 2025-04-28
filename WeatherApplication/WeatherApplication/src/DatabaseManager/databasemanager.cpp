#include "databasemanager.h"

DatabaseManager::DatabaseManager(QObject *parent) : QObject(parent)
{
    connectToDataBase();
    createTable();
}

bool DatabaseManager::connectToDataBase()
{
    if (!QSqlDatabase::contains()) {
        QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName("weather_data_request.db");

        if (!db.open()) {
            qDebug() << "Ошибка подключения к базе данных:" << db.lastError();
            return false;
        }
    }
    qDebug() << "Успешное подключение к базе данных";
    return true;
}

void DatabaseManager::createTable()
{
    QSqlQuery query;
    if (!query.exec("CREATE TABLE IF NOT EXISTS weather_data ("
                    "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                    "username TEXT, "
                    "timestamp DATETIME DEFAULT CURRENT_TIMESTAMP, "
                    "city TEXT, "
                    "date TEXT)")) {
        qDebug() << "Ошибка при создании таблицы:" << query.lastError();
    } else {
        qDebug() << "Таблица weather_data успешно создана или уже существует";
    }
}

void DatabaseManager::insertWeatherData(const QString &username, const QString &city, const QString &date)
{
    QSqlQuery query;
    query.prepare("INSERT INTO weather_data (username, city, date) "
                  "VALUES (:username, :city, :date)");
    query.bindValue(":username", username);
    query.bindValue(":city", city);
    query.bindValue(":date", date);

    if (!query.exec()) {
        qDebug() << "Ошибка при вставке данных:" << query.lastError();
    } else {
        qDebug() << "Данные успешно добавлены в базу данных";
    }
}

QVariantList DatabaseManager::getAllWeatherData()
{
    QVariantList results;
    QSqlQuery query("SELECT id, username, timestamp, city, date FROM weather_data");

    if (!query.exec()) {
        qDebug() << "Ошибка при получении данных:" << query.lastError();
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

void DatabaseManager::slotSubmitCompletedWeatherDataSearchRequest(const QString &username, const QString &city, const QDate &date)
{
    insertWeatherData(username, city, date.toString("yyyy-MM-dd"));
}
