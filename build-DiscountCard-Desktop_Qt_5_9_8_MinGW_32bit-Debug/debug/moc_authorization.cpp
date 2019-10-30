/****************************************************************************
** Meta object code from reading C++ file 'authorization.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../DiscountCard/authorization.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'authorization.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Authorization_t {
    QByteArrayData data[7];
    char stringdata0[84];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Authorization_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Authorization_t qt_meta_stringdata_Authorization = {
    {
QT_MOC_LITERAL(0, 0, 13), // "Authorization"
QT_MOC_LITERAL(1, 14, 21), // "SAuthorizationSuccess"
QT_MOC_LITERAL(2, 36, 0), // ""
QT_MOC_LITERAL(3, 37, 14), // "SAddNewAccount"
QT_MOC_LITERAL(4, 52, 5), // "Check"
QT_MOC_LITERAL(5, 58, 13), // "checkLineEdit"
QT_MOC_LITERAL(6, 72, 11) // "SNewAccount"

    },
    "Authorization\0SAuthorizationSuccess\0"
    "\0SAddNewAccount\0Check\0checkLineEdit\0"
    "SNewAccount"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Authorization[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x06 /* Public */,
       3,    0,   42,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   43,    2, 0x08 /* Private */,
       5,    0,   44,    2, 0x08 /* Private */,
       6,    0,   45,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Authorization::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Authorization *_t = static_cast<Authorization *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->SAuthorizationSuccess((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->SAddNewAccount(); break;
        case 2: _t->Check(); break;
        case 3: _t->checkLineEdit(); break;
        case 4: _t->SNewAccount(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (Authorization::*_t)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Authorization::SAuthorizationSuccess)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (Authorization::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Authorization::SAddNewAccount)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject Authorization::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Authorization.data,
      qt_meta_data_Authorization,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Authorization::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Authorization::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Authorization.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Authorization::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
void Authorization::SAuthorizationSuccess(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Authorization::SAddNewAccount()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
