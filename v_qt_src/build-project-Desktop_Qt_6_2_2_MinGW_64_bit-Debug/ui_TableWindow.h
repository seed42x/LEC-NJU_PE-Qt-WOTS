/********************************************************************************
** Form generated from reading UI file 'TableWindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TABLEWINDOW_H
#define UI_TABLEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TableWindow
{
public:
    QMenuBar *menubar;
    QWidget *centralwidget;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *TableWindow)
    {
        if (TableWindow->objectName().isEmpty())
            TableWindow->setObjectName(QString::fromUtf8("TableWindow"));
        TableWindow->resize(800, 600);
        menubar = new QMenuBar(TableWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        TableWindow->setMenuBar(menubar);
        centralwidget = new QWidget(TableWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        TableWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(TableWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        TableWindow->setStatusBar(statusbar);

        retranslateUi(TableWindow);

        QMetaObject::connectSlotsByName(TableWindow);
    } // setupUi

    void retranslateUi(QMainWindow *TableWindow)
    {
        TableWindow->setWindowTitle(QCoreApplication::translate("TableWindow", "MainWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TableWindow: public Ui_TableWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TABLEWINDOW_H
