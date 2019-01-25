/****************************************************************************
** Meta object code from reading C++ file 'w_test.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../AIPDebug/Display-Interface/w_test.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'w_test.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_w_Test[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      42,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      11,       // signalCount

 // signals: signature, parameters, type, tag, flags
      12,    8,    7,    7, 0x05,
      38,    7,    7,    7, 0x05,
      74,    7,    7,    7, 0x05,
     112,  110,    7,    7, 0x05,
     148,  141,    7,    7, 0x05,
     174,  171,    7,    7, 0x05,
     217,  171,    7,    7, 0x05,
     258,  171,    7,    7, 0x05,
     308,  171,    7,    7, 0x05,
     348,  171,    7,    7, 0x05,
     391,  110,    7,    7, 0x05,

 // slots: signature, parameters, type, tag, flags
     424,    7,    7,    7, 0x08,
     442,    7,    7,    7, 0x08,
     457,    7,    7,    7, 0x08,
     474,    7,    7,    7, 0x08,
     496,    7,    7,    7, 0x08,
     520,    7,    7,    7, 0x08,
     536,    7,    7,    7, 0x08,
     556,    7,    7,    7, 0x08,
     575,    7,    7,    7, 0x08,
     600,    7,    7,    7, 0x08,
     617,    7,    7,    7, 0x08,
     649,  643,    7,    7, 0x08,
     692,  681,    7,    7, 0x08,
     724,    7,    7,    7, 0x08,
     747,    7,    7,    7, 0x08,
     771,    7,    7,    7, 0x08,
     796,    7,    7,    7, 0x08,
     821,    7,    7,    7, 0x08,
     842,    7,    7,    7, 0x08,
     866,    7,    7,    7, 0x08,
     891,    7,    7,    7, 0x08,
     912,    7,    7,    7, 0x08,
     934,    7,    7,    7, 0x08,
     953,    7,    7,    7, 0x08,
     972,    7,    7,    7, 0x08,
     995,    7,    7,    7, 0x08,
    1019,    7,    7,    7, 0x08,
    1039,    7,    7,    7, 0x08,
    1061,    7,    7,    7, 0x08,
    1080,    7,    7,    7, 0x0a,
    1109,  171,    7,    7, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_w_Test[] = {
    "w_Test\0\0Buf\0Sigtest_Usart_Send(char*)\0"
    "Sigtest_Usart_Send_DeChang(QString)\0"
    "Sigtest_Usart_Send_WEILING(QString)\0"
    ",\0Signal_Test_to_Main(int,int)\0frame,\0"
    "canSend(can_frame,int)\0,,\0"
    "Sigtest_Save_Data(QStringList,QString,int)\0"
    "WriteMessage(quint16,quint16,QByteArray)\0"
    "WriteMessage_NoVacuum(quint16,quint16,QByteArray)\0"
    "Signal_test_to_pic(QStringList,int,int)\0"
    "Signal_test_to_Switchover(int,int32_t,int)\0"
    "Singal_Record_Error(int,QString)\0"
    "join_updateTime()\0join_key_out()\0"
    "join_beep_stop()\0join_shape_set_free()\0"
    "join_test_mouse_check()\0join_autoquit()\0"
    "join_autodump(bool)\0join_autoconfirm()\0"
    "join_test_button_start()\0join_test_hall()\0"
    "on_button_shape_clicked()\0index\0"
    "on_testTab_clicked(QModelIndex)\0"
    "row,column\0on_testTab_cellClicked(int,int)\0"
    "on_button_up_clicked()\0on_button_set_clicked()\0"
    "on_button_down_clicked()\0"
    "on_button_back_clicked()\0test_join_dcr_stop()\0"
    "IO_Pumb_Start_timeout()\0"
    "IO_Delay_Start_timeout()\0Noise_Stop_timeout()\0"
    "Noise_Blink_timeout()\0WL_Start_timeout()\0"
    "PG_State_timeout()\0Pri_Ask_Test_Current()\0"
    "Pri_Ask_Test_Continue()\0Pri_Ask_Test_Stop()\0"
    "Pri_Ask_Test_Cancel()\0on_Key_E_clicked()\0"
    "join_updatedata(QStringList)\0"
    "Pubs_from_pic(QString,int,int)\0"
};

void w_Test::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        w_Test *_t = static_cast<w_Test *>(_o);
        switch (_id) {
        case 0: _t->Sigtest_Usart_Send((*reinterpret_cast< char*(*)>(_a[1]))); break;
        case 1: _t->Sigtest_Usart_Send_DeChang((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->Sigtest_Usart_Send_WEILING((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->Signal_Test_to_Main((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 4: _t->canSend((*reinterpret_cast< can_frame(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 5: _t->Sigtest_Save_Data((*reinterpret_cast< QStringList(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 6: _t->WriteMessage((*reinterpret_cast< quint16(*)>(_a[1])),(*reinterpret_cast< quint16(*)>(_a[2])),(*reinterpret_cast< QByteArray(*)>(_a[3]))); break;
        case 7: _t->WriteMessage_NoVacuum((*reinterpret_cast< quint16(*)>(_a[1])),(*reinterpret_cast< quint16(*)>(_a[2])),(*reinterpret_cast< QByteArray(*)>(_a[3]))); break;
        case 8: _t->Signal_test_to_pic((*reinterpret_cast< QStringList(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 9: _t->Signal_test_to_Switchover((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int32_t(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 10: _t->Singal_Record_Error((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 11: _t->join_updateTime(); break;
        case 12: _t->join_key_out(); break;
        case 13: _t->join_beep_stop(); break;
        case 14: _t->join_shape_set_free(); break;
        case 15: _t->join_test_mouse_check(); break;
        case 16: _t->join_autoquit(); break;
        case 17: _t->join_autodump((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 18: _t->join_autoconfirm(); break;
        case 19: _t->join_test_button_start(); break;
        case 20: _t->join_test_hall(); break;
        case 21: _t->on_button_shape_clicked(); break;
        case 22: _t->on_testTab_clicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 23: _t->on_testTab_cellClicked((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 24: _t->on_button_up_clicked(); break;
        case 25: _t->on_button_set_clicked(); break;
        case 26: _t->on_button_down_clicked(); break;
        case 27: _t->on_button_back_clicked(); break;
        case 28: _t->test_join_dcr_stop(); break;
        case 29: _t->IO_Pumb_Start_timeout(); break;
        case 30: _t->IO_Delay_Start_timeout(); break;
        case 31: _t->Noise_Stop_timeout(); break;
        case 32: _t->Noise_Blink_timeout(); break;
        case 33: _t->WL_Start_timeout(); break;
        case 34: _t->PG_State_timeout(); break;
        case 35: _t->Pri_Ask_Test_Current(); break;
        case 36: _t->Pri_Ask_Test_Continue(); break;
        case 37: _t->Pri_Ask_Test_Stop(); break;
        case 38: _t->Pri_Ask_Test_Cancel(); break;
        case 39: _t->on_Key_E_clicked(); break;
        case 40: _t->join_updatedata((*reinterpret_cast< QStringList(*)>(_a[1]))); break;
        case 41: _t->Pubs_from_pic((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData w_Test::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject w_Test::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_w_Test,
      qt_meta_data_w_Test, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &w_Test::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *w_Test::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *w_Test::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_w_Test))
        return static_cast<void*>(const_cast< w_Test*>(this));
    return QWidget::qt_metacast(_clname);
}

int w_Test::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 42)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 42;
    }
    return _id;
}

// SIGNAL 0
void w_Test::Sigtest_Usart_Send(char * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void w_Test::Sigtest_Usart_Send_DeChang(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void w_Test::Sigtest_Usart_Send_WEILING(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void w_Test::Signal_Test_to_Main(int _t1, int _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void w_Test::canSend(can_frame _t1, int _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void w_Test::Sigtest_Save_Data(QStringList _t1, QString _t2, int _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void w_Test::WriteMessage(quint16 _t1, quint16 _t2, QByteArray _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void w_Test::WriteMessage_NoVacuum(quint16 _t1, quint16 _t2, QByteArray _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void w_Test::Signal_test_to_pic(QStringList _t1, int _t2, int _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void w_Test::Signal_test_to_Switchover(int _t1, int32_t _t2, int _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}

// SIGNAL 10
void w_Test::Singal_Record_Error(int _t1, QString _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 10, _a);
}
QT_END_MOC_NAMESPACE
