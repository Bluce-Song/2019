/****************************************************************************
** Meta object code from reading C++ file 'w_debug.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../AIPDebug/Display-Interface/w_debug.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'w_debug.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_w_Debug[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      24,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: signature, parameters, type, tag, flags
      12,    9,    8,    8, 0x05,
      56,   54,    8,    8, 0x05,
      98,   91,    8,    8, 0x05,

 // slots: signature, parameters, type, tag, flags
     121,    9,    8,    8, 0x0a,
     175,  161,    8,    8, 0x0a,
     221,    8,    8,    8, 0x08,
     238,    8,    8,    8, 0x08,
     258,    8,    8,    8, 0x08,
     278,    8,    8,    8, 0x08,
     297,    8,    8,    8, 0x08,
     317,    8,    8,    8, 0x08,
     343,  337,    8,    8, 0x08,
     377,    8,    8,    8, 0x08,
     405,    8,    8,    8, 0x08,
     435,    8,    8,    8, 0x08,
     465,    8,    8,    8, 0x08,
     491,    8,    8,    8, 0x08,
     503,    8,    8,    8, 0x08,
     528,    8,    8,    8, 0x08,
     555,    8,    8,    8, 0x08,
     582,    8,    8,    8, 0x08,
     606,    8,    8,    8, 0x08,
     636,    8,    8,    8, 0x08,
     662,    8,    8,    8, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_w_Debug[] = {
    "w_Debug\0\0,,\0Singal_debug_to_main(QStringList,int,int)\0"
    ",\0Singal_Save_Debug(QString,QString)\0"
    "frame,\0canSend(can_frame,int)\0"
    "Slot_from_Main(QStringList,QString,int)\0"
    "addr,cmd,data\0"
    "Slot_TransformCmd(quint16,quint16,QByteArray)\0"
    "ButtonJudge(int)\0DLRButtonJudge(int)\0"
    "IMPButtonJudge(int)\0IRButtonJudge(int)\0"
    "ACWButtonJudge(int)\0PWRButtonJudge(int)\0"
    "index\0on_tabWidget2_currentChanged(int)\0"
    "on_System_Current_clicked()\0"
    "on_Button_DLR_Check_clicked()\0"
    "on_Button_DLR_Clear_clicked()\0"
    "on_Button_Start_clicked()\0Beep_Stop()\0"
    "on_Button_Conf_clicked()\0"
    "on_pushButton_12_clicked()\0"
    "on_pushButton_13_clicked()\0"
    "on_pushButton_clicked()\0"
    "on_pushButton_IO_In_clicked()\0"
    "on_Button_uname_clicked()\0"
    "on_Button_uname_2_clicked()\0"
};

void w_Debug::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        w_Debug *_t = static_cast<w_Debug *>(_o);
        switch (_id) {
        case 0: _t->Singal_debug_to_main((*reinterpret_cast< QStringList(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 1: _t->Singal_Save_Debug((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 2: _t->canSend((*reinterpret_cast< can_frame(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 3: _t->Slot_from_Main((*reinterpret_cast< QStringList(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 4: _t->Slot_TransformCmd((*reinterpret_cast< quint16(*)>(_a[1])),(*reinterpret_cast< quint16(*)>(_a[2])),(*reinterpret_cast< QByteArray(*)>(_a[3]))); break;
        case 5: _t->ButtonJudge((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->DLRButtonJudge((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->IMPButtonJudge((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->IRButtonJudge((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->ACWButtonJudge((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->PWRButtonJudge((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->on_tabWidget2_currentChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: _t->on_System_Current_clicked(); break;
        case 13: _t->on_Button_DLR_Check_clicked(); break;
        case 14: _t->on_Button_DLR_Clear_clicked(); break;
        case 15: _t->on_Button_Start_clicked(); break;
        case 16: _t->Beep_Stop(); break;
        case 17: _t->on_Button_Conf_clicked(); break;
        case 18: _t->on_pushButton_12_clicked(); break;
        case 19: _t->on_pushButton_13_clicked(); break;
        case 20: _t->on_pushButton_clicked(); break;
        case 21: _t->on_pushButton_IO_In_clicked(); break;
        case 22: _t->on_Button_uname_clicked(); break;
        case 23: _t->on_Button_uname_2_clicked(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData w_Debug::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject w_Debug::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_w_Debug,
      qt_meta_data_w_Debug, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &w_Debug::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *w_Debug::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *w_Debug::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_w_Debug))
        return static_cast<void*>(const_cast< w_Debug*>(this));
    return QDialog::qt_metacast(_clname);
}

int w_Debug::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 24)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 24;
    }
    return _id;
}

// SIGNAL 0
void w_Debug::Singal_debug_to_main(QStringList _t1, int _t2, int _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void w_Debug::Singal_Save_Debug(QString _t1, QString _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void w_Debug::canSend(can_frame _t1, int _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
