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
    timer_tout = new QTimer(this);
    connect(timer_tout, SIGNAL(timeout()), this, SLOT(tout_close()));

    getDBupd *dbupd = new getDBupd();
    QObject::connect(dbupd,
                     SIGNAL(finished()),
                     this,
                     SLOT(closeupdnot()));
    dbupd->start();
    this->p_dbupd = dbupd;

    ui->setupUi(this);

    timer_tout->setSingleShot(true);
    timer_tout->setInterval(1000);
    timer_tout->start();

    ui->lbl2_restart->hide();
    ui->lbl2_updating->hide();
    ui->lbl2_warn->hide();
    ui->lbl2_xtr->hide();
    ui->bar2_xtr->hide();
    ui->bar2_downl->hide();
}

update_notif::~update_notif()
{
    delete timer_tout;
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
    QString ver;
    timer_tout->stop();
    show();
    if (p_dbupd->version > qApp->applicationVersion().toFloat()) {
        qDebug() << "Update found!";
        ver = QString::number(p_dbupd->version);
        ui->lbl_edt_vers->setText(ver);
        ui->lbl_edt_branch->setText(p_dbupd->branch);
        ui->lbl_edt_date->setText(p_dbupd->date);
        ui->txt_change->setText(p_dbupd->changelog);
        url = url;
    } else {
        qDebug() << "No update found.";
        this->close();
        d = new dragons();
        d->show();
    }
}

void update_notif::tout_close(void)
{
    this->close();
    d = new dragons();
    d->show();
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

void getDBupd::run(void)
{
    QSqlDatabase db = connectDB();
    QSqlQuery query;

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
    db.close();
    db.removeDatabase("default");
    this->finished();
    this->quit();
}

void update_notif::on_btn_now_clicked()
{
    ui->btn_later->hide();
    ui->btn_now->hide();
    ui->btn_quit->hide();
    ui->lbl_branch->hide();
    ui->lbl_change->hide();
    ui->lbl_date->hide();
    ui->lbl_edt_branch->hide();
    ui->lbl_edt_date->hide();
    ui->lbl_edt_vers->hide();
    ui->lbl_updnot->hide();
    ui->lbl_vers->hide();
    ui->txt_change->hide();

    ui->lbl2_warn->show();

    ui->lbl2_updating->show();
    ui->bar2_downl->show();
    ui->lbl2_xtr->show();
    ui->bar2_xtr->show();
    ui->lbl2_restart->show();
}
