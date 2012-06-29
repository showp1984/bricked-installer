#ifndef DRAGONS_H
#define DRAGONS_H

#include <QDialog>

#include "mainwindow.h"

namespace Ui {
    class dragons;
}

class dragons : public QDialog {
    Q_OBJECT
public:
    dragons(QWidget *parent = 0);
    ~dragons();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::dragons *ui;
    MainWindow *welcome;
    QTimer *timer;

private slots:
    void on_btn_no_clicked();
    void on_btn_yes_clicked();
    void closedragons(void);
};

#endif // DRAGONS_H
