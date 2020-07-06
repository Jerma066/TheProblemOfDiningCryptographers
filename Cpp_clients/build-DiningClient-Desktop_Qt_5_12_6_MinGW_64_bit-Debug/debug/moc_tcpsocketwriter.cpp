/****************************************************************************
** Meta object code from reading C++ file 'tcpsocketwriter.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../DCNetworkClient/tcpsocketwriter.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'tcpsocketwriter.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_TcpSocketWriter_t {
    QByteArrayData data[34];
    char stringdata0[527];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TcpSocketWriter_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TcpSocketWriter_t qt_meta_stringdata_TcpSocketWriter = {
    {
QT_MOC_LITERAL(0, 0, 15), // "TcpSocketWriter"
QT_MOC_LITERAL(1, 16, 21), // "finished_SocketWriter"
QT_MOC_LITERAL(2, 38, 0), // ""
QT_MOC_LITERAL(3, 39, 10), // "exportData"
QT_MOC_LITERAL(4, 50, 11), // "sended_data"
QT_MOC_LITERAL(5, 62, 20), // "process_SocketReader"
QT_MOC_LITERAL(6, 83, 15), // "writeDataToUser"
QT_MOC_LITERAL(7, 99, 4), // "host"
QT_MOC_LITERAL(8, 104, 4), // "port"
QT_MOC_LITERAL(9, 109, 4), // "data"
QT_MOC_LITERAL(10, 114, 23), // "SetConnectionParameters"
QT_MOC_LITERAL(11, 138, 22), // "QPair<QString,quint16>"
QT_MOC_LITERAL(12, 161, 12), // "selfSettings"
QT_MOC_LITERAL(13, 174, 14), // "serverSettings"
QT_MOC_LITERAL(14, 189, 27), // "CaughtSelfDescriptionNumber"
QT_MOC_LITERAL(15, 217, 25), // "CaughtSelfBroadcastNumber"
QT_MOC_LITERAL(16, 243, 26), // "CaughtDescriptionsOfGuests"
QT_MOC_LITERAL(17, 270, 17), // "QMap<int,QString>"
QT_MOC_LITERAL(18, 288, 18), // "users_descriptions"
QT_MOC_LITERAL(19, 307, 21), // "ProcessWritingMessage"
QT_MOC_LITERAL(20, 329, 7), // "message"
QT_MOC_LITERAL(21, 337, 24), // "ChangeStateOfBroacasting"
QT_MOC_LITERAL(22, 362, 5), // "state"
QT_MOC_LITERAL(23, 368, 13), // "connectToUser"
QT_MOC_LITERAL(24, 382, 17), // "disconnecFromUser"
QT_MOC_LITERAL(25, 400, 9), // "writeData"
QT_MOC_LITERAL(26, 410, 10), // "GetNumbers"
QT_MOC_LITERAL(27, 421, 23), // "SecretsFrindlyBroadcast"
QT_MOC_LITERAL(28, 445, 12), // "QVector<int>"
QT_MOC_LITERAL(29, 458, 7), // "secrets"
QT_MOC_LITERAL(30, 466, 16), // "BroadcastMessage"
QT_MOC_LITERAL(31, 483, 30), // "ProtocolAnswerBroadcastMessage"
QT_MOC_LITERAL(32, 514, 6), // "answer"
QT_MOC_LITERAL(33, 521, 5) // "Reset"

    },
    "TcpSocketWriter\0finished_SocketWriter\0"
    "\0exportData\0sended_data\0process_SocketReader\0"
    "writeDataToUser\0host\0port\0data\0"
    "SetConnectionParameters\0QPair<QString,quint16>\0"
    "selfSettings\0serverSettings\0"
    "CaughtSelfDescriptionNumber\0"
    "CaughtSelfBroadcastNumber\0"
    "CaughtDescriptionsOfGuests\0QMap<int,QString>\0"
    "users_descriptions\0ProcessWritingMessage\0"
    "message\0ChangeStateOfBroacasting\0state\0"
    "connectToUser\0disconnecFromUser\0"
    "writeData\0GetNumbers\0SecretsFrindlyBroadcast\0"
    "QVector<int>\0secrets\0BroadcastMessage\0"
    "ProtocolAnswerBroadcastMessage\0answer\0"
    "Reset"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TcpSocketWriter[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      18,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,  104,    2, 0x06 /* Public */,
       3,    1,  105,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,  108,    2, 0x0a /* Public */,
       6,    3,  109,    2, 0x0a /* Public */,
      10,    2,  116,    2, 0x0a /* Public */,
      14,    1,  121,    2, 0x0a /* Public */,
      15,    1,  124,    2, 0x0a /* Public */,
      16,    1,  127,    2, 0x0a /* Public */,
      19,    1,  130,    2, 0x0a /* Public */,
      21,    1,  133,    2, 0x0a /* Public */,
      23,    2,  136,    2, 0x08 /* Private */,
      24,    0,  141,    2, 0x08 /* Private */,
      25,    1,  142,    2, 0x08 /* Private */,
      26,    0,  145,    2, 0x08 /* Private */,
      27,    1,  146,    2, 0x08 /* Private */,
      30,    1,  149,    2, 0x08 /* Private */,
      31,    1,  152,    2, 0x08 /* Private */,
      33,    0,  155,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    4,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Bool, QMetaType::QString, QMetaType::UShort, QMetaType::QString,    7,    8,    9,
    QMetaType::Void, 0x80000000 | 11, 0x80000000 | 11,   12,   13,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, 0x80000000 | 17,   18,
    QMetaType::Void, QMetaType::QString,   20,
    QMetaType::Void, QMetaType::Bool,   22,
    QMetaType::Bool, QMetaType::QString, QMetaType::UShort,    7,    8,
    QMetaType::Void,
    QMetaType::Bool, QMetaType::QByteArray,    9,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 28,   29,
    QMetaType::Void, QMetaType::QString,   20,
    QMetaType::Void, QMetaType::Int,   32,
    QMetaType::Void,

       0        // eod
};

