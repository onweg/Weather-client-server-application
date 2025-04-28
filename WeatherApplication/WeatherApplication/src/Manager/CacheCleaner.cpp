#include "CacheCleaner.h"

CacheCleaner::CacheCleaner(QObject *parent) : QObject(parent)
{
    timer_ = new QTimer(this);
    connect(timer_, &QTimer::timeout, this, &CacheCleaner::timeout);
}

void CacheCleaner::start()
{
    if (!timer_->isActive()) {
        timer_->start(SEC * 1000);
    }
}
