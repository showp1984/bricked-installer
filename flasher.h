#ifndef FLASHER_H
#define FLASHER_H

#include <QMainWindow>
#include <QtGui>
#include <QtGui/QApplication>

#include "info.h"

namespace Ui {
    class flasher;
}

enum {
    EXTRACT = 0,
    DETECT,
    GET_BOOTED,
    CHECK_SNR,
    PUSH_FILES,
    REBOOT_FASTBOOT,
    FLASH_BOOTIMG,
    CHECK_INSTALL,
    RELEASE_CONTROLS,
};

class flasher : public QMainWindow {
    Q_OBJECT
public:
    flasher(QWidget *parent = 0);
    ~flasher();
    void set_snr(QString);
    void set_device(QString);
    void set_filename(QString);
    void set_filepath(QString);
    void set_type(int);

protected:
    void changeEvent(QEvent *e);

private:
    Ui::flasher *ui;
    Info *infowind;
    QTimer *flashtimer;
    QTextCursor c;
    QProcess p;
    bool error;
    bool firstcall;
    int flash_state;
    int type;
    QStringList list;
    QStringList list2;
    QStringList list3;
    QString p_out;
    QString device;
    QString snr_old;
    QString snr;
    QString state;
    QString filename;
    QString filepath;
    QString tmp_folder;

private slots:
    void on_txt_out_textChanged();
    void on_btn_start_clicked();
    void on_btn_quit_clicked();
    void on_actionInfo_triggered();
    void on_actionQuit_triggered();
    void flash_device(void);
    int extract(void);
    int detect_device(void);
    int get_booted(void);
    int push_files(void);
};

#endif // FLASHER_H
