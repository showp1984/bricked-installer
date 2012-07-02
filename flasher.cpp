#include "flasher.h"
#include "ui_flasher.h"
#include "openfile.h"

#include "quazip/quazip.h"
#include "quazip/quazipfile.h"
#include "quazip/JlCompress.h"

flasher::flasher(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::flasher)
{
    firstcall_push = true;

    flashtimer = new QTimer(this);
    connect(flashtimer, SIGNAL(timeout()), this, SLOT(flash_device()));

    list = QStringList() << "" << "" << "" << "" << "" << "" << "";
    list2 = QStringList() << "" << "";
    list3 = QStringList() << "" << "";
    error = false;

    ui->setupUi(this);

    ui->bar_flash->hide();
    ui->bar_flash->setMinimum(0);
    ui->bar_flash->setMaximum(90);
    ui->bar_flash->setValue(0);

    ui->bar_extract->hide();
    ui->bar_extract->setMinimum(0);
    ui->bar_extract->setMaximum(100);
    ui->bar_extract->setValue(0);

    ui->txt_out->hide();
}

flasher::~flasher()
{
    flashtimer->stop();
    delete flashtimer;
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

void flasher::set_filename(QString str)
{
    filename = str;
    ui->lbl_edt_filename->setText(filename);
}

void flasher::set_filepath(QString str)
{
    filepath = str;
    ui->edt_filepath->setText(filepath);
}

void flasher::set_type(int integer)
{
    type = integer;
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
    ui->txt_out->show();
    ui->btn_quit->setEnabled(false);
    ui->actionQuit->setEnabled(false);
    ui->bar_flash->show();

    ui->txt_out->clear();
    ui->txt_out->append("Wake up, daddy's home...");
    ui->txt_out->append("JARVIS: Welcome home, sir!");
    ui->txt_out->append("JARVIS: Starting automated flashing procedure.");

    if (type == KERNEL) {
        ui->txt_out->append("JARVIS: switching to Kernel flashing mode...\n");
    } else if (type == ROM) {
        ui->txt_out->append("JARVIS: switching to ROM flashing mode...\n");
    }

    flash_state = EXTRACT;
    firstcall = true;
    flashtimer->start(0);
}

void flasher::on_txt_out_textChanged()
{
    c = ui->txt_out->textCursor();
    c.movePosition(QTextCursor::End);
    ui->txt_out->setTextCursor(c);
}

bool flasher::extract_zip(const QString & filePath, const QString & extDirPath, const QString & singleFileName = QString(""))
{
    ui->bar_extract->show();

    QuaZip zip(filePath);

    if (!zip.open(QuaZip::mdUnzip)) {
        qWarning("testRead(): zip.open(): %d", zip.getZipError());
        return false;
    }

    zip.setFileNameCodec("IBM866");

    qWarning("%d entries\n", zip.getEntriesCount());
    qWarning("Global comment: %s\n", zip.getComment().toLocal8Bit().constData());

    QuaZipFileInfo info;

    QuaZipFile file(&zip);

    QFile out;
    QString name;
    QString temppath;
    QString basepath = qApp->applicationDirPath();
    QStringList splitpath = QStringList() << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << "";
    QByteArray cnt;
    QDir filedir;
    int filenr = 0;
    ui->bar_extract->setMaximum(zip.getEntriesCount());
    for (bool more = zip.goToFirstFile(); more; more = zip.goToNextFile()) {
        if (!zip.getCurrentFileInfo(&info)) {
            qWarning("testRead(): getCurrentFileInfo(): %d\n", zip.getZipError());
            return false;
        }
        if (!singleFileName.isEmpty())
            if (!info.name.contains(singleFileName))
                continue;
        if (!file.open(QuaZipFile::ReadOnly)) {
            qWarning("testRead(): file.open(): %d", file.getZipError());
            return false;
        }
        splitpath = file.getActualFileName().split("/");
        temppath = splitpath.takeLast();
        temppath = splitpath.join("/");
        abstemppath = QString("%1/%2/%3").arg(basepath).arg(extDirPath).arg(temppath);
        name = QString("%1/%2/%3").arg(basepath).arg(extDirPath).arg(file.getActualFileName());

        if (file.getZipError() != UNZ_OK) {
            qWarning("testRead(): file.getFileName(): %d", file.getZipError());
            return false;
        }

        filedir.setPath(abstemppath);
        if (!filedir.exists()) {
            filedir.mkpath(abstemppath);
        }

        out.setFileName(name);
        cnt=file.readAll();
        qDebug()<<"name: "<<name;
        qDebug()<<"writing "<<cnt.size()<<" bytes";
        out.open(QIODevice::WriteOnly);
        out.write(cnt);
        out.close();

        if (file.getZipError() != UNZ_OK) {
            qWarning("testRead(): file.getFileName(): %d", file.getZipError());
            return false;
        }

        if (!file.atEnd()) {
            qWarning("testRead(): read all but not EOF");
            return false;
        }

        file.close();

        if (file.getZipError() != UNZ_OK) {
            qWarning("testRead(): file.close(): %d", file.getZipError());
            return false;
        }
        ui->bar_extract->setValue(filenr);
        filenr++;
    }
    zip.close();
    if (zip.getZipError() != UNZ_OK) {
        qWarning("testRead(): zip.close(): %d", zip.getZipError());
        return false;
    }
    return true;
}

bool flasher::rmdir_recursive(const QString &dirName)
{
    bool result = true;
    QDir dir(dirName);

    if (dir.exists(dirName)) {
        Q_FOREACH(QFileInfo info, dir.entryInfoList(QDir::NoDotAndDotDot | QDir::System | QDir::Hidden  | QDir::AllDirs | QDir::Files, QDir::DirsFirst)) {
            if (info.isDir()) {
                result = rmdir_recursive(info.absoluteFilePath());
            }
            else {
                result = QFile::remove(info.absoluteFilePath());
            }
            if (!result) {
                return result;
            }
        }
        result = dir.rmdir(dirName);
    }
    return result;
}


void flasher::flash_device(void)
{
    bool ret;

    if (firstcall) {
            firstcall = false;
    } else {
        flashtimer->setInterval(1000);
    }
    /*
     * Available flash_states:
     *
     * EXTRACT = 0,
     * DETECT,
     * GET_BOOTED,
     * CHECK_SNR,
     * PUSH_FILES,
     * REBOOT_FASTBOOT,
     * FLASH_BOOTIMG,
     * CHECK_INSTALL,
     * RELEASE_CONTROLS,
     */
    switch (flash_state)
    {
    case EXTRACT:
        ui->bar_flash->setValue(10);
        flash_state = extract();
        break;
    case DETECT:
        flash_state = detect_device();
        ui->bar_flash->setValue(20);
        break;
    case GET_BOOTED:
        flash_state = get_booted();
        break;
    case CHECK_SNR:
        ui->txt_out->append("Checking if S/N changed...");
        if (snr_old != snr) {
            ui->txt_out->append("Device S/N has changed!");
            ui->txt_out->append("Old S/N: " + snr_old + ", new S/N: " + snr + "...");
            ui->txt_out->append("\nGo back and detect this device first!");
            flash_state = RELEASE_CONTROLS;
        } else {
            ui->txt_out->append("S/N matches. Checking state...");
        }
        ui->bar_flash->setValue(40);
        break;
    case PUSH_FILES:
        push_files();
        ui->bar_flash->setValue(50);
        break;
    case REBOOT_FASTBOOT:
        flash_state = reboot_fastboot();
        ui->bar_flash->setValue(60);
        break;
    case FLASH_BOOTIMG:
        flash_state = flash_boot();
        ui->bar_flash->setValue(70);
        break;
    case CHECK_INSTALL:
        ui->bar_flash->setValue(80);
        break;
    case RELEASE_CONTROLS:
        ui->txt_out->append("Doing some cleanup...");
        ret = rmdir_recursive(QString(qApp->applicationDirPath() + "/" + tmp_folder));
        if (!ret) {
            ui->txt_out->append("Error! Could not delete temporary directory: " + tmp_folder);
        } else {
            ui->txt_out->append("Deleted temporary directory: " + tmp_folder);
        }
        ui->bar_flash->setValue(90);
        flashtimer->stop();
        ui->btn_quit->setEnabled(true);
        ui->actionQuit->setEnabled(true);
        ui->txt_out->append("Installation finished...");
        break;
    default:
        break;
    }
}

int flasher::extract(void)
{
    unsigned int rnd = 0, max = 999999;
    bool success = false, xtr_return = false;

    while (!success) {
        rnd = qrand() % max;
        tmp_folder = QString("%1").arg(rnd);
        if (!QDir(tmp_folder).exists()) {
            QDir().mkdir(tmp_folder);
            success = true;
        }
    }
    ui->txt_out->append("Created temporary directory: " + tmp_folder);

    xtr_return = extract_zip(filepath, tmp_folder);

    if (!xtr_return) {
        ui->txt_out->append("Error! Could not extract zip file.");
        return RELEASE_CONTROLS;
    } else {
        ui->txt_out->append("Successfully extracted zip file.");
        ui->bar_extract->hide();
        return DETECT;
    }
}

int flasher::detect_device(void) {
    ui->txt_out->append("< Waiting for your device >");
    flashtimer->setInterval(6000);
    p.terminate();
    p_out = "";
    snr = "";
    state = "";
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
    if (!snr.isEmpty() && !state.isEmpty()) {
        flashtimer->setInterval(1000);
        return GET_BOOTED;
    }
    flashtimer->setInterval(6000);
    return DETECT;
}

int flasher::get_booted(void) {
    if (!state.isEmpty()) {
        ui->txt_out->append("Detecting device state...");
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
            p.waitForFinished(1000);
            p_out = p.readAllStandardOutput();
            if (!p_out.isEmpty()) {
                ui->txt_out->append(p_out);
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
            }
        }
        if (state.contains("device")) {
            ui->txt_out->append("Device booted, proceeding...");
            ui->bar_flash->setValue(30);
            return PUSH_FILES;
        }
       /* return CHECK_SNR;
        * we can't use this since the bootloader sometimes shows
        * '????????????' on unlocked devices. Skip this check for
        * now.
        */
        return DETECT;
    }
    return DETECT;
}

