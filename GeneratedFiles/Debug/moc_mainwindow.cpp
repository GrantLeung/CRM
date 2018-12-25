/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[20];
    char stringdata0[276];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 10), // "onMenuOpen"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 7), // "checked"
QT_MOC_LITERAL(4, 31, 10), // "onMenuSave"
QT_MOC_LITERAL(5, 42, 10), // "onMenuStat"
QT_MOC_LITERAL(6, 53, 20), // "on_btnSearch_clicked"
QT_MOC_LITERAL(7, 74, 17), // "on_btnAdd_clicked"
QT_MOC_LITERAL(8, 92, 20), // "on_btnDelete_clicked"
QT_MOC_LITERAL(9, 113, 11), // "slotAddItem"
QT_MOC_LITERAL(10, 125, 9), // "Customer*"
QT_MOC_LITERAL(11, 135, 4), // "item"
QT_MOC_LITERAL(12, 140, 30), // "on_comboBox_currentTextChanged"
QT_MOC_LITERAL(13, 171, 4), // "arg1"
QT_MOC_LITERAL(14, 176, 32), // "on_treeWidget_currentItemChanged"
QT_MOC_LITERAL(15, 209, 16), // "QTreeWidgetItem*"
QT_MOC_LITERAL(16, 226, 7), // "current"
QT_MOC_LITERAL(17, 234, 8), // "previous"
QT_MOC_LITERAL(18, 243, 26), // "on_tableView_doubleClicked"
QT_MOC_LITERAL(19, 270, 5) // "index"

    },
    "MainWindow\0onMenuOpen\0\0checked\0"
    "onMenuSave\0onMenuStat\0on_btnSearch_clicked\0"
    "on_btnAdd_clicked\0on_btnDelete_clicked\0"
    "slotAddItem\0Customer*\0item\0"
    "on_comboBox_currentTextChanged\0arg1\0"
    "on_treeWidget_currentItemChanged\0"
    "QTreeWidgetItem*\0current\0previous\0"
    "on_tableView_doubleClicked\0index"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   64,    2, 0x08 /* Private */,
       4,    1,   67,    2, 0x08 /* Private */,
       5,    1,   70,    2, 0x08 /* Private */,
       6,    0,   73,    2, 0x08 /* Private */,
       7,    0,   74,    2, 0x08 /* Private */,
       8,    0,   75,    2, 0x08 /* Private */,
       9,    1,   76,    2, 0x08 /* Private */,
      12,    1,   79,    2, 0x08 /* Private */,
      14,    2,   82,    2, 0x08 /* Private */,
      18,    1,   87,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 10,   11,
    QMetaType::Void, QMetaType::QString,   13,
    QMetaType::Void, 0x80000000 | 15, 0x80000000 | 15,   16,   17,
    QMetaType::Void, QMetaType::QModelIndex,   19,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->onMenuOpen((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->onMenuSave((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->onMenuStat((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->on_btnSearch_clicked(); break;
        case 4: _t->on_btnAdd_clicked(); break;
        case 5: _t->on_btnDelete_clicked(); break;
        case 6: _t->slotAddItem((*reinterpret_cast< Customer*(*)>(_a[1]))); break;
        case 7: _t->on_comboBox_currentTextChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 8: _t->on_treeWidget_currentItemChanged((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< QTreeWidgetItem*(*)>(_a[2]))); break;
        case 9: _t->on_tableView_doubleClicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
