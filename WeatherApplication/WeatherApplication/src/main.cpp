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

#include "infrastructure/DependencyContainer.h"

int main(int argc, char *argv[])
{
	QScopedPointer<QGuiApplication> application(
	    Aurora::Application::application(argc, argv));
	application->setOrganizationName(QStringLiteral("ru.auroraos"));
	application->setApplicationName(QStringLiteral("WeatherApplication"));

	QScopedPointer<QQuickView> view(Aurora::Application::createView());
	auto *rootView = view.data();

	DependencyContainer container(rootView);
	if (!container.init())
	{
		qDebug() << "Не удалось инициализировать приложение";
		return -1;
	}

	view->rootContext()->setContextProperty("authViewModel",
	                                        container.getAuthViewModel());
	view->rootContext()->setContextProperty("weatherViewModel",
	                                        container.getWeatherViewModel());
	view->setSource(Aurora::Application::pathTo(
	    QStringLiteral("qml/WeatherApplication.qml")));
	view->show();

	return application->exec();
}

// проверить от куда берутся данные из кеш или из api, сохраняются ли вообще
// данные в кеш