void TcpSocketWriter::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<TcpSocketWriter *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->finished_SocketWriter(); break;
        case 1: _t->exportData((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->process_SocketReader(); break;
        case 3: { bool _r = _t->writeDataToUser((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< quint16(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 4: _t->SetConnectionParameters((*reinterpret_cast< QPair<QString,quint16>(*)>(_a[1])),(*reinterpret_cast< QPair<QString,quint16>(*)>(_a[2]))); break;
        case 5: _t->CaughtSelfDescriptionNumber((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->CaughtSelfBroadcastNumber((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->CaughtDescriptionsOfGuests((*reinterpret_cast< QMap<int,QString>(*)>(_a[1]))); break;
        case 8: _t->ProcessWritingMessage((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 9: _t->ChangeStateOfBroacasting((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 10: { bool _r = _t->connectToUser((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< quint16(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 11: _t->disconnecFromUser(); break;
        case 12: { bool _r = _t->writeData((*reinterpret_cast< QByteArray(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 13: _t->GetNumbers(); break;
        case 14: _t->SecretsFrindlyBroadcast((*reinterpret_cast< QVector<int>(*)>(_a[1]))); break;
        case 15: _t->BroadcastMessage((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 16: _t->ProtocolAnswerBroadcastMessage((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 17: _t->Reset(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 14:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<int> >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (TcpSocketWriter::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TcpSocketWriter::finished_SocketWriter)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (TcpSocketWriter::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TcpSocketWriter::exportData)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject TcpSocketWriter::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_TcpSocketWriter.data,
    qt_meta_data_TcpSocketWriter,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *TcpSocketWriter::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TcpSocketWriter::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_TcpSocketWriter.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int TcpSocketWriter::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 18)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 18;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 18)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 18;
    }
    return _id;
}

// SIGNAL 0
void TcpSocketWriter::finished_SocketWriter()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void TcpSocketWriter::exportData(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
