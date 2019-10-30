/****************************************************************************
** Meta object code from reading C++ file 'database.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../DiscountCard fail/DiscountCard/database.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'database.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Database_t {
    QByteArrayData data[9];
    char stringdata0[103];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Database_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Database_t qt_meta_stringdata_Database = {
    {
QT_MOC_LITERAL(0, 0, 8), // "Database"
QT_MOC_LITERAL(1, 9, 12), // "SSaveSuccess"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 11), // "SSaveFailed"
QT_MOC_LITERAL(4, 35, 19), // "SRequirementCorrect"
QT_MOC_LITERAL(5, 55, 9), // "isCorrect"
QT_MOC_LITERAL(6, 65, 5), // "value"
QT_MOC_LITERAL(7, 71, 10), // "modelIndex"
QT_MOC_LITERAL(8, 82, 20) // "SlotCheckRequirement"

    },
    "Database\0SSaveSuccess\0\0SSaveFailed\0"
    "SRequirementCorrect\0isCorrect\0value\0"
    "modelIndex\0SlotCheckRequirement"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Database[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x06 /* Public */,
       3,    0,   35,    2, 0x06 /* Public */,
       4,    3,   36,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    2,   43,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool, QMetaType::QString, QMetaType::QModelIndex,    5,    6,    7,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QModelIndex,    6,    7,

       0        // eod
};

void Database::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Database *_t = static_cast<Database *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->SSaveSuccess(); break;
        case 1: _t->SSaveFailed(); break;
        case 2: _t->SRequirementCorrect((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QModelIndex(*)>(_a[3]))); break;
        case 3: _t->SlotCheckRequirement((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< const QModelIndex(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (Database::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Database::SSaveSuccess)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (Database::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Database::SSaveFailed)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (Database::*_t)(bool , const QString & , const QModelIndex & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Database::SRequirementCorrect)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject Database::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Database.data,
      qt_meta_data_Database,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Database::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Database::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Database.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Database::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
void Database::SSaveSuccess()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void Database::SSaveFailed()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void Database::SRequirementCorrect(bool _t1, const QString & _t2, const QModelIndex & _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
