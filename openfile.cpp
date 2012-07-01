#include "openfile.h"
#include "ui_openfile.h"

openfile::openfile(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::openfile)
{
    ui->setupUi(this);
}

openfile::~openfile()
{
    delete ui;
    delete this;
}

void openfile::changeEvent(QEvent *e)
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

void openfile::set_snr(QString str)
{
    snr_old = str;
}

void openfile::set_device(QString str)
{
    device = str;
}

void openfile::on_actionQuit_triggered()
{
    this->close();
}

void openfile::on_actionInfo_triggered()
{
    infowind = new Info();
    infowind->show();
}

void openfile::on_btn_quit_clicked()
{
    this->close();
}

void openfile::on_btn_go_clicked()
{
    flasherwind = new flasher();
    flasherwind->set_snr(snr_old);
    flasherwind->set_device(device);
    flasherwind->set_filename(filename);
    flasherwind->show();
    this->close();
}

void openfile::on_btn_find_clicked()
{
    file = QFileDialog::getOpenFileName(this, tr("Open File"), "", tr("Files (*.*)"));
    if (!file.isEmpty()) {
        ui->edt_filename->setText(file);
        fileinfo = file;
        filename = fileinfo.filename();
    }
}
