/****************************************************************************
** Meta object code from reading C++ file 'weathermanager.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../WeatherApplication/WeatherApplication/src/weathermanager.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'weathermanager.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_WeatherManager_t {
    QByteArrayData data[18];
    char stringdata0[269];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_WeatherManager_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_WeatherManager_t qt_meta_stringdata_WeatherManager = {
    {
QT_MOC_LITERAL(0, 0, 14), // "WeatherManager"
QT_MOC_LITERAL(1, 15, 27), // "sendWeatherDataToController"
QT_MOC_LITERAL(2, 43, 0), // ""
QT_MOC_LITERAL(3, 44, 7), // "jsonObj"
QT_MOC_LITERAL(4, 52, 39), // "submitCompletedWeatherDataSea..."
QT_MOC_LITERAL(5, 92, 4), // "user"
QT_MOC_LITERAL(6, 97, 4), // "city"
QT_MOC_LITERAL(7, 102, 4), // "date"
QT_MOC_LITERAL(8, 107, 23), // "sendAuthorizationResult"
QT_MOC_LITERAL(9, 131, 19), // "slotFindWeatherData"
QT_MOC_LITERAL(10, 151, 29), // "slotRecivedWeatherDataFromAPI"
QT_MOC_LITERAL(11, 181, 27), // "sloRecivedAuthorizationData"
QT_MOC_LITERAL(12, 209, 7), // "command"
QT_MOC_LITERAL(13, 217, 5), // "login"
QT_MOC_LITERAL(14, 223, 8), // "password"
QT_MOC_LITERAL(15, 232, 15), // "onReplyFinished"
QT_MOC_LITERAL(16, 248, 14), // "QNetworkReply*"
QT_MOC_LITERAL(17, 263, 5) // "reply"

    },
    "WeatherManager\0sendWeatherDataToController\0"
    "\0jsonObj\0submitCompletedWeatherDataSearchRequest\0"
    "user\0city\0date\0sendAuthorizationResult\0"
    "slotFindWeatherData\0slotRecivedWeatherDataFromAPI\0"
    "sloRecivedAuthorizationData\0command\0"
    "login\0password\0onReplyFinished\0"
    "QNetworkReply*\0reply"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_WeatherManager[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x06 /* Public */,
       4,    3,   52,    2, 0x06 /* Public */,
       8,    1,   59,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    2,   62,    2, 0x0a /* Public */,
      10,    1,   67,    2, 0x0a /* Public */,
      11,    3,   70,    2, 0x0a /* Public */,
      15,    1,   77,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QJsonObject,    3,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QDate,    5,    6,    7,
    QMetaType::Void, QMetaType::QJsonObject,    3,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QDate,    6,    7,
    QMetaType::Void, QMetaType::QJsonObject,    3,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,   12,   13,   14,
    QMetaType::Void, 0x80000000 | 16,   17,

       0        // eod
};

void WeatherManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        WeatherManager *_t = static_cast<WeatherManager *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendWeatherDataToController((*reinterpret_cast< const QJsonObject(*)>(_a[1]))); break;
        case 1: _t->submitCompletedWeatherDataSearchRequest((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QDate(*)>(_a[3]))); break;
        case 2: _t->sendAuthorizationResult((*reinterpret_cast< const QJsonObject(*)>(_a[1]))); break;
        case 3: _t->slotFindWeatherData((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QDate(*)>(_a[2]))); break;
        case 4: _t->slotRecivedWeatherDataFromAPI((*reinterpret_cast< const QJsonObject(*)>(_a[1]))); break;
        case 5: _t->sloRecivedAuthorizationData((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3]))); break;
        case 6: _t->onReplyFinished((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 6:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (WeatherManager::*_t)(const QJsonObject & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&WeatherManager::sendWeatherDataToController)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (WeatherManager::*_t)(const QString & , const QString & , const QDate & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&WeatherManager::submitCompletedWeatherDataSearchRequest)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (WeatherManager::*_t)(const QJsonObject & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&WeatherManager::sendAuthorizationResult)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject WeatherManager::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_WeatherManager.data,
      qt_meta_data_WeatherManager,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *WeatherManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *WeatherManager::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_WeatherManager.stringdata0))
        return static_cast<void*>(const_cast< WeatherManager*>(this));
    return QObject::qt_metacast(_clname);
}

int WeatherManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void WeatherManager::sendWeatherDataToController(const QJsonObject & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void WeatherManager::submitCompletedWeatherDataSearchRequest(const QString & _t1, const QString & _t2, const QDate & _t3)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void WeatherManager::sendAuthorizationResult(const QJsonObject & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
