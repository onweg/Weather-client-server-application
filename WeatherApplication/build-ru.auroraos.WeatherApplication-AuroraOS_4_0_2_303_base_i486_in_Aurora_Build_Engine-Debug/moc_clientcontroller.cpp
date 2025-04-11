/****************************************************************************
** Meta object code from reading C++ file 'clientcontroller.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../WeatherApplication/src/clientcontroller.h"
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
    QByteArrayData data[22];
    char stringdata0[263];
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
QT_MOC_LITERAL(5, 44, 11), // "dataUpdated"
QT_MOC_LITERAL(6, 56, 22), // "slotWeatherDataArrived"
QT_MOC_LITERAL(7, 79, 7), // "jsonObj"
QT_MOC_LITERAL(8, 87, 21), // "clickSearchCityButton"
QT_MOC_LITERAL(9, 109, 4), // "data"
QT_MOC_LITERAL(10, 114, 18), // "clickNextDayButton"
QT_MOC_LITERAL(11, 133, 18), // "clickPrevDayButton"
QT_MOC_LITERAL(12, 152, 7), // "getCity"
QT_MOC_LITERAL(13, 160, 7), // "getDate"
QT_MOC_LITERAL(14, 168, 14), // "getDescription"
QT_MOC_LITERAL(15, 183, 7), // "getTemp"
QT_MOC_LITERAL(16, 191, 12), // "getFeelsLike"
QT_MOC_LITERAL(17, 204, 10), // "getTempMax"
QT_MOC_LITERAL(18, 215, 10), // "getTempMin"
QT_MOC_LITERAL(19, 226, 12), // "getWindSpeed"
QT_MOC_LITERAL(20, 239, 11), // "getHumidity"
QT_MOC_LITERAL(21, 251, 11) // "getPressure"

    },
    "ClientController\0findWeatherData\0\0"
    "city\0date\0dataUpdated\0slotWeatherDataArrived\0"
    "jsonObj\0clickSearchCityButton\0data\0"
    "clickNextDayButton\0clickPrevDayButton\0"
    "getCity\0getDate\0getDescription\0getTemp\0"
    "getFeelsLike\0getTempMax\0getTempMin\0"
    "getWindSpeed\0getHumidity\0getPressure"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ClientController[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   99,    2, 0x06 /* Public */,
       1,    1,  104,    2, 0x26 /* Public | MethodCloned */,
       5,    0,  107,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    1,  108,    2, 0x0a /* Public */,

 // methods: name, argc, parameters, tag, flags
       8,    1,  111,    2, 0x02 /* Public */,
      10,    0,  114,    2, 0x02 /* Public */,
      11,    0,  115,    2, 0x02 /* Public */,
      12,    0,  116,    2, 0x02 /* Public */,
      13,    0,  117,    2, 0x02 /* Public */,
      14,    0,  118,    2, 0x02 /* Public */,
      15,    0,  119,    2, 0x02 /* Public */,
      16,    0,  120,    2, 0x02 /* Public */,
      17,    0,  121,    2, 0x02 /* Public */,
      18,    0,  122,    2, 0x02 /* Public */,
      19,    0,  123,    2, 0x02 /* Public */,
      20,    0,  124,    2, 0x02 /* Public */,
      21,    0,  125,    2, 0x02 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QDate,    3,    4,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QJsonObject,    7,

 // methods: parameters
    QMetaType::Void, QMetaType::QString,    9,
    QMetaType::Void,
    QMetaType::Void,
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
        case 2: _t->dataUpdated(); break;
        case 3: _t->slotWeatherDataArrived((*reinterpret_cast< const QJsonObject(*)>(_a[1]))); break;
        case 4: _t->clickSearchCityButton((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: _t->clickNextDayButton(); break;
        case 6: _t->clickPrevDayButton(); break;
        case 7: { QString _r = _t->getCity();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 8: { QString _r = _t->getDate();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 9: { QString _r = _t->getDescription();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 10: { QString _r = _t->getTemp();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 11: { QString _r = _t->getFeelsLike();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 12: { QString _r = _t->getTempMax();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 13: { QString _r = _t->getTempMin();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 14: { QString _r = _t->getWindSpeed();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 15: { QString _r = _t->getHumidity();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 16: { QString _r = _t->getPressure();
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
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ClientController::dataUpdated)) {
                *result = 2;
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
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 17)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 17;
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
void ClientController::dataUpdated()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
