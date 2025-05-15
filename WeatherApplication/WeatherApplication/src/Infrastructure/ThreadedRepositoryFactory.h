#ifndef THREADEDREPOSITORYFACTORY_H
#define THREADEDREPOSITORYFACTORY_H

#include <memory>
#include <QObject>
#include <QThread>

#include "../Domain/Interfaces/Api/IUserRepository.h"
#include "../Domain/Interfaces/Api/IApiWeatherSource.h"

class ThreadedRepositoryFactory : public QObject {
    Q_OBJECT
public:
    static std::shared_ptr<IUserRepository> createUserRepository(QObject* parent = nullptr);
    static std::shared_ptr<IApiWeatherSource> createWeatherApiSource(QObject* parent = nullptr);
};
#endif // THREADEDREPOSITORYFACTORY_H
