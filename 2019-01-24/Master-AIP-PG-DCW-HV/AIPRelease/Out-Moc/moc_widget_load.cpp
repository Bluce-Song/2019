/****************************************************************************
** Meta object code from reading C++ file 'widget_load.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../AIPDebug/Function-Module/widget_load.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'widget_load.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Widget_Load[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      19,   13,   12,   12, 0x05,

       0        // eod
};

static const char qt_meta_stringdata_Widget_Load[] = {
    "Widget_Load\0\0frame\0canSend(can_frame)\0"
};

void Widget_Load::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Widget_Load *_t = static_cast<Widget_Load *>(_o);
        switch (_id) {
        case 0: _t->canSend((*reinterpret_cast< can_frame(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Widget_Load::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Widget_Load::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Widget_Load,
      qt_meta_data_Widget_Load, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Widget_Load::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Widget_Load::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Widget_Load::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Widget_Load))
        return static_cast<void*>(const_cast< Widget_Load*>(this));
    return QWidget::qt_metacast(_clname);
}

int Widget_Load::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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

// SIGNAL 0
void Widget_Load::canSend(can_frame _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
