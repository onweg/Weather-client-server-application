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
    auroraapp

PKGCONFIG += \

SOURCES += \
    src/ClientController/clientcontroller.cpp \
    src/ClientController/weatherupdater.cpp \
    src/DatabaseManager/databasemanager.cpp \
    src/Manager/cachecleaner.cpp \
    src/Manager/dataeditor.cpp \
    src/Manager/weatherapiclient.cpp \
    src/Manager/weathercache.cpp \
    src/Manager/weathermanager.cpp \
    src/main.cpp

HEADERS += \
    src/ClientController/clientcontroller.h \
    src/ClientController/weatherupdater.h \
    src/DatabaseManager/databasemanager.h \
    src/Manager/cachecleaner.h \
    src/Manager/dataeditor.h \
    src/Manager/weatherapiclient.h \
    src/Manager/weathercache.h \
    src/Manager/weathermanager.h

DISTFILES += \
    qml/components/DateAndButtons.qml \
    qml/components/InputCity.qml \
    qml/components/SearchPanel.qml \
    qml/components/WeatherData.qml \
    qml/components/WeatherInformation.qml \
    qml/pages/Authorization.qml \
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
    README.md


AURORAAPP_ICONS = 86x86 108x108 128x128 172x172

CONFIG += auroraapp_i18n

TRANSLATIONS += \
    translations/ru.auroraos.WeatherApplication.ts \
    translations/ru.auroraos.WeatherApplication-ru.ts \
