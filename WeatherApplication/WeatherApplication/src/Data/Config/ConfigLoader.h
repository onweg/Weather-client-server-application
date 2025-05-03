#ifndef CONFIGLOADER_H
#define CONFIGLOADER_H

#include "../../Domain/Repositories/IConfigLoader.h"

#define FILE_PATH "/usr/share/ru.auroraos.WeatherApplication/config/config.json"

class ConfigLoader : public IConfigLoader {
public:
    explicit ConfigLoader();
    Result<AppConfig> load() override;
};

#endif // CONFIGLOADER_H

