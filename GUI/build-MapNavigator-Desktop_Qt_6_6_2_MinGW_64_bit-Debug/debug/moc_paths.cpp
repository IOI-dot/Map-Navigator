/****************************************************************************
** Meta object code from reading C++ file 'paths.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../MapNavigator/paths.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'paths.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSPathsENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSPathsENDCLASS = QtMocHelpers::stringData(
    "Paths",
    "on_back_clicked",
    "",
    "on_addpath_clicked",
    "on_modifypath_clicked",
    "on_deletepath_clicked",
    "on_cancel_clicked",
    "on_delete1_clicked",
    "on_add_clicked",
    "on_modify_clicked"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSPathsENDCLASS_t {
    uint offsetsAndSizes[20];
    char stringdata0[6];
    char stringdata1[16];
    char stringdata2[1];
    char stringdata3[19];
    char stringdata4[22];
    char stringdata5[22];
    char stringdata6[18];
    char stringdata7[19];
    char stringdata8[15];
    char stringdata9[18];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSPathsENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSPathsENDCLASS_t qt_meta_stringdata_CLASSPathsENDCLASS = {
    {
        QT_MOC_LITERAL(0, 5),  // "Paths"
        QT_MOC_LITERAL(6, 15),  // "on_back_clicked"
        QT_MOC_LITERAL(22, 0),  // ""
        QT_MOC_LITERAL(23, 18),  // "on_addpath_clicked"
        QT_MOC_LITERAL(42, 21),  // "on_modifypath_clicked"
        QT_MOC_LITERAL(64, 21),  // "on_deletepath_clicked"
        QT_MOC_LITERAL(86, 17),  // "on_cancel_clicked"
        QT_MOC_LITERAL(104, 18),  // "on_delete1_clicked"
        QT_MOC_LITERAL(123, 14),  // "on_add_clicked"
        QT_MOC_LITERAL(138, 17)   // "on_modify_clicked"
    },
    "Paths",
    "on_back_clicked",
    "",
    "on_addpath_clicked",
    "on_modifypath_clicked",
    "on_deletepath_clicked",
    "on_cancel_clicked",
    "on_delete1_clicked",
    "on_add_clicked",
    "on_modify_clicked"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSPathsENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   62,    2, 0x08,    1 /* Private */,
       3,    0,   63,    2, 0x08,    2 /* Private */,
       4,    0,   64,    2, 0x08,    3 /* Private */,
       5,    0,   65,    2, 0x08,    4 /* Private */,
       6,    0,   66,    2, 0x08,    5 /* Private */,
       7,    0,   67,    2, 0x08,    6 /* Private */,
       8,    0,   68,    2, 0x08,    7 /* Private */,
       9,    0,   69,    2, 0x08,    8 /* Private */,

 // slots: parameters
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

Q_CONSTINIT const QMetaObject Paths::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_CLASSPathsENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSPathsENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSPathsENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<Paths, std::true_type>,
        // method 'on_back_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_addpath_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_modifypath_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_deletepath_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_cancel_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_delete1_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_add_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_modify_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void Paths::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Paths *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_back_clicked(); break;
        case 1: _t->on_addpath_clicked(); break;
        case 2: _t->on_modifypath_clicked(); break;
        case 3: _t->on_deletepath_clicked(); break;
        case 4: _t->on_cancel_clicked(); break;
        case 5: _t->on_delete1_clicked(); break;
        case 6: _t->on_add_clicked(); break;
        case 7: _t->on_modify_clicked(); break;
        default: ;
        }
    }
    (void)_a;
}

const QMetaObject *Paths::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Paths::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSPathsENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int Paths::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 8;
    }
    return _id;
}
QT_WARNING_POP