void flasher::push_files(void)
{
    if (firstcall_push) {
        firstcall_push = false;

        ui->txt_out->append("Grabbing root...");
        p.terminate();
        p_out = "";
#ifdef Q_WS_X11
        p.start( "tools/adb -s " + snr + " root");
#endif
#ifdef Q_WS_MAC
        p.start( "tools/adb-mac -s " + snr + " root");
#endif
#ifdef Q_WS_WIN
        p.start( "tools\\adb.exe -s " + snr + " root");
#endif
        p.waitForFinished(-1);
        p_out = p.readAllStandardOutput();
        if (!p_out.isEmpty()) {
            ui->txt_out->append(p_out);
        }
    
        ui->txt_out->append("Remount /system with r/w...");
        p.terminate();
        p_out = "";
#ifdef Q_WS_X11
        p.start( "tools/adb -s " + snr + " remount");
#endif
#ifdef Q_WS_MAC
        p.start( "tools/adb-mac -s " + snr + " remount");
#endif
#ifdef Q_WS_WIN
        p.start( "tools\\adb.exe -s " + snr + " remount");
#endif
        p.waitForFinished(-1);
        p_out = p.readAllStandardOutput();
        if (!p_out.isEmpty()) {
            ui->txt_out->append(p_out);
        }
        ui->txt_out->append("Searching for modules...");
        PushWorker *pworker = new PushWorker();
        pworker->set_snr(snr);
        pworker->set_abstemppath(abstemppath);
        QObject::connect(pworker,
                         SIGNAL(finished()),
                         this,
                         SLOT(push_files_finished()));
        ui->txt_out->append("Pushing modules... (may take a minute)");
        pworker->start();
    }
}

