/****************************************************************************
** Meta object code from reading C++ file 'detect.h'
**
** Created: Sat Jun 30 17:09:29 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "detect.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'detect.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_detect[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
       8,    7,    7,    7, 0x08,
      28,    7,    7,    7, 0x08,
      50,    7,    7,    7, 0x08,
      76,    7,    7,    7, 0x08,
     102,    7,    7,    7, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_detect[] = {
    "detect\0\0on_btn_no_clicked()\0"
    "on_btn_quit_clicked()\0on_actionInfo_triggered()\0"
    "on_actionQuit_triggered()\0detect_device()\0"
};

const QMetaObject detect::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_detect,
      qt_meta_data_detect, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &detect::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *detect::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *detect::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_detect))
        return static_cast<void*>(const_cast< detect*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int detect::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: on_btn_no_clicked(); break;
        case 1: on_btn_quit_clicked(); break;
        case 2: on_actionInfo_triggered(); break;
        case 3: on_actionQuit_triggered(); break;
        case 4: detect_device(); break;
        default: ;
        }
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
