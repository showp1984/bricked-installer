#ifndef DETECT_H
#define DETECT_H

#include <QMainWindow>
#include <QtGui>
#include <QtGui/QApplication>

#include "info.h"
#include "openfile.h"

namespace Ui {
    class detect;
}

class detect : public QMainWindow {
    Q_OBJECT
public:
    detect(QWidget *parent = 0);
    ~detect();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::detect *ui;
    Info *infowind;
    openfile *openfilewind;
    QTimer *detecttimer;
    QProcess p;
    QStringList list;
    QStringList list2;
    QStringList list3;
    QStringList list4;
    QStringList list5;
    QString p_out;
    QString snr;
    QString state;
    QString model;
    QString device;
    QString romver;
    QString androidver;
    QString branchver;
    QString kernelbuildver;
    QString kernelver;
    bool firstcall;

private slots:
    void on_btn_back_clicked();
    void on_btn_yes_clicked();
    void on_btn_no_clicked();
    void on_btn_quit_clicked();
    void on_actionInfo_triggered();
    void on_actionQuit_triggered();
    void detect_device(void);
};

#endif // DETECT_H
