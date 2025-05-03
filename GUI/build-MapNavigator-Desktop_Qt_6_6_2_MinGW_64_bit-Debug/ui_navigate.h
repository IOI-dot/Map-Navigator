/********************************************************************************
** Form generated from reading UI file 'navigate.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NAVIGATE_H
#define UI_NAVIGATE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Navigate
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QComboBox *sourcebox;
    QComboBox *destinationbox;
    QFrame *frame;
    QPushButton *back;
    QFrame *frame_2;
    QPushButton *go;
    QFrame *frame_3;
    QLabel *errorlabel;
    QLabel *errorlabel_2;
    QLabel *thePath;
    QLabel *path;
    QFrame *frame_4;
    QLabel *theShortest;

    void setupUi(QDialog *Navigate)
    {
        if (Navigate->objectName().isEmpty())
            Navigate->setObjectName("Navigate");
        Navigate->resize(814, 600);
        Navigate->setStyleSheet(QString::fromUtf8("background-color: rgb(48, 50, 52);\n"
""));
        label = new QLabel(Navigate);
        label->setObjectName("label");
        label->setGeometry(QRect(0, 40, 814, 61));
        QFont font;
        font.setFamilies({QString::fromUtf8("Georgia")});
        font.setPointSize(28);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(128, 162, 146);"));
        label->setAlignment(Qt::AlignCenter);
        label_2 = new QLabel(Navigate);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(220, 160, 391, 41));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Georgia")});
        font1.setPointSize(18);
        font1.setItalic(true);
        label_2->setFont(font1);
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(128, 162, 146);"));
        label_2->setAlignment(Qt::AlignCenter);
        label_3 = new QLabel(Navigate);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(380, 230, 71, 31));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Georgia")});
        font2.setPointSize(18);
        label_3->setFont(font2);
        label_3->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(128, 162, 146);"));
        label_3->setAlignment(Qt::AlignCenter);
        sourcebox = new QComboBox(Navigate);
        sourcebox->setObjectName("sourcebox");
        sourcebox->setGeometry(QRect(220, 230, 101, 41));
        sourcebox->setStyleSheet(QString::fromUtf8("background-color: rgb(83, 86, 86);\n"
"color: rgb(255, 255, 255);"));
        destinationbox = new QComboBox(Navigate);
        destinationbox->setObjectName("destinationbox");
        destinationbox->setGeometry(QRect(500, 230, 101, 41));
        destinationbox->setStyleSheet(QString::fromUtf8("background-color: rgb(83, 86, 86);\n"
"color: rgb(255, 255, 255);"));
        frame = new QFrame(Navigate);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(470, 360, 161, 61));
        frame->setStyleSheet(QString::fromUtf8("background-color: rgb(68, 71, 71);"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        back = new QPushButton(frame);
        back->setObjectName("back");
        back->setGeometry(QRect(10, 10, 141, 41));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Georgia")});
        font3.setPointSize(16);
        back->setFont(font3);
        back->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(128, 162, 146);"));
        frame_2 = new QFrame(Navigate);
        frame_2->setObjectName("frame_2");
        frame_2->setGeometry(QRect(170, 130, 501, 181));
        frame_2->setStyleSheet(QString::fromUtf8("background-color: rgb(68, 71, 71);"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        go = new QPushButton(Navigate);
        go->setObjectName("go");
        go->setGeometry(QRect(220, 370, 141, 41));
        go->setFont(font3);
        go->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(128, 162, 146);"));
        frame_3 = new QFrame(Navigate);
        frame_3->setObjectName("frame_3");
        frame_3->setGeometry(QRect(210, 360, 161, 61));
        frame_3->setStyleSheet(QString::fromUtf8("background-color: rgb(68, 71, 71);"));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        errorlabel = new QLabel(Navigate);
        errorlabel->setObjectName("errorlabel");
        errorlabel->setGeometry(QRect(290, 320, 301, 31));
        QFont font4;
        font4.setFamilies({QString::fromUtf8("Georgia")});
        font4.setPointSize(12);
        font4.setItalic(true);
        errorlabel->setFont(font4);
        errorlabel->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);\n"
"background-color: rgba(0,0,0,0%);"));
        errorlabel_2 = new QLabel(Navigate);
        errorlabel_2->setObjectName("errorlabel_2");
        errorlabel_2->setGeometry(QRect(280, 320, 341, 31));
        errorlabel_2->setFont(font4);
        errorlabel_2->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);\n"
"background-color: rgba(0,0,0,0%);"));
        thePath = new QLabel(Navigate);
        thePath->setObjectName("thePath");
        thePath->setGeometry(QRect(270, 470, 331, 31));
        QFont font5;
        font5.setFamilies({QString::fromUtf8("Georgia")});
        font5.setPointSize(14);
        font5.setBold(false);
        font5.setItalic(true);
        thePath->setFont(font5);
        thePath->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgba(0,0,0,0%);"));
        path = new QLabel(Navigate);
        path->setObjectName("path");
        path->setGeometry(QRect(0, 510, 811, 51));
        path->setFont(font5);
        path->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgba(0,0,0,0%);"));
        path->setAlignment(Qt::AlignCenter);
        frame_4 = new QFrame(Navigate);
        frame_4->setObjectName("frame_4");
        frame_4->setGeometry(QRect(0, 430, 821, 141));
        frame_4->setStyleSheet(QString::fromUtf8("background-color: rgb(68, 71, 71);"));
        frame_4->setFrameShape(QFrame::StyledPanel);
        frame_4->setFrameShadow(QFrame::Raised);
        theShortest = new QLabel(frame_4);
        theShortest->setObjectName("theShortest");
        theShortest->setGeometry(QRect(10, 0, 801, 31));
        theShortest->setFont(font5);
        theShortest->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgba(0,0,0,0%);"));
        theShortest->setAlignment(Qt::AlignCenter);
        frame_4->raise();
        frame_3->raise();
        frame_2->raise();
        frame->raise();
        label->raise();
        label_2->raise();
        label_3->raise();
        sourcebox->raise();
        destinationbox->raise();
        go->raise();
        errorlabel->raise();
        errorlabel_2->raise();
        thePath->raise();
        path->raise();

        retranslateUi(Navigate);

        QMetaObject::connectSlotsByName(Navigate);
    } // setupUi

    void retranslateUi(QDialog *Navigate)
    {
        Navigate->setWindowTitle(QCoreApplication::translate("Navigate", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("Navigate", "Navigation", nullptr));
        label_2->setText(QCoreApplication::translate("Navigate", "Find the shortest path between:", nullptr));
        label_3->setText(QCoreApplication::translate("Navigate", "and", nullptr));
        back->setText(QCoreApplication::translate("Navigate", "Back to Menu", nullptr));
        go->setText(QCoreApplication::translate("Navigate", "Go!", nullptr));
        errorlabel->setText(QCoreApplication::translate("Navigate", "Please select two different cities!", nullptr));
        errorlabel_2->setText(QCoreApplication::translate("Navigate", "Please make sure you select two cities!", nullptr));
        thePath->setText(QCoreApplication::translate("Navigate", "Here is the path you need to take:", nullptr));
        path->setText(QCoreApplication::translate("Navigate", "path", nullptr));
        theShortest->setText(QCoreApplication::translate("Navigate", "The Shortest Distance between", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Navigate: public Ui_Navigate {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NAVIGATE_H