void flasher::push_files_finished(void) {
    ui->txt_out->append("Modules pushed...");
    flash_state = REBOOT_FASTBOOT;
}

void PushWorker::run(void)
{
    QProcess p;
    QDirIterator it(QString(abstemppath), QDirIterator::Subdirectories);
    while (it.hasNext()) {
        if (it.next().contains(".ko") && !it.next().isEmpty()) {
            p.terminate();
#ifdef Q_WS_X11
            p.start( "tools/adb -s " + snr + " push " + it.next() + " /system/lib/modules/");
#endif
#ifdef Q_WS_MAC
            p.start( "tools/adb-mac -s " + snr + " push " + it.next() + " /system/lib/modules/");
#endif
#ifdef Q_WS_WIN
            p.start( "tools\\adb.exe -s " + snr + " push " + it.next() + " /system/lib/modules/");
#endif
            p.waitForFinished(-1);
        }
    }
    this->finished();
    this->quit();
}

void PushWorker::set_snr(QString str)
{
    snr = str;
}

void PushWorker::set_abstemppath(QString str)
{
    abstemppath = str;
}

int flasher::reboot_fastboot(void)
{
    ui->txt_out->append("Rebooting device to fastboot...");
    p.terminate();
    p_out = "";
#ifdef Q_WS_X11
    p.start( "tools/adb -s " + snr + " reboot-bootloader" );
#endif
#ifdef Q_WS_MAC
    p.start( "tools/adb-mac -s " + snr + " reboot-bootloader" );
#endif
#ifdef Q_WS_WIN
    p.start( "tools\\adb.exe -s " + snr + " reboot-bootloader" );
#endif
    p.waitForFinished(-1);
    p_out = p.readAllStandardOutput();
    if (!p_out.isEmpty()) {
        ui->txt_out->append(p_out);
    }
    return FLASH_BOOTIMG;
}

