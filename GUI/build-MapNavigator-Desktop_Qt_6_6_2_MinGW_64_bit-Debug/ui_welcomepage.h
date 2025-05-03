/********************************************************************************
** Form generated from reading UI file 'welcomepage.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WELCOMEPAGE_H
#define UI_WELCOMEPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_welcomePage
{
public:
    QPushButton *cities;
    QPushButton *paths;
    QPushButton *navigate;
    QPushButton *quit;
    QPushButton *pushButton_5;
    QLabel *label_2;
    QFrame *frame;
    QFrame *frame_2;

    void setupUi(QDialog *welcomePage)
    {
        if (welcomePage->objectName().isEmpty())
            welcomePage->setObjectName("welcomePage");
        welcomePage->resize(814, 600);
        welcomePage->setStyleSheet(QString::fromUtf8("background-color: rgb(48, 50, 52);"));
        cities = new QPushButton(welcomePage);
        cities->setObjectName("cities");
        cities->setGeometry(QRect(310, 230, 191, 71));
        QFont font;
        font.setFamilies({QString::fromUtf8("Georgia")});
        font.setPointSize(16);
        cities->setFont(font);
        cities->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(128, 162, 146);"));
        paths = new QPushButton(welcomePage);
        paths->setObjectName("paths");
        paths->setGeometry(QRect(310, 340, 191, 71));
        paths->setFont(font);
        paths->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(128, 162, 146);"));
        navigate = new QPushButton(welcomePage);
        navigate->setObjectName("navigate");
        navigate->setGeometry(QRect(310, 450, 191, 71));
        navigate->setFont(font);
        navigate->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(128, 162, 146);"));
        quit = new QPushButton(welcomePage);
        quit->setObjectName("quit");
        quit->setGeometry(QRect(700, 550, 100, 32));
        quit->setFont(font);
        quit->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(128, 162, 146);"));
        pushButton_5 = new QPushButton(welcomePage);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setGeometry(QRect(700, 500, 100, 32));
        pushButton_5->setFont(font);
        pushButton_5->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(128, 162, 146);"));
        label_2 = new QLabel(welcomePage);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(0, 40, 814, 61));
        label_2->setMinimumSize(QSize(60, 30));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Georgia")});
        font1.setPointSize(28);
        font1.setBold(false);
        font1.setItalic(false);
        label_2->setFont(font1);
        label_2->setAutoFillBackground(false);
        label_2->setStyleSheet(QString::fromUtf8("background-color: rgb(128, 162, 146);\n"
"color: rgb(255, 255, 255);"));
        label_2->setFrameShape(QFrame::Box);
        label_2->setFrameShadow(QFrame::Sunken);
        label_2->setAlignment(Qt::AlignCenter);
        frame = new QFrame(welcomePage);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(290, 199, 231, 351));
        frame->setStyleSheet(QString::fromUtf8("background-color: rgb(68, 71, 71);"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        frame_2 = new QFrame(welcomePage);
        frame_2->setObjectName("frame_2");
        frame_2->setGeometry(QRect(689, 490, 121, 101));
        frame_2->setStyleSheet(QString::fromUtf8("background-color: rgb(68, 71, 71);"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        frame_2->raise();
        frame->raise();
        cities->raise();
        paths->raise();
        navigate->raise();
        quit->raise();
        pushButton_5->raise();
        label_2->raise();

        retranslateUi(welcomePage);

        QMetaObject::connectSlotsByName(welcomePage);
    } // setupUi

    void retranslateUi(QDialog *welcomePage)
    {
        welcomePage->setWindowTitle(QCoreApplication::translate("welcomePage", "Dialog", nullptr));
        cities->setText(QCoreApplication::translate("welcomePage", "Manage Cities", nullptr));
        paths->setText(QCoreApplication::translate("welcomePage", "Manage Paths", nullptr));
        navigate->setText(QCoreApplication::translate("welcomePage", "Navigate", nullptr));
        quit->setText(QCoreApplication::translate("welcomePage", "Quit", nullptr));
        pushButton_5->setText(QCoreApplication::translate("welcomePage", "Help!", nullptr));
        label_2->setText(QCoreApplication::translate("welcomePage", "Map Navigator ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class welcomePage: public Ui_welcomePage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WELCOMEPAGE_H
