/****************************************************************************
** Meta object code from reading C++ file 'protocolstages.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../DCNetworkClient/protocolstages.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'protocolstages.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ProtocolStages_t {
    QByteArrayData data[35];
    char stringdata0[586];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ProtocolStages_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ProtocolStages_t qt_meta_stringdata_ProtocolStages = {
    {
QT_MOC_LITERAL(0, 0, 14), // "ProtocolStages"
QT_MOC_LITERAL(1, 15, 16), // "finished_PSMaker"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 11), // "sendSecrets"
QT_MOC_LITERAL(4, 45, 12), // "QVector<int>"
QT_MOC_LITERAL(5, 58, 20), // "sendXORorNXOR_Result"
QT_MOC_LITERAL(6, 79, 18), // "sendProtocolAnswer"
QT_MOC_LITERAL(7, 98, 19), // "allSecretsWasGained"
QT_MOC_LITERAL(8, 118, 22), // "allXorResultsWasGained"
QT_MOC_LITERAL(9, 141, 21), // "gotMainProtocolAnswer"
QT_MOC_LITERAL(10, 163, 13), // "gotAnswerWord"
QT_MOC_LITERAL(11, 177, 24), // "allRoundResultsWasGained"
QT_MOC_LITERAL(12, 202, 13), // "endOfProtocol"
QT_MOC_LITERAL(13, 216, 10), // "lineSignal"
QT_MOC_LITERAL(14, 227, 21), // "CatchBroadcastingWord"
QT_MOC_LITERAL(15, 249, 25), // "CaughtSelfBroadcastNumber"
QT_MOC_LITERAL(16, 275, 15), // "broadcastNumber"
QT_MOC_LITERAL(17, 291, 27), // "CaughtSelfDescriptionNumber"
QT_MOC_LITERAL(18, 319, 6), // "number"
QT_MOC_LITERAL(19, 326, 22), // "CaughtNumberOfMessages"
QT_MOC_LITERAL(20, 349, 8), // "numOfMes"
QT_MOC_LITERAL(21, 358, 26), // "CaughtDescriptionsOfGuests"
QT_MOC_LITERAL(22, 385, 17), // "QMap<int,QString>"
QT_MOC_LITERAL(23, 403, 19), // "CatchMissingSecrets"
QT_MOC_LITERAL(24, 423, 12), // "side_secrets"
QT_MOC_LITERAL(25, 436, 20), // "CatchOthersXORorNXOR"
QT_MOC_LITERAL(26, 457, 9), // "xOrNx_res"
QT_MOC_LITERAL(27, 467, 21), // "CatchSideAnswerResult"
QT_MOC_LITERAL(28, 489, 6), // "result"
QT_MOC_LITERAL(29, 496, 18), // "FirstProtocolStage"
QT_MOC_LITERAL(30, 515, 22), // "process_ProtocolStages"
QT_MOC_LITERAL(31, 538, 18), // "ChangeIsPayerValue"
QT_MOC_LITERAL(32, 557, 5), // "state"
QT_MOC_LITERAL(33, 563, 16), // "NewProtocolCycle"
QT_MOC_LITERAL(34, 580, 5) // "Reset"

    },
    "ProtocolStages\0finished_PSMaker\0\0"
    "sendSecrets\0QVector<int>\0sendXORorNXOR_Result\0"
    "sendProtocolAnswer\0allSecretsWasGained\0"
    "allXorResultsWasGained\0gotMainProtocolAnswer\0"
    "gotAnswerWord\0allRoundResultsWasGained\0"
    "endOfProtocol\0lineSignal\0CatchBroadcastingWord\0"
    "CaughtSelfBroadcastNumber\0broadcastNumber\0"
    "CaughtSelfDescriptionNumber\0number\0"
    "CaughtNumberOfMessages\0numOfMes\0"
    "CaughtDescriptionsOfGuests\0QMap<int,QString>\0"
    "CatchMissingSecrets\0side_secrets\0"
    "CatchOthersXORorNXOR\0xOrNx_res\0"
    "CatchSideAnswerResult\0result\0"
    "FirstProtocolStage\0process_ProtocolStages\0"
    "ChangeIsPayerValue\0state\0NewProtocolCycle\0"
    "Reset"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ProtocolStages[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      24,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      11,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,  134,    2, 0x06 /* Public */,
       3,    1,  135,    2, 0x06 /* Public */,
       5,    1,  138,    2, 0x06 /* Public */,
       6,    1,  141,    2, 0x06 /* Public */,
       7,    0,  144,    2, 0x06 /* Public */,
       8,    0,  145,    2, 0x06 /* Public */,
       9,    1,  146,    2, 0x06 /* Public */,
      10,    1,  149,    2, 0x06 /* Public */,
      11,    0,  152,    2, 0x06 /* Public */,
      12,    0,  153,    2, 0x06 /* Public */,
      13,    0,  154,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      14,    1,  155,    2, 0x0a /* Public */,
      15,    1,  158,    2, 0x0a /* Public */,
      17,    1,  161,    2, 0x0a /* Public */,
      19,    1,  164,    2, 0x0a /* Public */,
      21,    1,  167,    2, 0x0a /* Public */,
      23,    1,  170,    2, 0x0a /* Public */,
      25,    1,  173,    2, 0x0a /* Public */,
      27,    1,  176,    2, 0x0a /* Public */,
      29,    0,  179,    2, 0x0a /* Public */,
      30,    0,  180,    2, 0x0a /* Public */,
      31,    1,  181,    2, 0x0a /* Public */,
      33,    1,  184,    2, 0x0a /* Public */,
      34,    0,  187,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::Int,   16,
    QMetaType::Void, QMetaType::Int,   18,
    QMetaType::Void, QMetaType::Int,   20,
    QMetaType::Void, 0x80000000 | 22,    2,
    QMetaType::Void, QMetaType::Int,   24,
    QMetaType::Void, QMetaType::Int,   26,
    QMetaType::Void, QMetaType::Int,   28,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   32,
    QMetaType::Void, QMetaType::Int,   28,
    QMetaType::Void,

       0        // eod
};

