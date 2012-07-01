#ifndef FLASHER_H
#define FLASHER_H

#include <QMainWindow>

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
};

#endif // FLASHER_H
