################################################################################
##
## Copyright (C) 2022 ru.auroraos
## 
## This file is part of the My Aurora OS Application project.
##
## Redistribution and use in source and binary forms,
## with or without modification, are permitted provided
## that the following conditions are met:
##
## * Redistributions of source code must retain the above copyright notice,
##   this list of conditions and the following disclaimer.
## * Redistributions in binary form must reproduce the above copyright notice,
##   this list of conditions and the following disclaimer
##   in the documentation and/or other materials provided with the distribution.
## * Neither the name of the copyright holder nor the names of its contributors
##   may be used to endorse or promote products derived from this software
##   without specific prior written permission.
##
## THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
## AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
## THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
## FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
## IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
## FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY,
## OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
## PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
## LOSS OF USE, DATA, OR PROFITS;
## OR BUSINESS INTERRUPTION)
## HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
## WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
## (INCLUDING NEGLIGENCE OR OTHERWISE)
## ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
## EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
##
################################################################################

QT += network core sql

TARGET = ru.auroraos.WeatherApplication

CONFIG += \
    auroraapp \
    c++17

PKGCONFIG += \

SOURCES += \
    src/ClientController/ClientController.cpp \
    src/ClientController/WeatherUpdater.cpp \
    src/DatabaseManager/DatabaseManager.cpp \
    src/DatabaseManager/DatabaseCreator.cpp \
    src/Manager/CacheCleaner.cpp \
    src/Manager/WeatherApiClient.cpp \
    src/Manager/WeatherCache.cpp \
    src/Manager/WeatherManager.cpp \
#    src/Models/WeatherModeList.cpp \
#    src/Models/WeatherModel.cpp \
#    src/Models/WeekWeatherModel.cpp \
    src/Utils/AuthorizationInfoJsonConverter.cpp \
    src/Utils/AuthorizationReplyJsonConverter.cpp \
    src/Utils/WeatherJsonConverter.cpp \
    src/Utils/AppConfigJsonConverter.cpp \
    src/Presentation/ViewModel/AuthViewModel.cpp \
    src/Domain/UseCases/AuthenticateUserUseCase.cpp \
    src/Domain/UseCases/RegisterUserUseCase.cpp \
    src/Domain/Utils/Result.cpp \
    src/Data/Api/UserRepository.cpp \
    src/Data/Config/ConfigProvider.cpp \
    src/Data/Config/ConfigLoader.cpp \
    src/Infrastructure/DependencyContainer.cpp\
    src/main.cpp

HEADERS += \
    src/ClientController/ClientController.h \
    src/ClientController/WeatherUpdater.h \
    src/Domain/Models/AuthorizationReply.h \
    src/Domain/Repositories/IConfigLoader.h \
    src/Domain/Repositories/IConfigProvider.h \
    src/Domain/Utils/SimpleOptional.h \
#    src/Models/AppConfig.h \
    src/DatabaseManager/DatabaseManager.h \
    src/DatabaseManager/DatabaseCreator.h \
    src/Manager/CacheCleaner.h \
    src/Manager/WeatherApiClient.h \
    src/Manager/WeatherCache.h \
    src/Manager/WeatherManager.h \
#    src/Models/WeatherModeList.h \
#    src/Models/WeatherModel.h \
#    src/Models/WeekWeatherModel.h \
#    src/Models/ApiConfig.h \
#    src/Models/ApiReply.h \
#    src/Models/AuthorizationInfo.h \
#    src/Models/AuthorizationReply.h \
#    src/Models/ServerHostConfig.h \
#    src/Models/WeatherData.h \
#    src/Models/WeatherHistoryItem.h \
#    src/Models/WeekWeatherData.h \
    src/Utils/AuthorizationInfoJsonConverter.h \
    src/Utils/AuthorizationReplyJsonConverter.h \
    src/Utils/AppConfigJsonConverter.h \
    src/Utils/WeatherJsonConverter.h \
    src/Presentation/ViewModel/AuthViewModel.h \
    src/Domain/UseCases/AuthenticateUserUseCase.h \
    src/Domain/UseCases/RegisterUserUseCase.h \
    src/Domain/Repositories/IUserRepository.h \
    src/Domain/Models/User.h \
    src/Domain/Models/ApiConfig.h \
    src/Domain/Models/ServerHostConfig.h \
    src/Domain/Models/AppConfig.h \
    src/Domain/Utils/Result.h \
    src/Data/Api/UserRepository.h \
    src/Data/Config/ConfigProvider.h \
    src/Data/Config/ConfigLoader.h \
    src/Infrastructure/DependencyContainer.h\

DISTFILES += \
    qml/components/DateAndButtons.qml \
    qml/components/InputCity.qml \
    qml/components/SearchPanel.qml \
    qml/components/WeatherData.qml \
    qml/components/WeatherInformation.qml \
    qml/components/Authorization.qml \
    qml/pages/MainPage.qml \
    qml/pages/WeatherPage.qml \
    qml/pages/WeekWeatherPage.qml \
    qml/WeatherApplication.qml \
    qml/cover/DefaultCoverPage.qml \
    rpm/ru.auroraos.WeatherApplication.spec \
    AUTHORS.md \
    CODE_OF_CONDUCT.md \
    CONTRIBUTING.md \
    LICENSE.BSD-3-CLAUSE.md \
    README.md \
    config/config.json


AURORAAPP_ICONS = 86x86 108x108 128x128 172x172

CONFIG += auroraapp_i18n

TRANSLATIONS += \
    translations/ru.auroraos.WeatherApplication.ts \
    translations/ru.auroraos.WeatherApplication-ru.ts \
    
my_additional_files.files = $${PWD}/config/*
my_additional_files.path = /usr/share/ru.auroraos.WeatherApplication/config
my_additional_files.CONFIG = no_check_exist

INSTALLS += \
    my_additional_files
