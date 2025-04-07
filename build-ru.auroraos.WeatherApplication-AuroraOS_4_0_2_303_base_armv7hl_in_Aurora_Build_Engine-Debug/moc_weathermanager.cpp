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
    QByteArrayData data[9];
    char stringdata0[116];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_WeatherManager_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_WeatherManager_t qt_meta_stringdata_WeatherManager = {
    {
QT_MOC_LITERAL(0, 0, 14), // "WeatherManager"
QT_MOC_LITERAL(1, 15, 13), // "countryChange"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 7), // "zipCode"
QT_MOC_LITERAL(4, 38, 11), // "countryCode"
QT_MOC_LITERAL(5, 50, 19), // "sendJsonDataFromAPI"
QT_MOC_LITERAL(6, 70, 7), // "jsonObj"
QT_MOC_LITERAL(7, 78, 17), // "slotCountryChange"
QT_MOC_LITERAL(8, 96, 19) // "slotRecivedJsonData"

    },
    "WeatherManager\0countryChange\0\0zipCode\0"
    "countryCode\0sendJsonDataFromAPI\0jsonObj\0"
    "slotCountryChange\0slotRecivedJsonData"
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
       1,    2,   34,    2, 0x06 /* Public */,
       5,    1,   39,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    2,   42,    2, 0x0a /* Public */,
       8,    1,   47,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    3,    4,
    QMetaType::Void, QMetaType::QJsonObject,    6,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    3,    4,
    QMetaType::Void, QMetaType::QJsonObject,    6,

       0        // eod
};

void WeatherManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        WeatherManager *_t = static_cast<WeatherManager *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->countryChange((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 1: _t->sendJsonDataFromAPI((*reinterpret_cast< const QJsonObject(*)>(_a[1]))); break;
        case 2: _t->slotCountryChange((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 3: _t->slotRecivedJsonData((*reinterpret_cast< const QJsonObject(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (WeatherManager::*_t)(const QString & , const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&WeatherManager::countryChange)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (WeatherManager::*_t)(const QJsonObject & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&WeatherManager::sendJsonDataFromAPI)) {
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
void WeatherManager::countryChange(const QString & _t1, const QString & _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void WeatherManager::sendJsonDataFromAPI(const QJsonObject & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
