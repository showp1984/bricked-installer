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

protected:
    void changeEvent(QEvent *e);

private:
    Ui::flasher *ui;
    Info *infowind;
    QTextCursor *c;

private slots:
    void on_txt_out_textChanged();
    void on_btn_start_clicked();
    void on_btn_quit_clicked();
    void on_actionInfo_triggered();
    void on_actionQuit_triggered();
};

#endif // FLASHER_H
