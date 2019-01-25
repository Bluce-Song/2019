/****************************************************************************
** Meta object code from reading C++ file 'password.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../AIPDebug/Display-Interface/password.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'password.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_PassWord[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      12,   10,    9,    9, 0x05,

 // slots: signature, parameters, type, tag, flags
      41,    9,    9,    9, 0x08,
      68,    9,    9,    9, 0x08,
      91,    9,    9,    9, 0x08,
     119,    9,    9,    9, 0x08,
     144,    9,    9,    9, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_PassWord[] = {
    "PassWord\0\0,\0Singal_pass_to_main(int,int)\0"
    "on_Cancle_Button_clicked()\0"
    "on_Ok_Button_clicked()\0"
    "on_MCancel_Button_clicked()\0"
    "on_Make_Button_clicked()\0"
    "on_MOK_Button_clicked()\0"
};

void PassWord::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        PassWord *_t = static_cast<PassWord *>(_o);
        switch (_id) {
        case 0: _t->Singal_pass_to_main((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->on_Cancle_Button_clicked(); break;
        case 2: _t->on_Ok_Button_clicked(); break;
        case 3: _t->on_MCancel_Button_clicked(); break;
        case 4: _t->on_Make_Button_clicked(); break;
        case 5: _t->on_MOK_Button_clicked(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData PassWord::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject PassWord::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_PassWord,
      qt_meta_data_PassWord, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &PassWord::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *PassWord::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *PassWord::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_PassWord))
        return static_cast<void*>(const_cast< PassWord*>(this));
    return QWidget::qt_metacast(_clname);
}

int PassWord::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void PassWord::Singal_pass_to_main(int _t1, int _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
