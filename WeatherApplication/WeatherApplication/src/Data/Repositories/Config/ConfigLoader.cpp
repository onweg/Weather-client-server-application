#include "ConfigLoader.h"
#include <QFile>
#include <QJsonParseError>
#include <QDebug>
#include <QJsonDocument>

#include "../../../Utils/AppConfigJsonConverter.h"

ConfigLoader::ConfigLoader()
{

}

Result<AppConfig> ConfigLoader::load()
{
    QByteArray data = readFile(FILE_PATH);
    if (data.isEmpty()) {
        return Result<AppConfig>::failure("Не удалось прочитать файл");
    }
    auto jsonResult = parseJson(data);
    if (!jsonResult.isSuccess()) {
        return Result<AppConfig>::failure(jsonResult.errorMessage());
    }
    AppConfig config;
    if (!AppConfigJsonConverter::fromJson(jsonResult.value(), config)) {
        return Result<AppConfig>::failure("Некорректный формат config.json");
    }
    return Result<AppConfig>::success(config);
}

QByteArray ConfigLoader::readFile(const QString &path)
{
    QFile file(path);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Ошибка открытия файла:" << path;
        return {};
    }
    QByteArray data = file.readAll();
    file.close();
    return data;
}

Result<QJsonObject> ConfigLoader::parseJson(const QByteArray &jsonData)
{
    QJsonParseError error;
    QJsonDocument doc = QJsonDocument::fromJson(jsonData, &error);
    if (error.error != QJsonParseError::NoError) {
        qDebug() << "Ошибка парсинга JSON:" << error.errorString();
        return Result<QJsonObject>::failure("Ошибка парсинга JSON");
    }
    if (!doc.isObject()) {
        return Result<QJsonObject>::failure("JSON не является объектом");
    }
    return Result<QJsonObject>::success(doc.object());
}


