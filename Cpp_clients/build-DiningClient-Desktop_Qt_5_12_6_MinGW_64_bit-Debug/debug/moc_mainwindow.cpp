/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../DCNetworkClient/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[28];
    char stringdata0[497];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 19), // "startProtocolSignal"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 19), // "resetProtocolSignal"
QT_MOC_LITERAL(4, 52, 27), // "CaughtSelfDescriptionNumber"
QT_MOC_LITERAL(5, 80, 25), // "CaughtSelfBroadcastNumber"
QT_MOC_LITERAL(6, 106, 22), // "CaughtNumberOfMessages"
QT_MOC_LITERAL(7, 129, 26), // "CaughtDescriptionsOfGuests"
QT_MOC_LITERAL(8, 156, 17), // "QMap<int,QString>"
QT_MOC_LITERAL(9, 174, 18), // "users_descriptions"
QT_MOC_LITERAL(10, 193, 16), // "CaughtAllSecrets"
QT_MOC_LITERAL(11, 210, 19), // "CaughtSelfXorResult"
QT_MOC_LITERAL(12, 230, 19), // "CaughtAllXorResults"
QT_MOC_LITERAL(13, 250, 20), // "CaughtProtocolAnswer"
QT_MOC_LITERAL(14, 271, 6), // "answer"
QT_MOC_LITERAL(15, 278, 19), // "PrintInfoToTheSreen"
QT_MOC_LITERAL(16, 298, 4), // "text"
QT_MOC_LITERAL(17, 303, 28), // "PrintProtocolStageToTheSreen"
QT_MOC_LITERAL(18, 332, 18), // "ChangeIsPayerValue"
QT_MOC_LITERAL(19, 351, 5), // "state"
QT_MOC_LITERAL(20, 357, 21), // "CatchBroadcastingWord"
QT_MOC_LITERAL(21, 379, 4), // "word"
QT_MOC_LITERAL(22, 384, 24), // "ChangeStateOfBroacasting"
QT_MOC_LITERAL(23, 409, 5), // "delay"
QT_MOC_LITERAL(24, 415, 18), // "millisecondsToWait"
QT_MOC_LITERAL(25, 434, 9), // "writeLine"
QT_MOC_LITERAL(26, 444, 21), // "EndOfProtocolStrPrint"
QT_MOC_LITERAL(27, 466, 30) // "on_startProtocolButton_clicked"

    },
    "MainWindow\0startProtocolSignal\0\0"
    "resetProtocolSignal\0CaughtSelfDescriptionNumber\0"
    "CaughtSelfBroadcastNumber\0"
    "CaughtNumberOfMessages\0"
    "CaughtDescriptionsOfGuests\0QMap<int,QString>\0"
    "users_descriptions\0CaughtAllSecrets\0"
    "CaughtSelfXorResult\0CaughtAllXorResults\0"
    "CaughtProtocolAnswer\0answer\0"
    "PrintInfoToTheSreen\0text\0"
    "PrintProtocolStageToTheSreen\0"
    "ChangeIsPayerValue\0state\0CatchBroadcastingWord\0"
    "word\0ChangeStateOfBroacasting\0delay\0"
    "millisecondsToWait\0writeLine\0"
    "EndOfProtocolStrPrint\0"
    "on_startProtocolButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      19,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,  109,    2, 0x06 /* Public */,
       3,    0,  110,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    1,  111,    2, 0x0a /* Public */,
       5,    1,  114,    2, 0x0a /* Public */,
       6,    1,  117,    2, 0x0a /* Public */,
       7,    1,  120,    2, 0x0a /* Public */,
      10,    0,  123,    2, 0x0a /* Public */,
      11,    1,  124,    2, 0x0a /* Public */,
      12,    0,  127,    2, 0x0a /* Public */,
      13,    1,  128,    2, 0x0a /* Public */,
      15,    1,  131,    2, 0x0a /* Public */,
      17,    1,  134,    2, 0x0a /* Public */,
      18,    1,  137,    2, 0x0a /* Public */,
      20,    1,  140,    2, 0x0a /* Public */,
      22,    1,  143,    2, 0x0a /* Public */,
      23,    1,  146,    2, 0x0a /* Public */,
      25,    0,  149,    2, 0x0a /* Public */,
      26,    0,  150,    2, 0x0a /* Public */,
      27,    0,  151,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   14,
    QMetaType::Void, QMetaType::QString,   16,
    QMetaType::Void, QMetaType::QString,   16,
    QMetaType::Void, QMetaType::Bool,   19,
    QMetaType::Void, QMetaType::QString,   21,
    QMetaType::Void, QMetaType::Bool,   19,
    QMetaType::Void, QMetaType::Int,   24,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->startProtocolSignal(); break;
        case 1: _t->resetProtocolSignal(); break;
        case 2: _t->CaughtSelfDescriptionNumber((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->CaughtSelfBroadcastNumber((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->CaughtNumberOfMessages((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->CaughtDescriptionsOfGuests((*reinterpret_cast< QMap<int,QString>(*)>(_a[1]))); break;
        case 6: _t->CaughtAllSecrets(); break;
        case 7: _t->CaughtSelfXorResult((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 8: _t->CaughtAllXorResults(); break;
        case 9: _t->CaughtProtocolAnswer((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->PrintInfoToTheSreen((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 11: _t->PrintProtocolStageToTheSreen((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 12: _t->ChangeIsPayerValue((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 13: _t->CatchBroadcastingWord((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 14: _t->ChangeStateOfBroacasting((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 15: _t->delay((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 16: _t->writeLine(); break;
        case 17: _t->EndOfProtocolStrPrint(); break;
        case 18: _t->on_startProtocolButton_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MainWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::startProtocolSignal)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::resetProtocolSignal)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    &QMainWindow::staticMetaObject,
    qt_meta_stringdata_MainWindow.data,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 19)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 19;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 19)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 19;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::startProtocolSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void MainWindow::resetProtocolSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
