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
    flasher.cpp
HEADERS += mainwindow.h \
    dragons.h \
    info.h \
    detect.h \
    flasher.h
FORMS += mainwindow.ui \
    dragons.ui \
    info.ui \
    detect.ui \
    flasher.ui
RESOURCES += res/res_loc.qrc
