/****************************************************************************
** Meta object code from reading C++ file 'enviardatos.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.13.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../enviardatos.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'enviardatos.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.13.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_enviardatos_t {
    QByteArrayData data[8];
    char stringdata0[134];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_enviardatos_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_enviardatos_t qt_meta_stringdata_enviardatos = {
    {
QT_MOC_LITERAL(0, 0, 11), // "enviardatos"
QT_MOC_LITERAL(1, 12, 9), // "send_data"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 20), // "on_bpm_envio_clicked"
QT_MOC_LITERAL(4, 44, 21), // "on_spo2_envio_clicked"
QT_MOC_LITERAL(5, 66, 21), // "on_pani_envio_clicked"
QT_MOC_LITERAL(6, 88, 21), // "on_temp_envio_clicked"
QT_MOC_LITERAL(7, 110, 23) // "on_toolButton_5_clicked"

    },
    "enviardatos\0send_data\0\0on_bpm_envio_clicked\0"
    "on_spo2_envio_clicked\0on_pani_envio_clicked\0"
    "on_temp_envio_clicked\0on_toolButton_5_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_enviardatos[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   47,    2, 0x08 /* Private */,
       4,    0,   48,    2, 0x08 /* Private */,
       5,    0,   49,    2, 0x08 /* Private */,
       6,    0,   50,    2, 0x08 /* Private */,
       7,    0,   51,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void enviardatos::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<enviardatos *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->send_data((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->on_bpm_envio_clicked(); break;
        case 2: _t->on_spo2_envio_clicked(); break;
        case 3: _t->on_pani_envio_clicked(); break;
        case 4: _t->on_temp_envio_clicked(); break;
        case 5: _t->on_toolButton_5_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (enviardatos::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&enviardatos::send_data)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject enviardatos::staticMetaObject = { {
    &QDialog::staticMetaObject,
    qt_meta_stringdata_enviardatos.data,
    qt_meta_data_enviardatos,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *enviardatos::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *enviardatos::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_enviardatos.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int enviardatos::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void enviardatos::send_data(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
