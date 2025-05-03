/********************************************************************************
** Form generated from reading UI file 'instructions.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INSTRUCTIONS_H
#define UI_INSTRUCTIONS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Instructions
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QPushButton *pushButton;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QFrame *frame;

    void setupUi(QDialog *Instructions)
    {
        if (Instructions->objectName().isEmpty())
            Instructions->setObjectName("Instructions");
        Instructions->resize(814, 600);
        Instructions->setStyleSheet(QString::fromUtf8("background-color: rgb(48, 50, 52);"));
        label = new QLabel(Instructions);
        label->setObjectName("label");
        label->setGeometry(QRect(80, 180, 431, 41));
        QFont font;
        font.setFamilies({QString::fromUtf8("Georgia")});
        font.setPointSize(16);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgba(0,0,0,0%)"));
        label_2 = new QLabel(Instructions);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(80, 340, 511, 41));
        label_2->setFont(font);
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgba(0,0,0,0%)"));
        label_3 = new QLabel(Instructions);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(80, 260, 391, 41));
        label_3->setFont(font);
        label_3->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgba(0,0,0,0%)"));
        label_4 = new QLabel(Instructions);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(0, 40, 814, 41));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Georgia")});
        font1.setPointSize(28);
        label_4->setFont(font1);
        label_4->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(128, 162, 146);"));
        label_4->setAlignment(Qt::AlignCenter);
        pushButton = new QPushButton(Instructions);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(650, 500, 131, 51));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Arial")});
        font2.setPointSize(18);
        pushButton->setFont(font2);
        pushButton->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(128, 162, 146);"));
        label_5 = new QLabel(Instructions);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(600, 190, 141, 21));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Georgia")});
        font3.setPointSize(14);
        font3.setItalic(true);
        label_5->setFont(font3);
        label_5->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgba(0,0,0,0%)"));
        label_6 = new QLabel(Instructions);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(600, 270, 141, 21));
        label_6->setFont(font3);
        label_6->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgba(0,0,0,0%)"));
        label_7 = new QLabel(Instructions);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(610, 350, 141, 21));
        label_7->setFont(font3);
        label_7->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgba(0,0,0,0%)"));
        frame = new QFrame(Instructions);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(69, 159, 681, 241));
        frame->setStyleSheet(QString::fromUtf8("background-color: rgb(68, 71, 71);"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        frame->raise();
        label->raise();
        label_2->raise();
        label_3->raise();
        label_4->raise();
        pushButton->raise();
        label_5->raise();
        label_6->raise();
        label_7->raise();

        retranslateUi(Instructions);

        QMetaObject::connectSlotsByName(Instructions);
    } // setupUi

    void retranslateUi(QDialog *Instructions)
    {
        Instructions->setWindowTitle(QCoreApplication::translate("Instructions", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("Instructions", "- To add or delete a city from the map click on", nullptr));
        label_2->setText(QCoreApplication::translate("Instructions", "- To find the shortest path between two cities, click on", nullptr));
        label_3->setText(QCoreApplication::translate("Instructions", "- To add, modify, or delete a path click on", nullptr));
        label_4->setText(QCoreApplication::translate("Instructions", "User Guide", nullptr));
        pushButton->setText(QCoreApplication::translate("Instructions", "OK", nullptr));
        label_5->setText(QCoreApplication::translate("Instructions", "Manage Cities", nullptr));
        label_6->setText(QCoreApplication::translate("Instructions", "Manage Paths", nullptr));
        label_7->setText(QCoreApplication::translate("Instructions", "Navigate", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Instructions: public Ui_Instructions {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INSTRUCTIONS_H
