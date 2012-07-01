#include "flasher.h"
#include "ui_flasher.h"

flasher::flasher(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::flasher)
{
    list = QStringList() << "" << "" << "" << "" << "" << "" << "";
    list2 = QStringList() << "" << "";
    list3 = QStringList() << "" << "";
    error = false;

    ui->setupUi(this);

    ui->bar_flash->hide();
    ui->bar_flash->setMinimum(0);
    ui->bar_flash->setMaximum(100);
    ui->bar_flash->setValue(0);
}

flasher::~flasher()
{
    delete ui;
    delete this;
}

void flasher::changeEvent(QEvent *e)
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

void flasher::set_snr(QString str)
{
    snr_old = str;
}

void flasher::set_device(QString str)
{
    device = str;
}

void flasher::on_actionQuit_triggered()
{
    this->close();
}

void flasher::on_actionInfo_triggered()
{
    infowind = new Info();
    infowind->show();
}

void flasher::on_btn_quit_clicked()
{
    this->close();
}

void flasher::on_btn_start_clicked()
{
    ui->btn_start->hide();
    ui->btn_quit->setEnabled(false);
    ui->actionQuit->setEnabled(false);
    ui->bar_flash->show();

    ui->txt_out->clear();
//    ui->txt_out->append("Old S/N: " + snr_old + "...");
//    ui->txt_out->append("Checking again...");
    ui->txt_out->append("Sending in GLaDoS...\n");

#ifdef Q_WS_X11
    p.start( "tools/adb devices" );
#endif
#ifdef Q_WS_MAC
    p.start( "tools/adb-mac devices" );
#endif
#ifdef Q_WS_WIN
    p.start( "tools\\adb.exe devices" );
#endif
    p.waitForFinished(-1);
    p_out = p.readAllStandardOutput();

    if (!p_out.isEmpty()) {
        list = p_out.split("\n");
        if (!list.isEmpty()) {
            while (snr.isEmpty()) {
                snr = list.takeLast();
            }
#ifdef Q_WS_WIN
            snr = list.takeLast();
#endif
            if (!snr.isEmpty()) {
                list2 = snr.split("\t");
                if ((!list2.isEmpty()) && (list2.count() > 1)) {
                    snr = list2[0];
                    state = list2[1];
                }
                if (list2.count() == 1) {
                    p.terminate();
                    p_out = "";

#ifdef Q_WS_X11
                    p.start( "tools/fastboot devices" );
#endif
#ifdef Q_WS_MAC
                    p.start( "tools/fastboot-mac devices" );
#endif
#ifdef Q_WS_WIN
                    p.start( "tools\\fastboot.exe devices" );
#endif
                    p.waitForFinished(-1);
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
/*    if (snr_old != snr) {
        error = true;
        ui->txt_out->append("Device S/N has changed!");
        ui->txt_out->append("Old S/N: " + snr_old + ", new S/N: " + snr + "...");
        ui->txt_out->append("\nGo back and detect this device first!");
        return;
    } else {
        ui->txt_out->append("S/N matches. Checking state...");
    }
*/

    ui->bar_flash->setValue(10);

    if (error != true) {
        if (!state.isEmpty()) {
            if (state.contains("fastboot")) {
                 ui->txt_out->append("Device in bootloader, rebooting...");
                 p.terminate();
                 p_out = "";
 #ifdef Q_WS_X11
                 p.start( "tools/fastboot -p " + device + " reboot" );
 #endif
 #ifdef Q_WS_MAC
                 p.start( "tools/fastboot-mac -p " + device + " reboot" );
 #endif
 #ifdef Q_WS_WIN
                 p.start( "tools\\fastboot.exe -p " + device + " reboot" );
 #endif
                 p.waitForFinished(-1);
                 p_out = p.readAllStandardOutput();
                 if (!p_out.isEmpty()) {
                     ui->txt_out->append(p_out);
                     ui->bar_flash->setValue(20);
                 }
            }
            if (state.contains("recovery")) {
                ui->txt_out->append("Device in recovery, rebooting...");
                p.terminate();
                p_out = "";
#ifdef Q_WS_X11
                p.start( "tools/adb -s " + snr + " reboot" );
#endif
#ifdef Q_WS_MAC
                p.start( "tools/adb-mac -s " + snr + " reboot" );
#endif
#ifdef Q_WS_WIN
                p.start( "tools\\adb.exe -s " + snr + " reboot" );
#endif
                p.waitForFinished(-1);
                p_out = p.readAllStandardOutput();
                if (!p_out.isEmpty()) {
                    ui->txt_out->append(p_out);
                    ui->bar_flash->setValue(20);
                }
            }
            if (state.contains("device")) {
                ui->txt_out->append("Device booted, proceeding...");
                ui->bar_flash->setValue(20);
            }
        }
    }
    ui->btn_quit->setEnabled(true);
    ui->actionQuit->setEnabled(true);
}

void flasher::on_txt_out_textChanged()
{
    c = ui->txt_out->textCursor();
    c.movePosition(QTextCursor::End);
    ui->txt_out->setTextCursor(c);
}
