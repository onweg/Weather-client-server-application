/****************************************************************************
** Meta object code from reading C++ file 'ClientController.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../WeatherApplication/src/ClientController/ClientController.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ClientController.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ClientController_t {
    QByteArrayData data[33];
    char stringdata0[560];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ClientController_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ClientController_t qt_meta_stringdata_ClientController = {
    {
QT_MOC_LITERAL(0, 0, 16), // "ClientController"
QT_MOC_LITERAL(1, 17, 15), // "findWeatherData"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 4), // "city"
QT_MOC_LITERAL(4, 39, 4), // "date"
QT_MOC_LITERAL(5, 44, 19), // "findWeekWeatherData"
QT_MOC_LITERAL(6, 64, 18), // "weatherDataUpdated"
QT_MOC_LITERAL(7, 83, 22), // "weekWeatherDataUpdated"
QT_MOC_LITERAL(8, 106, 30), // "sendAuthorizationDataToManager"
QT_MOC_LITERAL(9, 137, 17), // "AuthorizationInfo"
QT_MOC_LITERAL(10, 155, 4), // "data"
QT_MOC_LITERAL(11, 160, 22), // "authorizationCompleted"
QT_MOC_LITERAL(12, 183, 19), // "authorizationFailed"
QT_MOC_LITERAL(13, 203, 7), // "message"
QT_MOC_LITERAL(14, 211, 22), // "slotWeatherDataArrived"
QT_MOC_LITERAL(15, 234, 11), // "WeatherData"
QT_MOC_LITERAL(16, 246, 26), // "slotWeekWeatherDataArrived"
QT_MOC_LITERAL(17, 273, 15), // "WeekWeatherData"
QT_MOC_LITERAL(18, 289, 28), // "slotRecivedAuthorizationData"
QT_MOC_LITERAL(19, 318, 18), // "AuthorizationReply"
QT_MOC_LITERAL(20, 337, 28), // "slotUpdateWeatherFromUpdater"
QT_MOC_LITERAL(21, 366, 21), // "clickSearchCityButton"
QT_MOC_LITERAL(22, 388, 18), // "clickNextDayButton"
QT_MOC_LITERAL(23, 407, 18), // "clickPrevDayButton"
QT_MOC_LITERAL(24, 426, 26), // "clickWeekWeatherDataButton"
QT_MOC_LITERAL(25, 453, 21), // "sendAuthorizationData"
QT_MOC_LITERAL(26, 475, 7), // "command"
QT_MOC_LITERAL(27, 483, 5), // "login"
QT_MOC_LITERAL(28, 489, 8), // "password"
QT_MOC_LITERAL(29, 498, 12), // "weatherModel"
QT_MOC_LITERAL(30, 511, 13), // "WeatherModel*"
QT_MOC_LITERAL(31, 525, 16), // "weekWeatherModel"
QT_MOC_LITERAL(32, 542, 17) // "WeekWeatherModel*"

    },
    "ClientController\0findWeatherData\0\0"
    "city\0date\0findWeekWeatherData\0"
    "weatherDataUpdated\0weekWeatherDataUpdated\0"
    "sendAuthorizationDataToManager\0"
    "AuthorizationInfo\0data\0authorizationCompleted\0"
    "authorizationFailed\0message\0"
    "slotWeatherDataArrived\0WeatherData\0"
    "slotWeekWeatherDataArrived\0WeekWeatherData\0"
    "slotRecivedAuthorizationData\0"
    "AuthorizationReply\0slotUpdateWeatherFromUpdater\0"
    "clickSearchCityButton\0clickNextDayButton\0"
    "clickPrevDayButton\0clickWeekWeatherDataButton\0"
    "sendAuthorizationData\0command\0login\0"
    "password\0weatherModel\0WeatherModel*\0"
    "weekWeatherModel\0WeekWeatherModel*"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ClientController[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       2,  140, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       8,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   99,    2, 0x06 /* Public */,
       1,    1,  104,    2, 0x26 /* Public | MethodCloned */,
       5,    0,  107,    2, 0x06 /* Public */,
       6,    0,  108,    2, 0x06 /* Public */,
       7,    0,  109,    2, 0x06 /* Public */,
       8,    1,  110,    2, 0x06 /* Public */,
      11,    0,  113,    2, 0x06 /* Public */,
      12,    1,  114,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      14,    1,  117,    2, 0x0a /* Public */,
      16,    1,  120,    2, 0x0a /* Public */,
      18,    1,  123,    2, 0x0a /* Public */,
      20,    0,  126,    2, 0x08 /* Private */,

 // methods: name, argc, parameters, tag, flags
      21,    1,  127,    2, 0x02 /* Public */,
      22,    0,  130,    2, 0x02 /* Public */,
      23,    0,  131,    2, 0x02 /* Public */,
      24,    0,  132,    2, 0x02 /* Public */,
      25,    3,  133,    2, 0x02 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QDate,    3,    4,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   13,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 15,   10,
    QMetaType::Void, 0x80000000 | 17,   10,
    QMetaType::Void, 0x80000000 | 19,   10,
    QMetaType::Void,

 // methods: parameters
    QMetaType::Void, QMetaType::QString,   10,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,   26,   27,   28,

 // properties: name, type, flags
      29, 0x80000000 | 30, 0x00495009,
      31, 0x80000000 | 32, 0x00495009,

 // properties: notify_signal_id
       3,
       4,

       0        // eod
};

