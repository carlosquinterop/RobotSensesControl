/****************************************************************************
** Meta object code from reading C++ file 'RobotSensesControl.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../include/RobotSensesControl.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'RobotSensesControl.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_RobotSensesControl_t {
    QByteArrayData data[19];
    char stringdata0[268];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_RobotSensesControl_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_RobotSensesControl_t qt_meta_stringdata_RobotSensesControl = {
    {
QT_MOC_LITERAL(0, 0, 18), // "RobotSensesControl"
QT_MOC_LITERAL(1, 19, 20), // "playStandardMessages"
QT_MOC_LITERAL(2, 40, 0), // ""
QT_MOC_LITERAL(3, 41, 7), // "message"
QT_MOC_LITERAL(4, 49, 12), // "processEnded"
QT_MOC_LITERAL(5, 62, 8), // "exitCode"
QT_MOC_LITERAL(6, 71, 20), // "QProcess::ExitStatus"
QT_MOC_LITERAL(7, 92, 11), // "existStatus"
QT_MOC_LITERAL(8, 104, 14), // "playButtonSlot"
QT_MOC_LITERAL(9, 119, 12), // "captureImage"
QT_MOC_LITERAL(10, 132, 18), // "stopCapturingImage"
QT_MOC_LITERAL(11, 151, 18), // "leftTurnButtonSlot"
QT_MOC_LITERAL(12, 170, 19), // "rightTurnButtonSlot"
QT_MOC_LITERAL(13, 190, 16), // "upTurnButtonSlot"
QT_MOC_LITERAL(14, 207, 18), // "downTurnButtonSlot"
QT_MOC_LITERAL(15, 226, 7), // "yesSlot"
QT_MOC_LITERAL(16, 234, 6), // "noSlot"
QT_MOC_LITERAL(17, 241, 13), // "yesButtonSlot"
QT_MOC_LITERAL(18, 255, 12) // "noButtonSlot"

    },
    "RobotSensesControl\0playStandardMessages\0"
    "\0message\0processEnded\0exitCode\0"
    "QProcess::ExitStatus\0existStatus\0"
    "playButtonSlot\0captureImage\0"
    "stopCapturingImage\0leftTurnButtonSlot\0"
    "rightTurnButtonSlot\0upTurnButtonSlot\0"
    "downTurnButtonSlot\0yesSlot\0noSlot\0"
    "yesButtonSlot\0noButtonSlot"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_RobotSensesControl[] = {

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
       1,    1,   79,    2, 0x08 /* Private */,
       4,    2,   82,    2, 0x08 /* Private */,
       8,    0,   87,    2, 0x08 /* Private */,
       9,    0,   88,    2, 0x08 /* Private */,
      10,    0,   89,    2, 0x08 /* Private */,
      11,    0,   90,    2, 0x08 /* Private */,
      12,    0,   91,    2, 0x08 /* Private */,
      13,    0,   92,    2, 0x08 /* Private */,
      14,    0,   93,    2, 0x08 /* Private */,
      15,    0,   94,    2, 0x08 /* Private */,
      16,    0,   95,    2, 0x08 /* Private */,
      17,    0,   96,    2, 0x08 /* Private */,
      18,    0,   97,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 6,    5,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void RobotSensesControl::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        RobotSensesControl *_t = static_cast<RobotSensesControl *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->playStandardMessages((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->processEnded((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QProcess::ExitStatus(*)>(_a[2]))); break;
        case 2: _t->playButtonSlot(); break;
        case 3: _t->captureImage(); break;
        case 4: _t->stopCapturingImage(); break;
        case 5: _t->leftTurnButtonSlot(); break;
        case 6: _t->rightTurnButtonSlot(); break;
        case 7: _t->upTurnButtonSlot(); break;
        case 8: _t->downTurnButtonSlot(); break;
        case 9: _t->yesSlot(); break;
        case 10: _t->noSlot(); break;
        case 11: _t->yesButtonSlot(); break;
        case 12: _t->noButtonSlot(); break;
        default: ;
        }
    }
}

const QMetaObject RobotSensesControl::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_RobotSensesControl.data,
      qt_meta_data_RobotSensesControl,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *RobotSensesControl::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RobotSensesControl::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_RobotSensesControl.stringdata0))
        return static_cast<void*>(const_cast< RobotSensesControl*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int RobotSensesControl::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
