/********************************************************************************
** Form generated from reading UI file 'flasher.ui'
**
** Created: Mon Jul 2 01:03:12 2012
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FLASHER_H
#define UI_FLASHER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QProgressBar>
#include <QtGui/QPushButton>
#include <QtGui/QTextEdit>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_flasher
{
public:
    QAction *actionInfo;
    QAction *actionQuit;
    QWidget *centralwidget;
    QLabel *lbl_brickedimage;
    QPushButton *btn_quit;
    QLabel *lbl_filename;
    QLabel *lbl_edt_filename;
    QPushButton *btn_start;
    QProgressBar *bar_flash;
    QTextEdit *txt_out;
    QLabel *lbl_filepath;
    QLineEdit *edt_filepath;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuHelp;

    void setupUi(QMainWindow *flasher)
    {
        if (flasher->objectName().isEmpty())
            flasher->setObjectName(QString::fromUtf8("flasher"));
        flasher->resize(730, 516);
        flasher->setMinimumSize(QSize(730, 516));
        flasher->setMaximumSize(QSize(730, 516));
        actionInfo = new QAction(flasher);
        actionInfo->setObjectName(QString::fromUtf8("actionInfo"));
        actionQuit = new QAction(flasher);
        actionQuit->setObjectName(QString::fromUtf8("actionQuit"));
        centralwidget = new QWidget(flasher);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        lbl_brickedimage = new QLabel(centralwidget);
        lbl_brickedimage->setObjectName(QString::fromUtf8("lbl_brickedimage"));
        lbl_brickedimage->setGeometry(QRect(10, 10, 181, 461));
        btn_quit = new QPushButton(centralwidget);
        btn_quit->setObjectName(QString::fromUtf8("btn_quit"));
        btn_quit->setEnabled(true);
        btn_quit->setGeometry(QRect(630, 440, 93, 27));
        lbl_filename = new QLabel(centralwidget);
        lbl_filename->setObjectName(QString::fromUtf8("lbl_filename"));
        lbl_filename->setGeometry(QRect(200, 10, 151, 17));
        lbl_filename->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        lbl_edt_filename = new QLabel(centralwidget);
        lbl_edt_filename->setObjectName(QString::fromUtf8("lbl_edt_filename"));
        lbl_edt_filename->setGeometry(QRect(350, 10, 371, 20));
        lbl_edt_filename->setAlignment(Qt::AlignRight|Qt::AlignTop|Qt::AlignTrailing);
        btn_start = new QPushButton(centralwidget);
        btn_start->setObjectName(QString::fromUtf8("btn_start"));
        btn_start->setGeometry(QRect(260, 60, 401, 27));
        bar_flash = new QProgressBar(centralwidget);
        bar_flash->setObjectName(QString::fromUtf8("bar_flash"));
        bar_flash->setGeometry(QRect(10, 473, 710, 20));
        bar_flash->setMaximum(100);
        bar_flash->setValue(0);
        txt_out = new QTextEdit(centralwidget);
        txt_out->setObjectName(QString::fromUtf8("txt_out"));
        txt_out->setGeometry(QRect(200, 60, 521, 371));
        txt_out->setContextMenuPolicy(Qt::NoContextMenu);
        txt_out->setUndoRedoEnabled(false);
        txt_out->setReadOnly(true);
        txt_out->setTextInteractionFlags(Qt::NoTextInteraction);
        lbl_filepath = new QLabel(centralwidget);
        lbl_filepath->setObjectName(QString::fromUtf8("lbl_filepath"));
        lbl_filepath->setGeometry(QRect(200, 30, 41, 25));
        lbl_filepath->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        edt_filepath = new QLineEdit(centralwidget);
        edt_filepath->setObjectName(QString::fromUtf8("edt_filepath"));
        edt_filepath->setGeometry(QRect(242, 30, 481, 27));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(edt_filepath->sizePolicy().hasHeightForWidth());
        edt_filepath->setSizePolicy(sizePolicy);
        edt_filepath->setCursor(QCursor(Qt::IBeamCursor));
        edt_filepath->setReadOnly(true);
        flasher->setCentralWidget(centralwidget);
        menubar = new QMenuBar(flasher);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 730, 23));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuHelp = new QMenu(menubar);
        menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
        flasher->setMenuBar(menubar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionQuit);
        menuHelp->addAction(actionInfo);

        retranslateUi(flasher);

        QMetaObject::connectSlotsByName(flasher);
    } // setupUi

    void retranslateUi(QMainWindow *flasher)
    {
        flasher->setWindowTitle(QApplication::translate("flasher", "Bricked-Installer", 0, QApplication::UnicodeUTF8));
        actionInfo->setText(QApplication::translate("flasher", "Info", 0, QApplication::UnicodeUTF8));
        actionQuit->setText(QApplication::translate("flasher", "Quit", 0, QApplication::UnicodeUTF8));
        lbl_brickedimage->setText(QApplication::translate("flasher", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><img src=\":/res/img_us/img_us/skyscraper.png\" /></p></body></html>", 0, QApplication::UnicodeUTF8));
        btn_quit->setText(QApplication::translate("flasher", "Quit", 0, QApplication::UnicodeUTF8));
        lbl_filename->setText(QApplication::translate("flasher", "You are about to flash:", 0, QApplication::UnicodeUTF8));
        lbl_edt_filename->setText(QString());
        btn_start->setText(QApplication::translate("flasher", "Yeah, I know! Get it going already...", 0, QApplication::UnicodeUTF8));
        txt_out->setHtml(QApplication::translate("flasher", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"></p></body></html>", 0, QApplication::UnicodeUTF8));
        lbl_filepath->setText(QApplication::translate("flasher", "From:", 0, QApplication::UnicodeUTF8));
        menuFile->setTitle(QApplication::translate("flasher", "File", 0, QApplication::UnicodeUTF8));
        menuHelp->setTitle(QApplication::translate("flasher", "Help", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class flasher: public Ui_flasher {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FLASHER_H
