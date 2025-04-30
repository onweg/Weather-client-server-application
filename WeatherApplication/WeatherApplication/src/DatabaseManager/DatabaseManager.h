#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QObject>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QString>
#include <QDate>
#include <QVariantList>
#include <QList>
#include "../Models/WeatherHistoryItem.h"

class DatabaseManager : public QObject
{
    Q_OBJECT
public:
    explicit DatabaseManager(QObject *parent = nullptr);
    QList<WeatherHistoryItem> getAllWeatherData();
    void insertWeatherData(const WeatherHistoryItem &item);

public slots:
    void slotSubmitCompletedWeatherDataSearchRequest(const WeatherHistoryItem &item);

private:
    QSqlDatabase db;
};

#endif // DATABASEMANAGER_H
