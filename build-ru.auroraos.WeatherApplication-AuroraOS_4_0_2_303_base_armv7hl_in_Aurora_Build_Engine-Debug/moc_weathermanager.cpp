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
    QByteArrayData data[11];
    char stringdata0[167];
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
QT_MOC_LITERAL(6, 97, 9), // "timestamp"
QT_MOC_LITERAL(7, 107, 4), // "city"
QT_MOC_LITERAL(8, 112, 4), // "date"
QT_MOC_LITERAL(9, 117, 19), // "slotFindWeatherData"
QT_MOC_LITERAL(10, 137, 29) // "slotRecivedWeatherDataFromAPI"

    },
    "WeatherManager\0sendWeatherDataToController\0"
    "\0jsonObj\0submitCompletedWeatherDataSearchRequest\0"
    "user\0timestamp\0city\0date\0slotFindWeatherData\0"
    "slotRecivedWeatherDataFromAPI"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_WeatherManager[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x06 /* Public */,
       4,    5,   37,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    2,   48,    2, 0x0a /* Public */,
      10,    1,   53,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QJsonObject,    3,
    QMetaType::Void, QMetaType::QString, QMetaType::QDateTime, QMetaType::QString, QMetaType::QDate, QMetaType::QJsonObject,    5,    6,    7,    8,    3,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QDate,    7,    8,
    QMetaType::Void, QMetaType::QJsonObject,    3,

       0        // eod
};

void WeatherManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        WeatherManager *_t = static_cast<WeatherManager *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendWeatherDataToController((*reinterpret_cast< const QJsonObject(*)>(_a[1]))); break;
        case 1: _t->submitCompletedWeatherDataSearchRequest((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QDateTime(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3])),(*reinterpret_cast< const QDate(*)>(_a[4])),(*reinterpret_cast< const QJsonObject(*)>(_a[5]))); break;
        case 2: _t->slotFindWeatherData((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QDate(*)>(_a[2]))); break;
        case 3: _t->slotRecivedWeatherDataFromAPI((*reinterpret_cast< const QJsonObject(*)>(_a[1]))); break;
        default: ;
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
            typedef void (WeatherManager::*_t)(const QString & , const QDateTime & , const QString & , const QDate & , const QJsonObject & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&WeatherManager::submitCompletedWeatherDataSearchRequest)) {
                *result = 1;
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
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
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
void WeatherManager::submitCompletedWeatherDataSearchRequest(const QString & _t1, const QDateTime & _t2, const QString & _t3, const QDate & _t4, const QJsonObject & _t5)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
