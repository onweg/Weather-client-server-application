#ifndef CACHECLEANER_H
#define CACHECLEANER_H

#include <QObject>
#include <QTimer>

#define SEC 3600

class CacheCleaner : public QObject
{
    Q_OBJECT
public:
    explicit CacheCleaner(QObject *parent = nullptr);
    void start();

private:
    QTimer *timer;

signals:
    void timeout();
};

#endif // CACHECLEANER_H
