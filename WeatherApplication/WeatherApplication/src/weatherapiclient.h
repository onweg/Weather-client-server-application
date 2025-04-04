#ifndef WEATHERAPICLIENT_H
#define WEATHERAPICLIENT_H

// общается с внешним API через Http протокол
// получает данные в виде JSON формата
// Обрабатывает ошибки

#include <QObject>

class WeatherApiClient : public QObject
{
    Q_OBJECT
public:
    explicit WeatherApiClient(QObject *parent = nullptr);

signals:

};

#endif // WEATHERAPICLIENT_H
