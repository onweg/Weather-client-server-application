/*******************************************************************************
**
** Copyright (C) 2022 ru.auroraos
**
** This file is part of the My Aurora OS Application project.
**
** Redistribution and use in source and binary forms,
** with or without modification, are permitted provided
** that the following conditions are met:
**
** * Redistributions of source code must retain the above copyright notice,
**   this list of conditions and the following disclaimer.
** * Redistributions in binary form must reproduce the above copyright notice,
**   this list of conditions and the following disclaimer
**   in the documentation and/or other materials provided with the distribution.
** * Neither the name of the copyright holder nor the names of its contributors
**   may be used to endorse or promote products derived from this software
**   without specific prior written permission.
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
** AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
** THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
** FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
** IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
** FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY,
** OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
** PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
** LOSS OF USE, DATA, OR PROFITS;
** OR BUSINESS INTERRUPTION)
** HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
** WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE)
** ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
** EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
**
*******************************************************************************/

#include <auroraapp.h>
#include <QtQuick>
#include <QObject>
#include "weathermanager.h"
#include "clientcontroller.h"
#include "weatherapiclient.h"
#include "weathercache.h"
#include "databasemanager.h"

int main(int argc, char *argv[])
{
    QScopedPointer<QGuiApplication> application(Aurora::Application::application(argc, argv));
    application->setOrganizationName(QStringLiteral("ru.auroraos"));
    application->setApplicationName(QStringLiteral("WeatherApplication"));



    QScopedPointer<QQuickView> view(Aurora::Application::createView());
    WeatherManager manager;
    WeatherApiClient api;
    ClientController controller;
    WeatherCache cache;
    DatabaseManager db;
    QObject::connect(&controller, &ClientController::findWeatherData, &manager, &WeatherManager::slotFindWeatherData); // получили данные в каком городе в какой день искать погоду
    QObject::connect(&manager, &WeatherManager::findWeatherDataInCache, &cache, &WeatherCache::slotFindWeatherDataInCache); // ( сначала смотрим в кеш данные о горожде в определенный день)
    QObject::connect(&cache, &WeatherCache::sendWeatherDataFromCache, &manager, &WeatherManager::slotRecivedWeatherDataFromCache); // ( взвращает в манагер сформированный json )
    QObject::connect(&manager, &WeatherManager::sendWeatherDataToController, &controller, &ClientController::slotWeatherDataArrived); // если все хорошо то connect между манагер и контроллер (отправляет получившийся готовый json )
    QObject::connect(&manager, &WeatherManager::submitCompletedWeatherDataSearchRequest, &db, &DatabaseManager::slotSubmitCompletedWeatherDataSearchRequest);  //          ( сохраняем запрос который нам послали в бд )
    QObject::connect(&manager, &WeatherManager::findWeatherDataInAPI, &api, &WeatherApiClient::slotFindWeatherDataInAPI);     // если нет данных то идем искать все данные о городе через апи
    QObject::connect(&api, &WeatherApiClient::sendRecivedWeatherDataFromAPI, &manager, &WeatherManager::slotRecivedWeatherDataFromAPI); // возвращаем сформированный json по поиску данных о погоде в города
    QObject::connect(&manager, &WeatherManager::addNewWeatherDataInCache, &cache, &WeatherCache::slotAddNewWeatherDataInCache); // должен сохранить новые данные из api что получили )
    QObject::connect(&cache, &WeatherCache::dataInCacheUpdtaed, &manager, &WeatherManager::slotDataInCacheUpdated); // обновили данные в кеш
    /* connect между манагер и кеш             ( сначала смотрим в кеш данные о горожде в определенный день) */
    /* connect между кеш манагер               ( взвращает в манагер сформированный json ) */
    /* connect между манагер и контроллер      ( отправляем сформированный json даже если ошибка ) */
    /* connect между manager и бд              ( сохраняем запрос который нам послали в бд ) */

    view->rootContext()->setContextProperty("controller", &controller);
    view->setSource(Aurora::Application::pathTo(QStringLiteral("qml/WeatherApplication.qml")));
    view->show();


    return application->exec();
}


// хотим найти город
// ищем город в кеш (cc wm)
// если в кеш нет идем искать в API
// получили данные о городе идем записывать в кеш, в бд,