void ProtocolStages::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ProtocolStages *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->finished_PSMaker(); break;
        case 1: _t->sendSecrets((*reinterpret_cast< QVector<int>(*)>(_a[1]))); break;
        case 2: _t->sendXORorNXOR_Result((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->sendProtocolAnswer((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->allSecretsWasGained(); break;
        case 5: _t->allXorResultsWasGained(); break;
        case 6: _t->gotMainProtocolAnswer((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->gotAnswerWord((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 8: _t->allRoundResultsWasGained(); break;
        case 9: _t->endOfProtocol(); break;
        case 10: _t->lineSignal(); break;
        case 11: _t->CatchBroadcastingWord((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 12: _t->CaughtSelfBroadcastNumber((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 13: _t->CaughtSelfDescriptionNumber((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 14: _t->CaughtNumberOfMessages((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 15: _t->CaughtDescriptionsOfGuests((*reinterpret_cast< QMap<int,QString>(*)>(_a[1]))); break;
        case 16: _t->CatchMissingSecrets((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 17: _t->CatchOthersXORorNXOR((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 18: _t->CatchSideAnswerResult((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 19: _t->FirstProtocolStage(); break;
        case 20: _t->process_ProtocolStages(); break;
        case 21: _t->ChangeIsPayerValue((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 22: _t->NewProtocolCycle((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 23: _t->Reset(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 1:
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
            using _t = void (ProtocolStages::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ProtocolStages::finished_PSMaker)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (ProtocolStages::*)(QVector<int> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ProtocolStages::sendSecrets)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (ProtocolStages::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ProtocolStages::sendXORorNXOR_Result)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (ProtocolStages::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ProtocolStages::sendProtocolAnswer)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (ProtocolStages::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ProtocolStages::allSecretsWasGained)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (ProtocolStages::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ProtocolStages::allXorResultsWasGained)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (ProtocolStages::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ProtocolStages::gotMainProtocolAnswer)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (ProtocolStages::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ProtocolStages::gotAnswerWord)) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (ProtocolStages::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ProtocolStages::allRoundResultsWasGained)) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (ProtocolStages::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ProtocolStages::endOfProtocol)) {
                *result = 9;
                return;
            }
        }
        {
            using _t = void (ProtocolStages::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ProtocolStages::lineSignal)) {
                *result = 10;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ProtocolStages::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_ProtocolStages.data,
    qt_meta_data_ProtocolStages,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ProtocolStages::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ProtocolStages::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ProtocolStages.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int ProtocolStages::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 24)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 24;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 24)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 24;
    }
    return _id;
}

// SIGNAL 0
void ProtocolStages::finished_PSMaker()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void ProtocolStages::sendSecrets(QVector<int> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void ProtocolStages::sendXORorNXOR_Result(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void ProtocolStages::sendProtocolAnswer(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void ProtocolStages::allSecretsWasGained()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void ProtocolStages::allXorResultsWasGained()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void ProtocolStages::gotMainProtocolAnswer(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void ProtocolStages::gotAnswerWord(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void ProtocolStages::allRoundResultsWasGained()
{
    QMetaObject::activate(this, &staticMetaObject, 8, nullptr);
}

// SIGNAL 9
void ProtocolStages::endOfProtocol()
{
    QMetaObject::activate(this, &staticMetaObject, 9, nullptr);
}

// SIGNAL 10
void ProtocolStages::lineSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 10, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
