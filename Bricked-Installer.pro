# -------------------------------------------------
# Project created by QtCreator 2012-06-28T20:21:06
# -------------------------------------------------
QT += sql

# version
VERSION = 0.1

# preprocessor macro
DEFINES += APP_VERSION=\\\"$$VERSION\\\"
TARGET = Bricked-Installer
TEMPLATE = app
SOURCES += main.cpp \
    mainwindow.cpp \
    dragons.cpp \
    info.cpp \
    detect.cpp \
    flasher.cpp \
    openfile.cpp \
    update_notif.cpp \
    database.cpp \
    downmanager.cpp
HEADERS += mainwindow.h \
    dragons.h \
    info.h \
    detect.h \
    flasher.h \
    openfile.h \
    update_notif.h \
    downmanager.h
FORMS += mainwindow.ui \
    dragons.ui \
    info.ui \
    detect.ui \
    flasher.ui \
    openfile.ui \
    update_notif.ui
RESOURCES += res/res_loc.qrc
unix { 
    SOURCES += quazip/unzip.c \
        quazip/zip.c \
        quazip/JlCompress.cpp \
        quazip/qioapi.cpp \
        quazip/quaadler32.cpp \
        quazip/quacrc32.cpp \
        quazip/quazip.cpp \
        quazip/quazipfile.cpp \
        quazip/quazipnewinfo.cpp
    HEADERS += quazip/crypt.h \
        quazip/ioapi.h \
        quazip/JlCompress.h \
        quazip/quaadler32.h \
        quazip/quachecksum32.h \
        quazip/quacrc32.h \
        quazip/quazipfile.h \
        quazip/quazipfileinfo.h \
        quazip/quazip_global.h \
        quazip/quazip.h \
        quazip/quazipnewinfo.h \
        quazip/unzip.h \
        quazip/zip.h
}
win32 { 
    INCLUDEPATH += $$[QT_INSTALL_PREFIX]/src/3rdparty/zlib
    DEFINES += QUAZIP_BUILD
    CONFIG(staticlib):DEFINES += QUAZIP_STATIC
    LIBS += -Lquazip/libs
    LIBS += -lquazip
}
