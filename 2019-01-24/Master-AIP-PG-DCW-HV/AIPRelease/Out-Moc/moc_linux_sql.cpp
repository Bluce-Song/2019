/****************************************************************************
** Meta object code from reading C++ file 'linux_sql.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../AIPDebug/External-Interface/linux_sql.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'linux_sql.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_LINUX_SQL[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      21,   15,   11,   10, 0x0a,
      41,   15,   11,   10, 0x0a,
      78,   70,   65,   10, 0x0a,
      96,   70,   65,   10, 0x0a,
     119,   10,   65,   10, 0x0a,
     142,  130,   65,   10, 0x0a,
     192,  171,   65,   10, 0x0a,
     239,  171,   65,   10, 0x0a,
     310,  295,  286,   10, 0x0a,
     357,  348,   65,   10, 0x0a,
     386,   15,   65,   10, 0x0a,
     406,   15,   65,   10, 0x0a,
     433,  426,   65,   10, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_LINUX_SQL[] = {
    "LINUX_SQL\0\0int\0table\0selectMax(QVariant)\0"
    "selectMax_net(QVariant)\0bool\0sqldata\0"
    "openSql(QVariant)\0open_net_Sql(QVariant)\0"
    "closeSql()\0table,param\0"
    "createSql(QVariant,QVariant)\0"
    "table,title,param,id\0"
    "insertSql(QVariant,QVariant,QVariant,QVariant)\0"
    "updateSql(QVariant,QVariant,QVariant,QVariant)\0"
    "QVariant\0table,title,id\0"
    "selectSql(QVariant,QVariant,QVariant)\0"
    "table,id\0deleteSql(QVariant,QVariant)\0"
    "deleteAll(QVariant)\0deleteTab(QVariant)\0"
    "table,\0isTabExst(QVariant,QSqlDatabase)\0"
};

void LINUX_SQL::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        LINUX_SQL *_t = static_cast<LINUX_SQL *>(_o);
        switch (_id) {
        case 0: { int _r = _t->selectMax((*reinterpret_cast< QVariant(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 1: { int _r = _t->selectMax_net((*reinterpret_cast< QVariant(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 2: { bool _r = _t->openSql((*reinterpret_cast< QVariant(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 3: { bool _r = _t->open_net_Sql((*reinterpret_cast< QVariant(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 4: { bool _r = _t->closeSql();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 5: { bool _r = _t->createSql((*reinterpret_cast< QVariant(*)>(_a[1])),(*reinterpret_cast< QVariant(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 6: { bool _r = _t->insertSql((*reinterpret_cast< QVariant(*)>(_a[1])),(*reinterpret_cast< QVariant(*)>(_a[2])),(*reinterpret_cast< QVariant(*)>(_a[3])),(*reinterpret_cast< QVariant(*)>(_a[4])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 7: { bool _r = _t->updateSql((*reinterpret_cast< QVariant(*)>(_a[1])),(*reinterpret_cast< QVariant(*)>(_a[2])),(*reinterpret_cast< QVariant(*)>(_a[3])),(*reinterpret_cast< QVariant(*)>(_a[4])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 8: { QVariant _r = _t->selectSql((*reinterpret_cast< QVariant(*)>(_a[1])),(*reinterpret_cast< QVariant(*)>(_a[2])),(*reinterpret_cast< QVariant(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< QVariant*>(_a[0]) = _r; }  break;
        case 9: { bool _r = _t->deleteSql((*reinterpret_cast< QVariant(*)>(_a[1])),(*reinterpret_cast< QVariant(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 10: { bool _r = _t->deleteAll((*reinterpret_cast< QVariant(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 11: { bool _r = _t->deleteTab((*reinterpret_cast< QVariant(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 12: { bool _r = _t->isTabExst((*reinterpret_cast< QVariant(*)>(_a[1])),(*reinterpret_cast< QSqlDatabase(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        default: ;
        }
    }
}

const QMetaObjectExtraData LINUX_SQL::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject LINUX_SQL::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_LINUX_SQL,
      qt_meta_data_LINUX_SQL, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &LINUX_SQL::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *LINUX_SQL::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *LINUX_SQL::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_LINUX_SQL))
        return static_cast<void*>(const_cast< LINUX_SQL*>(this));
    return QWidget::qt_metacast(_clname);
}

int LINUX_SQL::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
