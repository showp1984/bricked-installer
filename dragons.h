/*
 * dragons.h
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

#ifndef DRAGONS_H
#define DRAGONS_H

#include <QDialog>

#include "mainwindow.h"

namespace Ui {
    class dragons;
}

class dragons : public QDialog {
    Q_OBJECT
public:
    dragons(QWidget *parent = 0);
    ~dragons();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::dragons *ui;
    MainWindow *welcome;
    QTimer *timer;

private slots:
    void on_btn_no_clicked();
    void on_btn_yes_clicked();
    void closedragons(void);
};

#endif // DRAGONS_H
