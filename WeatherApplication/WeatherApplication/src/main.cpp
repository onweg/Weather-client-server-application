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
#include "Manager/weathermanager.h"
#include "ClientController/clientcontroller.h"
#include "DatabaseManager/weatherdatawriter.h"

int main(int argc, char *argv[])
{
    QScopedPointer<QGuiApplication> application(Aurora::Application::application(argc, argv));
    application->setOrganizationName(QStringLiteral("ru.auroraos"));
    application->setApplicationName(QStringLiteral("WeatherApplication"));

    QScopedPointer<QQuickView> view(Aurora::Application::createView());

    WeatherManager manager;
    if (!manager.loadConfig()) {
       return 0;
    }
    ClientController controller;
    WeatherDataWriter writer;

    QObject::connect(&controller, &ClientController::findWeatherData, &manager, &WeatherManager::slotFindWeatherData);
    QObject::connect(&controller, &ClientController::findWeekWeatherData, &manager, &WeatherManager::slotFindWeekWeatherData);
    QObject::connect(&manager, &WeatherManager::sendWeatherDataToController, &controller, &ClientController::slotWeatherDataArrived);
    QObject::connect(&manager, &WeatherManager::sendWeekWeatherDataToController, &controller, &ClientController::slotWeekWeatherDataArrived);
    QObject::connect(&manager, &WeatherManager::submitCompletedWeatherDataSearchRequest, &writer, &WeatherDataWriter::slotSubmitCompletedWeatherDataSearchRequest);
    QObject::connect(&controller, &ClientController::sendAuthorizationDataToManager, &manager, &WeatherManager::sloRecivedAuthorizationData);
    QObject::connect(&manager, &WeatherManager::sendAuthorizationResult, &controller, &ClientController::slotRecivedAuthorizationData);

    view->rootContext()->setContextProperty("controller", &controller);
    view->setSource(Aurora::Application::pathTo(QStringLiteral("qml/WeatherApplication.qml")));
    view->show();


    return application->exec();
}

// добавлять в бд все запросы
// погода на неделю


