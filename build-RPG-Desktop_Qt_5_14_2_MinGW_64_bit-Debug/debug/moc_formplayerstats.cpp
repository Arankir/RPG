/****************************************************************************
** Meta object code from reading C++ file 'formplayerstats.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../RPG/playerWidgets/formplayerstats.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'formplayerstats.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_FormPlayerStats_t {
    QByteArrayData data[11];
    char stringdata0[244];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FormPlayerStats_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FormPlayerStats_t qt_meta_stringdata_FormPlayerStats = {
    {
QT_MOC_LITERAL(0, 0, 15), // "FormPlayerStats"
QT_MOC_LITERAL(1, 16, 20), // "s_playerStatsChanged"
QT_MOC_LITERAL(2, 37, 0), // ""
QT_MOC_LITERAL(3, 38, 6), // "Player"
QT_MOC_LITERAL(4, 45, 6), // "player"
QT_MOC_LITERAL(5, 52, 26), // "on_pushButtonApply_clicked"
QT_MOC_LITERAL(6, 79, 31), // "on_pushButtonLoadAvatar_clicked"
QT_MOC_LITERAL(7, 111, 32), // "on_pushButtonAddStrength_clicked"
QT_MOC_LITERAL(8, 144, 31), // "on_pushButtonAddAgility_clicked"
QT_MOC_LITERAL(9, 176, 35), // "on_pushButtonAddIntelegence_c..."
QT_MOC_LITERAL(10, 212, 31) // "on_pushButtonAddStamina_clicked"

    },
    "FormPlayerStats\0s_playerStatsChanged\0"
    "\0Player\0player\0on_pushButtonApply_clicked\0"
    "on_pushButtonLoadAvatar_clicked\0"
    "on_pushButtonAddStrength_clicked\0"
    "on_pushButtonAddAgility_clicked\0"
    "on_pushButtonAddIntelegence_clicked\0"
    "on_pushButtonAddStamina_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FormPlayerStats[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   52,    2, 0x08 /* Private */,
       6,    0,   53,    2, 0x08 /* Private */,
       7,    0,   54,    2, 0x08 /* Private */,
       8,    0,   55,    2, 0x08 /* Private */,
       9,    0,   56,    2, 0x08 /* Private */,
      10,    0,   57,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void FormPlayerStats::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<FormPlayerStats *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->s_playerStatsChanged((*reinterpret_cast< Player(*)>(_a[1]))); break;
        case 1: _t->on_pushButtonApply_clicked(); break;
        case 2: _t->on_pushButtonLoadAvatar_clicked(); break;
        case 3: _t->on_pushButtonAddStrength_clicked(); break;
        case 4: _t->on_pushButtonAddAgility_clicked(); break;
        case 5: _t->on_pushButtonAddIntelegence_clicked(); break;
        case 6: _t->on_pushButtonAddStamina_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (FormPlayerStats::*)(Player );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FormPlayerStats::s_playerStatsChanged)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject FormPlayerStats::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_FormPlayerStats.data,
    qt_meta_data_FormPlayerStats,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *FormPlayerStats::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FormPlayerStats::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_FormPlayerStats.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int FormPlayerStats::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void FormPlayerStats::s_playerStatsChanged(Player _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
