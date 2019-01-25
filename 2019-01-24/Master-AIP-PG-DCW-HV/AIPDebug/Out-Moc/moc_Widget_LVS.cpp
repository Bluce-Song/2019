/****************************************************************************
** Meta object code from reading C++ file 'Widget_LVS.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Function-Module/Widget_LVS.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Widget_LVS.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Widget_LVS[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      18,   12,   11,   11, 0x05,

 // slots: signature, parameters, type, tag, flags
      48,   37,   11,   11, 0x08,
      79,   11,   11,   11, 0x08,
     108,   11,   11,   11, 0x08,
     131,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Widget_LVS[] = {
    "Widget_LVS\0\0frame\0canSend(can_frame)\0"
    "row,column\0on_lvsTab_cellChanged(int,int)\0"
    "on_pushButton_Volt_clicked()\0"
    "Volt_Widget_autoquit()\0Volt_sample()\0"
};

void Widget_LVS::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Widget_LVS *_t = static_cast<Widget_LVS *>(_o);
        switch (_id) {
        case 0: _t->canSend((*reinterpret_cast< can_frame(*)>(_a[1]))); break;
        case 1: _t->on_lvsTab_cellChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: _t->on_pushButton_Volt_clicked(); break;
        case 3: _t->Volt_Widget_autoquit(); break;
        case 4: _t->Volt_sample(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Widget_LVS::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Widget_LVS::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Widget_LVS,
      qt_meta_data_Widget_LVS, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Widget_LVS::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Widget_LVS::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Widget_LVS::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Widget_LVS))
        return static_cast<void*>(const_cast< Widget_LVS*>(this));
    return QWidget::qt_metacast(_clname);
}

int Widget_LVS::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void Widget_LVS::canSend(can_frame _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
