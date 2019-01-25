/****************************************************************************
** Meta object code from reading C++ file 'Widget_PWR.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../AIPDebug/Function-Module/Widget_PWR.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Widget_PWR.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Widget_PWR[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      19,   12,   11,   11, 0x05,

 // slots: signature, parameters, type, tag, flags
      53,   42,   11,   11, 0x08,
      84,   42,   11,   11, 0x08,
     115,   11,   11,   11, 0x08,
     148,   11,   11,   11, 0x08,
     183,   42,   11,   11, 0x08,
     213,   11,   11,   11, 0x08,
     239,   11,   11,   11, 0x08,
     256,   11,   11,   11, 0x08,
     276,   11,   11,   11, 0x08,
     305,   11,   11,   11, 0x08,
     328,   11,   11,   11, 0x08,
     345,   11,   11,   11, 0x08,
     375,   11,   11,   11, 0x08,
     399,   11,   11,   11, 0x08,
     423,   42,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Widget_PWR[] = {
    "Widget_PWR\0\0frame,\0canSend(can_frame,int)\0"
    "row,column\0on_pwrTab_cellClicked(int,int)\0"
    "on_pwrTab_cellChanged(int,int)\0"
    "on_PWR_Volt_up_editingFinished()\0"
    "on_PWR_Volt_down_editingFinished()\0"
    "on_pgTab_cellChanged(int,int)\0"
    "on_toolButton_4_clicked()\0buttonJudge(int)\0"
    "pg_buttonJudge(int)\0on_pushButton_Volt_clicked()\0"
    "Volt_Widget_autoquit()\0Volt_sample(int)\0"
    "on_pushButton_Noise_clicked()\0"
    "Noise_Widget_autoquit()\0Noise_CCW_clicked(bool)\0"
    "on_pwrset_Turn_cellClicked(int,int)\0"
};

void Widget_PWR::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Widget_PWR *_t = static_cast<Widget_PWR *>(_o);
        switch (_id) {
        case 0: _t->canSend((*reinterpret_cast< can_frame(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->on_pwrTab_cellClicked((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: _t->on_pwrTab_cellChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 3: _t->on_PWR_Volt_up_editingFinished(); break;
        case 4: _t->on_PWR_Volt_down_editingFinished(); break;
        case 5: _t->on_pgTab_cellChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 6: _t->on_toolButton_4_clicked(); break;
        case 7: _t->buttonJudge((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->pg_buttonJudge((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->on_pushButton_Volt_clicked(); break;
        case 10: _t->Volt_Widget_autoquit(); break;
        case 11: _t->Volt_sample((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: _t->on_pushButton_Noise_clicked(); break;
        case 13: _t->Noise_Widget_autoquit(); break;
        case 14: _t->Noise_CCW_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 15: _t->on_pwrset_Turn_cellClicked((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Widget_PWR::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Widget_PWR::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Widget_PWR,
      qt_meta_data_Widget_PWR, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Widget_PWR::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Widget_PWR::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Widget_PWR::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Widget_PWR))
        return static_cast<void*>(const_cast< Widget_PWR*>(this));
    return QWidget::qt_metacast(_clname);
}

int Widget_PWR::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    }
    return _id;
}

// SIGNAL 0
void Widget_PWR::canSend(can_frame _t1, int _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
