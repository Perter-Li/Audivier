/****************************************************************************
** Meta object code from reading C++ file 'playerslider.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../playerslider.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'playerslider.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_PlayerSlider_t {
    const uint offsetsAndSize[14];
    char stringdata0[77];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_PlayerSlider_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_PlayerSlider_t qt_meta_stringdata_PlayerSlider = {
    {
QT_MOC_LITERAL(0, 12), // "PlayerSlider"
QT_MOC_LITERAL(13, 10), // "mousepress"
QT_MOC_LITERAL(24, 0), // ""
QT_MOC_LITERAL(25, 5), // "value"
QT_MOC_LITERAL(31, 12), // "mouserelease"
QT_MOC_LITERAL(44, 15), // "SliderMouseMove"
QT_MOC_LITERAL(60, 16) // "SliderMouseLeave"

    },
    "PlayerSlider\0mousepress\0\0value\0"
    "mouserelease\0SliderMouseMove\0"
    "SliderMouseLeave"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PlayerSlider[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   38,    2, 0x06,    1 /* Public */,
       4,    1,   41,    2, 0x06,    3 /* Public */,
       5,    1,   44,    2, 0x06,    5 /* Public */,
       6,    0,   47,    2, 0x06,    7 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Double,    3,
    QMetaType::Void, QMetaType::Double,    3,
    QMetaType::Void, QMetaType::Double,    3,
    QMetaType::Void,

       0        // eod
};

void PlayerSlider::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<PlayerSlider *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->mousepress((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 1: _t->mouserelease((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 2: _t->SliderMouseMove((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 3: _t->SliderMouseLeave(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (PlayerSlider::*)(double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PlayerSlider::mousepress)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (PlayerSlider::*)(double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PlayerSlider::mouserelease)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (PlayerSlider::*)(double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PlayerSlider::SliderMouseMove)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (PlayerSlider::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PlayerSlider::SliderMouseLeave)) {
                *result = 3;
                return;
            }
        }
    }
}

const QMetaObject PlayerSlider::staticMetaObject = { {
    QMetaObject::SuperData::link<QSlider::staticMetaObject>(),
    qt_meta_stringdata_PlayerSlider.offsetsAndSize,
    qt_meta_data_PlayerSlider,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_PlayerSlider_t
, QtPrivate::TypeAndForceComplete<PlayerSlider, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>



>,
    nullptr
} };


const QMetaObject *PlayerSlider::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PlayerSlider::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_PlayerSlider.stringdata0))
        return static_cast<void*>(this);
    return QSlider::qt_metacast(_clname);
}

int PlayerSlider::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QSlider::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void PlayerSlider::mousepress(double _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void PlayerSlider::mouserelease(double _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void PlayerSlider::SliderMouseMove(double _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void PlayerSlider::SliderMouseLeave()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
