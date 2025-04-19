#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QObject>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QString>
#include <QDate>
#include <QDir>

// работает с базой данных
// хранит историю прогноза погоды

class DatabaseManager : public QObject
{
    Q_OBJECT
public:
    explicit DatabaseManager(QObject *parent = nullptr);
    void insertData(const QString &user, const QString &city, const QString &date);

private:
    bool connectToDataBase();
    void createTable();

public slots:
    void slotSubmitCompletedWeatherDataSearchRequest(const QString &user, const QString &city, const QDate &date);

};

#endif // DATABASEMANAGER_H
