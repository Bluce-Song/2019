/****************************************************************************
** Meta object code from reading C++ file 'w_syst.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Display-Interface/w_syst.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'w_syst.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_w_Syst[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      29,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      11,    8,    7,    7, 0x05,

 // slots: signature, parameters, type, tag, flags
      49,   47,    7,    7, 0x0a,
      77,    7,    7,    7, 0x08,
      94,    7,    7,    7, 0x08,
     113,    7,    7,    7, 0x08,
     132,    7,    7,    7, 0x08,
     157,    7,    7,    7, 0x08,
     181,    7,    7,    7, 0x08,
     207,    7,    7,    7, 0x08,
     235,    7,    7,    7, 0x08,
     263,    7,    7,    7, 0x08,
     284,    7,    7,    7, 0x08,
     299,    7,    7,    7, 0x08,
     321,    7,    7,    7, 0x08,
     342,    7,    7,    7, 0x08,
     364,    7,    7,    7, 0x08,
     385,    7,    7,    7, 0x08,
     408,    7,    7,    7, 0x08,
     432,    7,    7,    7, 0x08,
     462,    7,    7,    7, 0x08,
     494,    7,    7,    7, 0x08,
     525,    7,    7,    7, 0x08,
     549,    7,    7,    7, 0x08,
     572,    7,    7,    7, 0x08,
     587,    7,    7,    7, 0x08,
     603,    7,    7,    7, 0x08,
     620,    7,    7,    7, 0x08,
     646,    7,    7,    7, 0x08,
     670,    7,    7,    7, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_w_Syst[] = {
    "w_Syst\0\0,,\0signal_to_main(QStringList,int,int)\0"
    ",\0slot_from_main(QString,int)\0"
    "ButtonJudge(int)\0on_Timer_clicked()\0"
    "on_Key_H_clicked()\0on_Beep_Button_clicked()\0"
    "on_Led_Button_clicked()\0"
    "on_Button_Check_clicked()\0"
    "on_Button_Check_2_clicked()\0"
    "on_Button_Check_3_clicked()\0"
    "net_Widget_set_net()\0Wifi_set_net()\0"
    "net_Widget_autoquit()\0IO_Widget_autoquit()\0"
    "SQL_Widget_autoquit()\0net_Widget_set_SQL()\0"
    "Left_Widget_autoquit()\0Right_Widget_autoquit()\0"
    "on_lineEdit_editingFinished()\0"
    "on_scan_start_editingFinished()\0"
    "on_scan_stop_editingFinished()\0"
    "on_Button_SQL_clicked()\0on_Button_IO_clicked()\0"
    "IO_RFID_Read()\0IO_RFID_Write()\0"
    "button_recover()\0on_Button_Usart_clicked()\0"
    "Usart_Widget_autoquit()\0Usart_OC_Clicked()\0"
};

void w_Syst::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        w_Syst *_t = static_cast<w_Syst *>(_o);
        switch (_id) {
        case 0: _t->signal_to_main((*reinterpret_cast< QStringList(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 1: _t->slot_from_main((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: _t->ButtonJudge((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->on_Timer_clicked(); break;
        case 4: _t->on_Key_H_clicked(); break;
        case 5: _t->on_Beep_Button_clicked(); break;
        case 6: _t->on_Led_Button_clicked(); break;
        case 7: _t->on_Button_Check_clicked(); break;
        case 8: _t->on_Button_Check_2_clicked(); break;
        case 9: _t->on_Button_Check_3_clicked(); break;
        case 10: _t->net_Widget_set_net(); break;
        case 11: _t->Wifi_set_net(); break;
        case 12: _t->net_Widget_autoquit(); break;
        case 13: _t->IO_Widget_autoquit(); break;
        case 14: _t->SQL_Widget_autoquit(); break;
        case 15: _t->net_Widget_set_SQL(); break;
        case 16: _t->Left_Widget_autoquit(); break;
        case 17: _t->Right_Widget_autoquit(); break;
        case 18: _t->on_lineEdit_editingFinished(); break;
        case 19: _t->on_scan_start_editingFinished(); break;
        case 20: _t->on_scan_stop_editingFinished(); break;
        case 21: _t->on_Button_SQL_clicked(); break;
        case 22: _t->on_Button_IO_clicked(); break;
        case 23: _t->IO_RFID_Read(); break;
        case 24: _t->IO_RFID_Write(); break;
        case 25: _t->button_recover(); break;
        case 26: _t->on_Button_Usart_clicked(); break;
        case 27: _t->Usart_Widget_autoquit(); break;
        case 28: _t->Usart_OC_Clicked(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData w_Syst::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject w_Syst::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_w_Syst,
      qt_meta_data_w_Syst, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &w_Syst::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *w_Syst::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *w_Syst::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_w_Syst))
        return static_cast<void*>(const_cast< w_Syst*>(this));
    return QDialog::qt_metacast(_clname);
}

int w_Syst::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 29)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 29;
    }
    return _id;
}

// SIGNAL 0
void w_Syst::signal_to_main(QStringList _t1, int _t2, int _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
