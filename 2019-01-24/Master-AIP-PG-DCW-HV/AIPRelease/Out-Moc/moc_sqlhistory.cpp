/****************************************************************************
** Meta object code from reading C++ file 'sqlhistory.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../AIPDebug/sql/sqlhistory.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'sqlhistory.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_SqlHistory[] = {

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
      16,   12,   11,   11, 0x05,

 // slots: signature, parameters, type, tag, flags
      40,   11,   11,   11, 0x08,
      49,   11,   11,   11, 0x08,
      60,   11,   11,   11, 0x08,
      73,   11,   11,   11, 0x08,
      86,   11,   11,   11, 0x08,
      99,   11,   11,   11, 0x08,
     112,   11,   11,   11, 0x08,
     127,  125,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_SqlHistory[] = {
    "SqlHistory\0\0msg\0sendSqlMap(QVariantMap)\0"
    "initUI()\0initView()\0initButton()\0"
    "initLayout()\0updateFile()\0recvExport()\0"
    "recvDelete()\0e\0showEvent(QShowEvent*)\0"
};

void SqlHistory::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        SqlHistory *_t = static_cast<SqlHistory *>(_o);
        switch (_id) {
        case 0: _t->sendSqlMap((*reinterpret_cast< QVariantMap(*)>(_a[1]))); break;
        case 1: _t->initUI(); break;
        case 2: _t->initView(); break;
        case 3: _t->initButton(); break;
        case 4: _t->initLayout(); break;
        case 5: _t->updateFile(); break;
        case 6: _t->recvExport(); break;
        case 7: _t->recvDelete(); break;
        case 8: _t->showEvent((*reinterpret_cast< QShowEvent*(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData SqlHistory::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject SqlHistory::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_SqlHistory,
      qt_meta_data_SqlHistory, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &SqlHistory::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *SqlHistory::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *SqlHistory::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SqlHistory))
        return static_cast<void*>(const_cast< SqlHistory*>(this));
    return QWidget::qt_metacast(_clname);
}

int SqlHistory::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
void SqlHistory::sendSqlMap(QVariantMap _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
