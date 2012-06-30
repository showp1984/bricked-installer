#include <QtGui>
#include <QtGui/QApplication>

#include "detect.h"
#include "ui_detect.h"

detect::detect(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::detect)
{
    p.setProcessChannelMode(QProcess::MergedChannels);

    detecttimer = new QTimer(this);
    connect(detecttimer, SIGNAL(timeout()), this, SLOT(detect_device()));
    detecttimer->start(5000);

    ui->setupUi(this);
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
    }
}