int flasher::flash_boot(void)
{
    ui->txt_out->append("Flashing boot.img...");
    QDirIterator it(QString(abstemppath), QDirIterator::Subdirectories);
    while (it.hasNext()) {
        if (it.next().contains("boot.img") && !it.next().isEmpty()) {
            p.terminate();
            p_out = "";
#ifdef Q_WS_X11
            p.start( "tools/fastboot -d " + device + " flash boot " + it.next());
#endif
#ifdef Q_WS_MAC
            p.start( "tools/fastboot-mac -d " + device + " flash boot " + it.next());
#endif
#ifdef Q_WS_WIN
            p.start( "tools\\fastboot.exe -d " + device + " flash boot " + it.next());
#endif
            p.waitForFinished(-1);
            p_out = p.readAllStandardOutput();
            if (!p_out.isEmpty()) {
                ui->txt_out->append(p_out);
            }
        }
    }
    ui->txt_out->append("boot.img flashed...");
    ui->txt_out->append("Rebooting device...");
    p.terminate();
    p_out = "";
#ifdef Q_WS_X11
    p.start( "tools/fastboot -d " + device + " reboot");
#endif
#ifdef Q_WS_MAC
    p.start( "tools/fastboot-mac -d " + device + " reboot");
#endif
#ifdef Q_WS_WIN
    p.start( "tools\\fastboot.exe -d " + device + " reboot");
#endif
    p.waitForFinished(-1);
    p_out = p.readAllStandardOutput();
    if (!p_out.isEmpty()) {
        ui->txt_out->append(p_out);
    }
    return RELEASE_CONTROLS;
}
