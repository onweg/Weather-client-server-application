#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QObject>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QString>
#include <QDate>
#include <QVariantList>

class DatabaseManager : public QObject
{
    Q_OBJECT
public:
    explicit DatabaseManager(QObject *parent = nullptr);
    QVariantList getAllWeatherData();
    void insertWeatherData(const QString &username, const QString &city, const QString &date);

public slots:
    void slotSubmitCompletedWeatherDataSearchRequest(const QString &username, const QString &city, const QDate &date);

private:
    bool connectToDataBase();
    void createTable();
};

#endif // DATABASEMANAGER_H
