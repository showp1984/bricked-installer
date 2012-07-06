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

#include "dragons.h"

namespace Ui {
    class update_notif;
}

class update_notif : public QMainWindow {
    Q_OBJECT
public:
    update_notif(QWidget *parent = 0);
    ~update_notif();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::update_notif *ui;
    dragons *d;
    QTimer *timer;
    QString url;

private slots:
    void on_btn_later_clicked();
    void on_btn_quit_clicked();
    void closeupdnot(void);
};

#endif // UPDATE_NOTIF_H
