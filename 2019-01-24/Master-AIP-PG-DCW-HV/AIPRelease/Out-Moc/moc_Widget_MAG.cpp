/****************************************************************************
** Meta object code from reading C++ file 'Widget_MAG.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../AIPDebug/Function-Module/Widget_MAG.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Widget_MAG.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Widget_MAG[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      18,   12,   11,   11, 0x05,

 // slots: signature, parameters, type, tag, flags
      54,   37,   11,   11, 0x08,
      95,   11,   11,   11, 0x08,
     112,   11,   11,   11, 0x08,
     131,   11,   11,   11, 0x08,
     161,  150,   11,   11, 0x08,
     192,  150,   11,   11, 0x08,
     223,   11,   11,   11, 0x08,
     249,   11,   11,   11, 0x08,
     270,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Widget_MAG[] = {
    "Widget_MAG\0\0frame\0canSend(can_frame)\0"
    "spin,dec,min,max\0"
    "initSpinBox(QDoubleSpinBox*,int,int,int)\0"
    "buttonJudge(int)\0Box_0_clicked(int)\0"
    "Box_1_clicked(int)\0row,column\0"
    "on_oppTab_cellChanged(int,int)\0"
    "on_oppTab_cellClicked(int,int)\0"
    "on_button_power_clicked()\0"
    "Quick_Set_autoquit()\0Quick_Set_Show_join_Clicked()\0"
};

void Widget_MAG::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Widget_MAG *_t = static_cast<Widget_MAG *>(_o);
        switch (_id) {
        case 0: _t->canSend((*reinterpret_cast< can_frame(*)>(_a[1]))); break;
        case 1: _t->initSpinBox((*reinterpret_cast< QDoubleSpinBox*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 2: _t->buttonJudge((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->Box_0_clicked((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->Box_1_clicked((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->on_oppTab_cellChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 6: _t->on_oppTab_cellClicked((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 7: _t->on_button_power_clicked(); break;
        case 8: _t->Quick_Set_autoquit(); break;
        case 9: _t->Quick_Set_Show_join_Clicked(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Widget_MAG::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Widget_MAG::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Widget_MAG,
      qt_meta_data_Widget_MAG, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Widget_MAG::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Widget_MAG::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Widget_MAG::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Widget_MAG))
        return static_cast<void*>(const_cast< Widget_MAG*>(this));
    return QWidget::qt_metacast(_clname);
}

int Widget_MAG::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void Widget_MAG::canSend(can_frame _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
