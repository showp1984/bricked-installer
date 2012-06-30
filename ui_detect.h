/********************************************************************************
** Form generated from reading UI file 'detect.ui'
**
** Created: Sat Jun 30 00:30:25 2012
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
#include <QtGui/QPlainTextEdit>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_detect
{
public:
    QAction *actionQuit;
    QAction *actionInfo;
    QWidget *centralwidget;
    QLabel *lbl_brickedimage;
    QPlainTextEdit *out;
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
        out = new QPlainTextEdit(centralwidget);
        out->setObjectName(QString::fromUtf8("out"));
        out->setGeometry(QRect(200, 10, 521, 461));
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
        out->setPlainText(QApplication::translate("detect", "test", 0, QApplication::UnicodeUTF8));
        menuFile->setTitle(QApplication::translate("detect", "File", 0, QApplication::UnicodeUTF8));
        menuHelp->setTitle(QApplication::translate("detect", "Help", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class detect: public Ui_detect {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DETECT_H
