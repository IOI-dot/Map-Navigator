/********************************************************************************
** Form generated from reading UI file 'cities.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CITIES_H
#define UI_CITIES_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Cities
{
public:
    QLabel *label;
    QPushButton *back;
    QPushButton *addcity;
    QPushButton *deletecity;
    QFrame *frame;
    QLabel *entername;
    QLineEdit *nameEdit;
    QPushButton *add;
    QPushButton *cancel;
    QLabel *choosecity;
    QComboBox *comboBox;
    QPushButton *delete1;
    QLabel *status;

    void setupUi(QDialog *Cities)
    {
        if (Cities->objectName().isEmpty())
            Cities->setObjectName("Cities");
        Cities->resize(814, 600);
        Cities->setStyleSheet(QString::fromUtf8("color: rgb(48, 50, 52);"));
        label = new QLabel(Cities);
        label->setObjectName("label");
        label->setGeometry(QRect(0, 40, 821, 61));
        QFont font;
        font.setFamilies({QString::fromUtf8("Georgia")});
        font.setPointSize(28);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(128, 162, 146);\n"
""));
        label->setAlignment(Qt::AlignCenter);
        back = new QPushButton(Cities);
        back->setObjectName("back");
        back->setGeometry(QRect(640, 540, 151, 32));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Georgia")});
        font1.setPointSize(16);
        back->setFont(font1);
        back->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(128, 162, 146);"));
        addcity = new QPushButton(Cities);
        addcity->setObjectName("addcity");
        addcity->setGeometry(QRect(180, 170, 141, 41));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Georgia")});
        font2.setPointSize(14);
        addcity->setFont(font2);
        addcity->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(128, 162, 146);"));
        deletecity = new QPushButton(Cities);
        deletecity->setObjectName("deletecity");
        deletecity->setGeometry(QRect(510, 170, 141, 41));
        deletecity->setFont(font2);
        deletecity->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(128, 162, 146);"));
        frame = new QFrame(Cities);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(200, 250, 421, 211));
        frame->setStyleSheet(QString::fromUtf8("background-color: rgb(68, 71, 71);"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        entername = new QLabel(frame);
        entername->setObjectName("entername");
        entername->setGeometry(QRect(160, 30, 101, 16));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Georgia")});
        font3.setPointSize(12);
        font3.setItalic(true);
        entername->setFont(font3);
        entername->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        nameEdit = new QLineEdit(frame);
        nameEdit->setObjectName("nameEdit");
        nameEdit->setGeometry(QRect(120, 80, 181, 41));
        QFont font4;
        font4.setPointSize(12);
        nameEdit->setFont(font4);
        nameEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(83, 86, 86);\n"
"color: rgb(255, 255, 255);"));
        add = new QPushButton(frame);
        add->setObjectName("add");
        add->setGeometry(QRect(100, 170, 91, 31));
        QFont font5;
        font5.setFamilies({QString::fromUtf8("Georgia")});
        font5.setPointSize(12);
        add->setFont(font5);
        add->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(128, 162, 146);"));
        cancel = new QPushButton(frame);
        cancel->setObjectName("cancel");
        cancel->setGeometry(QRect(240, 170, 91, 31));
        cancel->setFont(font5);
        cancel->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(128, 162, 146);"));
        choosecity = new QLabel(frame);
        choosecity->setObjectName("choosecity");
        choosecity->setGeometry(QRect(160, 30, 111, 21));
        choosecity->setFont(font3);
        choosecity->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        comboBox = new QComboBox(frame);
        comboBox->addItem(QString());
        comboBox->setObjectName("comboBox");
        comboBox->setGeometry(QRect(160, 80, 101, 31));
        comboBox->setStyleSheet(QString::fromUtf8("background-color: rgb(83, 86, 86);\n"
"color: rgb(255, 255, 255);"));
        delete1 = new QPushButton(frame);
        delete1->setObjectName("delete1");
        delete1->setGeometry(QRect(100, 170, 91, 31));
        delete1->setFont(font5);
        delete1->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(128, 162, 146);"));
        status = new QLabel(frame);
        status->setObjectName("status");
        status->setGeometry(QRect(110, 140, 181, 16));
        QFont font6;
        font6.setFamilies({QString::fromUtf8("Georgia")});
        font6.setPointSize(11);
        font6.setItalic(true);
        status->setFont(font6);
        status->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));
        status->setAlignment(Qt::AlignCenter);

        retranslateUi(Cities);

        QMetaObject::connectSlotsByName(Cities);
    } // setupUi

    void retranslateUi(QDialog *Cities)
    {
        Cities->setWindowTitle(QCoreApplication::translate("Cities", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("Cities", "Manage Cities", nullptr));
        back->setText(QCoreApplication::translate("Cities", "Back to Menu", nullptr));
        addcity->setText(QCoreApplication::translate("Cities", "Add a City", nullptr));
        deletecity->setText(QCoreApplication::translate("Cities", "Delete a City", nullptr));
        entername->setText(QCoreApplication::translate("Cities", "Enter name:", nullptr));
        add->setText(QCoreApplication::translate("Cities", "Add", nullptr));
        cancel->setText(QCoreApplication::translate("Cities", "Cancel", nullptr));
        choosecity->setText(QCoreApplication::translate("Cities", "Choose a City:", nullptr));
        comboBox->setItemText(0, QString());

        delete1->setText(QCoreApplication::translate("Cities", "Delete", nullptr));
        status->setText(QCoreApplication::translate("Cities", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Cities: public Ui_Cities {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CITIES_H
