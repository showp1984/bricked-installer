/*
 * mainwindow.h
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

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "info.h"
#include "detect.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::MainWindow *ui;
    QMessageBox alertbox;
    Info *infowind;
    detect *detectwind;

private slots:
    void on_btn_back_clicked();
    void on_btn_go_clicked();
    void on_btn_go_2_clicked();
    void on_btn_quit_clicked();
    void on_actionInfo_triggered();
    void on_actionQuit_triggered();
};

void set_back_detect(bool);

#endif // MAINWINDOW_H
