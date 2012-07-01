/********************************************************************************
** Form generated from reading UI file 'openfile.ui'
**
** Created: Mon Jul 2 01:03:12 2012
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OPENFILE_H
#define UI_OPENFILE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_openfile
{
public:
    QAction *actionQuit;
    QAction *actionInfo;
    QWidget *centralwidget;
    QLabel *lbl_brickedimage;
    QPushButton *btn_quit;
    QPushButton *btn_go;
    QLineEdit *edt_filename;
    QPushButton *btn_find;
    QLabel *lbl_file;
    QComboBox *cmb_type;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuHelp;

    void setupUi(QMainWindow *openfile)
    {
        if (openfile->objectName().isEmpty())
            openfile->setObjectName(QString::fromUtf8("openfile"));
        openfile->resize(730, 516);
        openfile->setMinimumSize(QSize(730, 516));
        openfile->setMaximumSize(QSize(730, 516));
        actionQuit = new QAction(openfile);
        actionQuit->setObjectName(QString::fromUtf8("actionQuit"));
        actionInfo = new QAction(openfile);
        actionInfo->setObjectName(QString::fromUtf8("actionInfo"));
        centralwidget = new QWidget(openfile);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        lbl_brickedimage = new QLabel(centralwidget);
        lbl_brickedimage->setObjectName(QString::fromUtf8("lbl_brickedimage"));
        lbl_brickedimage->setGeometry(QRect(10, 10, 181, 461));
        btn_quit = new QPushButton(centralwidget);
        btn_quit->setObjectName(QString::fromUtf8("btn_quit"));
        btn_quit->setGeometry(QRect(630, 460, 93, 27));
        btn_go = new QPushButton(centralwidget);
        btn_go->setObjectName(QString::fromUtf8("btn_go"));
        btn_go->setGeometry(QRect(530, 460, 93, 27));
        edt_filename = new QLineEdit(centralwidget);
        edt_filename->setObjectName(QString::fromUtf8("edt_filename"));
        edt_filename->setGeometry(QRect(200, 30, 521, 27));
        btn_find = new QPushButton(centralwidget);
        btn_find->setObjectName(QString::fromUtf8("btn_find"));
        btn_find->setGeometry(QRect(620, 60, 93, 27));
        lbl_file = new QLabel(centralwidget);
        lbl_file->setObjectName(QString::fromUtf8("lbl_file"));
        lbl_file->setGeometry(QRect(200, 10, 521, 17));
        cmb_type = new QComboBox(centralwidget);
        cmb_type->setObjectName(QString::fromUtf8("cmb_type"));
        cmb_type->setGeometry(QRect(200, 90, 521, 31));
        cmb_type->setFrame(true);
        openfile->setCentralWidget(centralwidget);
        menubar = new QMenuBar(openfile);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 730, 23));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuHelp = new QMenu(menubar);
        menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
        openfile->setMenuBar(menubar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionQuit);
        menuHelp->addAction(actionInfo);

        retranslateUi(openfile);

        cmb_type->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(openfile);
    } // setupUi

    void retranslateUi(QMainWindow *openfile)
    {
        openfile->setWindowTitle(QApplication::translate("openfile", "MainWindow", 0, QApplication::UnicodeUTF8));
        actionQuit->setText(QApplication::translate("openfile", "Quit", 0, QApplication::UnicodeUTF8));
        actionInfo->setText(QApplication::translate("openfile", "Info", 0, QApplication::UnicodeUTF8));
        lbl_brickedimage->setText(QApplication::translate("openfile", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><img src=\":/res/img_us/img_us/skyscraper.png\" /></p></body></html>", 0, QApplication::UnicodeUTF8));
        btn_quit->setText(QApplication::translate("openfile", "Quit", 0, QApplication::UnicodeUTF8));
        btn_go->setText(QApplication::translate("openfile", "Go!", 0, QApplication::UnicodeUTF8));
        btn_find->setText(QApplication::translate("openfile", "Find", 0, QApplication::UnicodeUTF8));
        lbl_file->setText(QApplication::translate("openfile", "Which file do you want to flash?", 0, QApplication::UnicodeUTF8));
        cmb_type->clear();
        cmb_type->insertItems(0, QStringList()
         << QApplication::translate("openfile", "This contains a kernel", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("openfile", "This contains a ROM", 0, QApplication::UnicodeUTF8)
        );
        menuFile->setTitle(QApplication::translate("openfile", "File", 0, QApplication::UnicodeUTF8));
        menuHelp->setTitle(QApplication::translate("openfile", "Help", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class openfile: public Ui_openfile {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPENFILE_H
