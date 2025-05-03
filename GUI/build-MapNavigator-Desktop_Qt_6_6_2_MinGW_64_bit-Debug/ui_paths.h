/********************************************************************************
** Form generated from reading UI file 'paths.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PATHS_H
#define UI_PATHS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Paths
{
public:
    QLabel *label;
    QPushButton *back;
    QPushButton *addpath;
    QPushButton *modifypath;
    QPushButton *deletepath;
    QFrame *frame;
    QLabel *label_2;
    QLabel *label_3;
    QComboBox *sourcebox;
    QComboBox *destbox;
    QPushButton *add;
    QPushButton *modify;
    QPushButton *delete1;
    QLabel *newdistlabel;
    QLineEdit *distedit;
    QPushButton *cancel;
    QLabel *enterdistlabel;
    QLabel *errorlabel;
    QLabel *errorlabel_2;
    QFrame *frame_2;
    QFrame *frame_3;

    void setupUi(QDialog *Paths)
    {
        if (Paths->objectName().isEmpty())
            Paths->setObjectName("Paths");
        Paths->resize(814, 600);
        Paths->setStyleSheet(QString::fromUtf8("background-color: rgb(48, 50, 52);\n"
"color: rgb(255, 255, 255);"));
        label = new QLabel(Paths);
        label->setObjectName("label");
        label->setGeometry(QRect(0, 40, 814, 61));
        QFont font;
        font.setFamilies({QString::fromUtf8("Georgia")});
        font.setPointSize(28);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(128, 162, 146);"));
        label->setAlignment(Qt::AlignCenter);
        back = new QPushButton(Paths);
        back->setObjectName("back");
        back->setGeometry(QRect(650, 540, 141, 32));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Georgia")});
        font1.setPointSize(16);
        back->setFont(font1);
        back->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(128, 162, 146);"));
        addpath = new QPushButton(Paths);
        addpath->setObjectName("addpath");
        addpath->setGeometry(QRect(70, 180, 141, 41));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Georgia")});
        font2.setPointSize(14);
        addpath->setFont(font2);
        addpath->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(128, 162, 146);"));
        modifypath = new QPushButton(Paths);
        modifypath->setObjectName("modifypath");
        modifypath->setGeometry(QRect(330, 180, 141, 41));
        modifypath->setFont(font2);
        modifypath->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(128, 162, 146);"));
        deletepath = new QPushButton(Paths);
        deletepath->setObjectName("deletepath");
        deletepath->setGeometry(QRect(610, 180, 141, 41));
        deletepath->setFont(font2);
        deletepath->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(128, 162, 146);"));
        frame = new QFrame(Paths);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(150, 270, 501, 231));
        frame->setStyleSheet(QString::fromUtf8("background-color: rgb(68, 71, 71);\n"
""));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        label_2 = new QLabel(frame);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(60, 20, 131, 21));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Georgia")});
        font3.setPointSize(12);
        font3.setItalic(true);
        label_2->setFont(font3);
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_3 = new QLabel(frame);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(310, 20, 141, 21));
        label_3->setFont(font3);
        label_3->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        sourcebox = new QComboBox(frame);
        sourcebox->addItem(QString());
        sourcebox->setObjectName("sourcebox");
        sourcebox->setGeometry(QRect(80, 70, 90, 24));
        sourcebox->setStyleSheet(QString::fromUtf8("background-color: rgb(83, 86, 86);\n"
"color: rgb(255, 255, 255);"));
        destbox = new QComboBox(frame);
        destbox->addItem(QString());
        destbox->setObjectName("destbox");
        destbox->setGeometry(QRect(330, 70, 90, 24));
        destbox->setStyleSheet(QString::fromUtf8("background-color: rgb(83, 86, 86);\n"
"color: rgb(255, 255, 255);"));
        add = new QPushButton(frame);
        add->setObjectName("add");
        add->setGeometry(QRect(150, 180, 91, 31));
        QFont font4;
        font4.setFamilies({QString::fromUtf8("Georgia")});
        font4.setPointSize(12);
        add->setFont(font4);
        add->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(128, 162, 146);"));
        modify = new QPushButton(frame);
        modify->setObjectName("modify");
        modify->setGeometry(QRect(150, 180, 91, 31));
        modify->setFont(font4);
        modify->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(128, 162, 146);"));
        delete1 = new QPushButton(frame);
        delete1->setObjectName("delete1");
        delete1->setGeometry(QRect(150, 180, 91, 31));
        delete1->setFont(font4);
        delete1->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(128, 162, 146);"));
        newdistlabel = new QLabel(frame);
        newdistlabel->setObjectName("newdistlabel");
        newdistlabel->setGeometry(QRect(20, 130, 221, 16));
        newdistlabel->setFont(font3);
        newdistlabel->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        distedit = new QLineEdit(frame);
        distedit->setObjectName("distedit");
        distedit->setGeometry(QRect(230, 130, 113, 24));
        distedit->setStyleSheet(QString::fromUtf8("background-color: rgb(83, 86, 86);\n"
"color: rgb(255, 255, 255);"));
        cancel = new QPushButton(frame);
        cancel->setObjectName("cancel");
        cancel->setGeometry(QRect(270, 180, 91, 31));
        cancel->setFont(font4);
        cancel->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(128, 162, 146);"));
        enterdistlabel = new QLabel(frame);
        enterdistlabel->setObjectName("enterdistlabel");
        enterdistlabel->setGeometry(QRect(20, 130, 181, 16));
        enterdistlabel->setFont(font3);
        enterdistlabel->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        errorlabel = new QLabel(frame);
        errorlabel->setObjectName("errorlabel");
        errorlabel->setGeometry(QRect(20, 160, 141, 51));
        QFont font5;
        font5.setFamilies({QString::fromUtf8("Georgia")});
        font5.setPointSize(11);
        font5.setItalic(true);
        errorlabel->setFont(font5);
        errorlabel->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));
        errorlabel->setWordWrap(true);
        errorlabel_2 = new QLabel(frame);
        errorlabel_2->setObjectName("errorlabel_2");
        errorlabel_2->setGeometry(QRect(10, 160, 141, 51));
        errorlabel_2->setFont(font5);
        errorlabel_2->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));
        errorlabel_2->setWordWrap(true);
        frame_2 = new QFrame(Paths);
        frame_2->setObjectName("frame_2");
        frame_2->setGeometry(QRect(640, 530, 161, 51));
        frame_2->setStyleSheet(QString::fromUtf8("background-color: rgb(68, 71, 71);"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        frame_3 = new QFrame(Paths);
        frame_3->setObjectName("frame_3");
        frame_3->setGeometry(QRect(50, 160, 711, 80));
        frame_3->setStyleSheet(QString::fromUtf8("background-color: rgb(68, 71, 71);"));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        frame_3->raise();
        frame_2->raise();
        frame->raise();
        label->raise();
        back->raise();
        addpath->raise();
        modifypath->raise();
        deletepath->raise();

        retranslateUi(Paths);

        QMetaObject::connectSlotsByName(Paths);
    } // setupUi

    void retranslateUi(QDialog *Paths)
    {
        Paths->setWindowTitle(QCoreApplication::translate("Paths", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("Paths", "Manage Paths", nullptr));
        back->setText(QCoreApplication::translate("Paths", "Back to Menu", nullptr));
        addpath->setText(QCoreApplication::translate("Paths", "Add a Path", nullptr));
        modifypath->setText(QCoreApplication::translate("Paths", "Modify a Path", nullptr));
        deletepath->setText(QCoreApplication::translate("Paths", "Delete a Path", nullptr));
        label_2->setText(QCoreApplication::translate("Paths", "Select first city", nullptr));
        label_3->setText(QCoreApplication::translate("Paths", "Select second city", nullptr));
        sourcebox->setItemText(0, QString());

        destbox->setItemText(0, QString());

        add->setText(QCoreApplication::translate("Paths", "Add", nullptr));
        modify->setText(QCoreApplication::translate("Paths", "Modify", nullptr));
        delete1->setText(QCoreApplication::translate("Paths", "Delete", nullptr));
        newdistlabel->setText(QCoreApplication::translate("Paths", "Enter new distance (in km):", nullptr));
        cancel->setText(QCoreApplication::translate("Paths", "Cancel", nullptr));
        enterdistlabel->setText(QCoreApplication::translate("Paths", "Enter distance (in km):", nullptr));
        errorlabel->setText(QCoreApplication::translate("Paths", "Please select two cities and enter a distance above", nullptr));
        errorlabel_2->setText(QCoreApplication::translate("Paths", "Please select two cities above", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Paths: public Ui_Paths {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PATHS_H
