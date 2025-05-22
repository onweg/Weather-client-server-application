/****************************************************************************
** Meta object code from reading C++ file 'AuthViewModel.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../WeatherApplication/src/presentation/viewmodels/AuthViewModel.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'AuthViewModel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_AuthViewModel_t {
    QByteArrayData data[9];
    char stringdata0[89];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AuthViewModel_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AuthViewModel_t qt_meta_stringdata_AuthViewModel = {
    {
QT_MOC_LITERAL(0, 0, 13), // "AuthViewModel"
QT_MOC_LITERAL(1, 14, 13), // "authSucceeded"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 10), // "authFailed"
QT_MOC_LITERAL(4, 40, 7), // "message"
QT_MOC_LITERAL(5, 48, 9), // "loginUser"
QT_MOC_LITERAL(6, 58, 8), // "username"
QT_MOC_LITERAL(7, 67, 8), // "password"
QT_MOC_LITERAL(8, 76, 12) // "registerUser"

    },
    "AuthViewModel\0authSucceeded\0\0authFailed\0"
    "message\0loginUser\0username\0password\0"
    "registerUser"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AuthViewModel[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x06 /* Public */,
       3,    1,   35,    2, 0x06 /* Public */,

 // methods: name, argc, parameters, tag, flags
       5,    2,   38,    2, 0x02 /* Public */,
       8,    2,   43,    2, 0x02 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    4,

 // methods: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    6,    7,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    6,    7,

       0        // eod
};

void AuthViewModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        AuthViewModel *_t = static_cast<AuthViewModel *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->authSucceeded(); break;
        case 1: _t->authFailed((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->loginUser((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 3: _t->registerUser((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (AuthViewModel::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&AuthViewModel::authSucceeded)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (AuthViewModel::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&AuthViewModel::authFailed)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject AuthViewModel::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_AuthViewModel.data,
      qt_meta_data_AuthViewModel,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *AuthViewModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AuthViewModel::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_AuthViewModel.stringdata0))
        return static_cast<void*>(const_cast< AuthViewModel*>(this));
    return QObject::qt_metacast(_clname);
}

int AuthViewModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void AuthViewModel::authSucceeded()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void AuthViewModel::authFailed(const QString & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
