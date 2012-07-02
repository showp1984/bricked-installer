/****************************************************************************
** Meta object code from reading C++ file 'flasher.h'
**
** Created: Mon Jul 2 10:56:42 2012
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
      15,   14, // methods
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
     146,    8,    8,    8, 0x08,
     172,    8,  168,    8, 0x08,
     182,    8,  168,    8, 0x08,
     198,    8,  168,    8, 0x08,
     211,    8,    8,    8, 0x08,
     232,  229,  224,    8, 0x08,
     269,    8,  224,    8, 0x08,
     294,    8,  168,    8, 0x08,
     312,    8,  168,    8, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_flasher[] = {
    "flasher\0\0on_txt_out_textChanged()\0"
    "on_btn_start_clicked()\0on_btn_quit_clicked()\0"
    "on_actionInfo_triggered()\0"
    "on_actionQuit_triggered()\0flash_device()\0"
    "push_files_finished()\0int\0extract()\0"
    "detect_device()\0get_booted()\0push_files()\0"
    "bool\0,,\0extract_zip(QString,QString,QString)\0"
    "rmdir_recursive(QString)\0reboot_fastboot()\0"
    "flash_boot()\0"
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
        case 6: push_files_finished(); break;
        case 7: { int _r = extract();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 8: { int _r = detect_device();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 9: { int _r = get_booted();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 10: push_files(); break;
        case 11: { bool _r = extract_zip((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 12: { bool _r = rmdir_recursive((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 13: { int _r = reboot_fastboot();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 14: { int _r = flash_boot();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        default: ;
        }
        _id -= 15;
    }
    return _id;
}
static const uint qt_meta_data_PushWorker[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x05,
      27,   23,   11,   11, 0x05,

       0        // eod
};

static const char qt_meta_stringdata_PushWorker[] = {
    "PushWorker\0\0finished()\0err\0error(QString)\0"
};

const QMetaObject PushWorker::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_PushWorker,
      qt_meta_data_PushWorker, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &PushWorker::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *PushWorker::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *PushWorker::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_PushWorker))
        return static_cast<void*>(const_cast< PushWorker*>(this));
    return QThread::qt_metacast(_clname);
}

int PushWorker::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: finished(); break;
        case 1: error((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void PushWorker::finished()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void PushWorker::error(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
