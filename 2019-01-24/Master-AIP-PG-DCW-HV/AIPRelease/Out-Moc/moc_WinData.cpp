/****************************************************************************
** Meta object code from reading C++ file 'WinData.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../AIPDebug/Display-Interface/WinData.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'WinData.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_WinData[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      23,    9,    8,    8, 0x05,
      65,   63,    8,    8, 0x05,

 // slots: signature, parameters, type, tag, flags
      94,    8,    8,    8, 0x08,
     108,    8,    8,    8, 0x08,
     125,  122,    8,    8, 0x08,
     142,    8,    8,    8, 0x08,
     155,    8,    8,    8, 0x08,
     176,  171,    8,    8, 0x08,
     196,    8,    8,    8, 0x08,
     210,    8,    8,    8, 0x08,
     232,    8,  224,    8, 0x08,
     242,    8,    8,    8, 0x08,
     282,  276,  265,    8, 0x08,
     297,    8,    8,    8, 0x08,
     308,    8,    8,    8, 0x08,
     320,  171,    8,    8, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_WinData[] = {
    "WinData\0\0addr,cmd,data\0"
    "SendCommand(quint16,quint16,QByteArray)\0"
    ",\0Signal_Data_to_Main(int,int)\0"
    "InitWindows()\0InitButtons()\0id\0"
    "ReadButtons(int)\0InitSqlite()\0"
    "ReadSqliteAll()\0item\0ReadSqlite(QString)\0"
    "ClearSqlite()\0ExportToUsb()\0QString\0"
    "ReadUsb()\0showEvent(QShowEvent*)\0"
    "QByteArray\0inStr\0ToGbk(QString)\0"
    "dateopen()\0datequite()\0ReadView(QString)\0"
};

void WinData::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        WinData *_t = static_cast<WinData *>(_o);
        switch (_id) {
        case 0: _t->SendCommand((*reinterpret_cast< quint16(*)>(_a[1])),(*reinterpret_cast< quint16(*)>(_a[2])),(*reinterpret_cast< QByteArray(*)>(_a[3]))); break;
        case 1: _t->Signal_Data_to_Main((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: _t->InitWindows(); break;
        case 3: _t->InitButtons(); break;
        case 4: _t->ReadButtons((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->InitSqlite(); break;
        case 6: _t->ReadSqliteAll(); break;
        case 7: _t->ReadSqlite((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 8: _t->ClearSqlite(); break;
        case 9: _t->ExportToUsb(); break;
        case 10: { QString _r = _t->ReadUsb();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 11: _t->showEvent((*reinterpret_cast< QShowEvent*(*)>(_a[1]))); break;
        case 12: { QByteArray _r = _t->ToGbk((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QByteArray*>(_a[0]) = _r; }  break;
        case 13: _t->dateopen(); break;
        case 14: _t->datequite(); break;
        case 15: _t->ReadView((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData WinData::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject WinData::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_WinData,
      qt_meta_data_WinData, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &WinData::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *WinData::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *WinData::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_WinData))
        return static_cast<void*>(const_cast< WinData*>(this));
    return QWidget::qt_metacast(_clname);
}

int WinData::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void WinData::SendCommand(quint16 _t1, quint16 _t2, QByteArray _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void WinData::Signal_Data_to_Main(int _t1, int _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
