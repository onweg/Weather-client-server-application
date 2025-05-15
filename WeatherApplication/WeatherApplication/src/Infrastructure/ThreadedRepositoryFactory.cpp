#include "ThreadedRepositoryFactory.h"
#include "../Data/Repositories/Api/UserRepository.h"
#include "../Data/Repositories/Api/WeatherApiSource.h"

struct ThreadedWorker {
    QThread* thread;
    QObject* worker;
};

template<typename TImpl, typename TInterface>
static std::shared_ptr<TInterface> createThreadedRepository(QObject* parent) {
    auto* thread = new QThread(parent);
    auto* worker = new TImpl();
    worker->moveToThread(thread);

    QObject::connect(thread, &QThread::started, [worker]() {
        // Можно вызвать init()
    });

    QObject::connect(worker, &QObject::destroyed, thread, &QThread::deleteLater);

    thread->start();

    return std::shared_ptr<TInterface>(dynamic_cast<TInterface*>(worker),
        [thread](TInterface*) { thread->quit(); });
}
