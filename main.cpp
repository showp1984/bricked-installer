#include <string>
#include <iostream>
#include <QtGui/QApplication>
#include <QTimer>

#include "dragons.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    a.setApplicationVersion(APP_VERSION);

    dragons d;
    d.show();

    return a.exec();
}
