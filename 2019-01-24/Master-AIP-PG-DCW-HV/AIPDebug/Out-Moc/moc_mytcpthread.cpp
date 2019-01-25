/****************************************************************************
** Meta object code from reading C++ file 'mytcpthread.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../External-Interface/mytcpthread.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mytcpthread.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MyTcpThread[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      27,   13,   12,   12, 0x05,

 // slots: signature, parameters, type, tag, flags
      68,   12,   12,   12, 0x08,
      78,   12,   12,   12, 0x08,
      90,   12,   12,   12, 0x08,
     102,   12,   12,   12, 0x08,
     123,  114,   12,   12, 0x08,
     156,  114,   12,   12, 0x08,
     198,  189,   12,   12, 0x08,
     220,   13,   12,   12, 0x08,
     259,   13,   12,   12, 0x08,
     301,   13,   12,   12, 0x08,
     347,   12,  339,   12, 0x08,
     368,   12,   12,   12, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MyTcpThread[] = {
    "MyTcpThread\0\0addr,cmd,data\0"
    "TransformCmd(quint16,quint16,QByteArray)\0"
    "TcpInit()\0Connected()\0KeepAlive()\0"
    "ReadBlock()\0addr,msg\0"
    "ReadFileHead(quint16,QByteArray)\0"
    "ReadFileData(quint16,QByteArray)\0"
    "numBytes\0WriteFileData(qint64)\0"
    "WriteBlock(quint16,quint16,QByteArray)\0"
    "WriteFileHead(quint16,quint16,QByteArray)\0"
    "ExcuteCmd(quint16,quint16,QByteArray)\0"
    "QString\0getHardwareAddress()\0"
    "Error(QAbstractSocket::SocketError)\0"
};

void MyTcpThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MyTcpThread *_t = static_cast<MyTcpThread *>(_o);
        switch (_id) {
        case 0: _t->TransformCmd((*reinterpret_cast< quint16(*)>(_a[1])),(*reinterpret_cast< quint16(*)>(_a[2])),(*reinterpret_cast< QByteArray(*)>(_a[3]))); break;
        case 1: _t->TcpInit(); break;
        case 2: _t->Connected(); break;
        case 3: _t->KeepAlive(); break;
        case 4: _t->ReadBlock(); break;
        case 5: _t->ReadFileHead((*reinterpret_cast< quint16(*)>(_a[1])),(*reinterpret_cast< QByteArray(*)>(_a[2]))); break;
        case 6: _t->ReadFileData((*reinterpret_cast< quint16(*)>(_a[1])),(*reinterpret_cast< QByteArray(*)>(_a[2]))); break;
        case 7: _t->WriteFileData((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        case 8: _t->WriteBlock((*reinterpret_cast< quint16(*)>(_a[1])),(*reinterpret_cast< quint16(*)>(_a[2])),(*reinterpret_cast< QByteArray(*)>(_a[3]))); break;
        case 9: _t->WriteFileHead((*reinterpret_cast< quint16(*)>(_a[1])),(*reinterpret_cast< quint16(*)>(_a[2])),(*reinterpret_cast< QByteArray(*)>(_a[3]))); break;
        case 10: _t->ExcuteCmd((*reinterpret_cast< quint16(*)>(_a[1])),(*reinterpret_cast< quint16(*)>(_a[2])),(*reinterpret_cast< QByteArray(*)>(_a[3]))); break;
        case 11: { QString _r = _t->getHardwareAddress();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 12: _t->Error((*reinterpret_cast< QAbstractSocket::SocketError(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData MyTcpThread::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MyTcpThread::staticMetaObject = {
    { &QTcpSocket::staticMetaObject, qt_meta_stringdata_MyTcpThread,
      qt_meta_data_MyTcpThread, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MyTcpThread::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MyTcpThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MyTcpThread::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MyTcpThread))
        return static_cast<void*>(const_cast< MyTcpThread*>(this));
    return QTcpSocket::qt_metacast(_clname);
}

int MyTcpThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTcpSocket::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
void MyTcpThread::TransformCmd(quint16 _t1, quint16 _t2, QByteArray _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
