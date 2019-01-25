/****************************************************************************
** Meta object code from reading C++ file 'sqlproduct.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../sql/sqlproduct.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'sqlproduct.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_SqlProduct[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x08,
      21,   11,   11,   11, 0x08,
      32,   11,   11,   11, 0x08,
      43,   11,   11,   11, 0x08,
      56,   11,   11,   11, 0x08,
      71,   11,   11,   11, 0x08,
      86,   11,   11,   11, 0x08,
     101,   11,   11,   11, 0x08,
     118,  116,   11,   11, 0x08,
     145,  141,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_SqlProduct[] = {
    "SqlProduct\0\0initUI()\0initView()\0"
    "initText()\0initLayout()\0createSqlite()\0"
    "updateSqlite()\0insertSqlite()\0"
    "selectSqlite()\0e\0showEvent(QShowEvent*)\0"
    "msg\0recvSqlMap(QVariantMap)\0"
};

void SqlProduct::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        SqlProduct *_t = static_cast<SqlProduct *>(_o);
        switch (_id) {
        case 0: _t->initUI(); break;
        case 1: _t->initView(); break;
        case 2: _t->initText(); break;
        case 3: _t->initLayout(); break;
        case 4: _t->createSqlite(); break;
        case 5: _t->updateSqlite(); break;
        case 6: _t->insertSqlite(); break;
        case 7: _t->selectSqlite(); break;
        case 8: _t->showEvent((*reinterpret_cast< QShowEvent*(*)>(_a[1]))); break;
        case 9: _t->recvSqlMap((*reinterpret_cast< QVariantMap(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData SqlProduct::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject SqlProduct::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_SqlProduct,
      qt_meta_data_SqlProduct, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &SqlProduct::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *SqlProduct::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *SqlProduct::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SqlProduct))
        return static_cast<void*>(const_cast< SqlProduct*>(this));
    return QWidget::qt_metacast(_clname);
}

int SqlProduct::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
