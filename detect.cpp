#include <QtGui>
#include <QtGui/QApplication>

#include "detect.h"
#include "ui_detect.h"

detect::detect(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::detect)
{
    firstcall = true;

    p.setProcessChannelMode(QProcess::MergedChannels);
    p.waitForFinished(5000);

    detecttimer = new QTimer(this);
    connect(detecttimer, SIGNAL(timeout()), this, SLOT(detect_device()));
    detecttimer->start(600);

    list = QStringList() << "" << "" << "" << "" << "" << "";
    list2 = QStringList() << "" << "";

    ui->setupUi(this);

    ui->lbl_detectandroidversion->hide();
    ui->lbl_detectdevice->hide();
    ui->lbl_detectphone->hide();
    ui->lbl_detectromversion->hide();
    ui->lbl_detectsenseversion->hide();
    ui->lbl_detectstate->hide();
    ui->lbl_doneandroid->hide();
    ui->lbl_donedevcode->hide();
    ui->lbl_donephone->hide();
    ui->lbl_donerom->hide();
    ui->lbl_donesense->hide();
    ui->lbl_donestate->hide();
}

detect::~detect()
{
    delete ui;
}

void detect::changeEvent(QEvent *e)
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

void detect::on_actionQuit_triggered()
{
    this->close();
}

void detect::on_actionInfo_triggered()
{
    infowind = new Info();
    infowind->show();
}

void detect::detect_device(void)
{
    if (firstcall) {
            firstcall = false;
            detecttimer->stop();
            detecttimer->start(5000);
    }

    snr = "";

    ui->bar_detectphone->setMinimum(0);
    ui->bar_detectphone->setMaximum(0);
    ui->bar_detectphone->setValue(-1);

    ui->lbl_detectphone->show();
    ui->lbl_detectstate->show();

    p.start( "tools/adb devices" );
    p.waitForFinished(4000);
    p_out = p.readAllStandardOutput();

    if (!p_out.isEmpty()) {
        list = p_out.split("\n");
        if (!list.isEmpty()) {
            while (snr.isEmpty()) {
                snr = list.takeLast();
            }
            if (!snr.isEmpty()) {
                list2 = snr.split("\t");
                if ((!list2.isEmpty()) && (list2.count() > 1)) {
                    snr = list2[0];
                    state = list2[1];
                }
            }
        }
    }
    if (!snr.isEmpty() && !state.isEmpty()) {
        detecttimer->stop();
        ui->bar_detectphone->setMinimum(0);
        ui->bar_detectphone->setMaximum(100);
        ui->bar_detectphone->setValue(31);

        ui->lbl_donephone->show();
        ui->lbl_donestate->show();

        p.terminate();
        p_out = "";

        ui->lbl_detectdevice->show();

        p.start( "tools/adb shell getprop ro.product.model" );
        p.waitForFinished(4000);
        p_out = p.readAllStandardOutput();

        if (!p_out.isEmpty()) {
            model = p_out;
            ui->bar_detectphone->setValue(46);

            p.terminate();
            p_out = "";

            p.start( "tools/adb shell getprop ro.product.device" );
            p.waitForFinished(4000);
            p_out = p.readAllStandardOutput();

            if (!p_out.isEmpty()) {
                device = p_out;
                ui->lbl_donedevcode->show();
                ui->bar_detectphone->setValue(62);
            }
        }

        p.terminate();
        p_out = "";

        ui->lbl_detectromversion->show();

        p.start( "tools/adb shell getprop ro.product.version" );
        p.waitForFinished(4000);
        p_out = p.readAllStandardOutput();

        if (!p_out.isEmpty()) {
            romver = p_out;
            ui->lbl_donerom->show();
            ui->bar_detectphone->setValue(77);
        }

        p.terminate();
        p_out = "";

        ui->lbl_detectandroidversion->show();

        p.start( "tools/adb shell getprop ro.product.release" );
        p.waitForFinished(4000);
        p_out = p.readAllStandardOutput();

        if (!p_out.isEmpty()) {
            androidver = p_out;
            ui->lbl_doneandroid->show();
            ui->bar_detectphone->setValue(83);
        }

        p.terminate();
        p_out = "";

        ui->lbl_detectsenseversion->show();

        p.start( "tools/adb shell getprop ro.product.sense.version" );
        p.waitForFinished(4000);
        p_out = p.readAllStandardOutput();

        if (!p_out.isEmpty()) {
            sensever = p_out;
            ui->lbl_donesense->show();
            ui->bar_detectphone->setValue(100);
        }
    }
    p.terminate();
}
