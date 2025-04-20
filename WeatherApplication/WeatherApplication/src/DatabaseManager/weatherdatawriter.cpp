#include "weatherdatawriter.h"

WeatherDataWriter::WeatherDataWriter(QObject *parent) : QObject(parent)
{
    connectToDataBase();
    createTable();
}

void WeatherDataWriter::insertData(const QString &username, const QString &city, const QString &date)
{
    QSqlQuery query;

    query.prepare("INSERT INTO weather_data (username, city, date) "
                  "VALUES (:username, :city, :date)");
    query.bindValue(":username", username);
    query.bindValue(":city", city);
    query.bindValue(":date", date);

    if (!query.exec()) {
        qDebug() << "Ошибка при вставке данных: " << query.lastError();
    } else {
        qDebug() << "Данные успешно добавлены в базу данных!";
    }
}

bool WeatherDataWriter::connectToDataBase()
{
    if (!QSqlDatabase::contains()) {
        QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName("weather_data_request.db");
        if (!db.open()) {
            qDebug() << "Ошибка подключения к базе данных";
            return false;
        }
    }
    qDebug() << "Успешное подключение к базе данных";
    return true;
}

void WeatherDataWriter::createTable()
{
    QSqlQuery query;
    if (!query.exec("CREATE TABLE IF NOT EXISTS weather_data ("
                    "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                    "username TEXT, "
                    "timestamp DATETIME DEFAULT CURRENT_TIMESTAMP, "
                    "city TEXT, "
                    "date TEXT)")) {
        qDebug() << "Ошибка при создании таблицы: " << query.lastError();
    }
}

void WeatherDataWriter::slotSubmitCompletedWeatherDataSearchRequest(const QString &user, const QString &city, const QDate &date)
{
    insertData(user, city, date.toString("yyyy-MM-dd"));
}
