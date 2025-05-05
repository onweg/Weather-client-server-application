/****************************************************************************
** Meta object code from reading C++ file 'WeatherDataDto.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../WeatherApplication/src/Data/DtoModels/WeatherDataDto.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'WeatherDataDto.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_WeatherDataDto_t {
    QByteArrayData data[14];
    char stringdata0[122];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_WeatherDataDto_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_WeatherDataDto_t qt_meta_stringdata_WeatherDataDto = {
    {
QT_MOC_LITERAL(0, 0, 14), // "WeatherDataDto"
QT_MOC_LITERAL(1, 15, 11), // "dataChanged"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 4), // "city"
QT_MOC_LITERAL(4, 33, 4), // "date"
QT_MOC_LITERAL(5, 38, 11), // "description"
QT_MOC_LITERAL(6, 50, 4), // "temp"
QT_MOC_LITERAL(7, 55, 9), // "feelsLike"
QT_MOC_LITERAL(8, 65, 7), // "tempMax"
QT_MOC_LITERAL(9, 73, 7), // "tempMin"
QT_MOC_LITERAL(10, 81, 9), // "windSpeed"
QT_MOC_LITERAL(11, 91, 8), // "humidity"
QT_MOC_LITERAL(12, 100, 8), // "pressure"
QT_MOC_LITERAL(13, 109, 12) // "messageError"

    },
    "WeatherDataDto\0dataChanged\0\0city\0date\0"
    "description\0temp\0feelsLike\0tempMax\0"
    "tempMin\0windSpeed\0humidity\0pressure\0"
    "messageError"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_WeatherDataDto[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
      11,   20, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   19,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,

 // properties: name, type, flags
       3, QMetaType::QString, 0x00495001,
       4, QMetaType::QString, 0x00495001,
       5, QMetaType::QString, 0x00495001,
       6, QMetaType::Double, 0x00495001,
       7, QMetaType::Double, 0x00495001,
       8, QMetaType::Double, 0x00495001,
       9, QMetaType::Double, 0x00495001,
      10, QMetaType::Double, 0x00495001,
      11, QMetaType::Int, 0x00495001,
      12, QMetaType::Int, 0x00495001,
      13, QMetaType::QString, 0x00495001,

 // properties: notify_signal_id
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,
       0,

       0        // eod
};

void WeatherDataDto::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        WeatherDataDto *_t = static_cast<WeatherDataDto *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->dataChanged(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (WeatherDataDto::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&WeatherDataDto::dataChanged)) {
                *result = 0;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        WeatherDataDto *_t = static_cast<WeatherDataDto *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = _t->getCity(); break;
        case 1: *reinterpret_cast< QString*>(_v) = _t->getDate(); break;
        case 2: *reinterpret_cast< QString*>(_v) = _t->getDescription(); break;
        case 3: *reinterpret_cast< double*>(_v) = _t->getTemp(); break;
        case 4: *reinterpret_cast< double*>(_v) = _t->getFeelsLike(); break;
        case 5: *reinterpret_cast< double*>(_v) = _t->getTempMax(); break;
        case 6: *reinterpret_cast< double*>(_v) = _t->getTempMin(); break;
        case 7: *reinterpret_cast< double*>(_v) = _t->getWindSpeed(); break;
        case 8: *reinterpret_cast< int*>(_v) = _t->getHumidity(); break;
        case 9: *reinterpret_cast< int*>(_v) = _t->getPressure(); break;
        case 10: *reinterpret_cast< QString*>(_v) = _t->getMessageError(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
    Q_UNUSED(_a);
}

const QMetaObject WeatherDataDto::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_WeatherDataDto.data,
      qt_meta_data_WeatherDataDto,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *WeatherDataDto::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *WeatherDataDto::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_WeatherDataDto.stringdata0))
        return static_cast<void*>(const_cast< WeatherDataDto*>(this));
    return QObject::qt_metacast(_clname);
}

int WeatherDataDto::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
#ifndef QT_NO_PROPERTIES
   else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 11;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 11;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 11;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 11;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 11;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void WeatherDataDto::dataChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
