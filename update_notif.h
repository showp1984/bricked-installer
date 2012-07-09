/*
 * update_notif.h
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

#ifndef UPDATE_NOTIF_H
#define UPDATE_NOTIF_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QThread>
#include <QtGui/QMainWindow>
#include <QProgressDialog>
#include <QFile>
#include <QtNetwork>
#include <QMessageBox>

#include "ui_update_notif.h"
#include "dragons.h"

namespace Ui {
    class update_notif;
}
class getDBupd;
class update_notif : public QMainWindow {
    Q_OBJECT
public:
    update_notif(QWidget *parent = 0);
    ~update_notif();
    getDBupd *p_dbupd;

public slots:
    void downloadProgress(qint64 bytesReceived, qint64 bytesTotal);
    void downloadFinished();
    void downloadReadyRead();
    void cancelDownload();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::update_notif *ui;
    dragons *d;
    QTimer *timer_tout;
    QString url;
    QString abspath;
    QString downfilepath;
    QString oldname;
    QNetworkAccessManager manager;
    QFile *file;
    QNetworkReply *reply;
    bool downloadRequestAborted;
    void rename_installer(void);
    void extract_files(void);
    bool extract_zip(const QString&);
    bool rmdir_recursive_notparent(const QString&);

private slots:
    void on_btn_now_clicked();
    void on_btn_later_clicked();
    void on_btn_quit_clicked();
    void closeupdnot(void);
    void tout_close(void);
};

class getDBupd : public QThread {
    Q_OBJECT
 public:
     void run();
     QString branch;
     QString changelog;
     QString date;
     QString url;
     float version;

 signals:
     void finished();
     void error(QString err);
 };

#endif // UPDATE_NOTIF_H
