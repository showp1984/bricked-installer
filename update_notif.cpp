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
#include <QSqlError>

#include "quazip/quazip.h"
#include "quazip/quazipfile.h"
#include "quazip/JlCompress.h"

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
    QString ver;

    qDebug() << "Local: " << qApp->applicationVersion();

    query.prepare("SELECT version, branch, changelog, date, url FROM hp_downloads WHERE cat='installer' AND version > " + qApp->applicationVersion() + "ORDER BY version DESC LIMIT 1");
    query.exec();
    while (query.next()) {
        version = query.value(0).toFloat();
        ver = QString::number(version);
        branch = query.value(1).toString();
        changelog = query.value(2).toString();
        date = query.value(3).toString();
        url = query.value(4).toString();
        url = url.replace(QString("%%%VERSION%%%"), ver);
#ifdef Q_WS_X11
        url = url.replace(QString("%%%SHORT_PLATFORM%%%"), QString("lnx"));
#endif
#ifdef Q_WS_MAC
        url = url.replace(QString("%%%SHORT_PLATFORM%%%"), QString("mac"));
#endif
#ifdef Q_WS_WIN
        url = url.replace(QString("%%%SHORT_PLATFORM%%%"), QString("win"));
#endif
#ifdef Q_WS_X11
        url = url.replace(QString("%%%PLATFORM%%%"), QString("LINUX"));
#endif
#ifdef Q_WS_MAC
        url = url.replace(QString("%%%PLATFORM%%%"), QString("MACOS"));
#endif
#ifdef Q_WS_WIN
        url = url.replace(QString("%%%PLATFORM%%%"), QString("WINDOWS"));
#endif
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

    QUrl qurl(p_dbupd->url);
    QString filename = QFileInfo(qurl.path()).fileName();
    downfilepath = qApp->applicationDirPath() + "/" + filename;

    if(QFile::exists(downfilepath)) {
        if(QMessageBox::question(this, tr("Updater: Download"),
                tr("There already exists a file called %1 in "
                "the current directory. Overwrite?").arg(downfilepath),
                QMessageBox::Yes|QMessageBox::No, QMessageBox::No)
                == QMessageBox::No) {
            cancelDownload();
            return;
        }
            QFile::remove(downfilepath);
    }

    file = new QFile(downfilepath);
    if(!file->open(QIODevice::WriteOnly)) {
        QMessageBox::information(this, "Updater: Download",
                tr("Unable to save the file %1: %2.")
                .arg(downfilepath).arg(file->errorString()));
        cancelDownload();
        delete file;
        file = NULL;
        return;
    }

    QString ver;
    QSqlDatabase db = connectDB();
    QSqlQuery query;
    ver = QString::number(p_dbupd->version);
    query.prepare("UPDATE hp_downloads SET nrdowns = nrdowns + 1 WHERE version = " + ver);
    query.exec();
    db.close();
    db.removeDatabase("default");

    downloadRequestAborted = false;
    reply = manager.get(QNetworkRequest(qurl));
    connect(reply, SIGNAL(finished()), this, SLOT(downloadFinished()));
    connect(reply, SIGNAL(readyRead()), this, SLOT(downloadReadyRead()));
    connect(reply, SIGNAL(downloadProgress(qint64,qint64)), this, SLOT(downloadProgress(qint64,qint64)));
}

void update_notif::downloadProgress(qint64 bytesReceived, qint64 bytesTotal)
{
    if(downloadRequestAborted)
        return;
    ui->bar2_downl->setMaximum(bytesTotal);
    ui->bar2_downl->setValue(bytesReceived);
}

void update_notif::downloadReadyRead()
{
    if(file)
        file->write(reply->readAll());
}

void update_notif::cancelDownload()
{
    downloadRequestAborted = true;
    reply->abort();
    ui->btn_now->show();
}

