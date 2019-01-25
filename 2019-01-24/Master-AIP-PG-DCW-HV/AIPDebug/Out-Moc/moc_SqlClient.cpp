/****************************************************************************
** Meta object code from reading C++ file 'SqlClient.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../External-Interface/SqlClient.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'SqlClient.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_SqlClient[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      11,   10,   10,   10, 0x08,
      24,   10,   10,   10, 0x08,
      41,   37,   10,   10, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_SqlClient[] = {
    "SqlClient\0\0DeviceOpen()\0DeviceQuit()\0"
    "msg\0Write(QByteArray)\0"
};

void SqlClient::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        SqlClient *_t = static_cast<SqlClient *>(_o);
        switch (_id) {
        case 0: _t->DeviceOpen(); break;
        case 1: _t->DeviceQuit(); break;
        case 2: _t->Write((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData SqlClient::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject SqlClient::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_SqlClient,
      qt_meta_data_SqlClient, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &SqlClient::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *SqlClient::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *SqlClient::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SqlClient))
        return static_cast<void*>(const_cast< SqlClient*>(this));
    return QObject::qt_metacast(_clname);
}

int SqlClient::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
