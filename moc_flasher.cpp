/****************************************************************************
** Meta object code from reading C++ file 'flasher.h'
**
** Created: Sun Jul 1 17:35:14 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "flasher.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'flasher.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_flasher[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
       9,    8,    8,    8, 0x08,
      34,    8,    8,    8, 0x08,
      57,    8,    8,    8, 0x08,
      79,    8,    8,    8, 0x08,
     105,    8,    8,    8, 0x08,
     131,    8,    8,    8, 0x08,
     150,    8,  146,    8, 0x08,
     166,    8,  146,    8, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_flasher[] = {
    "flasher\0\0on_txt_out_textChanged()\0"
    "on_btn_start_clicked()\0on_btn_quit_clicked()\0"
    "on_actionInfo_triggered()\0"
    "on_actionQuit_triggered()\0flash_device()\0"
    "int\0detect_device()\0get_booted()\0"
};

const QMetaObject flasher::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_flasher,
      qt_meta_data_flasher, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &flasher::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *flasher::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *flasher::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_flasher))
        return static_cast<void*>(const_cast< flasher*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int flasher::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: on_txt_out_textChanged(); break;
        case 1: on_btn_start_clicked(); break;
        case 2: on_btn_quit_clicked(); break;
        case 3: on_actionInfo_triggered(); break;
        case 4: on_actionQuit_triggered(); break;
        case 5: flash_device(); break;
        case 6: { int _r = detect_device();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 7: { int _r = get_booted();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        default: ;
        }
        _id -= 8;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