void update_notif::downloadFinished()
{
    bool error = false;
    if(downloadRequestAborted) {
        if(file) {
            file->close();
            file->remove();
            delete file;
            file = NULL;
        }
        reply->deleteLater();
        ui->btn_later->show();
        ui->btn_now->show();
        ui->btn_quit->show();
        ui->lbl_branch->show();
        ui->lbl_change->show();
        ui->lbl_date->show();
        ui->lbl_edt_branch->show();
        ui->lbl_edt_date->show();
        ui->lbl_edt_vers->show();
        ui->lbl_updnot->show();
        ui->lbl_vers->show();
        ui->txt_change->show();

        ui->lbl2_restart->hide();
        ui->lbl2_updating->hide();
        ui->lbl2_warn->hide();
        ui->lbl2_xtr->hide();
        ui->bar2_xtr->hide();
        ui->bar2_downl->hide();
        return;
    }

    downloadReadyRead();
    file->flush();
    file->close();

    if(reply->error()) {
        //Download failed
        QMessageBox::information(this, "Download failed", tr("Failed: %1").arg(reply->errorString()));
        cancelDownload();
        downloadFinished();
        error = true;
    }

    reply->deleteLater();
    reply = NULL;
    delete file;
    file = NULL;

    if(!error)
        rename_files();
}

void update_notif::rename_files(void)
{
    QDir dir(qApp->applicationDirPath());
    QString fPath;
    QString fPath_ren;

    if (dir.exists(qApp->applicationDirPath())) {
        Q_FOREACH(QFileInfo info, dir.entryInfoList(QDir::NoDotAndDotDot | QDir::System | QDir::Hidden  | QDir::AllDirs | QDir::Files, QDir::DirsFirst)) {
            if ((!info.isDir()) && (info.absoluteFilePath() != downfilepath)) {
                fPath = info.absoluteFilePath();
                qDebug() << fPath;

                fPath_ren = fPath;
                fPath_ren += "_old";
                qDebug() << fPath_ren;

                oldname = fPath_ren;
                dir.rename(fPath, fPath_ren);
            }
        }
    }
    extract_files();
}

