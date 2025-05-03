/****************************************************************************
** Meta object code from reading C++ file 'WeatherModel.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../WeatherApplication/src/Models/WeatherModel.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'WeatherModel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_WeatherModel_t {
    QByteArrayData data[12];
    char stringdata0[107];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_WeatherModel_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_WeatherModel_t qt_meta_stringdata_WeatherModel = {
    {
QT_MOC_LITERAL(0, 0, 12), // "WeatherModel"
QT_MOC_LITERAL(1, 13, 4), // "city"
QT_MOC_LITERAL(2, 18, 4), // "date"
QT_MOC_LITERAL(3, 23, 11), // "description"
QT_MOC_LITERAL(4, 35, 4), // "temp"
QT_MOC_LITERAL(5, 40, 9), // "feelsLike"
QT_MOC_LITERAL(6, 50, 7), // "tempMax"
QT_MOC_LITERAL(7, 58, 7), // "tempMin"
QT_MOC_LITERAL(8, 66, 9), // "windSpeed"
QT_MOC_LITERAL(9, 76, 8), // "humidity"
QT_MOC_LITERAL(10, 85, 8), // "pressure"
QT_MOC_LITERAL(11, 94, 12) // "messageError"

    },
    "WeatherModel\0city\0date\0description\0"
    "temp\0feelsLike\0tempMax\0tempMin\0windSpeed\0"
    "humidity\0pressure\0messageError"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_WeatherModel[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
      11,   14, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // properties: name, type, flags
       1, QMetaType::QString, 0x00095401,
       2, QMetaType::QString, 0x00095401,
       3, QMetaType::QString, 0x00095401,
       4, QMetaType::Double, 0x00095401,
       5, QMetaType::Double, 0x00095401,
       6, QMetaType::Double, 0x00095401,
       7, QMetaType::Double, 0x00095401,
       8, QMetaType::Double, 0x00095401,
       9, QMetaType::Int, 0x00095401,
      10, QMetaType::Int, 0x00095401,
      11, QMetaType::QString, 0x00095401,

       0        // eod
};

void WeatherModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{

#ifndef QT_NO_PROPERTIES
    if (_c == QMetaObject::ReadProperty) {
        WeatherModel *_t = static_cast<WeatherModel *>(_o);
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
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject WeatherModel::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_WeatherModel.data,
      qt_meta_data_WeatherModel,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *WeatherModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *WeatherModel::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_WeatherModel.stringdata0))
        return static_cast<void*>(const_cast< WeatherModel*>(this));
    return QObject::qt_metacast(_clname);
}

int WeatherModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    
#ifndef QT_NO_PROPERTIES
   if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
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
QT_END_MOC_NAMESPACE
