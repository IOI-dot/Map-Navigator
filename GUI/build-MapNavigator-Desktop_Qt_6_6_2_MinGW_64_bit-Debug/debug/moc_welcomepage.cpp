/****************************************************************************
** Meta object code from reading C++ file 'welcomepage.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../MapNavigator/welcomepage.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'welcomepage.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSwelcomePageENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSwelcomePageENDCLASS = QtMocHelpers::stringData(
    "welcomePage",
    "on_cities_clicked",
    "",
    "on_paths_clicked",
    "on_navigate_clicked",
    "on_quit_clicked",
    "on_pushButton_5_clicked"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSwelcomePageENDCLASS_t {
    uint offsetsAndSizes[14];
    char stringdata0[12];
    char stringdata1[18];
    char stringdata2[1];
    char stringdata3[17];
    char stringdata4[20];
    char stringdata5[16];
    char stringdata6[24];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSwelcomePageENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSwelcomePageENDCLASS_t qt_meta_stringdata_CLASSwelcomePageENDCLASS = {
    {
        QT_MOC_LITERAL(0, 11),  // "welcomePage"
        QT_MOC_LITERAL(12, 17),  // "on_cities_clicked"
        QT_MOC_LITERAL(30, 0),  // ""
        QT_MOC_LITERAL(31, 16),  // "on_paths_clicked"
        QT_MOC_LITERAL(48, 19),  // "on_navigate_clicked"
        QT_MOC_LITERAL(68, 15),  // "on_quit_clicked"
        QT_MOC_LITERAL(84, 23)   // "on_pushButton_5_clicked"
    },
    "welcomePage",
    "on_cities_clicked",
    "",
    "on_paths_clicked",
    "on_navigate_clicked",
    "on_quit_clicked",
    "on_pushButton_5_clicked"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSwelcomePageENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   44,    2, 0x08,    1 /* Private */,
       3,    0,   45,    2, 0x08,    2 /* Private */,
       4,    0,   46,    2, 0x08,    3 /* Private */,
       5,    0,   47,    2, 0x08,    4 /* Private */,
       6,    0,   48,    2, 0x08,    5 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject welcomePage::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_CLASSwelcomePageENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSwelcomePageENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSwelcomePageENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<welcomePage, std::true_type>,
        // method 'on_cities_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_paths_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_navigate_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_quit_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_5_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void welcomePage::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<welcomePage *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_cities_clicked(); break;
        case 1: _t->on_paths_clicked(); break;
        case 2: _t->on_navigate_clicked(); break;
        case 3: _t->on_quit_clicked(); break;
        case 4: _t->on_pushButton_5_clicked(); break;
        default: ;
        }
    }
    (void)_a;
}

const QMetaObject *welcomePage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *welcomePage::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSwelcomePageENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int welcomePage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 5;
    }
    return _id;
}
QT_WARNING_POP
