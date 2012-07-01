/********************************************************************************
** Form generated from reading UI file 'dragons.ui'
**
** Created: Mon Jul 2 01:03:12 2012
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DRAGONS_H
#define UI_DRAGONS_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_dragons
{
public:
    QLabel *lbl_warn;
    QPushButton *btn_yes;
    QPushButton *btn_no;
    QLabel *lbl_vague;

    void setupUi(QDialog *dragons)
    {
        if (dragons->objectName().isEmpty())
            dragons->setObjectName(QString::fromUtf8("dragons"));
        dragons->resize(514, 160);
        dragons->setMinimumSize(QSize(514, 160));
        dragons->setMaximumSize(QSize(514, 160));
        lbl_warn = new QLabel(dragons);
        lbl_warn->setObjectName(QString::fromUtf8("lbl_warn"));
        lbl_warn->setGeometry(QRect(10, 10, 491, 111));
        lbl_warn->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        lbl_warn->setWordWrap(true);
        btn_yes = new QPushButton(dragons);
        btn_yes->setObjectName(QString::fromUtf8("btn_yes"));
        btn_yes->setGeometry(QRect(10, 130, 93, 27));
        btn_no = new QPushButton(dragons);
        btn_no->setObjectName(QString::fromUtf8("btn_no"));
        btn_no->setGeometry(QRect(410, 130, 93, 27));
        lbl_vague = new QLabel(dragons);
        lbl_vague->setObjectName(QString::fromUtf8("lbl_vague"));
        lbl_vague->setEnabled(true);
        lbl_vague->setGeometry(QRect(20, 30, 471, 91));

        retranslateUi(dragons);

        QMetaObject::connectSlotsByName(dragons);
    } // setupUi

    void retranslateUi(QDialog *dragons)
    {
        dragons->setWindowTitle(QApplication::translate("dragons", "WARNING! Dragons ahead!", 0, QApplication::UnicodeUTF8));
        lbl_warn->setText(QApplication::translate("dragons", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:600;\">There is important information popping up on the next screens.</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt; font-weight:600; color:#ff0000;\">READ IT CAREFULLY!</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0"
                        "px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:600;\">Understood my far too young Padawan?</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        btn_yes->setText(QApplication::translate("dragons", "Yes, master!", 0, QApplication::UnicodeUTF8));
        btn_no->setText(QApplication::translate("dragons", "Erm... What?", 0, QApplication::UnicodeUTF8));
        lbl_vague->setText(QApplication::translate("dragons", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:18pt; font-weight:600;\">Interpreting vague answer as 'no'.</span></p></body></html>", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class dragons: public Ui_dragons {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DRAGONS_H
