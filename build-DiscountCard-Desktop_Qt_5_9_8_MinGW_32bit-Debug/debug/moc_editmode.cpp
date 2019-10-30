/****************************************************************************
** Meta object code from reading C++ file 'editmode.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../DiscountCard fail/DiscountCard/editmode.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'editmode.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_EditMode_t {
    QByteArrayData data[11];
    char stringdata0[112];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_EditMode_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_EditMode_t qt_meta_stringdata_EditMode = {
    {
QT_MOC_LITERAL(0, 0, 8), // "EditMode"
QT_MOC_LITERAL(1, 9, 9), // "SEditMode"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 10), // "isEditMode"
QT_MOC_LITERAL(4, 31, 18), // "SCheckRequirements"
QT_MOC_LITERAL(5, 50, 5), // "value"
QT_MOC_LITERAL(6, 56, 10), // "modelIndex"
QT_MOC_LITERAL(7, 67, 10), // "SlotCancel"
QT_MOC_LITERAL(8, 78, 15), // "SlotDataChanged"
QT_MOC_LITERAL(9, 94, 11), // "SlotEditBox"
QT_MOC_LITERAL(10, 106, 5) // "index"

    },
    "EditMode\0SEditMode\0\0isEditMode\0"
    "SCheckRequirements\0value\0modelIndex\0"
    "SlotCancel\0SlotDataChanged\0SlotEditBox\0"
    "index"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_EditMode[] = {

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
       4,    2,   42,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    0,   47,    2, 0x0a /* Public */,
       8,    0,   48,    2, 0x0a /* Public */,
       9,    1,   49,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::QString, QMetaType::QModelIndex,    5,    6,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QModelIndex,   10,

       0        // eod
};

void EditMode::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        EditMode *_t = static_cast<EditMode *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->SEditMode((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->SCheckRequirements((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< const QModelIndex(*)>(_a[2]))); break;
        case 2: _t->SlotCancel(); break;
        case 3: _t->SlotDataChanged(); break;
        case 4: _t->SlotEditBox((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (EditMode::*_t)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&EditMode::SEditMode)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (EditMode::*_t)(QString , const QModelIndex & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&EditMode::SCheckRequirements)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject EditMode::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_EditMode.data,
      qt_meta_data_EditMode,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *EditMode::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *EditMode::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_EditMode.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int EditMode::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void EditMode::SEditMode(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void EditMode::SCheckRequirements(QString _t1, const QModelIndex & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
