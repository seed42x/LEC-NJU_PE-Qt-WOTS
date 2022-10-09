/********************************************************************************
** Form generated from reading UI file 'EasterEggWindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EASTEREGGWINDOW_H
#define UI_EASTEREGGWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EasterEggWindow
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *EasterEggWindow)
    {
        if (EasterEggWindow->objectName().isEmpty())
            EasterEggWindow->setObjectName(QString::fromUtf8("EasterEggWindow"));
        EasterEggWindow->resize(300, 400);
        centralwidget = new QWidget(EasterEggWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(40, 40, 181, 31));
        EasterEggWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(EasterEggWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 300, 25));
        EasterEggWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(EasterEggWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        EasterEggWindow->setStatusBar(statusbar);

        retranslateUi(EasterEggWindow);

        QMetaObject::connectSlotsByName(EasterEggWindow);
    } // setupUi

    void retranslateUi(QMainWindow *EasterEggWindow)
    {
        EasterEggWindow->setWindowTitle(QCoreApplication::translate("EasterEggWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("EasterEggWindow", "\345\256\214\347\273\223\346\222\222\350\212\261\357\274\201just for fun.\360\237\230\217", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EasterEggWindow: public Ui_EasterEggWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EASTEREGGWINDOW_H
