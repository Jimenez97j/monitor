/****************************************************************************
** Meta object code from reading C++ file 'config_alarmas.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.13.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../config_alarmas.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'config_alarmas.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.13.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_config_alarmas_t {
    QByteArrayData data[18];
    char stringdata0[367];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_config_alarmas_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_config_alarmas_t qt_meta_stringdata_config_alarmas = {
    {
QT_MOC_LITERAL(0, 0, 14), // "config_alarmas"
QT_MOC_LITERAL(1, 15, 12), // "sonido_click"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 13), // "alarms_change"
QT_MOC_LITERAL(4, 43, 24), // "on_menos_min_ecg_pressed"
QT_MOC_LITERAL(5, 68, 22), // "on_mas_min_ecg_pressed"
QT_MOC_LITERAL(6, 91, 24), // "on_menos_max_ecg_pressed"
QT_MOC_LITERAL(7, 116, 25), // "on_menos_min_spo2_pressed"
QT_MOC_LITERAL(8, 142, 22), // "on_mas_max_ecg_pressed"
QT_MOC_LITERAL(9, 165, 23), // "on_mas_min_spo2_pressed"
QT_MOC_LITERAL(10, 189, 24), // "on_menos_min_rpm_pressed"
QT_MOC_LITERAL(11, 214, 22), // "on_mas_min_rpm_pressed"
QT_MOC_LITERAL(12, 237, 24), // "on_menos_max_rpm_pressed"
QT_MOC_LITERAL(13, 262, 22), // "on_mas_max_rpm_pressed"
QT_MOC_LITERAL(14, 285, 25), // "on_menos_max_spo2_pressed"
QT_MOC_LITERAL(15, 311, 23), // "on_mas_max_spo2_pressed"
QT_MOC_LITERAL(16, 335, 17), // "on_CERRAR_pressed"
QT_MOC_LITERAL(17, 353, 13) // "on_OK_pressed"

    },
    "config_alarmas\0sonido_click\0\0alarms_change\0"
    "on_menos_min_ecg_pressed\0"
    "on_mas_min_ecg_pressed\0on_menos_max_ecg_pressed\0"
    "on_menos_min_spo2_pressed\0"
    "on_mas_max_ecg_pressed\0on_mas_min_spo2_pressed\0"
    "on_menos_min_rpm_pressed\0"
    "on_mas_min_rpm_pressed\0on_menos_max_rpm_pressed\0"
    "on_mas_max_rpm_pressed\0on_menos_max_spo2_pressed\0"
    "on_mas_max_spo2_pressed\0on_CERRAR_pressed\0"
    "on_OK_pressed"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_config_alarmas[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   94,    2, 0x06 /* Public */,
       3,    0,   95,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   96,    2, 0x08 /* Private */,
       5,    0,   97,    2, 0x08 /* Private */,
       6,    0,   98,    2, 0x08 /* Private */,
       7,    0,   99,    2, 0x08 /* Private */,
       8,    0,  100,    2, 0x08 /* Private */,
       9,    0,  101,    2, 0x08 /* Private */,
      10,    0,  102,    2, 0x08 /* Private */,
      11,    0,  103,    2, 0x08 /* Private */,
      12,    0,  104,    2, 0x08 /* Private */,
      13,    0,  105,    2, 0x08 /* Private */,
      14,    0,  106,    2, 0x08 /* Private */,
      15,    0,  107,    2, 0x08 /* Private */,
      16,    0,  108,    2, 0x08 /* Private */,
      17,    0,  109,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void config_alarmas::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<config_alarmas *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sonido_click(); break;
        case 1: _t->alarms_change(); break;
        case 2: _t->on_menos_min_ecg_pressed(); break;
        case 3: _t->on_mas_min_ecg_pressed(); break;
        case 4: _t->on_menos_max_ecg_pressed(); break;
        case 5: _t->on_menos_min_spo2_pressed(); break;
        case 6: _t->on_mas_max_ecg_pressed(); break;
        case 7: _t->on_mas_min_spo2_pressed(); break;
        case 8: _t->on_menos_min_rpm_pressed(); break;
        case 9: _t->on_mas_min_rpm_pressed(); break;
        case 10: _t->on_menos_max_rpm_pressed(); break;
        case 11: _t->on_mas_max_rpm_pressed(); break;
        case 12: _t->on_menos_max_spo2_pressed(); break;
        case 13: _t->on_mas_max_spo2_pressed(); break;
        case 14: _t->on_CERRAR_pressed(); break;
        case 15: _t->on_OK_pressed(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (config_alarmas::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&config_alarmas::sonido_click)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (config_alarmas::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&config_alarmas::alarms_change)) {
                *result = 1;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject config_alarmas::staticMetaObject = { {
    &QDialog::staticMetaObject,
    qt_meta_stringdata_config_alarmas.data,
    qt_meta_data_config_alarmas,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *config_alarmas::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *config_alarmas::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_config_alarmas.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int config_alarmas::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 16;
    }
    return _id;
}

// SIGNAL 0
void config_alarmas::sonido_click()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void config_alarmas::alarms_change()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
