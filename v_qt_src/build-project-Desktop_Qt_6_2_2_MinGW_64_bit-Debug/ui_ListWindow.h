/********************************************************************************
** Form generated from reading UI file 'ListWindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LISTWINDOW_H
#define UI_LISTWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ListWindow
{
public:
    QWidget *centralwidget;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *sure_btn;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *exit_btn;
    QSpacerItem *horizontalSpacer_3;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *ListWindow)
    {
        if (ListWindow->objectName().isEmpty())
            ListWindow->setObjectName(QString::fromUtf8("ListWindow"));
        ListWindow->resize(800, 450);
        centralwidget = new QWidget(ListWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(11, 359, 641, 41));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        sure_btn = new QPushButton(layoutWidget);
        sure_btn->setObjectName(QString::fromUtf8("sure_btn"));

        horizontalLayout->addWidget(sure_btn);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        exit_btn = new QPushButton(layoutWidget);
        exit_btn->setObjectName(QString::fromUtf8("exit_btn"));

        horizontalLayout->addWidget(exit_btn);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        ListWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(ListWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 25));
        ListWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(ListWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        ListWindow->setStatusBar(statusbar);

        retranslateUi(ListWindow);

        QMetaObject::connectSlotsByName(ListWindow);
    } // setupUi

    void retranslateUi(QMainWindow *ListWindow)
    {
        ListWindow->setWindowTitle(QCoreApplication::translate("ListWindow", "MainWindow", nullptr));
        sure_btn->setText(QCoreApplication::translate("ListWindow", "\347\241\256\350\256\244", nullptr));
        exit_btn->setText(QCoreApplication::translate("ListWindow", "\351\200\200\345\207\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ListWindow: public Ui_ListWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LISTWINDOW_H
