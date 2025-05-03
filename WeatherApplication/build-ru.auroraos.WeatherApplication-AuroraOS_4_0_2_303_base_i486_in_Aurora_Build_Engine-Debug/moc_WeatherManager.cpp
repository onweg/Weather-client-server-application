/****************************************************************************
** Meta object code from reading C++ file 'WeatherManager.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../WeatherApplication/src/Manager/WeatherManager.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'WeatherManager.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_WeatherManager_t {
    QByteArrayData data[24];
    char stringdata0[400];
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
QT_MOC_LITERAL(3, 44, 11), // "WeatherData"
QT_MOC_LITERAL(4, 56, 4), // "data"
QT_MOC_LITERAL(5, 61, 31), // "sendWeekWeatherDataToController"
QT_MOC_LITERAL(6, 93, 15), // "WeekWeatherData"
QT_MOC_LITERAL(7, 109, 39), // "submitCompletedWeatherDataSea..."
QT_MOC_LITERAL(8, 149, 18), // "WeatherHistoryItem"
QT_MOC_LITERAL(9, 168, 4), // "item"
QT_MOC_LITERAL(10, 173, 23), // "sendAuthorizationResult"
QT_MOC_LITERAL(11, 197, 18), // "AuthorizationReply"
QT_MOC_LITERAL(12, 216, 19), // "slotFindWeatherData"
QT_MOC_LITERAL(13, 236, 4), // "city"
QT_MOC_LITERAL(14, 241, 4), // "date"
QT_MOC_LITERAL(15, 246, 29), // "slotRecivedWeatherDataFromAPI"
QT_MOC_LITERAL(16, 276, 8), // "ApiReply"
QT_MOC_LITERAL(17, 285, 7), // "jsonObj"
QT_MOC_LITERAL(18, 293, 27), // "sloRecivedAuthorizationData"
QT_MOC_LITERAL(19, 321, 17), // "AuthorizationInfo"
QT_MOC_LITERAL(20, 339, 23), // "slotFindWeekWeatherData"
QT_MOC_LITERAL(21, 363, 15), // "onReplyFinished"
QT_MOC_LITERAL(22, 379, 14), // "QNetworkReply*"
QT_MOC_LITERAL(23, 394, 5) // "reply"

    },
    "WeatherManager\0sendWeatherDataToController\0"
    "\0WeatherData\0data\0sendWeekWeatherDataToController\0"
    "WeekWeatherData\0submitCompletedWeatherDataSearchRequest\0"
    "WeatherHistoryItem\0item\0sendAuthorizationResult\0"
    "AuthorizationReply\0slotFindWeatherData\0"
    "city\0date\0slotRecivedWeatherDataFromAPI\0"
    "ApiReply\0jsonObj\0sloRecivedAuthorizationData\0"
    "AuthorizationInfo\0slotFindWeekWeatherData\0"
    "onReplyFinished\0QNetworkReply*\0reply"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_WeatherManager[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   59,    2, 0x06 /* Public */,
       5,    1,   62,    2, 0x06 /* Public */,
       7,    1,   65,    2, 0x06 /* Public */,
      10,    1,   68,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      12,    2,   71,    2, 0x0a /* Public */,
      15,    1,   76,    2, 0x0a /* Public */,
      18,    1,   79,    2, 0x0a /* Public */,
      20,    0,   82,    2, 0x0a /* Public */,
      21,    1,   83,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 6,    4,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void, 0x80000000 | 11,    4,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QDate,   13,   14,
    QMetaType::Void, 0x80000000 | 16,   17,
    QMetaType::Void, 0x80000000 | 19,    4,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 22,   23,

       0        // eod
};

void WeatherManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        WeatherManager *_t = static_cast<WeatherManager *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendWeatherDataToController((*reinterpret_cast< const WeatherData(*)>(_a[1]))); break;
        case 1: _t->sendWeekWeatherDataToController((*reinterpret_cast< const WeekWeatherData(*)>(_a[1]))); break;
        case 2: _t->submitCompletedWeatherDataSearchRequest((*reinterpret_cast< const WeatherHistoryItem(*)>(_a[1]))); break;
        case 3: _t->sendAuthorizationResult((*reinterpret_cast< const AuthorizationReply(*)>(_a[1]))); break;
        case 4: _t->slotFindWeatherData((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QDate(*)>(_a[2]))); break;
        case 5: _t->slotRecivedWeatherDataFromAPI((*reinterpret_cast< const ApiReply(*)>(_a[1]))); break;
        case 6: _t->sloRecivedAuthorizationData((*reinterpret_cast< const AuthorizationInfo(*)>(_a[1]))); break;
        case 7: _t->slotFindWeekWeatherData(); break;
        case 8: _t->onReplyFinished((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 8:
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
            typedef void (WeatherManager::*_t)(const WeatherData & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&WeatherManager::sendWeatherDataToController)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (WeatherManager::*_t)(const WeekWeatherData & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&WeatherManager::sendWeekWeatherDataToController)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (WeatherManager::*_t)(const WeatherHistoryItem & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&WeatherManager::submitCompletedWeatherDataSearchRequest)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (WeatherManager::*_t)(const AuthorizationReply & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&WeatherManager::sendAuthorizationResult)) {
                *result = 3;
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
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void WeatherManager::sendWeatherDataToController(const WeatherData & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void WeatherManager::sendWeekWeatherDataToController(const WeekWeatherData & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void WeatherManager::submitCompletedWeatherDataSearchRequest(const WeatherHistoryItem & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void WeatherManager::sendAuthorizationResult(const AuthorizationReply & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_END_MOC_NAMESPACE
