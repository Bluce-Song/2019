/****************************************************************************
** Meta object code from reading C++ file 'ipmethod.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../AIPDebug/External-Interface/ipmethod.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ipmethod.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_IPMethod[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      10,    9,    9,    9, 0x05,

 // slots: signature, parameters, type, tag, flags
      25,    9,    9,    9, 0x08,
      45,    9,    9,    9, 0x08,
      62,    9,    9,    9, 0x08,
      72,    9,    9,    9, 0x08,
      84,    9,    9,    9, 0x08,
      93,    9,    9,    9, 0x08,
     104,    9,    9,    9, 0x08,
     114,    9,    9,    9, 0x08,
     126,    9,    9,    9, 0x08,
     137,    9,    9,    9, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_IPMethod[] = {
    "IPMethod\0\0SendCaps(bool)\0SendString(QString)\0"
    "Preedit(QString)\0Confirm()\0Backspace()\0"
    "Escape()\0CapsLock()\0Upspace()\0Downspace()\0"
    "Tabspace()\0BackTabspace()\0"
};

void IPMethod::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        IPMethod *_t = static_cast<IPMethod *>(_o);
        switch (_id) {
        case 0: _t->SendCaps((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->SendString((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->Preedit((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->Confirm(); break;
        case 4: _t->Backspace(); break;
        case 5: _t->Escape(); break;
        case 6: _t->CapsLock(); break;
        case 7: _t->Upspace(); break;
        case 8: _t->Downspace(); break;
        case 9: _t->Tabspace(); break;
        case 10: _t->BackTabspace(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData IPMethod::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject IPMethod::staticMetaObject = {
    { &QWSInputMethod::staticMetaObject, qt_meta_stringdata_IPMethod,
      qt_meta_data_IPMethod, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &IPMethod::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *IPMethod::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *IPMethod::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_IPMethod))
        return static_cast<void*>(const_cast< IPMethod*>(this));
    return QWSInputMethod::qt_metacast(_clname);
}

int IPMethod::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWSInputMethod::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void IPMethod::SendCaps(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
