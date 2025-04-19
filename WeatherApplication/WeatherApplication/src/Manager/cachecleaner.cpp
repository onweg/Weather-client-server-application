#include "cachecleaner.h"

CacheCleaner::CacheCleaner(QObject *parent) : QObject(parent)
{
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &CacheCleaner::timeout);
}

void CacheCleaner::start()
{
    if (!timer->isActive()) {
        timer->start(SEC * 1000);
    }
}
