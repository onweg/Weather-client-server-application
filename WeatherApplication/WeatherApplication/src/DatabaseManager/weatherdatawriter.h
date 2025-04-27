// #ifndef WEATHERDATAWRITER_H
// #define WEATHERDATAWRITER_H

// #include <QObject>
// #include <QSqlDatabase>
// #include <QSqlQuery>
// #include <QSqlError>
// #include <QDebug>
// #include <QString>
// #include <QDate>
// #include <QDir>

// class WeatherDataWriter : public QObject
// {
//     Q_OBJECT
// public:
//     explicit WeatherDataWriter(QObject *parent = nullptr);
//     void insertData(const QString &user, const QString &city, const QString &date);

// private:
//     bool connectToDataBase();
//     void createTable();

// public slots:
//     void slotSubmitCompletedWeatherDataSearchRequest(const QString &user, const QString &city, const QDate &date);
// };

// #endif // WEATHERDATAWRITER_H
