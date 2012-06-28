/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Thu Jun 28 21:31:49 2012
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionQuit;
    QAction *actionInfo;
    QWidget *centralWidget;
    QPushButton *btn_quit;
    QLabel *lbl_welcome;
    QLabel *lbl_brickedimage;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuInfo;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(734, 516);
        actionQuit = new QAction(MainWindow);
        actionQuit->setObjectName(QString::fromUtf8("actionQuit"));
        actionInfo = new QAction(MainWindow);
        actionInfo->setObjectName(QString::fromUtf8("actionInfo"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        centralWidget->setEnabled(true);
        centralWidget->setAutoFillBackground(false);
        btn_quit = new QPushButton(centralWidget);
        btn_quit->setObjectName(QString::fromUtf8("btn_quit"));
        btn_quit->setGeometry(QRect(630, 460, 93, 27));
        lbl_welcome = new QLabel(centralWidget);
        lbl_welcome->setObjectName(QString::fromUtf8("lbl_welcome"));
        lbl_welcome->setGeometry(QRect(200, 10, 511, 431));
        lbl_welcome->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        lbl_welcome->setWordWrap(true);
        lbl_welcome->setIndent(-1);
        lbl_welcome->setOpenExternalLinks(true);
        lbl_brickedimage = new QLabel(centralWidget);
        lbl_brickedimage->setObjectName(QString::fromUtf8("lbl_brickedimage"));
        lbl_brickedimage->setGeometry(QRect(10, 10, 181, 461));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 734, 23));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuInfo = new QMenu(menuBar);
        menuInfo->setObjectName(QString::fromUtf8("menuInfo"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuInfo->menuAction());
        menuFile->addAction(actionQuit);
        menuInfo->addAction(actionInfo);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        actionQuit->setText(QApplication::translate("MainWindow", "Quit", 0, QApplication::UnicodeUTF8));
        actionInfo->setText(QApplication::translate("MainWindow", "Info", 0, QApplication::UnicodeUTF8));
        btn_quit->setText(QApplication::translate("MainWindow", "Go!", 0, QApplication::UnicodeUTF8));
        lbl_welcome->setText(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt; font-weight:600;\">Welcome to Bricked-Installer!</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">This installer will attempt to guide you through the deep rabbit hole of flashing kernels onto your Android powered phone.</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px"
                        "; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Please follow the steps precisely, plug your phone in when asked and don't unplug it during the process.</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Have fun!</p></body></html>", 0, QApplication::UnicodeUTF8));
        lbl_brickedimage->setText(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><img src=\":/res/img_us/img_us/skyscraper.png\" /></p></body></html>", 0, QApplication::UnicodeUTF8));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0, QApplication::UnicodeUTF8));
        menuInfo->setTitle(QApplication::translate("MainWindow", "Help", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
