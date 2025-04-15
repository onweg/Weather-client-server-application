/****************************************************************************
** Meta object code from reading C++ file 'clientcontroller.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../WeatherApplication/WeatherApplication/src/clientcontroller.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'clientcontroller.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ClientController_t {
    QByteArrayData data[39];
    char stringdata0[576];
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
QT_MOC_LITERAL(6, 64, 11), // "dataUpdated"
QT_MOC_LITERAL(7, 76, 15), // "weekDataUpdated"
QT_MOC_LITERAL(8, 92, 30), // "sendAuthorizationDataToManager"
QT_MOC_LITERAL(9, 123, 7), // "command"
QT_MOC_LITERAL(10, 131, 5), // "login"
QT_MOC_LITERAL(11, 137, 8), // "password"
QT_MOC_LITERAL(12, 146, 22), // "authorizationCompleted"
QT_MOC_LITERAL(13, 169, 19), // "authorizationFailed"
QT_MOC_LITERAL(14, 189, 7), // "message"
QT_MOC_LITERAL(15, 197, 22), // "slotWeatherDataArrived"
QT_MOC_LITERAL(16, 220, 7), // "jsonObj"
QT_MOC_LITERAL(17, 228, 26), // "slotWeekWeatherDataArrived"
QT_MOC_LITERAL(18, 255, 28), // "slotRecivedAuthorizationData"
QT_MOC_LITERAL(19, 284, 28), // "slotUpdateWeatherFromUpdater"
QT_MOC_LITERAL(20, 313, 21), // "clickSearchCityButton"
QT_MOC_LITERAL(21, 335, 4), // "data"
QT_MOC_LITERAL(22, 340, 18), // "clickNextDayButton"
QT_MOC_LITERAL(23, 359, 18), // "clickPrevDayButton"
QT_MOC_LITERAL(24, 378, 26), // "clickWeekWeatherDataButton"
QT_MOC_LITERAL(25, 405, 21), // "sendAuthorizationData"
QT_MOC_LITERAL(26, 427, 7), // "getCity"
QT_MOC_LITERAL(27, 435, 7), // "getDate"
QT_MOC_LITERAL(28, 443, 14), // "getDescription"
QT_MOC_LITERAL(29, 458, 7), // "getTemp"
QT_MOC_LITERAL(30, 466, 12), // "getFeelsLike"
QT_MOC_LITERAL(31, 479, 10), // "getTempMax"
QT_MOC_LITERAL(32, 490, 10), // "getTempMin"
QT_MOC_LITERAL(33, 501, 12), // "getWindSpeed"
QT_MOC_LITERAL(34, 514, 11), // "getHumidity"
QT_MOC_LITERAL(35, 526, 11), // "getPressure"
QT_MOC_LITERAL(36, 538, 15), // "getDateFromWeek"
QT_MOC_LITERAL(37, 554, 5), // "index"
QT_MOC_LITERAL(38, 560, 15) // "getTempFromWeek"

    },
    "ClientController\0findWeatherData\0\0"
    "city\0date\0findWeekWeatherData\0dataUpdated\0"
    "weekDataUpdated\0sendAuthorizationDataToManager\0"
    "command\0login\0password\0authorizationCompleted\0"
    "authorizationFailed\0message\0"
    "slotWeatherDataArrived\0jsonObj\0"
    "slotWeekWeatherDataArrived\0"
    "slotRecivedAuthorizationData\0"
    "slotUpdateWeatherFromUpdater\0"
    "clickSearchCityButton\0data\0"
    "clickNextDayButton\0clickPrevDayButton\0"
    "clickWeekWeatherDataButton\0"
    "sendAuthorizationData\0getCity\0getDate\0"
    "getDescription\0getTemp\0getFeelsLike\0"
    "getTempMax\0getTempMin\0getWindSpeed\0"
    "getHumidity\0getPressure\0getDateFromWeek\0"
    "index\0getTempFromWeek"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ClientController[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      29,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       8,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,  159,    2, 0x06 /* Public */,
       1,    1,  164,    2, 0x26 /* Public | MethodCloned */,
       5,    0,  167,    2, 0x06 /* Public */,
       6,    0,  168,    2, 0x06 /* Public */,
       7,    0,  169,    2, 0x06 /* Public */,
       8,    3,  170,    2, 0x06 /* Public */,
      12,    0,  177,    2, 0x06 /* Public */,
      13,    1,  178,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      15,    1,  181,    2, 0x0a /* Public */,
      17,    1,  184,    2, 0x0a /* Public */,
      18,    1,  187,    2, 0x0a /* Public */,
      19,    0,  190,    2, 0x08 /* Private */,

 // methods: name, argc, parameters, tag, flags
      20,    1,  191,    2, 0x02 /* Public */,
      22,    0,  194,    2, 0x02 /* Public */,
      23,    0,  195,    2, 0x02 /* Public */,
      24,    0,  196,    2, 0x02 /* Public */,
      25,    3,  197,    2, 0x02 /* Public */,
      26,    0,  204,    2, 0x02 /* Public */,
      27,    0,  205,    2, 0x02 /* Public */,
      28,    0,  206,    2, 0x02 /* Public */,
      29,    0,  207,    2, 0x02 /* Public */,
      30,    0,  208,    2, 0x02 /* Public */,
      31,    0,  209,    2, 0x02 /* Public */,
      32,    0,  210,    2, 0x02 /* Public */,
      33,    0,  211,    2, 0x02 /* Public */,
      34,    0,  212,    2, 0x02 /* Public */,
      35,    0,  213,    2, 0x02 /* Public */,
      36,    1,  214,    2, 0x02 /* Public */,
      38,    1,  217,    2, 0x02 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QDate,    3,    4,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,    9,   10,   11,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   14,

 // slots: parameters
    QMetaType::Void, QMetaType::QJsonObject,   16,
    QMetaType::Void, QMetaType::QJsonObject,   16,
    QMetaType::Void, QMetaType::QJsonObject,   16,
    QMetaType::Void,

 // methods: parameters
    QMetaType::Void, QMetaType::QString,   21,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,    9,   10,   11,
    QMetaType::QString,
    QMetaType::QString,
    QMetaType::QString,
    QMetaType::QString,
    QMetaType::QString,
    QMetaType::QString,
    QMetaType::QString,
    QMetaType::QString,
    QMetaType::QString,
    QMetaType::QString,
    QMetaType::QString, QMetaType::Int,   37,
    QMetaType::QString, QMetaType::Int,   37,

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
        case 3: _t->dataUpdated(); break;
        case 4: _t->weekDataUpdated(); break;
        case 5: _t->sendAuthorizationDataToManager((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3]))); break;
        case 6: _t->authorizationCompleted(); break;
        case 7: _t->authorizationFailed((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 8: _t->slotWeatherDataArrived((*reinterpret_cast< const QJsonObject(*)>(_a[1]))); break;
        case 9: _t->slotWeekWeatherDataArrived((*reinterpret_cast< const QJsonObject(*)>(_a[1]))); break;
        case 10: _t->slotRecivedAuthorizationData((*reinterpret_cast< const QJsonObject(*)>(_a[1]))); break;
        case 11: _t->slotUpdateWeatherFromUpdater(); break;
        case 12: _t->clickSearchCityButton((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 13: _t->clickNextDayButton(); break;
        case 14: _t->clickPrevDayButton(); break;
        case 15: _t->clickWeekWeatherDataButton(); break;
        case 16: _t->sendAuthorizationData((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3]))); break;
        case 17: { QString _r = _t->getCity();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 18: { QString _r = _t->getDate();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 19: { QString _r = _t->getDescription();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 20: { QString _r = _t->getTemp();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 21: { QString _r = _t->getFeelsLike();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 22: { QString _r = _t->getTempMax();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 23: { QString _r = _t->getTempMin();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 24: { QString _r = _t->getWindSpeed();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 25: { QString _r = _t->getHumidity();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 26: { QString _r = _t->getPressure();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 27: { QString _r = _t->getDateFromWeek((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 28: { QString _r = _t->getTempFromWeek((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
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
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ClientController::dataUpdated)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (ClientController::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ClientController::weekDataUpdated)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (ClientController::*_t)(const QString & , const QString & , const QString & );
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
    }
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
        if (_id < 29)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 29;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 29)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 29;
    }
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
void ClientController::dataUpdated()
{
    QMetaObject::activate(this, &staticMetaObject, 3, Q_NULLPTR);
}

// SIGNAL 4
void ClientController::weekDataUpdated()
{
    QMetaObject::activate(this, &staticMetaObject, 4, Q_NULLPTR);
}

// SIGNAL 5
void ClientController::sendAuthorizationDataToManager(const QString & _t1, const QString & _t2, const QString & _t3)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
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
