/*
 * openfile.h
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

#ifndef OPENFILE_H
#define OPENFILE_H

#include <QMainWindow>
#include <QtGui>
#include <QtGui/QApplication>

#include "info.h"
#include "flasher.h"

namespace Ui {
    class openfile;
}

enum {
    KERNEL = 0,
    ROM
};

class openfile : public QMainWindow {
    Q_OBJECT
public:
    openfile(QWidget *parent = 0);
    ~openfile();
    void set_snr(QString);
    void set_device(QString);

protected:
    void changeEvent(QEvent *e);

private:
    Ui::openfile *ui;
    Info *infowind;
    flasher *flasherwind;
    QMessageBox alertbox;
    QFileInfo fileinfo;
    QString device;
    QString snr_old;
    QString filename;
    QString filepath;

private slots:
    void on_cmb_type_currentIndexChanged(int index);
    void on_btn_find_clicked();
    void on_btn_go_clicked();
    void on_btn_quit_clicked();
    void on_actionInfo_triggered();
    void on_actionQuit_triggered();
};

#endif // OPENFILE_H
