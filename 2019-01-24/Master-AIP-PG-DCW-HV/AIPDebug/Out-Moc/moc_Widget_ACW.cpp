/****************************************************************************
** Meta object code from reading C++ file 'Widget_ACW.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Function-Module/Widget_ACW.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Widget_ACW.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Widget_ACW[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      18,   12,   11,   11, 0x05,

 // slots: signature, parameters, type, tag, flags
      37,   11,   11,   11, 0x08,
      70,   59,   11,   11, 0x08,
     101,   59,   11,   11, 0x08,
     132,   11,   11,   11, 0x08,
     150,   11,   11,   11, 0x08,
     185,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Widget_ACW[] = {
    "Widget_ACW\0\0frame\0canSend(can_frame)\0"
    "join_buttonJudge(int)\0row,column\0"
    "on_acwTab_cellChanged(int,int)\0"
    "on_acwTab_cellClicked(int,int)\0"
    "box_statechange()\0on_double_I_Down_editingFinished()\0"
    "on_double_I_Up_editingFinished()\0"
};

void Widget_ACW::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Widget_ACW *_t = static_cast<Widget_ACW *>(_o);
        switch (_id) {
        case 0: _t->canSend((*reinterpret_cast< can_frame(*)>(_a[1]))); break;
        case 1: _t->join_buttonJudge((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->on_acwTab_cellChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 3: _t->on_acwTab_cellClicked((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 4: _t->box_statechange(); break;
        case 5: _t->on_double_I_Down_editingFinished(); break;
        case 6: _t->on_double_I_Up_editingFinished(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Widget_ACW::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Widget_ACW::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Widget_ACW,
      qt_meta_data_Widget_ACW, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Widget_ACW::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Widget_ACW::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Widget_ACW::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Widget_ACW))
        return static_cast<void*>(const_cast< Widget_ACW*>(this));
    return QWidget::qt_metacast(_clname);
}

int Widget_ACW::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void Widget_ACW::canSend(can_frame _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
