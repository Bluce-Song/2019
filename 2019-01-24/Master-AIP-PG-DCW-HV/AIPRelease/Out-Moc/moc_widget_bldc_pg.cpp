/****************************************************************************
** Meta object code from reading C++ file 'widget_bldc_pg.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../AIPDebug/Function-Module/widget_bldc_pg.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'widget_bldc_pg.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Widget_BLDC_PG[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      22,   16,   15,   15, 0x05,

 // slots: signature, parameters, type, tag, flags
      41,   15,   15,   15, 0x08,
      69,   58,   15,   15, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Widget_BLDC_PG[] = {
    "Widget_BLDC_PG\0\0frame\0canSend(can_frame)\0"
    "buttonJudge(int)\0row,column\0"
    "on_bldcpgTab_cellChanged(int,int)\0"
};

void Widget_BLDC_PG::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Widget_BLDC_PG *_t = static_cast<Widget_BLDC_PG *>(_o);
        switch (_id) {
        case 0: _t->canSend((*reinterpret_cast< can_frame(*)>(_a[1]))); break;
        case 1: _t->buttonJudge((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->on_bldcpgTab_cellChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Widget_BLDC_PG::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Widget_BLDC_PG::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Widget_BLDC_PG,
      qt_meta_data_Widget_BLDC_PG, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Widget_BLDC_PG::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Widget_BLDC_PG::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Widget_BLDC_PG::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Widget_BLDC_PG))
        return static_cast<void*>(const_cast< Widget_BLDC_PG*>(this));
    return QWidget::qt_metacast(_clname);
}

int Widget_BLDC_PG::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void Widget_BLDC_PG::canSend(can_frame _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
