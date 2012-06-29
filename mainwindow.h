#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "info.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::MainWindow *ui;
    Info *infowind;

private slots:
    void on_btn_go_clicked();
    void on_btn_go_2_clicked();
    void on_btn_quit_clicked();
    void on_actionInfo_triggered();
    void on_actionQuit_triggered();
};

#endif // MAINWINDOW_H
