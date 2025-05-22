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
    src/data/mappers/ApiConfigDomainMapper.cpp \
    src/data/mappers/AppConfigDomainMapper.cpp \
    src/data/mappers/AuthorizationReplyDomainMapper.cpp \
    src/data/mappers/AuthorizationRequestDomainMapper.cpp \
    src/data/mappers/CacheConfigDomainMapper.cpp \
    src/data/mappers/ServerHostConfigDomainMapper.cpp \
    src/data/mappers/WeatherDomainMapper.cpp \
    src/data/mappers/WeatherHistoryItemDomainMapper.cpp \
    src/data/mappers/WeekWeatherDomainMapper.cpp \
    src/data/repositories/database/QtDatabaseConnection.cpp \
    src/data/repositories/database/SqliteWeatherHistoryRepository.cpp \
    src/data/repositories/database/WeatherDatabaseInitializer.cpp \
    src/data/repositories/sharedstate/SharedState.cpp \
    src/data/repositories/weather/WeatherRepository.cpp \
    src/domain/entities/CacheConfig.cpp \
    src/domain/usecases/GetWeatherHistoryUseCase.cpp \
    src/domain/usecases/SaveWeatherHistoryUseCase.cpp \
    src/domain/entities/AuthorizationReply.cpp \
    src/domain/entities/AuthorizationRequest.cpp \
    src/domain/entities/ApiConfig.cpp \
    src/domain/entities/ServerHostConfig.cpp \
    src/domain/entities/AppConfig.cpp \
    src/domain/entities/WeatherData.cpp \
    src/domain/entities/WeatherHistoryItem.cpp \
    src/domain/entities/WeekWeatherData.cpp \
    src/presentation/mappers/WeatherUiMapper.cpp \
    src/presentation/mappers/WeekWeatherUiMapper.cpp \
    src/presentation/uimodels/WeatherUiModel.cpp \
    src/presentation/uimodels/WeekWeatherUiModel.cpp \
    src/presentation/viewmodels/WeatherViewModel.cpp \
    src/utils/AuthorizationInfoJsonConverter.cpp \
    src/utils/AuthorizationReplyJsonConverter.cpp \
    src/utils/WeatherJsonConverter.cpp \
    src/utils/AppConfigJsonConverter.cpp \
    src/presentation/viewmodels/AuthViewModel.cpp \
    src/domain/usecases/AuthenticateUserUseCase.cpp \
    src/domain/usecases/RegisterUserUseCase.cpp \
    src/domain/usecases/GetDailyWeatherUseCase.cpp \
    src/domain/usecases/GetWeeklyWeatherUseCase.cpp \
    src/data/repositories/api/UserRepository.cpp \
    src/data/repositories/api/WeatherApiSource.cpp \
    src/data/repositories/config/ConfigProvider.cpp \
    src/data/repositories/config/ConfigLoader.cpp \
    src/data/repositories/cache/WeatherCache.cpp \
    src/infrastructure/DependencyContainer.cpp \
    src/main.cpp

HEADERS += \
    src/data/dtomodels/ApiConfigDto.h \
    src/data/dtomodels/AppConfigDto.h \
    src/data/dtomodels/AuthorizationReplyDto.h \
    src/data/dtomodels/AuthorizationRequestDto.h \
    src/data/dtomodels/CacheConfigDto.h \
    src/data/dtomodels/ServerHostConfigDto.h \
    src/data/dtomodels/WeatherDataDto.h \
    src/data/dtomodels/WeatherHistoryItemDto.h \
    src/data/dtomodels/WeekWeatherDataDto.h \
    src/data/mappers/ApiConfigDomainMapper.h \
    src/data/mappers/AppConfigDomainMapper.h \
    src/data/mappers/AuthorizationReplyDomainMapper.h \
    src/data/mappers/AuthorizationRequestDomainMapper.h \
    src/data/mappers/CacheConfigDomainMapper.h \
    src/data/mappers/ServerHostConfigDomainMapper.h \
    src/data/mappers/WeatherDomainMapper.h \
    src/data/mappers/WeatherHistoryItemDomainMapper.h \
    src/data/mappers/WeekWeatherDomainMapper.h \
    src/data/repositories/database/QtDatabaseConnection.h \
    src/data/repositories/database/SqliteWeatherHistoryRepository.h \
    src/data/repositories/database/WeatherDatabaseInitializer.h \
    src/data/repositories/sharedstate/SharedState.h \
    src/data/repositories/weather/WeatherRepository.h \
    src/domain/entities/AuthorizationReply.h \
    src/domain/entities/AuthorizationRequest.h \
    src/domain/entities/ApiConfig.h \
    src/domain/entities/CacheConfig.h \
    src/domain/entities/ServerHostConfig.h \
    src/domain/entities/AppConfig.h \
    src/domain/entities/WeatherData.h \
    src/domain/entities/WeatherHistoryItem.h \
    src/domain/entities/WeekWeatherData.h \
    src/domain/interfaces/cache/IWeatherCacheSource.h \
    src/domain/interfaces/config/IConfigLoader.h \
    src/domain/interfaces/config/IConfigProvider.h \
    src/domain/interfaces/api/IUserRepository.h \
    src/domain/interfaces/api/IApiWeatherSource.h \
    src/domain/interfaces/database/IWeatherDatabaseConnection.h \
    src/domain/interfaces/database/IWeatherDatabaseInitializer.h \
    src/domain/interfaces/database/IWeatherHistoryRepository.h \
    src/domain/interfaces/sharedstate/ISharedState.h \
    src/domain/interfaces/weather/IWeatherRepository.h \
    src/domain/usecases/GetWeatherHistoryUseCase.h \
    src/domain/usecases/SaveWeatherHistoryUseCase.h \
    src/domain/utils/MakeReadyFuture.h \
    src/domain/utils/SimpleOptional.h \
    src/presentation/mappers/WeatherUiMapper.h \
    src/presentation/mappers/WeekWeatherUiMapper.h \
    src/presentation/uimodels/WeatherUiModel.h \
    src/presentation/uimodels/WeekWeatherUiModel.h \
    src/presentation/viewmodels/WeatherViewModel.h \
    src/utils/AuthorizationInfoJsonConverter.h \
    src/utils/AuthorizationReplyJsonConverter.h \
    src/utils/AppConfigJsonConverter.h \
    src/utils/WeatherJsonConverter.h \
    src/presentation/viewmodels/AuthViewModel.h \
    src/domain/usecases/AuthenticateUserUseCase.h \
    src/domain/usecases/RegisterUserUseCase.h \
    src/domain/usecases/GetDailyWeatherUseCase.h \
    src/domain/usecases/GetWeeklyWeatherUseCase.h \
    src/domain/utils/Result.h \
    src/data/repositories/api/UserRepository.h \
    src/data/repositories/api/WeatherApiSource.h \
    src/data/repositories/config/ConfigProvider.h \
    src/data/repositories/config/ConfigLoader.h \
    src/data/repositories/cache/WeatherCache.h \
    src/infrastructure/DependencyContainer.h \

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
