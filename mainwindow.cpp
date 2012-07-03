/*
 * mainwindow.cpp
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

#include <QMessageBox>

#include "mainwindow.h"
#include "ui_mainwindow.h"

static bool back_detect = false;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->btn_go->show();
    ui->btn_back->hide();
    ui->lbl_welcome->show();
    ui->btn_go_2->hide();
    ui->lbl_disclaimer_accept->hide();
    ui->txt_disclaimer->hide();
    ui->chk_agreed->hide();
    ui->line->hide();

    if (back_detect) {
        back_detect = false;
        ui->btn_go->hide();
        ui->btn_back->show();
        ui->lbl_welcome->hide();
        ui->btn_go_2->show();
        ui->lbl_disclaimer_accept->show();
        ui->txt_disclaimer->show();
        ui->chk_agreed->show();
        ui->line->show();
    }
}

MainWindow::~MainWindow()
{
    delete ui;
    delete this;
}

void MainWindow::changeEvent(QEvent *e)
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

void MainWindow::on_actionQuit_triggered()
{
    this->close();
}

void MainWindow::on_actionInfo_triggered()
{
    infowind = new Info();
    infowind->show();
}

void MainWindow::on_btn_quit_clicked()
{
    this->close();
}

void MainWindow::on_btn_go_2_clicked()
{
    if (ui->chk_agreed->isChecked()) {
        this->close();
        detectwind = new detect();
        detectwind->show();
    } else {
        alertbox.setText("You haven't agreed to the terms.");
        alertbox.exec();
    }
}

void MainWindow::on_btn_go_clicked()
{
    //hide label & go, visible label2 and go2
    ui->btn_go->hide();
    ui->btn_back->show();
    ui->lbl_welcome->hide();
    ui->btn_go_2->show();
    ui->lbl_disclaimer_accept->show();
    ui->txt_disclaimer->show();
    ui->chk_agreed->show();
    ui->line->show();
}

void MainWindow::on_btn_back_clicked()
{
    ui->btn_go->show();
    ui->btn_back->hide();
    ui->lbl_welcome->show();
    ui->btn_go_2->hide();
    ui->lbl_disclaimer_accept->hide();
    ui->txt_disclaimer->hide();
    ui->chk_agreed->hide();
    ui->line->hide();
}

void set_back_detect(bool bo) {
    back_detect = bo;
}
