/****************************************************************************
** Meta object code from reading C++ file 'server.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../RPG/class/network/server.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'server.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MyServer_t {
    QByteArrayData data[18];
    char stringdata0[206];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MyServer_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MyServer_t qt_meta_stringdata_MyServer = {
    {
QT_MOC_LITERAL(0, 0, 8), // "MyServer"
QT_MOC_LITERAL(1, 9, 9), // "s_started"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 9), // "s_connect"
QT_MOC_LITERAL(4, 30, 12), // "QHostAddress"
QT_MOC_LITERAL(5, 43, 6), // "s_read"
QT_MOC_LITERAL(6, 50, 15), // "RequestToServer"
QT_MOC_LITERAL(7, 66, 12), // "s_disconnect"
QT_MOC_LITERAL(8, 79, 17), // "slotNewConnection"
QT_MOC_LITERAL(9, 97, 14), // "slotServerRead"
QT_MOC_LITERAL(10, 112, 11), // "QTcpSocket*"
QT_MOC_LITERAL(11, 124, 7), // "aClient"
QT_MOC_LITERAL(12, 132, 9), // "slotWrite"
QT_MOC_LITERAL(13, 142, 8), // "aAddress"
QT_MOC_LITERAL(14, 151, 13), // "ReplyToClient"
QT_MOC_LITERAL(15, 165, 6), // "aReply"
QT_MOC_LITERAL(16, 172, 10), // "slotsWrite"
QT_MOC_LITERAL(17, 183, 22) // "slotClientDisconnected"

    },
    "MyServer\0s_started\0\0s_connect\0"
    "QHostAddress\0s_read\0RequestToServer\0"
    "s_disconnect\0slotNewConnection\0"
    "slotServerRead\0QTcpSocket*\0aClient\0"
    "slotWrite\0aAddress\0ReplyToClient\0"
    "aReply\0slotsWrite\0slotClientDisconnected"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MyServer[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   59,    2, 0x06 /* Public */,
       3,    1,   62,    2, 0x06 /* Public */,
       5,    2,   65,    2, 0x06 /* Public */,
       7,    1,   70,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    0,   73,    2, 0x0a /* Public */,
       9,    1,   74,    2, 0x0a /* Public */,
      12,    2,   77,    2, 0x0a /* Public */,
      16,    1,   82,    2, 0x0a /* Public */,
      17,    1,   85,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, 0x80000000 | 4,    2,
    QMetaType::Void, 0x80000000 | 4, 0x80000000 | 6,    2,    2,
    QMetaType::Void, 0x80000000 | 4,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 10,   11,
    QMetaType::Int, 0x80000000 | 4, 0x80000000 | 14,   13,   15,
    QMetaType::Void, 0x80000000 | 14,   15,
    QMetaType::Void, 0x80000000 | 10,   11,

       0        // eod
};

void MyServer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MyServer *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->s_started((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->s_connect((*reinterpret_cast< QHostAddress(*)>(_a[1]))); break;
        case 2: _t->s_read((*reinterpret_cast< QHostAddress(*)>(_a[1])),(*reinterpret_cast< RequestToServer(*)>(_a[2]))); break;
        case 3: _t->s_disconnect((*reinterpret_cast< QHostAddress(*)>(_a[1]))); break;
        case 4: _t->slotNewConnection(); break;
        case 5: _t->slotServerRead((*reinterpret_cast< QTcpSocket*(*)>(_a[1]))); break;
        case 6: { int _r = _t->slotWrite((*reinterpret_cast< const QHostAddress(*)>(_a[1])),(*reinterpret_cast< const ReplyToClient(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 7: _t->slotsWrite((*reinterpret_cast< const ReplyToClient(*)>(_a[1]))); break;
        case 8: _t->slotClientDisconnected((*reinterpret_cast< QTcpSocket*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 5:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QTcpSocket* >(); break;
            }
            break;
        case 8:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QTcpSocket* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MyServer::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MyServer::s_started)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (MyServer::*)(QHostAddress );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MyServer::s_connect)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (MyServer::*)(QHostAddress , RequestToServer );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MyServer::s_read)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (MyServer::*)(QHostAddress );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MyServer::s_disconnect)) {
                *result = 3;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MyServer::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_MyServer.data,
    qt_meta_data_MyServer,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MyServer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MyServer::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MyServer.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int MyServer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void MyServer::s_started(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MyServer::s_connect(QHostAddress _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void MyServer::s_read(QHostAddress _t1, RequestToServer _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void MyServer::s_disconnect(QHostAddress _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
