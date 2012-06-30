/********************************************************************************
** Form generated from reading UI file 'detect.ui'
**
** Created: Sat Jun 30 02:48:38 2012
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DETECT_H
#define UI_DETECT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QProgressBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_detect
{
public:
    QAction *actionQuit;
    QAction *actionInfo;
    QWidget *centralwidget;
    QLabel *lbl_brickedimage;
    QLabel *lbl_detectphone;
    QLabel *lbl_plugin;
    QProgressBar *bar_detectphone;
    QLabel *lbl_detectstate;
    QLabel *lbl_detectdevice;
    QLabel *lbl_detectromversion;
    QLabel *lbl_detectandroidversion;
    QLabel *lbl_detectsenseversion;
    QLabel *lbl_donephone;
    QLabel *lbl_donestate;
    QLabel *lbl_donedevcode;
    QLabel *lbl_donerom;
    QLabel *lbl_doneandroid;
    QLabel *lbl_donesense;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuHelp;

    void setupUi(QMainWindow *detect)
    {
        if (detect->objectName().isEmpty())
            detect->setObjectName(QString::fromUtf8("detect"));
        detect->resize(730, 516);
        detect->setMinimumSize(QSize(730, 516));
        detect->setMaximumSize(QSize(730, 516));
        actionQuit = new QAction(detect);
        actionQuit->setObjectName(QString::fromUtf8("actionQuit"));
        actionInfo = new QAction(detect);
        actionInfo->setObjectName(QString::fromUtf8("actionInfo"));
        centralwidget = new QWidget(detect);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        lbl_brickedimage = new QLabel(centralwidget);
        lbl_brickedimage->setObjectName(QString::fromUtf8("lbl_brickedimage"));
        lbl_brickedimage->setGeometry(QRect(10, 10, 181, 461));
        lbl_detectphone = new QLabel(centralwidget);
        lbl_detectphone->setObjectName(QString::fromUtf8("lbl_detectphone"));
        lbl_detectphone->setGeometry(QRect(200, 40, 361, 16));
        lbl_plugin = new QLabel(centralwidget);
        lbl_plugin->setObjectName(QString::fromUtf8("lbl_plugin"));
        lbl_plugin->setGeometry(QRect(200, 10, 521, 16));
        bar_detectphone = new QProgressBar(centralwidget);
        bar_detectphone->setObjectName(QString::fromUtf8("bar_detectphone"));
        bar_detectphone->setGeometry(QRect(710, 10, 16, 461));
        bar_detectphone->setMinimum(0);
        bar_detectphone->setMaximum(100);
        bar_detectphone->setValue(0);
        bar_detectphone->setTextVisible(false);
        bar_detectphone->setOrientation(Qt::Vertical);
        bar_detectphone->setInvertedAppearance(true);
        bar_detectphone->setTextDirection(QProgressBar::TopToBottom);
        lbl_detectstate = new QLabel(centralwidget);
        lbl_detectstate->setObjectName(QString::fromUtf8("lbl_detectstate"));
        lbl_detectstate->setGeometry(QRect(200, 60, 361, 17));
        lbl_detectdevice = new QLabel(centralwidget);
        lbl_detectdevice->setObjectName(QString::fromUtf8("lbl_detectdevice"));
        lbl_detectdevice->setGeometry(QRect(200, 80, 361, 17));
        lbl_detectromversion = new QLabel(centralwidget);
        lbl_detectromversion->setObjectName(QString::fromUtf8("lbl_detectromversion"));
        lbl_detectromversion->setGeometry(QRect(200, 100, 361, 17));
        lbl_detectandroidversion = new QLabel(centralwidget);
        lbl_detectandroidversion->setObjectName(QString::fromUtf8("lbl_detectandroidversion"));
        lbl_detectandroidversion->setGeometry(QRect(200, 120, 361, 17));
        lbl_detectsenseversion = new QLabel(centralwidget);
        lbl_detectsenseversion->setObjectName(QString::fromUtf8("lbl_detectsenseversion"));
        lbl_detectsenseversion->setGeometry(QRect(200, 140, 361, 17));
        lbl_donephone = new QLabel(centralwidget);
        lbl_donephone->setObjectName(QString::fromUtf8("lbl_donephone"));
        lbl_donephone->setGeometry(QRect(650, 40, 41, 16));
        lbl_donestate = new QLabel(centralwidget);
        lbl_donestate->setObjectName(QString::fromUtf8("lbl_donestate"));
        lbl_donestate->setGeometry(QRect(650, 60, 41, 16));
        lbl_donedevcode = new QLabel(centralwidget);
        lbl_donedevcode->setObjectName(QString::fromUtf8("lbl_donedevcode"));
        lbl_donedevcode->setGeometry(QRect(650, 80, 41, 16));
        lbl_donerom = new QLabel(centralwidget);
        lbl_donerom->setObjectName(QString::fromUtf8("lbl_donerom"));
        lbl_donerom->setGeometry(QRect(650, 100, 41, 16));
        lbl_doneandroid = new QLabel(centralwidget);
        lbl_doneandroid->setObjectName(QString::fromUtf8("lbl_doneandroid"));
        lbl_doneandroid->setGeometry(QRect(650, 120, 41, 16));
        lbl_donesense = new QLabel(centralwidget);
        lbl_donesense->setObjectName(QString::fromUtf8("lbl_donesense"));
        lbl_donesense->setGeometry(QRect(650, 140, 41, 16));
        detect->setCentralWidget(centralwidget);
        menubar = new QMenuBar(detect);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 730, 23));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuHelp = new QMenu(menubar);
        menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
        detect->setMenuBar(menubar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionQuit);
        menuHelp->addAction(actionInfo);

        retranslateUi(detect);

        QMetaObject::connectSlotsByName(detect);
    } // setupUi

    void retranslateUi(QMainWindow *detect)
    {
        detect->setWindowTitle(QApplication::translate("detect", "Detecting your phone...", 0, QApplication::UnicodeUTF8));
        actionQuit->setText(QApplication::translate("detect", "Quit", 0, QApplication::UnicodeUTF8));
        actionInfo->setText(QApplication::translate("detect", "Info", 0, QApplication::UnicodeUTF8));
        lbl_brickedimage->setText(QApplication::translate("detect", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><img src=\":/res/img_us/img_us/skyscraper.png\" /></p></body></html>", 0, QApplication::UnicodeUTF8));
        lbl_detectphone->setText(QApplication::translate("detect", "Detecting your phone...", 0, QApplication::UnicodeUTF8));
        lbl_plugin->setText(QApplication::translate("detect", "Please connect your phone to your PC now. I will attempt to detect it.", 0, QApplication::UnicodeUTF8));
        bar_detectphone->setFormat(QApplication::translate("detect", "%p% Done", 0, QApplication::UnicodeUTF8));
        lbl_detectstate->setText(QApplication::translate("detect", "Detecting boot state...", 0, QApplication::UnicodeUTF8));
        lbl_detectdevice->setText(QApplication::translate("detect", "Detecting device & codename...", 0, QApplication::UnicodeUTF8));
        lbl_detectromversion->setText(QApplication::translate("detect", "Detecting Rom version...", 0, QApplication::UnicodeUTF8));
        lbl_detectandroidversion->setText(QApplication::translate("detect", "Detecting Android version...", 0, QApplication::UnicodeUTF8));
        lbl_detectsenseversion->setText(QApplication::translate("detect", "Detecting Sense version...", 0, QApplication::UnicodeUTF8));
        lbl_donephone->setText(QApplication::translate("detect", "Done!", 0, QApplication::UnicodeUTF8));
        lbl_donestate->setText(QApplication::translate("detect", "Done!", 0, QApplication::UnicodeUTF8));
        lbl_donedevcode->setText(QApplication::translate("detect", "Done!", 0, QApplication::UnicodeUTF8));
        lbl_donerom->setText(QApplication::translate("detect", "Done!", 0, QApplication::UnicodeUTF8));
        lbl_doneandroid->setText(QApplication::translate("detect", "Done!", 0, QApplication::UnicodeUTF8));
        lbl_donesense->setText(QApplication::translate("detect", "Done!", 0, QApplication::UnicodeUTF8));
        menuFile->setTitle(QApplication::translate("detect", "File", 0, QApplication::UnicodeUTF8));
        menuHelp->setTitle(QApplication::translate("detect", "Help", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class detect: public Ui_detect {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DETECT_H
