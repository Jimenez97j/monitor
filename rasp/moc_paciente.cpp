/****************************************************************************
** Meta object code from reading C++ file 'paciente.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.13.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../paciente.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'paciente.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.13.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Paciente_t {
    QByteArrayData data[12];
    char stringdata0[189];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Paciente_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Paciente_t qt_meta_stringdata_Paciente = {
    {
QT_MOC_LITERAL(0, 0, 8), // "Paciente"
QT_MOC_LITERAL(1, 9, 12), // "sonido_click"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 20), // "on_paciente1_clicked"
QT_MOC_LITERAL(4, 44, 20), // "on_paciente2_clicked"
QT_MOC_LITERAL(5, 65, 20), // "on_paciente3_clicked"
QT_MOC_LITERAL(6, 86, 13), // "colorpaciente"
QT_MOC_LITERAL(7, 100, 16), // "restore_position"
QT_MOC_LITERAL(8, 117, 16), // "erase_last_names"
QT_MOC_LITERAL(9, 134, 21), // "letter_press_lastname"
QT_MOC_LITERAL(10, 156, 6), // "letter"
QT_MOC_LITERAL(11, 163, 25) // "on_notas_selectionChanged"

    },
    "Paciente\0sonido_click\0\0on_paciente1_clicked\0"
    "on_paciente2_clicked\0on_paciente3_clicked\0"
    "colorpaciente\0restore_position\0"
    "erase_last_names\0letter_press_lastname\0"
    "letter\0on_notas_selectionChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Paciente[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   60,    2, 0x08 /* Private */,
       4,    0,   61,    2, 0x08 /* Private */,
       5,    0,   62,    2, 0x08 /* Private */,
       6,    0,   63,    2, 0x08 /* Private */,
       7,    0,   64,    2, 0x08 /* Private */,
       8,    0,   65,    2, 0x08 /* Private */,
       9,    1,   66,    2, 0x08 /* Private */,
      11,    0,   69,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   10,
    QMetaType::Void,

       0        // eod
};

void Paciente::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Paciente *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sonido_click(); break;
        case 1: _t->on_paciente1_clicked(); break;
        case 2: _t->on_paciente2_clicked(); break;
        case 3: _t->on_paciente3_clicked(); break;
        case 4: _t->colorpaciente(); break;
        case 5: _t->restore_position(); break;
        case 6: _t->erase_last_names(); break;
        case 7: _t->letter_press_lastname((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 8: _t->on_notas_selectionChanged(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Paciente::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Paciente::sonido_click)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Paciente::staticMetaObject = { {
    &QDialog::staticMetaObject,
    qt_meta_stringdata_Paciente.data,
    qt_meta_data_Paciente,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Paciente::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Paciente::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Paciente.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int Paciente::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void Paciente::sonido_click()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
