#include "ConfigLoader.h"
#include <QFile>
#include <QJsonObject>
#include <QJsonParseError>
#include <QDebug>

#include "../../Utils/AppConfigJsonConverter.h"

ConfigLoader::ConfigLoader()
{

}

Result<AppConfig> ConfigLoader::load()
{
    qDebug() << "ConfigLoader::load()";
    QFile file(QString::fromStdString(FILE_PATH));
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Не удалось открыть config.json файл";
        return Result<AppConfig>::failure("Не удалось открыть config.json файл");

    }
    QByteArray jsonData = file.readAll();
    file.close();
    QJsonParseError parseError;
    QJsonDocument doc = QJsonDocument::fromJson(jsonData, &parseError);
    if (parseError.error != QJsonParseError::NoError) {
        qDebug() << "Ошибка парсинга json файла";
        return Result<AppConfig>::failure("Ошибка парсинга json файла");
    }
    AppConfig appConfig;
    if (AppConfigJsonConverter::fromJson(doc.object(), appConfig) == false) {
        qDebug() << "Нет нужных полей в config.json";
        return Result<AppConfig>::failure("Нет нужных полей в config.json");
    }
    qDebug() << "Конец загрузки ConfigLoader::load()";
    return Result<AppConfig>::success(appConfig);
}
