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
    QByteArrayData data[17];
    char stringdata0[188];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ClientController_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ClientController_t qt_meta_stringdata_ClientController = {
    {
QT_MOC_LITERAL(0, 0, 16), // "ClientController"
QT_MOC_LITERAL(1, 17, 10), // "cityChange"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 4), // "city"
QT_MOC_LITERAL(4, 34, 11), // "dataUpdated"
QT_MOC_LITERAL(5, 46, 15), // "slotWeatherData"
QT_MOC_LITERAL(6, 62, 7), // "jsonObj"
QT_MOC_LITERAL(7, 70, 14), // "getDescription"
QT_MOC_LITERAL(8, 85, 7), // "getTemp"
QT_MOC_LITERAL(9, 93, 12), // "getFeelsLike"
QT_MOC_LITERAL(10, 106, 10), // "getTempMax"
QT_MOC_LITERAL(11, 117, 10), // "getTempMin"
QT_MOC_LITERAL(12, 128, 12), // "getWindSpeed"
QT_MOC_LITERAL(13, 141, 11), // "getHumidity"
QT_MOC_LITERAL(14, 153, 11), // "getPressure"
QT_MOC_LITERAL(15, 165, 17), // "getDataSearchCity"
QT_MOC_LITERAL(16, 183, 4) // "data"

    },
    "ClientController\0cityChange\0\0city\0"
    "dataUpdated\0slotWeatherData\0jsonObj\0"
    "getDescription\0getTemp\0getFeelsLike\0"
    "getTempMax\0getTempMin\0getWindSpeed\0"
    "getHumidity\0getPressure\0getDataSearchCity\0"
    "data"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ClientController[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   74,    2, 0x06 /* Public */,
       4,    0,   77,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    1,   78,    2, 0x0a /* Public */,
       7,    0,   81,    2, 0x0a /* Public */,
       8,    0,   82,    2, 0x0a /* Public */,
       9,    0,   83,    2, 0x0a /* Public */,
      10,    0,   84,    2, 0x0a /* Public */,
      11,    0,   85,    2, 0x0a /* Public */,
      12,    0,   86,    2, 0x0a /* Public */,
      13,    0,   87,    2, 0x0a /* Public */,
      14,    0,   88,    2, 0x0a /* Public */,

 // methods: name, argc, parameters, tag, flags
      15,    1,   89,    2, 0x02 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QJsonObject,    6,
    QMetaType::QString,
    QMetaType::QString,
    QMetaType::QString,
    QMetaType::QString,
    QMetaType::QString,
    QMetaType::QString,
    QMetaType::QString,
    QMetaType::QString,

 // methods: parameters
    QMetaType::Void, QMetaType::QString,   16,

       0        // eod
};

void ClientController::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ClientController *_t = static_cast<ClientController *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->cityChange((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->dataUpdated(); break;
        case 2: _t->slotWeatherData((*reinterpret_cast< const QJsonObject(*)>(_a[1]))); break;
        case 3: { QString _r = _t->getDescription();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 4: { QString _r = _t->getTemp();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 5: { QString _r = _t->getFeelsLike();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 6: { QString _r = _t->getTempMax();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 7: { QString _r = _t->getTempMin();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 8: { QString _r = _t->getWindSpeed();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 9: { QString _r = _t->getHumidity();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 10: { QString _r = _t->getPressure();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 11: _t->getDataSearchCity((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (ClientController::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ClientController::cityChange)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (ClientController::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ClientController::dataUpdated)) {
                *result = 1;
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
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void ClientController::cityChange(const QString & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ClientController::dataUpdated()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
