#ifndef CONFIGLOADER_H
#define CONFIGLOADER_H

#include "../../../Domain/Interfaces/Config/IConfigLoader.h"
#include <QByteArray>
#include <QJsonObject>
#define FILE_PATH "/usr/share/ru.auroraos.WeatherApplication/config/config.json"

class ConfigLoader : public IConfigLoader {
public:
    explicit ConfigLoader();
    // принимаем ничего, получсем Json файл, переводим его в Dto, потом переводит в entiy, возвращаем entiry
    Result<AppConfig> load() override;
private:
    QByteArray readFile(const QString& path);
    Result<QJsonObject> parseJson(const QByteArray& jsonData);
};

#endif // CONFIGLOADER_H

