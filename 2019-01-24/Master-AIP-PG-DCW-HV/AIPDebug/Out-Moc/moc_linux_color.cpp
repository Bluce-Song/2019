/****************************************************************************
** Meta object code from reading C++ file 'linux_color.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../External-Interface/linux_color.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'linux_color.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_LINUX_COLOR[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      26,   20,   13,   12, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_LINUX_COLOR[] = {
    "LINUX_COLOR\0\0QColor\0color\0backColor(int)\0"
};

void LINUX_COLOR::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        LINUX_COLOR *_t = static_cast<LINUX_COLOR *>(_o);
        switch (_id) {
        case 0: { QColor _r = _t->backColor((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QColor*>(_a[0]) = _r; }  break;
        default: ;
        }
    }
}

const QMetaObjectExtraData LINUX_COLOR::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject LINUX_COLOR::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_LINUX_COLOR,
      qt_meta_data_LINUX_COLOR, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &LINUX_COLOR::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *LINUX_COLOR::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *LINUX_COLOR::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_LINUX_COLOR))
        return static_cast<void*>(const_cast< LINUX_COLOR*>(this));
    return QWidget::qt_metacast(_clname);
}

int LINUX_COLOR::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
