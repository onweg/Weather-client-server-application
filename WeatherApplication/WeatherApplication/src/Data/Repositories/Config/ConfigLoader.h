#ifndef CONFIGLOADER_H
#define CONFIGLOADER_H

#include <QByteArray>
#include <QJsonObject>

#include "../../../Domain/Interfaces/Config/IConfigLoader.h"
#define FILE_PATH "/usr/share/ru.auroraos.WeatherApplication/config/config.json"

class ConfigLoader : public IConfigLoader
{
  public:
	explicit ConfigLoader();
	Result<AppConfig> load() override;

  private:
	QByteArray readFile(const QString &path);
	Result<QJsonObject> parseJson(const QByteArray &jsonData);
};

#endif // CONFIGLOADER_H
