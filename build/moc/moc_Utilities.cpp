/****************************************************************************
** Meta object code from reading C++ file 'Utilities.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../src/Utilities.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Utilities.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Utilities_t {
    QByteArrayData data[11];
    char stringdata0[127];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Utilities_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Utilities_t qt_meta_stringdata_Utilities = {
    {
QT_MOC_LITERAL(0, 0, 9), // "Utilities"
QT_MOC_LITERAL(1, 10, 11), // "openLogFile"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 10), // "revealFile"
QT_MOC_LITERAL(4, 34, 12), // "pathToReveal"
QT_MOC_LITERAL(5, 47, 14), // "showMessageBox"
QT_MOC_LITERAL(6, 62, 4), // "text"
QT_MOC_LITERAL(7, 67, 15), // "informativeText"
QT_MOC_LITERAL(8, 83, 11), // "windowTitle"
QT_MOC_LITERAL(9, 95, 28), // "QMessageBox::StandardButtons"
QT_MOC_LITERAL(10, 124, 2) // "bt"

    },
    "Utilities\0openLogFile\0\0revealFile\0"
    "pathToReveal\0showMessageBox\0text\0"
    "informativeText\0windowTitle\0"
    "QMessageBox::StandardButtons\0bt"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Utilities[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x0a /* Public */,
       3,    1,   40,    2, 0x0a /* Public */,

 // methods: name, argc, parameters, tag, flags
       5,    4,   43,    2, 0x02 /* Public */,
       5,    3,   52,    2, 0x22 /* Public | MethodCloned */,
       5,    2,   59,    2, 0x22 /* Public | MethodCloned */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    4,

 // methods: parameters
    QMetaType::Int, QMetaType::QString, QMetaType::QString, QMetaType::QString, 0x80000000 | 9,    6,    7,    8,   10,
    QMetaType::Int, QMetaType::QString, QMetaType::QString, QMetaType::QString,    6,    7,    8,
    QMetaType::Int, QMetaType::QString, QMetaType::QString,    6,    7,

       0        // eod
};

void Utilities::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Utilities *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->openLogFile(); break;
        case 1: _t->revealFile((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: { int _r = _t->showMessageBox((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QMessageBox::StandardButtons(*)>(_a[4])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 3: { int _r = _t->showMessageBox((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 4: { int _r = _t->showMessageBox((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Utilities::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_Utilities.data,
    qt_meta_data_Utilities,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Utilities::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Utilities::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Utilities.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Utilities::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
