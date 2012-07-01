#include <QtGui>
#include <QtGui/QApplication>

#include "dragons.h"
#include "ui_dragons.h"
#include "mainwindow.h"

dragons::dragons(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dragons)
{
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(closedragons()));

    ui->setupUi(this);
    ui->lbl_vague->hide();
}

dragons::~dragons()
{
    timer->stop();
    delete timer;
    delete ui;
    delete this;
}

void dragons::changeEvent(QEvent *e)
{
    QDialog::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void dragons::on_btn_yes_clicked()
{
    welcome = new MainWindow();
    welcome->show();
    this->close();
}

void dragons::on_btn_no_clicked()
{
    ui->btn_no->hide();
    ui->btn_yes->hide();
    ui->lbl_warn->hide();
    ui->lbl_vague->show();
    timer->start(3000);
}

void dragons::closedragons(void)
{
    this->close();
}
