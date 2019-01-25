/****************************************************************************
** Meta object code from reading C++ file 'sqlsnowuid.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../AIPDebug/sql/sqlsnowuid.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'sqlsnowuid.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_SqlSnowUid[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      20,   11,   12,   11, 0x0a,
      31,   28,   11,   11, 0x0a,
      53,   28,   11,   11, 0x0a,
      78,   11,   12,   11, 0x08,
     107,   93,   12,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_SqlSnowUid[] = {
    "SqlSnowUid\0\0quint64\0getId()\0id\0"
    "setMachineId(quint64)\0setDataCenterId(quint64)\0"
    "getTimestamp()\0lastTimestamp\0"
    "getNextTimestamp(quint64)\0"
};

void SqlSnowUid::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        SqlSnowUid *_t = static_cast<SqlSnowUid *>(_o);
        switch (_id) {
        case 0: { quint64 _r = _t->getId();
            if (_a[0]) *reinterpret_cast< quint64*>(_a[0]) = _r; }  break;
        case 1: _t->setMachineId((*reinterpret_cast< quint64(*)>(_a[1]))); break;
        case 2: _t->setDataCenterId((*reinterpret_cast< quint64(*)>(_a[1]))); break;
        case 3: { quint64 _r = _t->getTimestamp();
            if (_a[0]) *reinterpret_cast< quint64*>(_a[0]) = _r; }  break;
        case 4: { quint64 _r = _t->getNextTimestamp((*reinterpret_cast< quint64(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< quint64*>(_a[0]) = _r; }  break;
        default: ;
        }
    }
}

const QMetaObjectExtraData SqlSnowUid::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject SqlSnowUid::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_SqlSnowUid,
      qt_meta_data_SqlSnowUid, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &SqlSnowUid::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *SqlSnowUid::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *SqlSnowUid::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SqlSnowUid))
        return static_cast<void*>(const_cast< SqlSnowUid*>(this));
    return QObject::qt_metacast(_clname);
}

int SqlSnowUid::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
