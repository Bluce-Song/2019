/****************************************************************************
** Meta object code from reading C++ file 'w_keyb.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../AIPDebug/Display-Interface/w_keyb.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'w_keyb.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_w_Keyb[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: signature, parameters, type, tag, flags
      12,    8,    7,    7, 0x05,
      32,    7,    7,    7, 0x05,
      44,    7,    7,    7, 0x05,
      60,    7,    7,    7, 0x05,
      73,    7,    7,    7, 0x05,
      88,    7,    7,    7, 0x05,

 // slots: signature, parameters, type, tag, flags
      99,    7,    7,    7, 0x0a,
     116,    7,    7,    7, 0x0a,
     128,    7,    7,    7, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_w_Keyb[] = {
    "w_Keyb\0\0str\0SendString(QString)\0"
    "SendEnter()\0SendBackspace()\0SendEscape()\0"
    "SendCapsLock()\0SendCaps()\0ButtonJudge(int)\0"
    "updatePos()\0Caps(bool)\0"
};

void w_Keyb::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        w_Keyb *_t = static_cast<w_Keyb *>(_o);
        switch (_id) {
        case 0: _t->SendString((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->SendEnter(); break;
        case 2: _t->SendBackspace(); break;
        case 3: _t->SendEscape(); break;
        case 4: _t->SendCapsLock(); break;
        case 5: _t->SendCaps(); break;
        case 6: _t->ButtonJudge((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->updatePos(); break;
        case 8: _t->Caps((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData w_Keyb::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject w_Keyb::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_w_Keyb,
      qt_meta_data_w_Keyb, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &w_Keyb::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *w_Keyb::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *w_Keyb::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_w_Keyb))
        return static_cast<void*>(const_cast< w_Keyb*>(this));
    return QWidget::qt_metacast(_clname);
}

int w_Keyb::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void w_Keyb::SendString(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void w_Keyb::SendEnter()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void w_Keyb::SendBackspace()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void w_Keyb::SendEscape()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}

// SIGNAL 4
void w_Keyb::SendCapsLock()
{
    QMetaObject::activate(this, &staticMetaObject, 4, 0);
}

// SIGNAL 5
void w_Keyb::SendCaps()
{
    QMetaObject::activate(this, &staticMetaObject, 5, 0);
}
QT_END_MOC_NAMESPACE
