/****************************************************************************
** Meta object code from reading C++ file 'sqlexports.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../AIPDebug/sql/sqlexports.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'sqlexports.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_SqlExports[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      16,   12,   11,   11, 0x05,

 // slots: signature, parameters, type, tag, flags
      57,   51,   40,   11, 0x08,
      72,   12,   11,   11, 0x08,
     100,   11,   96,   11, 0x08,
     113,   11,   96,   11, 0x08,
     126,   11,   96,   11, 0x08,
     139,   11,   96,   11, 0x08,
     152,   11,   96,   11, 0x08,
     165,   11,   96,   11, 0x08,
     182,  178,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_SqlExports[] = {
    "SqlExports\0\0msg\0sendSqlMap(QVariantMap)\0"
    "QByteArray\0inStr\0ToGbk(QString)\0"
    "recvSqlMap(QVariantMap)\0int\0exportFile()\0"
    "createFile()\0selectNumb()\0selectItem()\0"
    "exportHead()\0exportData()\0err\0"
    "showText(QString)\0"
};

void SqlExports::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        SqlExports *_t = static_cast<SqlExports *>(_o);
        switch (_id) {
        case 0: _t->sendSqlMap((*reinterpret_cast< QVariantMap(*)>(_a[1]))); break;
        case 1: { QByteArray _r = _t->ToGbk((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QByteArray*>(_a[0]) = _r; }  break;
        case 2: _t->recvSqlMap((*reinterpret_cast< QVariantMap(*)>(_a[1]))); break;
        case 3: { int _r = _t->exportFile();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 4: { int _r = _t->createFile();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 5: { int _r = _t->selectNumb();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 6: { int _r = _t->selectItem();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 7: { int _r = _t->exportHead();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 8: { int _r = _t->exportData();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 9: _t->showText((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData SqlExports::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject SqlExports::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_SqlExports,
      qt_meta_data_SqlExports, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &SqlExports::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *SqlExports::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *SqlExports::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SqlExports))
        return static_cast<void*>(const_cast< SqlExports*>(this));
    return QObject::qt_metacast(_clname);
}

int SqlExports::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void SqlExports::sendSqlMap(QVariantMap _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
