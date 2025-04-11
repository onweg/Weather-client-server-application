#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QObject>

// работает с базой данных
// хранит историю прогноза погоды

class DatabaseManager : public QObject
{
    Q_OBJECT
public:
    explicit DatabaseManager(QObject *parent = nullptr);

public slots:
    void slotSubmitCompletedWeatherDataSearchRequest(const QString &user, const QDateTime &timestamp, const QString &city, const QDate &date, const QJsonObject &jsonObj);

};

#endif // DATABASEMANAGER_H
