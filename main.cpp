/*
 * main.cpp
 *
 * Copyright (c) 2012, Dennis Rassmann <showp1984@gmail.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 */

#include <string>
#include <iostream>
#include <QtGui/QApplication>
#include <QTimer>
#include <QDebug>

#include "update_notif.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    update_notif un;
    QStringList splitlist;
    QString last_splitlist;
    QDir dir(a.applicationDirPath());

    if (dir.exists(a.applicationDirPath())) {
        Q_FOREACH(QFileInfo info, dir.entryInfoList(QDir::NoDotAndDotDot | QDir::System | QDir::Hidden  | QDir::AllDirs | QDir::Files, QDir::DirsFirst)) {
            splitlist = info.absoluteFilePath().split(QString("_"));
            last_splitlist = splitlist.takeLast();
            if ((!info.isDir()) && (last_splitlist == "old")) {
                (void) QFile::remove(info.absoluteFilePath());
            }
        }
    }

    a.setApplicationVersion(APP_VERSION);

    un.show();
    un.hide();

    return a.exec();
}
