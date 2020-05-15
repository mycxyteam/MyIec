/****************************************************************************
** Meta object code from reading C++ file 'myiec.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../MyIec/myiec.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'myiec.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MyIec_t {
    QByteArrayData data[20];
    char stringdata[367];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MyIec_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MyIec_t qt_meta_stringdata_MyIec = {
    {
QT_MOC_LITERAL(0, 0, 5),
QT_MOC_LITERAL(1, 6, 20),
QT_MOC_LITERAL(2, 27, 0),
QT_MOC_LITERAL(3, 28, 19),
QT_MOC_LITERAL(4, 48, 31),
QT_MOC_LITERAL(5, 80, 4),
QT_MOC_LITERAL(6, 85, 20),
QT_MOC_LITERAL(7, 106, 36),
QT_MOC_LITERAL(8, 143, 5),
QT_MOC_LITERAL(9, 149, 32),
QT_MOC_LITERAL(10, 182, 12),
QT_MOC_LITERAL(11, 195, 9),
QT_MOC_LITERAL(12, 205, 4),
QT_MOC_LITERAL(13, 210, 14),
QT_MOC_LITERAL(14, 225, 16),
QT_MOC_LITERAL(15, 242, 17),
QT_MOC_LITERAL(16, 260, 39),
QT_MOC_LITERAL(17, 300, 21),
QT_MOC_LITERAL(18, 322, 23),
QT_MOC_LITERAL(19, 346, 20)
    },
    "MyIec\0on_actionA_triggered\0\0"
    "on_comboBox_clicked\0on_comboBox_currentIndexChanged\0"
    "arg1\0on_actionB_triggered\0"
    "on_comboBox_Baud_currentIndexChanged\0"
    "index\0on_lineEdit_Password_textChanged\0"
    "receiverData\0SerialVar\0data\0receiverData_1\0"
    "CommunicationVar\0GetSerialPortName\0"
    "on_pushButton_OpenOrCloseSerial_clicked\0"
    "on_pushButton_clicked\0on_pushButton_2_clicked\0"
    "on_actionQ_triggered"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MyIec[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   79,    2, 0x08 /* Private */,
       3,    0,   80,    2, 0x08 /* Private */,
       4,    1,   81,    2, 0x08 /* Private */,
       6,    0,   84,    2, 0x08 /* Private */,
       7,    1,   85,    2, 0x08 /* Private */,
       9,    1,   88,    2, 0x08 /* Private */,
      10,    1,   91,    2, 0x08 /* Private */,
      13,    1,   94,    2, 0x08 /* Private */,
      15,    0,   97,    2, 0x08 /* Private */,
      16,    0,   98,    2, 0x08 /* Private */,
      17,    0,   99,    2, 0x08 /* Private */,
      18,    0,  100,    2, 0x08 /* Private */,
      19,    0,  101,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, 0x80000000 | 11,   12,
    QMetaType::Void, 0x80000000 | 14,   12,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MyIec::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MyIec *_t = static_cast<MyIec *>(_o);
        switch (_id) {
        case 0: _t->on_actionA_triggered(); break;
        case 1: _t->on_comboBox_clicked(); break;
        case 2: _t->on_comboBox_currentIndexChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->on_actionB_triggered(); break;
        case 4: _t->on_comboBox_Baud_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->on_lineEdit_Password_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 6: _t->receiverData((*reinterpret_cast< SerialVar(*)>(_a[1]))); break;
        case 7: _t->receiverData_1((*reinterpret_cast< CommunicationVar(*)>(_a[1]))); break;
        case 8: _t->GetSerialPortName(); break;
        case 9: _t->on_pushButton_OpenOrCloseSerial_clicked(); break;
        case 10: _t->on_pushButton_clicked(); break;
        case 11: _t->on_pushButton_2_clicked(); break;
        case 12: _t->on_actionQ_triggered(); break;
        default: ;
        }
    }
}

const QMetaObject MyIec::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MyIec.data,
      qt_meta_data_MyIec,  qt_static_metacall, 0, 0}
};


const QMetaObject *MyIec::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MyIec::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MyIec.stringdata))
        return static_cast<void*>(const_cast< MyIec*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MyIec::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