void ClientController::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ClientController *_t = static_cast<ClientController *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->findWeatherData((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QDate(*)>(_a[2]))); break;
        case 1: _t->findWeatherData((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->findWeekWeatherData(); break;
        case 3: _t->weatherDataUpdated(); break;
        case 4: _t->weekWeatherDataUpdated(); break;
        case 5: _t->sendAuthorizationDataToManager((*reinterpret_cast< const AuthorizationInfo(*)>(_a[1]))); break;
        case 6: _t->authorizationCompleted(); break;
        case 7: _t->authorizationFailed((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 8: _t->slotWeatherDataArrived((*reinterpret_cast< const WeatherData(*)>(_a[1]))); break;
        case 9: _t->slotWeekWeatherDataArrived((*reinterpret_cast< const WeekWeatherData(*)>(_a[1]))); break;
        case 10: _t->slotRecivedAuthorizationData((*reinterpret_cast< const AuthorizationReply(*)>(_a[1]))); break;
        case 11: _t->slotUpdateWeatherFromUpdater(); break;
        case 12: _t->clickSearchCityButton((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 13: _t->clickNextDayButton(); break;
        case 14: _t->clickPrevDayButton(); break;
        case 15: _t->clickWeekWeatherDataButton(); break;
        case 16: _t->sendAuthorizationData((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (ClientController::*_t)(const QString & , const QDate & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ClientController::findWeatherData)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (ClientController::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ClientController::findWeekWeatherData)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (ClientController::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ClientController::weatherDataUpdated)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (ClientController::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ClientController::weekWeatherDataUpdated)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (ClientController::*_t)(const AuthorizationInfo & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ClientController::sendAuthorizationDataToManager)) {
                *result = 5;
                return;
            }
        }
        {
            typedef void (ClientController::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ClientController::authorizationCompleted)) {
                *result = 6;
                return;
            }
        }
        {
            typedef void (ClientController::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ClientController::authorizationFailed)) {
                *result = 7;
                return;
            }
        }
    } else if (_c == QMetaObject::RegisterPropertyMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< WeatherModel* >(); break;
        case 1:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< WeekWeatherModel* >(); break;
        }
    }

#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        ClientController *_t = static_cast<ClientController *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< WeatherModel**>(_v) = _t->getWeatherModel(); break;
        case 1: *reinterpret_cast< WeekWeatherModel**>(_v) = _t->getWeekWeatherModel(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

const QMetaObject ClientController::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_ClientController.data,
      qt_meta_data_ClientController,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ClientController::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ClientController::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ClientController.stringdata0))
        return static_cast<void*>(const_cast< ClientController*>(this));
    return QObject::qt_metacast(_clname);
}

int ClientController::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 17)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 17;
    }
#ifndef QT_NO_PROPERTIES
   else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 2;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void ClientController::findWeatherData(const QString & _t1, const QDate & _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 2
void ClientController::findWeekWeatherData()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}

// SIGNAL 3
void ClientController::weatherDataUpdated()
{
    QMetaObject::activate(this, &staticMetaObject, 3, Q_NULLPTR);
}

// SIGNAL 4
void ClientController::weekWeatherDataUpdated()
{
    QMetaObject::activate(this, &staticMetaObject, 4, Q_NULLPTR);
}

// SIGNAL 5
void ClientController::sendAuthorizationDataToManager(const AuthorizationInfo & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void ClientController::authorizationCompleted()
{
    QMetaObject::activate(this, &staticMetaObject, 6, Q_NULLPTR);
}

// SIGNAL 7
void ClientController::authorizationFailed(const QString & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}
QT_END_MOC_NAMESPACE
