/****************************************************************************
** Meta object code from reading C++ file 'WeatherViewModel.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../WeatherApplication/src/Presentation/ViewModels/WeatherViewModel.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'WeatherViewModel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_WeatherViewModel_t {
    QByteArrayData data[13];
    char stringdata0[218];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_WeatherViewModel_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_WeatherViewModel_t qt_meta_stringdata_WeatherViewModel = {
    {
QT_MOC_LITERAL(0, 0, 16), // "WeatherViewModel"
QT_MOC_LITERAL(1, 17, 18), // "weatherDataUpdated"
QT_MOC_LITERAL(2, 36, 0), // ""
QT_MOC_LITERAL(3, 37, 22), // "weekWeatherDataUpdated"
QT_MOC_LITERAL(4, 60, 21), // "clickSearchCityButton"
QT_MOC_LITERAL(5, 82, 4), // "city"
QT_MOC_LITERAL(6, 87, 18), // "clickNextDayButton"
QT_MOC_LITERAL(7, 106, 18), // "clickPrevDayButton"
QT_MOC_LITERAL(8, 125, 26), // "clickWeekWeatherDataButton"
QT_MOC_LITERAL(9, 152, 12), // "weatherModel"
QT_MOC_LITERAL(10, 165, 15), // "WeatherUiModel*"
QT_MOC_LITERAL(11, 181, 16), // "weekWeatherModel"
QT_MOC_LITERAL(12, 198, 19) // "WeekWeatherUiModel*"

    },
    "WeatherViewModel\0weatherDataUpdated\0"
    "\0weekWeatherDataUpdated\0clickSearchCityButton\0"
    "city\0clickNextDayButton\0clickPrevDayButton\0"
    "clickWeekWeatherDataButton\0weatherModel\0"
    "WeatherUiModel*\0weekWeatherModel\0"
    "WeekWeatherUiModel*"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_WeatherViewModel[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       2,   52, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x06 /* Public */,
       3,    0,   45,    2, 0x06 /* Public */,

 // methods: name, argc, parameters, tag, flags
       4,    1,   46,    2, 0x02 /* Public */,
       6,    0,   49,    2, 0x02 /* Public */,
       7,    0,   50,    2, 0x02 /* Public */,
       8,    0,   51,    2, 0x02 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // methods: parameters
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // properties: name, type, flags
       9, 0x80000000 | 10, 0x00495009,
      11, 0x80000000 | 12, 0x00495009,

 // properties: notify_signal_id
       0,
       1,

       0        // eod
};

void WeatherViewModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        WeatherViewModel *_t = static_cast<WeatherViewModel *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->weatherDataUpdated(); break;
        case 1: _t->weekWeatherDataUpdated(); break;
        case 2: _t->clickSearchCityButton((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->clickNextDayButton(); break;
        case 4: _t->clickPrevDayButton(); break;
        case 5: _t->clickWeekWeatherDataButton(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (WeatherViewModel::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&WeatherViewModel::weatherDataUpdated)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (WeatherViewModel::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&WeatherViewModel::weekWeatherDataUpdated)) {
                *result = 1;
                return;
            }
        }
    } else if (_c == QMetaObject::RegisterPropertyMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< WeatherUiModel* >(); break;
        case 1:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< WeekWeatherUiModel* >(); break;
        }
    }

#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        WeatherViewModel *_t = static_cast<WeatherViewModel *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< WeatherUiModel**>(_v) = _t->getWeatherModel(); break;
        case 1: *reinterpret_cast< WeekWeatherUiModel**>(_v) = _t->getWeekWeatherModel(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

const QMetaObject WeatherViewModel::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_WeatherViewModel.data,
      qt_meta_data_WeatherViewModel,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *WeatherViewModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *WeatherViewModel::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_WeatherViewModel.stringdata0))
        return static_cast<void*>(const_cast< WeatherViewModel*>(this));
    return QObject::qt_metacast(_clname);
}

int WeatherViewModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
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
void WeatherViewModel::weatherDataUpdated()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void WeatherViewModel::weekWeatherDataUpdated()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
