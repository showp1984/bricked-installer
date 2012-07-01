/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Sun Jul 1 03:17:40 2012
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
#include <QtGui/QCheckBox>
#include <QtGui/QFrame>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPlainTextEdit>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionQuit;
    QAction *actionInfo;
    QWidget *welcome;
    QPushButton *btn_go;
    QLabel *lbl_welcome;
    QLabel *lbl_brickedimage;
    QPushButton *btn_go_2;
    QPushButton *btn_quit;
    QPlainTextEdit *txt_disclaimer;
    QLabel *lbl_disclaimer_accept;
    QCheckBox *chk_agreed;
    QFrame *line;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuInfo;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(730, 516);
        MainWindow->setMinimumSize(QSize(730, 516));
        MainWindow->setMaximumSize(QSize(730, 516));
        actionQuit = new QAction(MainWindow);
        actionQuit->setObjectName(QString::fromUtf8("actionQuit"));
        actionInfo = new QAction(MainWindow);
        actionInfo->setObjectName(QString::fromUtf8("actionInfo"));
        welcome = new QWidget(MainWindow);
        welcome->setObjectName(QString::fromUtf8("welcome"));
        welcome->setEnabled(true);
        welcome->setAutoFillBackground(false);
        btn_go = new QPushButton(welcome);
        btn_go->setObjectName(QString::fromUtf8("btn_go"));
        btn_go->setEnabled(true);
        btn_go->setGeometry(QRect(530, 460, 93, 27));
        lbl_welcome = new QLabel(welcome);
        lbl_welcome->setObjectName(QString::fromUtf8("lbl_welcome"));
        lbl_welcome->setGeometry(QRect(200, 10, 511, 431));
        lbl_welcome->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        lbl_welcome->setWordWrap(true);
        lbl_welcome->setIndent(-1);
        lbl_welcome->setOpenExternalLinks(true);
        lbl_brickedimage = new QLabel(welcome);
        lbl_brickedimage->setObjectName(QString::fromUtf8("lbl_brickedimage"));
        lbl_brickedimage->setGeometry(QRect(10, 10, 181, 461));
        btn_go_2 = new QPushButton(welcome);
        btn_go_2->setObjectName(QString::fromUtf8("btn_go_2"));
        btn_go_2->setEnabled(true);
        btn_go_2->setGeometry(QRect(530, 460, 93, 27));
        btn_quit = new QPushButton(welcome);
        btn_quit->setObjectName(QString::fromUtf8("btn_quit"));
        btn_quit->setEnabled(true);
        btn_quit->setGeometry(QRect(630, 460, 93, 27));
        txt_disclaimer = new QPlainTextEdit(welcome);
        txt_disclaimer->setObjectName(QString::fromUtf8("txt_disclaimer"));
        txt_disclaimer->setGeometry(QRect(200, 10, 521, 291));
        txt_disclaimer->setFrameShape(QFrame::StyledPanel);
        txt_disclaimer->setFrameShadow(QFrame::Sunken);
        txt_disclaimer->setLineWidth(1);
        txt_disclaimer->setMidLineWidth(0);
        txt_disclaimer->setUndoRedoEnabled(false);
        txt_disclaimer->setReadOnly(true);
        txt_disclaimer->setTextInteractionFlags(Qt::NoTextInteraction);
        txt_disclaimer->setBackgroundVisible(false);
        txt_disclaimer->setCenterOnScroll(false);
        lbl_disclaimer_accept = new QLabel(welcome);
        lbl_disclaimer_accept->setObjectName(QString::fromUtf8("lbl_disclaimer_accept"));
        lbl_disclaimer_accept->setGeometry(QRect(230, 340, 481, 81));
        lbl_disclaimer_accept->setWordWrap(true);
        chk_agreed = new QCheckBox(welcome);
        chk_agreed->setObjectName(QString::fromUtf8("chk_agreed"));
        chk_agreed->setGeometry(QRect(200, 350, 20, 21));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(chk_agreed->sizePolicy().hasHeightForWidth());
        chk_agreed->setSizePolicy(sizePolicy);
        chk_agreed->setMinimumSize(QSize(0, 0));
        chk_agreed->setSizeIncrement(QSize(0, 0));
        chk_agreed->setBaseSize(QSize(0, 0));
        chk_agreed->setIconSize(QSize(16, 16));
        chk_agreed->setTristate(false);
        line = new QFrame(welcome);
        line->setObjectName(QString::fromUtf8("line"));
        line->setEnabled(true);
        line->setGeometry(QRect(207, 299, 511, 51));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        MainWindow->setCentralWidget(welcome);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 730, 23));
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
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Bricked-Installer", 0, QApplication::UnicodeUTF8));
        actionQuit->setText(QApplication::translate("MainWindow", "Quit", 0, QApplication::UnicodeUTF8));
        actionInfo->setText(QApplication::translate("MainWindow", "Info", 0, QApplication::UnicodeUTF8));
        btn_go->setText(QApplication::translate("MainWindow", "Go!", 0, QApplication::UnicodeUTF8));
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
        btn_go_2->setText(QApplication::translate("MainWindow", "Go!", 0, QApplication::UnicodeUTF8));
        btn_quit->setText(QApplication::translate("MainWindow", "Quit", 0, QApplication::UnicodeUTF8));
        txt_disclaimer->setPlainText(QApplication::translate("MainWindow", "#include <std_disclaimer.h>\n"
"/*\n"
" * Your warranty is now void.\n"
" *\n"
" * I am not responsible for bricked devices, dead SD cards,\n"
" * thermonuclear war, or you getting fired because the alarm app failed.\n"
" * Please do some research if you have any concerns about features\n"
" * included in this kernel before flashing it! YOU are choosing to make\n"
" * these modifications, and if you point the finger at me for messing up\n"
" * your device, I will laugh at you.\n"
" *\n"
" * This program might also transmit your device data (!encrypted!) to a\n"
" * database for certain functions. You will be asked if you want that, if you\n"
" * choose no then some functions of this program might not be available\n"
" * for you.\n"
" */", 0, QApplication::UnicodeUTF8));
        lbl_disclaimer_accept->setText(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:18pt; font-weight:600; color:#ff0000;\">Yes</span> I accept the above terms and I have understood that <span style=\" font-weight:600;\">the author of this kernel/application is in no way responsible</span> for <span style=\" font-size:20pt; font-weight:600; color:#ff0000;\">my</span> actions.</p></body></html>", 0, QApplication::UnicodeUTF8));
        chk_agreed->setText(QString());
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0, QApplication::UnicodeUTF8));
        menuInfo->setTitle(QApplication::translate("MainWindow", "Help", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
