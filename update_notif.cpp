/*
 * update_notif.cpp
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

#include <QDebug>
#include <QTimer>

#include "update_notif.h"
#include "ui_update_notif.h"

extern QSqlDatabase connectDB(void);
extern void closeDB(QSqlDatabase);

update_notif::update_notif(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::update_notif)
{
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(closeupdnot()));

    ui->setupUi(this);

    timer->setSingleShot(true);
    timer->setInterval(0);
    timer->start();
}

update_notif::~update_notif()
{
    delete timer;
    delete ui;
}

void update_notif::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void update_notif::closeupdnot(void)
{
    float version = 0;
    QSqlDatabase db = connectDB();
    QSqlQuery query;
    QString branch;
    QString changelog;
    QString date;
    QString url;
    QString ver;

    qDebug() << "Local: " << qApp->applicationVersion();

    query.prepare("SELECT version, branch, changelog, date, url FROM versions WHERE version = (SELECT MAX(version) FROM versions) AND version > " + qApp->applicationVersion());
    query.exec();
    while (query.next()) {
        version = query.value(0).toFloat();
        branch = query.value(1).toString();
        changelog = query.value(2).toString();
        date = query.value(3).toString();
        url = query.value(4).toString();
        qDebug() << version << branch << date << url;// << changelog;
    }

    if (version > qApp->applicationVersion().toFloat()) {
        qDebug() << "Update found!";
        ver = QString::number(version);
        ui->lbl_edt_vers->setText(ver);
        ui->lbl_edt_branch->setText(branch);
        ui->lbl_edt_date->setText(date);
        ui->txt_change->setText(changelog);
        url = url;
    } else {
        qDebug() << "No update found.";
        closeDB(db);
        this->close();
        d = new dragons();
        d->show();
    }

    closeDB(db);
}

void update_notif::on_btn_quit_clicked()
{
    this->close();
}

void update_notif::on_btn_later_clicked()
{
    this->close();
    d = new dragons();
    d->show();
}
