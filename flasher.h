/*
 * flasher.h
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

#ifndef FLASHER_H
#define FLASHER_H

#include <QMainWindow>
#include <QtGui>
#include <QtGui/QApplication>

#include "info.h"

namespace Ui {
    class flasher;
}

enum {
    EXTRACT = 0,
    DETECT,
    GET_BOOTED,
    CHECK_SNR,
    PUSH_FILES,
    REBOOT_FASTBOOT,
    FLASH_BOOTIMG,
    CHECK_INSTALL,
    RELEASE_CONTROLS,
};

class flasher : public QMainWindow {
    Q_OBJECT
public:
    flasher(QWidget *parent = 0);
    ~flasher();
    void set_snr(QString);
    void set_device(QString);
    void set_filename(QString);
    void set_filepath(QString);
    void set_type(int);

protected:
    void changeEvent(QEvent *e);

private:
    Ui::flasher *ui;
    Info *infowind;
    QTimer *flashtimer;
    QTextCursor c;
    QProcess p;
    bool error;
    bool firstcall;
    bool firstcall_push;
    int flash_state;
    int type;
    QStringList list;
    QStringList list2;
    QStringList list3;
    QString p_out;
    QString device;
    QString snr_old;
    QString snr;
    QString state;
    QString filename;
    QString filepath;
    QString tmp_folder;
    QString abstemppath;
    QString itprev;

private slots:
    void on_txt_out_textChanged();
    void on_btn_start_clicked();
    void on_btn_quit_clicked();
    void on_actionInfo_triggered();
    void on_actionQuit_triggered();
    void flash_device(void);
    void push_files_finished(void);
    int extract(void);
    int detect_device(void);
    int get_booted(void);
    void push_files(void);
    bool extract_zip(const QString&, const QString&, const QString&);
    bool rmdir_recursive(const QString&);
    int reboot_fastboot(void);
    int flash_boot(void);
};

class PushWorker : public QThread {
    Q_OBJECT
 public:
     void run();
     void set_snr(QString);
     void set_abstemppath(QString);
 signals:
     void finished();
     void error(QString err);
 private:
     QString snr;
     QString abstemppath;
 };

#endif // FLASHER_H
