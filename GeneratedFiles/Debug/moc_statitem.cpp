/****************************************************************************
** Meta object code from reading C++ file 'statitem.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../statitem.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'statitem.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_StatItem_t {
    QByteArrayData data[8];
    char stringdata0[77];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_StatItem_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_StatItem_t qt_meta_stringdata_StatItem = {
    {
QT_MOC_LITERAL(0, 0, 8), // "StatItem"
QT_MOC_LITERAL(1, 9, 8), // "getModel"
QT_MOC_LITERAL(2, 18, 0), // ""
QT_MOC_LITERAL(3, 19, 19), // "QStandardItemModel*"
QT_MOC_LITERAL(4, 39, 6), // "mModel"
QT_MOC_LITERAL(5, 46, 12), // "mAllProvince"
QT_MOC_LITERAL(6, 59, 8), // "mAllArea"
QT_MOC_LITERAL(7, 68, 8) // "mAllType"

    },
    "StatItem\0getModel\0\0QStandardItemModel*\0"
    "mModel\0mAllProvince\0mAllArea\0mAllType"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_StatItem[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    4,   19,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::QStringList, QMetaType::QStringList, QMetaType::QStringList,    4,    5,    6,    7,

       0        // eod
};

void StatItem::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        StatItem *_t = static_cast<StatItem *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->getModel((*reinterpret_cast< QStandardItemModel*(*)>(_a[1])),(*reinterpret_cast< QStringList(*)>(_a[2])),(*reinterpret_cast< QStringList(*)>(_a[3])),(*reinterpret_cast< QStringList(*)>(_a[4]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QStandardItemModel* >(); break;
            }
            break;
        }
    }
}

const QMetaObject StatItem::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_StatItem.data,
      qt_meta_data_StatItem,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *StatItem::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *StatItem::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_StatItem.stringdata0))
        return static_cast<void*>(const_cast< StatItem*>(this));
    return QDialog::qt_metacast(_clname);
}

int StatItem::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
