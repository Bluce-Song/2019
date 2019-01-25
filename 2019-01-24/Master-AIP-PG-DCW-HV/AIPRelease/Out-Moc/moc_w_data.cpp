/****************************************************************************
** Meta object code from reading C++ file 'w_data.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../AIPDebug/Display-Interface/w_data.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'w_data.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_w_Data[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      18,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      11,    8,    7,    7, 0x05,
      52,    8,    7,    7, 0x05,

 // slots: signature, parameters, type, tag, flags
      97,    7,    7,    7, 0x08,
     115,    7,    7,    7, 0x08,
     139,    7,    7,    7, 0x08,
     165,    7,    7,    7, 0x08,
     190,    7,    7,    7, 0x08,
     219,    7,    7,    7, 0x08,
     245,    7,    7,    7, 0x08,
     272,    7,    7,    7, 0x08,
     298,    7,    7,    7, 0x08,
     321,    7,    7,    7, 0x08,
     356,  351,    7,    7, 0x08,
     386,    7,    7,    7, 0x08,
     415,  413,    7,    7, 0x08,
     437,    7,    7,    7, 0x08,
     452,    7,    7,    7, 0x08,
     466,    8,    7,    7, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_w_Data[] = {
    "w_Data\0\0,,\0Signal_Data_to_Main(QStringList,int,int)\0"
    "Singal_Data_to_Conf(QString,QStringList,int)\0"
    "on_back_clicked()\0on_button_put_clicked()\0"
    "on_button_start_clicked()\0"
    "on_button_stop_clicked()\0"
    "on_button_detailed_clicked()\0"
    "on_button_clear_clicked()\0"
    "on_button_change_clicked()\0"
    "on_button_check_clicked()\0"
    "on_button_in_clicked()\0"
    "on_button_out_model_clicked()\0arg1\0"
    "on_Model_textChanged(QString)\0"
    "on_Model_editingFinished()\0,\0"
    "join_getData(int,int)\0join_setData()\0"
    "U_show_time()\0pubslot_display_scale(QStringList,int,int)\0"
};

void w_Data::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        w_Data *_t = static_cast<w_Data *>(_o);
        switch (_id) {
        case 0: _t->Signal_Data_to_Main((*reinterpret_cast< QStringList(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 1: _t->Singal_Data_to_Conf((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QStringList(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 2: _t->on_back_clicked(); break;
        case 3: _t->on_button_put_clicked(); break;
        case 4: _t->on_button_start_clicked(); break;
        case 5: _t->on_button_stop_clicked(); break;
        case 6: _t->on_button_detailed_clicked(); break;
        case 7: _t->on_button_clear_clicked(); break;
        case 8: _t->on_button_change_clicked(); break;
        case 9: _t->on_button_check_clicked(); break;
        case 10: _t->on_button_in_clicked(); break;
        case 11: _t->on_button_out_model_clicked(); break;
        case 12: _t->on_Model_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 13: _t->on_Model_editingFinished(); break;
        case 14: _t->join_getData((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 15: _t->join_setData(); break;
        case 16: _t->U_show_time(); break;
        case 17: _t->pubslot_display_scale((*reinterpret_cast< QStringList(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData w_Data::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject w_Data::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_w_Data,
      qt_meta_data_w_Data, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &w_Data::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *w_Data::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *w_Data::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_w_Data))
        return static_cast<void*>(const_cast< w_Data*>(this));
    return QDialog::qt_metacast(_clname);
}

int w_Data::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 18)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 18;
    }
    return _id;
}

// SIGNAL 0
void w_Data::Signal_Data_to_Main(QStringList _t1, int _t2, int _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void w_Data::Singal_Data_to_Conf(QString _t1, QStringList _t2, int _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
