/****************************************************************************
** Meta object code from reading C++ file 'tcpsocketreader.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../DCNetworkClient/tcpsocketreader.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'tcpsocketreader.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_TcpSocketReader_t {
    QByteArrayData data[24];
    char stringdata0[351];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TcpSocketReader_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TcpSocketReader_t qt_meta_stringdata_TcpSocketReader = {
    {
QT_MOC_LITERAL(0, 0, 15), // "TcpSocketReader"
QT_MOC_LITERAL(1, 16, 21), // "finished_SocketReader"
QT_MOC_LITERAL(2, 38, 0), // ""
QT_MOC_LITERAL(3, 39, 9), // "outSocket"
QT_MOC_LITERAL(4, 49, 11), // "sended_data"
QT_MOC_LITERAL(5, 61, 24), // "gotSelfDescriptionNumber"
QT_MOC_LITERAL(6, 86, 6), // "number"
QT_MOC_LITERAL(7, 93, 22), // "gotSelfBroadcastNumber"
QT_MOC_LITERAL(8, 116, 19), // "gotNumberOfMessages"
QT_MOC_LITERAL(9, 136, 23), // "gotDescriptionsOfGuests"
QT_MOC_LITERAL(10, 160, 17), // "QMap<int,QString>"
QT_MOC_LITERAL(11, 178, 16), // "gotSideXorResult"
QT_MOC_LITERAL(12, 195, 5), // "value"
QT_MOC_LITERAL(13, 201, 13), // "gotSideSecret"
QT_MOC_LITERAL(14, 215, 21), // "gotSideProtocolAnswer"
QT_MOC_LITERAL(15, 237, 20), // "process_SocketReader"
QT_MOC_LITERAL(16, 258, 7), // "NewUser"
QT_MOC_LITERAL(17, 266, 14), // "ReadFromSocket"
QT_MOC_LITERAL(18, 281, 15), // "Process_Message"
QT_MOC_LITERAL(19, 297, 4), // "data"
QT_MOC_LITERAL(20, 302, 21), // "ConvertFromIPv6ToIpv4"
QT_MOC_LITERAL(21, 324, 12), // "QHostAddress"
QT_MOC_LITERAL(22, 337, 7), // "address"
QT_MOC_LITERAL(23, 345, 5) // "Reset"

    },
    "TcpSocketReader\0finished_SocketReader\0"
    "\0outSocket\0sended_data\0gotSelfDescriptionNumber\0"
    "number\0gotSelfBroadcastNumber\0"
    "gotNumberOfMessages\0gotDescriptionsOfGuests\0"
    "QMap<int,QString>\0gotSideXorResult\0"
    "value\0gotSideSecret\0gotSideProtocolAnswer\0"
    "process_SocketReader\0NewUser\0"
    "ReadFromSocket\0Process_Message\0data\0"
    "ConvertFromIPv6ToIpv4\0QHostAddress\0"
    "address\0Reset"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TcpSocketReader[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       9,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   89,    2, 0x06 /* Public */,
       3,    1,   90,    2, 0x06 /* Public */,
       5,    1,   93,    2, 0x06 /* Public */,
       7,    1,   96,    2, 0x06 /* Public */,
       8,    1,   99,    2, 0x06 /* Public */,
       9,    1,  102,    2, 0x06 /* Public */,
      11,    1,  105,    2, 0x06 /* Public */,
      13,    1,  108,    2, 0x06 /* Public */,
      14,    1,  111,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      15,    0,  114,    2, 0x0a /* Public */,
      16,    0,  115,    2, 0x0a /* Public */,
      17,    0,  116,    2, 0x0a /* Public */,
      18,    1,  117,    2, 0x0a /* Public */,
      20,    1,  120,    2, 0x0a /* Public */,
      23,    0,  123,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, 0x80000000 | 10,    2,
    QMetaType::Void, QMetaType::Int,   12,
    QMetaType::Void, QMetaType::Int,   12,
    QMetaType::Void, QMetaType::Int,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   19,
    QMetaType::QString, 0x80000000 | 21,   22,
    QMetaType::Void,

       0        // eod
};

void TcpSocketReader::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<TcpSocketReader *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->finished_SocketReader(); break;
        case 1: _t->outSocket((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->gotSelfDescriptionNumber((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->gotSelfBroadcastNumber((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->gotNumberOfMessages((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->gotDescriptionsOfGuests((*reinterpret_cast< QMap<int,QString>(*)>(_a[1]))); break;
        case 6: _t->gotSideXorResult((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->gotSideSecret((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->gotSideProtocolAnswer((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->process_SocketReader(); break;
        case 10: _t->NewUser(); break;
        case 11: _t->ReadFromSocket(); break;
        case 12: _t->Process_Message((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 13: { QString _r = _t->ConvertFromIPv6ToIpv4((*reinterpret_cast< QHostAddress(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 14: _t->Reset(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (TcpSocketReader::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TcpSocketReader::finished_SocketReader)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (TcpSocketReader::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TcpSocketReader::outSocket)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (TcpSocketReader::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TcpSocketReader::gotSelfDescriptionNumber)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (TcpSocketReader::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TcpSocketReader::gotSelfBroadcastNumber)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (TcpSocketReader::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TcpSocketReader::gotNumberOfMessages)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (TcpSocketReader::*)(QMap<int,QString> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TcpSocketReader::gotDescriptionsOfGuests)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (TcpSocketReader::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TcpSocketReader::gotSideXorResult)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (TcpSocketReader::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TcpSocketReader::gotSideSecret)) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (TcpSocketReader::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TcpSocketReader::gotSideProtocolAnswer)) {
                *result = 8;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject TcpSocketReader::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_TcpSocketReader.data,
    qt_meta_data_TcpSocketReader,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *TcpSocketReader::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TcpSocketReader::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_TcpSocketReader.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int TcpSocketReader::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 15;
    }
    return _id;
}

// SIGNAL 0
void TcpSocketReader::finished_SocketReader()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void TcpSocketReader::outSocket(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void TcpSocketReader::gotSelfDescriptionNumber(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void TcpSocketReader::gotSelfBroadcastNumber(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void TcpSocketReader::gotNumberOfMessages(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void TcpSocketReader::gotDescriptionsOfGuests(QMap<int,QString> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void TcpSocketReader::gotSideXorResult(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void TcpSocketReader::gotSideSecret(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void TcpSocketReader::gotSideProtocolAnswer(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
