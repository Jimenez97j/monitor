/****************************************************************************
** Meta object code from reading C++ file 'ajustes.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.13.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../ajustes.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ajustes.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.13.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ajustes_t {
    QByteArrayData data[20];
    char stringdata0[304];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ajustes_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ajustes_t qt_meta_stringdata_ajustes = {
    {
QT_MOC_LITERAL(0, 0, 7), // "ajustes"
QT_MOC_LITERAL(1, 8, 18), // "change_color_click"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 16), // "detection_change"
QT_MOC_LITERAL(4, 45, 16), // "time_save_change"
QT_MOC_LITERAL(5, 62, 1), // "x"
QT_MOC_LITERAL(6, 64, 12), // "sonido_click"
QT_MOC_LITERAL(7, 77, 19), // "on_cleanAll_pressed"
QT_MOC_LITERAL(8, 97, 16), // "changebackground"
QT_MOC_LITERAL(9, 114, 5), // "color"
QT_MOC_LITERAL(10, 120, 31), // "on_comboBox_currentIndexChanged"
QT_MOC_LITERAL(11, 152, 5), // "index"
QT_MOC_LITERAL(12, 158, 21), // "on_toolButton_pressed"
QT_MOC_LITERAL(13, 180, 19), // "on_checkBox_toggled"
QT_MOC_LITERAL(14, 200, 7), // "checked"
QT_MOC_LITERAL(15, 208, 10), // "getajustes"
QT_MOC_LITERAL(16, 219, 7), // "gettime"
QT_MOC_LITERAL(17, 227, 19), // "on_Guia_Usu_pressed"
QT_MOC_LITERAL(18, 247, 32), // "on_time_save_currentIndexChanged"
QT_MOC_LITERAL(19, 280, 23) // "on_toolButton_2_clicked"

    },
    "ajustes\0change_color_click\0\0"
    "detection_change\0time_save_change\0x\0"
    "sonido_click\0on_cleanAll_pressed\0"
    "changebackground\0color\0"
    "on_comboBox_currentIndexChanged\0index\0"
    "on_toolButton_pressed\0on_checkBox_toggled\0"
    "checked\0getajustes\0gettime\0"
    "on_Guia_Usu_pressed\0"
    "on_time_save_currentIndexChanged\0"
    "on_toolButton_2_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ajustes[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   84,    2, 0x06 /* Public */,
       3,    0,   85,    2, 0x06 /* Public */,
       4,    1,   86,    2, 0x06 /* Public */,
       6,    0,   89,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    0,   90,    2, 0x08 /* Private */,
       8,    1,   91,    2, 0x08 /* Private */,
      10,    1,   94,    2, 0x08 /* Private */,
      12,    0,   97,    2, 0x08 /* Private */,
      13,    1,   98,    2, 0x08 /* Private */,
      15,    0,  101,    2, 0x08 /* Private */,
      16,    0,  102,    2, 0x08 /* Private */,
      17,    0,  103,    2, 0x08 /* Private */,
      18,    1,  104,    2, 0x08 /* Private */,
      19,    0,  107,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    9,
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   14,
    QMetaType::QString,
    QMetaType::QString,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Void,

       0        // eod
};

void ajustes::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ajustes *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->change_color_click(); break;
        case 1: _t->detection_change(); break;
        case 2: _t->time_save_change((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->sonido_click(); break;
        case 4: _t->on_cleanAll_pressed(); break;
        case 5: _t->changebackground((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->on_comboBox_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->on_toolButton_pressed(); break;
        case 8: _t->on_checkBox_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 9: { QString _r = _t->getajustes();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 10: { QString _r = _t->gettime();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 11: _t->on_Guia_Usu_pressed(); break;
        case 12: _t->on_time_save_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 13: _t->on_toolButton_2_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ajustes::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ajustes::change_color_click)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (ajustes::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ajustes::detection_change)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (ajustes::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ajustes::time_save_change)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (ajustes::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ajustes::sonido_click)) {
                *result = 3;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ajustes::staticMetaObject = { {
    &QDialog::staticMetaObject,
    qt_meta_stringdata_ajustes.data,
    qt_meta_data_ajustes,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ajustes::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ajustes::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ajustes.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int ajustes::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 14;
    }
    return _id;
}

// SIGNAL 0
void ajustes::change_color_click()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void ajustes::detection_change()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void ajustes::time_save_change(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void ajustes::sonido_click()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
