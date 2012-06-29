#include <QMessageBox>

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->btn_go->show();
    ui->lbl_welcome->show();
    ui->btn_go_2->hide();
    ui->lbl_disclaimer_accept->hide();
    ui->txt_disclaimer->hide();
    ui->chk_agreed->hide();
}

MainWindow::~MainWindow()
{
    delete ui;
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
        //load new form
    } else {
        QMessageBox alertbox;
        alertbox.setText("You haven't agreed to the terms.");
        alertbox.exec();
    }
}

void MainWindow::on_btn_go_clicked()
{
    //hide label & go, visible label2 and go2
    ui->btn_go->hide();
    ui->lbl_welcome->hide();
    ui->btn_go_2->show();
    ui->lbl_disclaimer_accept->show();
    ui->txt_disclaimer->show();
    ui->chk_agreed->show();
}
