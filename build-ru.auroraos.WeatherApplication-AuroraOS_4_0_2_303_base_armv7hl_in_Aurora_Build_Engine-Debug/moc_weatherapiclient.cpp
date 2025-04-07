/****************************************************************************
** Meta object code from reading C++ file 'weatherapiclient.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../WeatherApplication/WeatherApplication/src/weatherapiclient.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'weatherapiclient.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_WeatherApiClient_t {
    QByteArrayData data[8];
    char stringdata0[110];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_WeatherApiClient_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_WeatherApiClient_t qt_meta_stringdata_WeatherApiClient = {
    {
QT_MOC_LITERAL(0, 0, 16), // "WeatherApiClient"
QT_MOC_LITERAL(1, 17, 23), // "jsonDataReceivedFromAPI"
QT_MOC_LITERAL(2, 41, 0), // ""
QT_MOC_LITERAL(3, 42, 7), // "jsonObj"
QT_MOC_LITERAL(4, 50, 17), // "slotCountryChange"
QT_MOC_LITERAL(5, 68, 7), // "zipCode"
QT_MOC_LITERAL(6, 76, 11), // "countryCode"
QT_MOC_LITERAL(7, 88, 21) // "onWeatherDataReceived"

    },
    "WeatherApiClient\0jsonDataReceivedFromAPI\0"
    "\0jsonObj\0slotCountryChange\0zipCode\0"
    "countryCode\0onWeatherDataReceived"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_WeatherApiClient[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    2,   32,    2, 0x0a /* Public */,
       7,    0,   37,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QJsonObject,    3,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    5,    6,
    QMetaType::Void,

       0        // eod
};

void WeatherApiClient::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        WeatherApiClient *_t = static_cast<WeatherApiClient *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->jsonDataReceivedFromAPI((*reinterpret_cast< const QJsonObject(*)>(_a[1]))); break;
        case 1: _t->slotCountryChange((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 2: _t->onWeatherDataReceived(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (WeatherApiClient::*_t)(const QJsonObject & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&WeatherApiClient::jsonDataReceivedFromAPI)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject WeatherApiClient::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_WeatherApiClient.data,
      qt_meta_data_WeatherApiClient,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *WeatherApiClient::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *WeatherApiClient::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_WeatherApiClient.stringdata0))
        return static_cast<void*>(const_cast< WeatherApiClient*>(this));
    return QObject::qt_metacast(_clname);
}

int WeatherApiClient::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void WeatherApiClient::jsonDataReceivedFromAPI(const QJsonObject & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
