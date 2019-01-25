/****************************************************************************
** Meta object code from reading C++ file 'sqldesktop.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../sql/sqldesktop.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'sqldesktop.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_SqlDesktop[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      30,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: signature, parameters, type, tag, flags
      16,   12,   11,   11, 0x05,
      40,   12,   11,   11, 0x05,
      67,   64,   11,   11, 0x05,

 // slots: signature, parameters, type, tag, flags
     108,   11,   11,   11, 0x08,
     117,   11,   11,   11, 0x08,
     127,   11,   11,   11, 0x08,
     137,   11,   11,   11, 0x08,
     150,   11,   11,   11, 0x08,
     167,   11,   11,   11, 0x08,
     184,   11,   11,   11, 0x08,
     201,   11,   11,   11, 0x08,
     218,   11,   11,   11, 0x08,
     235,   11,   11,   11, 0x08,
     252,   12,   11,   11, 0x08,
     280,   12,   11,   11, 0x08,
     316,   11,   11,   11, 0x08,
     334,   11,   11,   11, 0x08,
     352,   11,   11,   11, 0x08,
     370,   11,   11,   11, 0x08,
     388,   11,   11,   11, 0x08,
     407,   11,   11,   11, 0x08,
     426,   11,  421,   11, 0x08,
     453,   11,  445,   11, 0x08,
     471,   11,   11,   11, 0x08,
     489,   12,   11,   11, 0x08,
     511,   12,   11,   11, 0x08,
     533,   12,   11,   11, 0x08,
     557,   12,   11,   11, 0x08,
     590,  585,  581,   11, 0x08,
     609,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_SqlDesktop[] = {
    "SqlDesktop\0\0msg\0sendAppMsg(QVariantMap)\0"
    "sendSqlMap(QVariantMap)\0,,\0"
    "Signal_Data_to_Main(QStringList,int,int)\0"
    "initUI()\0initDir()\0initSql()\0initLayout()\0"
    "initSqlDisplay()\0initSqlProduct()\0"
    "initSqlNetwork()\0initSqlHistory()\0"
    "initSqlExports()\0initSqlSignOut()\0"
    "sendSqlExports(QVariantMap)\0"
    "sendSqlExports_picture(QVariantMap)\0"
    "initProgressBar()\0updateSqlExport()\0"
    "createSqlRecord()\0backupSqlRecord()\0"
    "updateSqlMessage()\0clickButton()\0bool\0"
    "existsSdcardDisk()\0QString\0existsFlashDisk()\0"
    "deleteFlashDisk()\0recvQuan(QVariantMap)\0"
    "recvOver(QVariantMap)\0recvSqlMap(QVariantMap)\0"
    "recvSqlDat(QVariantMap)\0int\0numb\0"
    "getNumber(QString)\0widget_hide()\0"
};

void SqlDesktop::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        SqlDesktop *_t = static_cast<SqlDesktop *>(_o);
        switch (_id) {
        case 0: _t->sendAppMsg((*reinterpret_cast< QVariantMap(*)>(_a[1]))); break;
        case 1: _t->sendSqlMap((*reinterpret_cast< QVariantMap(*)>(_a[1]))); break;
        case 2: _t->Signal_Data_to_Main((*reinterpret_cast< QStringList(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 3: _t->initUI(); break;
        case 4: _t->initDir(); break;
        case 5: _t->initSql(); break;
        case 6: _t->initLayout(); break;
        case 7: _t->initSqlDisplay(); break;
        case 8: _t->initSqlProduct(); break;
        case 9: _t->initSqlNetwork(); break;
        case 10: _t->initSqlHistory(); break;
        case 11: _t->initSqlExports(); break;
        case 12: _t->initSqlSignOut(); break;
        case 13: _t->sendSqlExports((*reinterpret_cast< QVariantMap(*)>(_a[1]))); break;
        case 14: _t->sendSqlExports_picture((*reinterpret_cast< QVariantMap(*)>(_a[1]))); break;
        case 15: _t->initProgressBar(); break;
        case 16: _t->updateSqlExport(); break;
        case 17: _t->createSqlRecord(); break;
        case 18: _t->backupSqlRecord(); break;
        case 19: _t->updateSqlMessage(); break;
        case 20: _t->clickButton(); break;
        case 21: { bool _r = _t->existsSdcardDisk();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 22: { QString _r = _t->existsFlashDisk();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 23: _t->deleteFlashDisk(); break;
        case 24: _t->recvQuan((*reinterpret_cast< QVariantMap(*)>(_a[1]))); break;
        case 25: _t->recvOver((*reinterpret_cast< QVariantMap(*)>(_a[1]))); break;
        case 26: _t->recvSqlMap((*reinterpret_cast< QVariantMap(*)>(_a[1]))); break;
        case 27: _t->recvSqlDat((*reinterpret_cast< QVariantMap(*)>(_a[1]))); break;
        case 28: { int _r = _t->getNumber((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 29: _t->widget_hide(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData SqlDesktop::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject SqlDesktop::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_SqlDesktop,
      qt_meta_data_SqlDesktop, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &SqlDesktop::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *SqlDesktop::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *SqlDesktop::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SqlDesktop))
        return static_cast<void*>(const_cast< SqlDesktop*>(this));
    return QWidget::qt_metacast(_clname);
}

int SqlDesktop::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 30)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 30;
    }
    return _id;
}

// SIGNAL 0
void SqlDesktop::sendAppMsg(QVariantMap _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void SqlDesktop::sendSqlMap(QVariantMap _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void SqlDesktop::Signal_Data_to_Main(QStringList _t1, int _t2, int _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
