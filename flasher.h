#ifndef FLASHER_H
#define FLASHER_H

#include <QMainWindow>
#include <QtGui>
#include <QtGui/QApplication>

#include "info.h"

namespace Ui {
    class flasher;
}

class flasher : public QMainWindow {
    Q_OBJECT
public:
    flasher(QWidget *parent = 0);
    ~flasher();
    void set_snr(QString);
    void set_state(QString);

protected:
    void changeEvent(QEvent *e);

private:
    Ui::flasher *ui;
    Info *infowind;
    QTextCursor c;
    QProcess p;
    bool error;
    QStringList list;
    QStringList list2;
    QStringList list3;
    QString p_out;
    QString snr_old;
    QString state_old;
    QString snr;
    QString state;

private slots:
    void on_txt_out_textChanged();
    void on_btn_start_clicked();
    void on_btn_quit_clicked();
    void on_actionInfo_triggered();
    void on_actionQuit_triggered();
};

#endif // FLASHER_H
