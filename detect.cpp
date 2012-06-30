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

    list = QStringList() << "" << "" << "" << "" << "" << "" << "";
    list2 = QStringList() << "" << "";
    list3 = QStringList() << "" << "";
    list4 = QStringList() << "" << "" << "" << "" << "" << "";
    list5 = QStringList() << "" << "";

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

    ui->lbl_found->hide();
    ui->lbl_snr->hide();
    ui->lbl_state->hide();
    ui->lbl_name->hide();
    ui->lbl_device->hide();
    ui->lbl_romver->hide();
    ui->lbl_androver->hide();
    ui->lbl_sensever->hide();

    ui->lbl_qcorrect->hide();
    ui->btn_no->hide();
    ui->btn_yes->hide();
}

detect::~detect()
{
    delete detecttimer;
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
                ui->lbl_detectstate->show();
                if ((!list2.isEmpty()) && (list2.count() > 1)) {
                    snr = list2[0];
                    state = list2[1];
                }
                if (list2.count() == 1) {
                    p.terminate();
                    p_out = "";

                    p.start( "tools/fastboot devices" );
                    p.waitForFinished(4000);
                    p_out = p.readAllStandardOutput();

                    if (!p_out.isEmpty()) {
                        list3 = p_out.split("\t");
                        if ((!list3.isEmpty()) && (list3.count() > 1)) {
                            snr = list3[0];
                            state = list3[1];
                        }
                    }
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

        if (state.contains("device") || state.contains("recovery")) {

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

            p.start( "tools/adb shell getprop ro.build.version.release" );
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

            p.start( "tools/adb shell getprop ro.build.sense.version" );
            p.waitForFinished(4000);
            p_out = p.readAllStandardOutput();

            if (!p_out.isEmpty()) {
                sensever = p_out;
                ui->lbl_donesense->show();
            }
            ui->lbl_device->show();
            ui->lbl_name->show();
            ui->lbl_romver->show();
            ui->lbl_androver->show();
            ui->lbl_sensever->show();

            ui->lbl_edt_device->setText(device);
            ui->lbl_edt_model->setText(model);
            ui->lbl_edt_romver->setText(romver);
            ui->lbl_edt_androidver->setText(androidver);
            ui->lbl_edt_sensever->setText(sensever);
        } else if (state.contains("bootloader") || state.contains("fastboot")) {
            p.terminate();
            p_out = "";

            ui->lbl_detectdevice->show();

            p.start( "tools/fastboot getvar product" );
            p.waitForFinished(4000);
            p_out = p.readAllStandardOutput();

            if (!p_out.isEmpty()) {
                list4 = p_out.split("\n");
                if (!list4.isEmpty()) {
                    while (device.isEmpty()) {
                        device = list4.takeLast();
                    }
                    device = list4.takeLast();
                    if (!device.isEmpty()) {
                        list5 = device.split(": ");
                        if ((!list5.isEmpty()) && (list5.count() > 1)) {
                            device = list5[1];
                            ui->lbl_donedevcode->show();
                        }
                    }
                }
                ui->lbl_device->show();
                ui->lbl_edt_device->setText(device);
            }
        }
        ui->bar_detectphone->setValue(100);
        ui->lbl_found->show();
        ui->lbl_snr->show();
        ui->lbl_state->show();

        ui->lbl_qcorrect->show();
        ui->btn_no->show();
        ui->btn_yes->show();

        ui->lbl_edt_snr->setText(snr);

        if (state == "device") {
            state = "booted";
        }
        ui->lbl_edt_state->setText(state);
    }
    p.terminate();
}

void detect::on_btn_quit_clicked()
{
    this->close();
}

void detect::on_btn_no_clicked()
{
    firstcall = true;

    detecttimer->start(600);

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

    ui->bar_detectphone->setMinimum(0);
    ui->bar_detectphone->setMaximum(0);
    ui->bar_detectphone->setValue(-1);

    ui->lbl_found->hide();
    ui->lbl_snr->hide();
    ui->lbl_state->hide();
    ui->lbl_name->hide();
    ui->lbl_device->hide();
    ui->lbl_romver->hide();
    ui->lbl_androver->hide();
    ui->lbl_sensever->hide();

    ui->lbl_qcorrect->hide();
    ui->btn_no->hide();
    ui->btn_yes->hide();

    ui->lbl_edt_snr->setText("");
    ui->lbl_edt_model->setText("");
    ui->lbl_edt_device->setText("");
    ui->lbl_edt_romver->setText("");
    ui->lbl_edt_androidver->setText("");
    ui->lbl_edt_sensever->setText("");
    ui->lbl_edt_state->setText("");

    p_out = "";
    snr = "";
    state = "";
    model = "";
    device = "";
    romver = "";
    androidver = "";
    sensever = "";
}
