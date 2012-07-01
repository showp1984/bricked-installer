#ifndef OPENFILE_H
#define OPENFILE_H

#include <QMainWindow>
#include <QtGui>
#include <QtGui/QApplication>

#include "info.h"
#include "flasher.h"

namespace Ui {
    class openfile;
}

class openfile : public QMainWindow {
    Q_OBJECT
public:
    openfile(QWidget *parent = 0);
    ~openfile();
    void set_snr(QString);
    void set_device(QString);

protected:
    void changeEvent(QEvent *e);

private:
    Ui::openfile *ui;
    Info *infowind;
    flasher *flasherwind;
    QFileInfo fileInfo;
    QString device;
    QString snr_old;
    QString fileName;
    QString file;

private slots:
    void on_btn_find_clicked();
    void on_btn_go_clicked();
    void on_btn_quit_clicked();
    void on_actionInfo_triggered();
    void on_actionQuit_triggered();
};

#endif // OPENFILE_H
