#include "ConfigLoader.h"

#include <QDebug>
#include <QFile>
#include <QJsonDocument>
#include <QJsonParseError>

#include "../../../utils/AppConfigJsonConverter.h"
#include "../../dtomodels/AppConfigDto.h"
#include "../../mappers/AppConfigDomainMapper.h"

ConfigLoader::ConfigLoader() {}

Result<AppConfig> ConfigLoader::
load()
{
	QByteArray data = readFile(FILE_PATH);
	if (data.isEmpty())
	{
		return Result<AppConfig>::failure("Не удалось прочитать файл");
	}
	auto jsonResult = parseJson(data);
	if (!jsonResult.isSuccess())
	{
		return Result<AppConfig>::failure(jsonResult.errorMessage());
	}
    AppConfigDto dto;
	int result = AppConfigJsonConverter::fromJson(jsonResult.value(), dto);
	if (!result)
	{
		return Result<AppConfig>::failure("Некорректный формат config.json");
	}
	AppConfig config = AppConfigDomainMapper::fromDto(dto);
	return Result<AppConfig>::success(config);
}

QByteArray ConfigLoader::readFile(const QString &path)
{
	QFile file(path);
	if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
	{
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
	if (error.error != QJsonParseError::NoError)
	{
		qDebug() << "Ошибка парсинга JSON:" << error.errorString();
		return Result<QJsonObject>::failure("Ошибка парсинга JSON");
	}
	if (!doc.isObject())
	{
		return Result<QJsonObject>::failure("JSON не является объектом");
	}
	return Result<QJsonObject>::success(doc.object());
}
