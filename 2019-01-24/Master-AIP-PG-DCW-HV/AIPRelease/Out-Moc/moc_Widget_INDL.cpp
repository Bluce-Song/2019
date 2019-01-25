/****************************************************************************
** Meta object code from reading C++ file 'Widget_INDL.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../AIPDebug/Function-Module/Widget_INDL.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Widget_INDL.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Widget_INDL[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      19,   13,   12,   12, 0x05,
      38,   12,   12,   12, 0x05,

 // slots: signature, parameters, type, tag, flags
      65,   54,   12,   12, 0x08,
      97,   12,   12,   12, 0x08,
     119,   54,   12,   12, 0x08,
     151,   12,   12,   12, 0x08,
     176,   12,   12,   12, 0x08,
     206,   12,   12,   12, 0x08,
     243,  231,   12,   12, 0x08,
     270,   12,   12,   12, 0x08,
     296,   12,   12,   12, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Widget_INDL[] = {
    "Widget_INDL\0\0frame\0canSend(can_frame)\0"
    "Lable_Display()\0row,column\0"
    "on_indlTab_cellClicked(int,int)\0"
    "join_buttonJudge(int)\0"
    "on_indlTab_cellChanged(int,int)\0"
    "on_Button_Auto_clicked()\0"
    "on_INDL_Min_editingFinished()\0"
    "on_Button_Comp_clicked()\0Waring_Text\0"
    "Pri_INDL_WMessage(QString)\0"
    "on_button_model_clicked()\0"
    "IO_Widget_autoquit()\0"
};

void Widget_INDL::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Widget_INDL *_t = static_cast<Widget_INDL *>(_o);
        switch (_id) {
        case 0: _t->canSend((*reinterpret_cast< can_frame(*)>(_a[1]))); break;
        case 1: _t->Lable_Display(); break;
        case 2: _t->on_indlTab_cellClicked((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 3: _t->join_buttonJudge((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->on_indlTab_cellChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 5: _t->on_Button_Auto_clicked(); break;
        case 6: _t->on_INDL_Min_editingFinished(); break;
        case 7: _t->on_Button_Comp_clicked(); break;
        case 8: _t->Pri_INDL_WMessage((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 9: _t->on_button_model_clicked(); break;
        case 10: _t->IO_Widget_autoquit(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Widget_INDL::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Widget_INDL::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Widget_INDL,
      qt_meta_data_Widget_INDL, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Widget_INDL::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Widget_INDL::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Widget_INDL::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Widget_INDL))
        return static_cast<void*>(const_cast< Widget_INDL*>(this));
    return QWidget::qt_metacast(_clname);
}

int Widget_INDL::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
void Widget_INDL::canSend(can_frame _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Widget_INDL::Lable_Display()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}
QT_END_MOC_NAMESPACE
