#include "ConfigProvider.h"
#include <QDebug>

ConfigProvider::ConfigProvider(IConfigLoader *configLoader)
    :configLoader_(configLoader)
{
    appConfig_ = configLoader_->load();
}

Result<ApiConfig> ConfigProvider::getApiConfig()
{
    if (appConfig_.isSuccess()) {
        return Result<ApiConfig>::success(appConfig_.value().apiConfig);
    } else {
         return Result<ApiConfig>::failure(appConfig_.errorMessage());
    }
}

Result<ServerHostConfig> ConfigProvider::getServerHostConfig()
{
    qDebug() << "ConfigProvider::getServerHostConfig()";
    if (appConfig_.isSuccess()) {
        return Result<ServerHostConfig>::success(appConfig_.value().serverHostConfig);
    } else {
         return Result<ServerHostConfig>::failure(appConfig_.errorMessage());
    }
}
