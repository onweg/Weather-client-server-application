/****************************************************************************
** Meta object code from reading C++ file 'WeekWeatherUiModel.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../WeatherApplication/src/presentation/uimodels/WeekWeatherUiModel.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'WeekWeatherUiModel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_WeekWeatherUiModel_t {
    QByteArrayData data[9];
    char stringdata0[119];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_WeekWeatherUiModel_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_WeekWeatherUiModel_t qt_meta_stringdata_WeekWeatherUiModel = {
    {
QT_MOC_LITERAL(0, 0, 18), // "WeekWeatherUiModel"
QT_MOC_LITERAL(1, 19, 11), // "cityChanged"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 19), // "messageErrorChanged"
QT_MOC_LITERAL(4, 52, 19), // "dailyWeatherChanged"
QT_MOC_LITERAL(5, 72, 4), // "city"
QT_MOC_LITERAL(6, 77, 12), // "messageError"
QT_MOC_LITERAL(7, 90, 12), // "dailyWeather"
QT_MOC_LITERAL(8, 103, 15) // "QList<QObject*>"

    },
    "WeekWeatherUiModel\0cityChanged\0\0"
    "messageErrorChanged\0dailyWeatherChanged\0"
    "city\0messageError\0dailyWeather\0"
    "QList<QObject*>"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_WeekWeatherUiModel[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       3,   32, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   29,    2, 0x06 /* Public */,
       3,    0,   30,    2, 0x06 /* Public */,
       4,    0,   31,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // properties: name, type, flags
       5, QMetaType::QString, 0x00495103,
       6, QMetaType::QString, 0x00495103,
       7, 0x80000000 | 8, 0x00495009,

 // properties: notify_signal_id
       0,
       1,
       2,

       0        // eod
};

void WeekWeatherUiModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        WeekWeatherUiModel *_t = static_cast<WeekWeatherUiModel *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->cityChanged(); break;
        case 1: _t->messageErrorChanged(); break;
        case 2: _t->dailyWeatherChanged(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (WeekWeatherUiModel::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&WeekWeatherUiModel::cityChanged)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (WeekWeatherUiModel::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&WeekWeatherUiModel::messageErrorChanged)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (WeekWeatherUiModel::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&WeekWeatherUiModel::dailyWeatherChanged)) {
                *result = 2;
                return;
            }
        }
    } else if (_c == QMetaObject::RegisterPropertyMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 2:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<QObject*> >(); break;
        }
    }

#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        WeekWeatherUiModel *_t = static_cast<WeekWeatherUiModel *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = _t->city(); break;
        case 1: *reinterpret_cast< QString*>(_v) = _t->messageError(); break;
        case 2: *reinterpret_cast< QList<QObject*>*>(_v) = _t->dailyWeather(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        WeekWeatherUiModel *_t = static_cast<WeekWeatherUiModel *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setCity(*reinterpret_cast< QString*>(_v)); break;
        case 1: _t->setMessageError(*reinterpret_cast< QString*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

const QMetaObject WeekWeatherUiModel::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_WeekWeatherUiModel.data,
      qt_meta_data_WeekWeatherUiModel,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *WeekWeatherUiModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *WeekWeatherUiModel::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_WeekWeatherUiModel.stringdata0))
        return static_cast<void*>(const_cast< WeekWeatherUiModel*>(this));
    return QObject::qt_metacast(_clname);
}

int WeekWeatherUiModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
#ifndef QT_NO_PROPERTIES
   else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 3;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void WeekWeatherUiModel::cityChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void WeekWeatherUiModel::messageErrorChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void WeekWeatherUiModel::dailyWeatherChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
