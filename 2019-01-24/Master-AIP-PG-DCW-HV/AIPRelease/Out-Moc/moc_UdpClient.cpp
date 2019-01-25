/****************************************************************************
** Meta object code from reading C++ file 'UdpClient.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../AIPDebug/External-Interface/UdpClient.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'UdpClient.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_UdpClient[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      24,   11,   10,   10, 0x05,

 // slots: signature, parameters, type, tag, flags
      64,   10,   10,   10, 0x08,
      71,   10,   10,   10, 0x08,
      78,   10,   10,   10, 0x08,
      93,   10,   10,   10, 0x08,
     108,   10,   10,   10, 0x08,
     118,   10,   10,   10, 0x08,
     146,   11,   10,   10, 0x0a,
     186,   11,   10,   10, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_UdpClient[] = {
    "UdpClient\0\0addr,cmd,msg\0"
    "SendCommand(quint16,quint16,QByteArray)\0"
    "Init()\0Quit()\0InitSettings()\0"
    "SaveSettings()\0ReadAll()\0"
    "Analy_XML_Data(QStringList)\0"
    "ReadMessage(quint16,quint16,QByteArray)\0"
    "ReadMessage_NoVacuum(quint16,quint16,QByteArray)\0"
};

void UdpClient::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        UdpClient *_t = static_cast<UdpClient *>(_o);
        switch (_id) {
        case 0: _t->SendCommand((*reinterpret_cast< quint16(*)>(_a[1])),(*reinterpret_cast< quint16(*)>(_a[2])),(*reinterpret_cast< QByteArray(*)>(_a[3]))); break;
        case 1: _t->Init(); break;
        case 2: _t->Quit(); break;
        case 3: _t->InitSettings(); break;
        case 4: _t->SaveSettings(); break;
        case 5: _t->ReadAll(); break;
        case 6: _t->Analy_XML_Data((*reinterpret_cast< QStringList(*)>(_a[1]))); break;
        case 7: _t->ReadMessage((*reinterpret_cast< quint16(*)>(_a[1])),(*reinterpret_cast< quint16(*)>(_a[2])),(*reinterpret_cast< QByteArray(*)>(_a[3]))); break;
        case 8: _t->ReadMessage_NoVacuum((*reinterpret_cast< quint16(*)>(_a[1])),(*reinterpret_cast< quint16(*)>(_a[2])),(*reinterpret_cast< QByteArray(*)>(_a[3]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData UdpClient::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject UdpClient::staticMetaObject = {
    { &QUdpSocket::staticMetaObject, qt_meta_stringdata_UdpClient,
      qt_meta_data_UdpClient, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &UdpClient::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *UdpClient::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *UdpClient::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_UdpClient))
        return static_cast<void*>(const_cast< UdpClient*>(this));
    return QUdpSocket::qt_metacast(_clname);
}

int UdpClient::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QUdpSocket::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void UdpClient::SendCommand(quint16 _t1, quint16 _t2, QByteArray _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
