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
    QByteArrayData data[8];
    char stringdata0[129];
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
QT_MOC_LITERAL(3, 37, 21), // "clickSearchCityButton"
QT_MOC_LITERAL(4, 59, 4), // "data"
QT_MOC_LITERAL(5, 64, 18), // "clickNextDayButton"
QT_MOC_LITERAL(6, 83, 18), // "clickPrevDayButton"
QT_MOC_LITERAL(7, 102, 26) // "clickWeekWeatherDataButton"

    },
    "WeatherViewModel\0weatherDataUpdated\0"
    "\0clickSearchCityButton\0data\0"
    "clickNextDayButton\0clickPrevDayButton\0"
    "clickWeekWeatherDataButton"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_WeatherViewModel[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x06 /* Public */,

 // methods: name, argc, parameters, tag, flags
       3,    1,   40,    2, 0x02 /* Public */,
       5,    0,   43,    2, 0x02 /* Public */,
       6,    0,   44,    2, 0x02 /* Public */,
       7,    0,   45,    2, 0x02 /* Public */,

 // signals: parameters
    QMetaType::Void,

 // methods: parameters
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void WeatherViewModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        WeatherViewModel *_t = static_cast<WeatherViewModel *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->weatherDataUpdated(); break;
        case 1: _t->clickSearchCityButton((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->clickNextDayButton(); break;
        case 3: _t->clickPrevDayButton(); break;
        case 4: _t->clickWeekWeatherDataButton(); break;
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
    }
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
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void WeatherViewModel::weatherDataUpdated()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
