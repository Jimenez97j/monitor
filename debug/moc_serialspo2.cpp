/****************************************************************************
** Meta object code from reading C++ file 'serialspo2.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.13.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../serialspo2.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'serialspo2.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.13.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SerialSpo2_t {
    QByteArrayData data[16];
    char stringdata0[178];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SerialSpo2_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SerialSpo2_t qt_meta_stringdata_SerialSpo2 = {
    {
QT_MOC_LITERAL(0, 0, 10), // "SerialSpo2"
QT_MOC_LITERAL(1, 11, 13), // "boton_ajustes"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 12), // "receive_data"
QT_MOC_LITERAL(4, 39, 15), // "QVector<double>"
QT_MOC_LITERAL(5, 55, 8), // "not_data"
QT_MOC_LITERAL(6, 64, 9), // "bpm_count"
QT_MOC_LITERAL(7, 74, 11), // "cuadronegro"
QT_MOC_LITERAL(8, 86, 5), // "pleth"
QT_MOC_LITERAL(9, 92, 14), // "porcentualspo2"
QT_MOC_LITERAL(10, 107, 17), // "updatetemperature"
QT_MOC_LITERAL(11, 125, 9), // "errorpani"
QT_MOC_LITERAL(12, 135, 10), // "panivalues"
QT_MOC_LITERAL(13, 146, 7), // "escribe"
QT_MOC_LITERAL(14, 154, 11), // "handle_data"
QT_MOC_LITERAL(15, 166, 11) // "procesaDato"

    },
    "SerialSpo2\0boton_ajustes\0\0receive_data\0"
    "QVector<double>\0not_data\0bpm_count\0"
    "cuadronegro\0pleth\0porcentualspo2\0"
    "updatetemperature\0errorpani\0panivalues\0"
    "escribe\0handle_data\0procesaDato"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SerialSpo2[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      11,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   79,    2, 0x06 /* Public */,
       3,    6,   82,    2, 0x06 /* Public */,
       5,    0,   95,    2, 0x06 /* Public */,
       6,    1,   96,    2, 0x06 /* Public */,
       7,    1,   99,    2, 0x06 /* Public */,
       8,    6,  102,    2, 0x06 /* Public */,
       9,    1,  115,    2, 0x06 /* Public */,
      10,    2,  118,    2, 0x06 /* Public */,
      11,    0,  123,    2, 0x06 /* Public */,
      12,    3,  124,    2, 0x06 /* Public */,
      13,    1,  131,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      14,    0,  134,    2, 0x0a /* Public */,
      15,    1,  135,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, 0x80000000 | 4, 0x80000000 | 4, QMetaType::Int, QMetaType::Double, QMetaType::Double, QMetaType::Double,    2,    2,    2,    2,    2,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, 0x80000000 | 4, 0x80000000 | 4, QMetaType::Int, QMetaType::Double, QMetaType::Double, QMetaType::Double,    2,    2,    2,    2,    2,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::Double,    2,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,    2,    2,    2,
    QMetaType::Void, QMetaType::QByteArray,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QByteArray,    2,

       0        // eod
};

void SerialSpo2::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<SerialSpo2 *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->boton_ajustes((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->receive_data((*reinterpret_cast< QVector<double>(*)>(_a[1])),(*reinterpret_cast< QVector<double>(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< double(*)>(_a[4])),(*reinterpret_cast< double(*)>(_a[5])),(*reinterpret_cast< double(*)>(_a[6]))); break;
        case 2: _t->not_data(); break;
        case 3: _t->bpm_count((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->cuadronegro((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->pleth((*reinterpret_cast< QVector<double>(*)>(_a[1])),(*reinterpret_cast< QVector<double>(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< double(*)>(_a[4])),(*reinterpret_cast< double(*)>(_a[5])),(*reinterpret_cast< double(*)>(_a[6]))); break;
        case 6: _t->porcentualspo2((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 7: _t->updatetemperature((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 8: _t->errorpani(); break;
        case 9: _t->panivalues((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 10: _t->escribe((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 11: _t->handle_data(); break;
        case 12: _t->procesaDato((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<double> >(); break;
            }
            break;
        case 5:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<double> >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (SerialSpo2::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SerialSpo2::boton_ajustes)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (SerialSpo2::*)(QVector<double> , QVector<double> , int , double , double , double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SerialSpo2::receive_data)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (SerialSpo2::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SerialSpo2::not_data)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (SerialSpo2::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SerialSpo2::bpm_count)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (SerialSpo2::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SerialSpo2::cuadronegro)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (SerialSpo2::*)(QVector<double> , QVector<double> , int , double , double , double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SerialSpo2::pleth)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (SerialSpo2::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SerialSpo2::porcentualspo2)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (SerialSpo2::*)(QString , double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SerialSpo2::updatetemperature)) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (SerialSpo2::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SerialSpo2::errorpani)) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (SerialSpo2::*)(QString , QString , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SerialSpo2::panivalues)) {
                *result = 9;
                return;
            }
        }
        {
            using _t = void (SerialSpo2::*)(QByteArray );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SerialSpo2::escribe)) {
                *result = 10;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject SerialSpo2::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_SerialSpo2.data,
    qt_meta_data_SerialSpo2,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *SerialSpo2::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SerialSpo2::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SerialSpo2.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int SerialSpo2::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
void SerialSpo2::boton_ajustes(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void SerialSpo2::receive_data(QVector<double> _t1, QVector<double> _t2, int _t3, double _t4, double _t5, double _t6)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t5))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t6))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void SerialSpo2::not_data()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void SerialSpo2::bpm_count(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void SerialSpo2::cuadronegro(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void SerialSpo2::pleth(QVector<double> _t1, QVector<double> _t2, int _t3, double _t4, double _t5, double _t6)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t5))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t6))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void SerialSpo2::porcentualspo2(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void SerialSpo2::updatetemperature(QString _t1, double _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void SerialSpo2::errorpani()
{
    QMetaObject::activate(this, &staticMetaObject, 8, nullptr);
}

// SIGNAL 9
void SerialSpo2::panivalues(QString _t1, QString _t2, QString _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}

// SIGNAL 10
void SerialSpo2::escribe(QByteArray _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 10, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
