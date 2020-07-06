/****************************************************************************
** Meta object code from reading C++ file 'logterminal.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../DCNetworkClient/logterminal.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'logterminal.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_LogTerminal_t {
    QByteArrayData data[12];
    char stringdata0[171];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_LogTerminal_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_LogTerminal_t qt_meta_stringdata_LogTerminal = {
    {
QT_MOC_LITERAL(0, 0, 11), // "LogTerminal"
QT_MOC_LITERAL(1, 12, 15), // "showLogTerminal"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 9), // "WriteLine"
QT_MOC_LITERAL(4, 39, 22), // "on_closeButton_clicked"
QT_MOC_LITERAL(5, 62, 15), // "printSendedData"
QT_MOC_LITERAL(6, 78, 4), // "data"
QT_MOC_LITERAL(7, 83, 17), // "printReceivedData"
QT_MOC_LITERAL(8, 101, 13), // "printSentData"
QT_MOC_LITERAL(9, 115, 11), // "sended_data"
QT_MOC_LITERAL(10, 127, 21), // "on_cls1Button_clicked"
QT_MOC_LITERAL(11, 149, 21) // "on_cls2Button_clicked"

    },
    "LogTerminal\0showLogTerminal\0\0WriteLine\0"
    "on_closeButton_clicked\0printSendedData\0"
    "data\0printReceivedData\0printSentData\0"
    "sended_data\0on_cls1Button_clicked\0"
    "on_cls2Button_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_LogTerminal[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x0a /* Public */,
       3,    0,   55,    2, 0x0a /* Public */,
       4,    0,   56,    2, 0x08 /* Private */,
       5,    1,   57,    2, 0x08 /* Private */,
       7,    1,   60,    2, 0x08 /* Private */,
       8,    1,   63,    2, 0x08 /* Private */,
      10,    0,   66,    2, 0x08 /* Private */,
      11,    0,   67,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QByteArray,    6,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void, QMetaType::QString,    9,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void LogTerminal::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<LogTerminal *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->showLogTerminal(); break;
        case 1: _t->WriteLine(); break;
        case 2: _t->on_closeButton_clicked(); break;
        case 3: _t->printSendedData((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 4: _t->printReceivedData((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->printSentData((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->on_cls1Button_clicked(); break;
        case 7: _t->on_cls2Button_clicked(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject LogTerminal::staticMetaObject = { {
    &QDialog::staticMetaObject,
    qt_meta_stringdata_LogTerminal.data,
    qt_meta_data_LogTerminal,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *LogTerminal::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *LogTerminal::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_LogTerminal.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int LogTerminal::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
