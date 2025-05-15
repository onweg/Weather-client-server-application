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

QT += network core sql concurrent

TARGET = ru.auroraos.WeatherApplication

CONFIG += \
    auroraapp \
    c++17

PKGCONFIG += \

SOURCES += \
    src/Data/Mappers/WeatherDomainMapper.cpp \
    src/Data/Mappers/WeekWeatherDomainMapper.cpp \
    src/Data/Repositories/Database/SqliteWeatherHistoryRepository.cpp \
    src/Data/Repositories/Database/WeatherDatabaseInitializer.cpp \
    src/Data/Repositories/SharedState/SharedState.cpp \
    src/Domain/UseCases/GetWeatherHistoryUseCase.cpp \
    src/Domain/UseCases/SaveWeatherHistoryUseCase.cpp \
    src/Infrastructure/ThreadedRepositoryFactory.cpp \
    src/Presentation/Mappers/WeatherUiMapper.cpp \
    src/Presentation/Mappers/WeekWeatherUiMapper.cpp \
    src/Presentation/UIModels/WeatherUiModel.cpp \
    src/Presentation/UIModels/WeekWeatherUiModel.cpp \
    src/Presentation/ViewModels/WeatherViewModel.cpp \
    src/Utils/AuthorizationInfoJsonConverter.cpp \
    src/Utils/AuthorizationReplyJsonConverter.cpp \
    src/Utils/WeatherJsonConverter.cpp \
    src/Utils/AppConfigJsonConverter.cpp \
    src/Presentation/ViewModels/AuthViewModel.cpp \
    src/Domain/UseCases/AuthenticateUserUseCase.cpp \
    src/Domain/UseCases/RegisterUserUseCase.cpp \
    src/Domain/UseCases/GetDailyWeatherUseCase.cpp \
    src/Domain/UseCases/GetWeeklyWeatherUseCase.cpp \
    src/Data/Repositories/Api/UserRepository.cpp \
    src/Data/Repositories/Api/WeatherApiSource.cpp \
    src/Data/Repositories/Config/ConfigProvider.cpp \
    src/Data/Repositories/Config/ConfigLoader.cpp \
    src/Data/Repositories/Cache/WeatherCache.cpp \
    src/Infrastructure/DependencyContainer.cpp\
    src/main.cpp

HEADERS += \
    src/Data/DtoModels/WeatherDataDto.h \
    src/Data/DtoModels/WeekWeatherDataDto.h \
    src/Data/Mappers/WeatherDomainMapper.h \
    src/Data/Mappers/WeekWeatherDomainMapper.h \
    src/Data/Repositories/Database/SqliteWeatherHistoryRepository.h \
    src/Data/Repositories/Database/WeatherDatabaseInitializer.h \
    src/Data/Repositories/SharedState/SharedState.h \
    src/Domain/Entities/AuthorizationReply.h \
    src/Domain/Entities/ApiConfig.h \
    src/Domain/Entities/AuthorizationRequest.h \
    src/Domain/Entities/ServerHostConfig.h \
    src/Domain/Entities/AppConfig.h \
    src/Domain/Entities/WeatherData.h \
    src/Domain/Entities/WeatherHistoryItem.h \
    src/Domain/Entities/WeekWeatherData.h \
    src/Domain/Interfaces/Api/IWeatherRepository.h \
    src/Domain/Interfaces/Cache/IWeatherCacheSource.h \
    src/Domain/Interfaces/Config/IConfigLoader.h \
    src/Domain/Interfaces/Config/IConfigProvider.h \
    src/Domain/Interfaces/Api/IUserRepository.h \
    src/Domain/Interfaces/Api/IApiWeatherSource.h \
    src/Domain/Interfaces/Database/IWeatherDatabaseInitializer.h \
    src/Domain/Interfaces/Database/IWeatherHistoryRepository.h \
    src/Domain/Interfaces/SharedState/ISharedState.h \
    src/Domain/UseCases/GetWeatherHistoryUseCase.h \
    src/Domain/UseCases/SaveWeatherHistoryUseCase.h \
    src/Domain/Utils/SimpleOptional.h \
    src/Infrastructure/ThreadedRepositoryFactory.h \
    src/Presentation/Mappers/WeatherUiMapper.h \
    src/Presentation/Mappers/WeekWeatherUiMapper.h \
    src/Presentation/UIModels/WeatherUiModel.h \
    src/Presentation/UIModels/WeekWeatherUiModel.h \
    src/Presentation/ViewModels/WeatherViewModel.h \
    src/Utils/AuthorizationInfoJsonConverter.h \
    src/Utils/AuthorizationReplyJsonConverter.h \
    src/Utils/AppConfigJsonConverter.h \
    src/Utils/WeatherJsonConverter.h \
    src/Presentation/ViewModels/AuthViewModel.h \
    src/Domain/UseCases/AuthenticateUserUseCase.h \
    src/Domain/UseCases/RegisterUserUseCase.h \
    src/Domain/UseCases/GetDailyWeatherUseCase.h \
    src/Domain/UseCases/GetWeeklyWeatherUseCase.h \
    src/Domain/Utils/Result.h \
    src/Data/Repositories/Api/UserRepository.h \
    src/Data/Repositories/Api/WeatherApiSource.h \
    src/Data/Repositories/Config/ConfigProvider.h \
    src/Data/Repositories/Config/ConfigLoader.h \
    src/Data/Repositories/Cache/WeatherCache.h \
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