bool update_notif::rmdir_recursive_notparent(const QString &dirName)
{
    bool result = true;
    QDir dir(dirName);
    QString namedir;

    p.terminate();
#ifdef Q_WS_X11
    p.start( "tools/adb kill-server" );
#endif
#ifdef Q_WS_MAC
    p.start( "tools/adb-mac kill-server" );
#endif
#ifdef Q_WS_WIN
    p.start( "tools\\adb.exe kill-server" );
#endif
    p.waitForFinished(4000);

#ifdef Q_WS_X11
    namedir = qApp->applicationDirPath() + "/" + "Bricked-Installer";
#endif
#ifdef Q_WS_MAC
    namedir = qApp->applicationDirPath() + "/" + "Bricked-Installer";
#endif
#ifdef Q_WS_WIN
    namedir = qApp->applicationDirPath() + "/" + "Bricked-Installer.exe";
#endif
    namedir += "_old";

    if (dir.exists(dirName)) {
        Q_FOREACH(QFileInfo info, dir.entryInfoList(QDir::NoDotAndDotDot | QDir::System | QDir::Hidden  | QDir::AllDirs | QDir::Files, QDir::DirsFirst)) {
            if (info.isDir()) {
                if (info.absoluteFilePath() != dirName) {
                    result = rmdir_recursive_notparent(info.absoluteFilePath());
                }
            }
            else {
                if ((info.absoluteFilePath() != namedir) && (info.absoluteFilePath() != downfilepath) && (!info.absoluteFilePath().contains(QString(".dll_old"))) && (!info.absoluteFilePath().contains(QString(".exe_old")))) {
                    result = QFile::remove(info.absoluteFilePath());
                }
            }
            if (!result) {
                return result;
            }
        }
#ifdef Q_WS_WIN
        if (QString(qApp->applicationDirPath() + "/") != dirName) {
#else
        if (QString(qApp->applicationDirPath() + "/") != dirName) {
#endif
            result = dir.rmdir(dirName);
        } else {
            result = true;
        }
    }
    return result;
}

bool update_notif::extract_zip(const QString & filePath)
{
    ui->bar2_xtr->show();

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
    QString basepath = qApp->applicationDirPath();
    QByteArray cnt;
    QDir filedir;
    QString temppath;
    QStringList splitpath = QStringList() << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << "" << "";
    int filenr = 0;
    ui->bar2_xtr->setMaximum(zip.getEntriesCount());
    for (bool more = zip.goToFirstFile(); more; more = zip.goToNextFile()) {
        if (!zip.getCurrentFileInfo(&info)) {
            qWarning("testRead(): getCurrentFileInfo(): %d\n", zip.getZipError());
            return false;
        }
        if (!file.open(QuaZipFile::ReadOnly)) {
            qWarning("testRead(): file.open(): %d", file.getZipError());
            return false;
        }
        splitpath = file.getActualFileName().split("/");
        temppath = splitpath.takeLast();
        temppath = splitpath.join("/");
        abspath = QString("%1/%2").arg(basepath).arg(temppath);
        name = QString("%1/%2").arg(basepath).arg(file.getActualFileName());

        if (file.getZipError() != UNZ_OK) {
            qWarning("testRead(): file.getFileName(): %d", file.getZipError());
            return false;
        }

        filedir.setPath(abspath);
        if (!filedir.exists()) {
            filedir.mkpath(abspath);
        }

        out.setFileName(name);
        cnt=file.readAll();
        qDebug()<<"name: "<<name;
        qDebug()<<"writing "<<cnt.size()<<" bytes";
        out.open(QIODevice::WriteOnly);
        out.write(cnt);
        out.close();
        if (out.fileName().contains(QString("adb")) || out.fileName().contains(QString("fastboot")) || out.fileName().contains(QString("perl"))) {
            bool ret = false;
            ret = QFile::setPermissions(out.fileName(), QFile::ReadOwner|QFile::WriteOwner|QFile::ExeOwner|QFile::ReadGroup|QFile::ExeGroup|QFile::ReadOther|QFile::ExeOther);
            qDebug() << "Extract perms set: " << ret << endl;
        }


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
        ui->bar2_xtr->setValue(filenr);
        filenr++;
    }
    zip.close();
    if (zip.getZipError() != UNZ_OK) {
        qWarning("testRead(): zip.close(): %d", zip.getZipError());
        return false;
    }
    return true;
}

void update_notif::extract_files(void)
{
    bool ret = false;

    ret = rmdir_recursive_notparent(QString(qApp->applicationDirPath() + "/"));
    if (!ret) {
        QMessageBox::information(this, "Update failed!", tr("Error! Could not delete old files! You are required to redownload the application from www.bricked.de"));
        qApp->closeAllWindows();
        this->close();
    }
    ret = false;

    ui->lbl2_xtr->show();

    ret = extract_zip(downfilepath);

    if (ret) {
        ui->bar2_xtr->setMinimum(0);
        ui->bar2_xtr->setMaximum(1);
        ui->bar2_xtr->setValue(1);
        QMessageBox::information(this, "Update sucessfull!", tr("The update was successfull. I will now restart to the new version."));
        ui->lbl2_restart->show();
        ui->lbl2_warn->hide();
        QTimer::singleShot(2000, this, SLOT(restart_app()));
    } else {
        QMessageBox::information(this, "Update failed", tr("The update failed. You are required to redownload the application from www.bricked.de"));
        qApp->closeAllWindows();
        this->close();
    }
}

void update_notif::restart_app(void)
{
    QString appname;
#ifdef Q_WS_X11
    appname = qApp->applicationDirPath() + "/" + "Bricked-Installer";
#endif
#ifdef Q_WS_MAC
    appname = qApp->applicationDirPath() + "/" + "Bricked-Installer";
#endif
#ifdef Q_WS_WIN
    appname = qApp->applicationDirPath() + "/" + "Bricked-Installer.exe";
#endif
    QString oldappname = appname;
    oldappname += "_old";

    //Get file permissions of old binary
    QFile::Permissions oldperm;
    oldperm = QFile::permissions(QString(oldappname));

    //Set file permissions of new binary
    bool ret = false;
    ret = QFile::setPermissions(appname, oldperm);
    qDebug() << "Perms set: " << ret << endl;

    p.terminate();
    p.startDetached( appname );
    p.waitForFinished(-1);
    this->close();
    qApp->closeAllWindows();
    qApp->exit();
}
