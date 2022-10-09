/********************************************************************************
** Form generated from reading UI file 'UsrMainMenu.ui'
**
** Created by: Qt User Interface Compiler version 6.2.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USRMAINMENU_H
#define UI_USRMAINMENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UsrMainMenu
{
public:
    QWidget *centralwidget;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QPushButton *buyer_btn;
    QPushButton *seller_btn;
    QPushButton *info_manage_btn;
    QPushButton *exit_btn;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *UsrMainMenu)
    {
        if (UsrMainMenu->objectName().isEmpty())
            UsrMainMenu->setObjectName(QString::fromUtf8("UsrMainMenu"));
        UsrMainMenu->resize(600, 450);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(UsrMainMenu->sizePolicy().hasHeightForWidth());
        UsrMainMenu->setSizePolicy(sizePolicy);
        centralwidget = new QWidget(UsrMainMenu);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(10, 130, 101, 161));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        buyer_btn = new QPushButton(widget);
        buyer_btn->setObjectName(QString::fromUtf8("buyer_btn"));

        verticalLayout->addWidget(buyer_btn);

        seller_btn = new QPushButton(widget);
        seller_btn->setObjectName(QString::fromUtf8("seller_btn"));

        verticalLayout->addWidget(seller_btn);

        info_manage_btn = new QPushButton(widget);
        info_manage_btn->setObjectName(QString::fromUtf8("info_manage_btn"));

        verticalLayout->addWidget(info_manage_btn);

        exit_btn = new QPushButton(widget);
        exit_btn->setObjectName(QString::fromUtf8("exit_btn"));

        verticalLayout->addWidget(exit_btn);

        UsrMainMenu->setCentralWidget(centralwidget);
        menubar = new QMenuBar(UsrMainMenu);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 600, 25));
        UsrMainMenu->setMenuBar(menubar);
        statusbar = new QStatusBar(UsrMainMenu);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        UsrMainMenu->setStatusBar(statusbar);

        retranslateUi(UsrMainMenu);

        QMetaObject::connectSlotsByName(UsrMainMenu);
    } // setupUi

    void retranslateUi(QMainWindow *UsrMainMenu)
    {
        UsrMainMenu->setWindowTitle(QCoreApplication::translate("UsrMainMenu", "\345\206\254\345\245\245\347\272\252\345\277\265\345\223\201\344\272\244\346\230\223\345\271\263\345\217\260-\347\224\250\346\210\267\344\270\273\350\217\234\345\215\225", nullptr));
        buyer_btn->setText(QCoreApplication::translate("UsrMainMenu", "\346\210\221\346\230\257\344\271\260\345\256\266", nullptr));
        seller_btn->setText(QCoreApplication::translate("UsrMainMenu", "\346\210\221\346\230\257\345\215\226\345\256\266", nullptr));
        info_manage_btn->setText(QCoreApplication::translate("UsrMainMenu", "\344\270\252\344\272\272\344\277\241\346\201\257\347\256\241\347\220\206", nullptr));
        exit_btn->setText(QCoreApplication::translate("UsrMainMenu", "\346\263\250\351\224\200\347\231\273\345\275\225", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UsrMainMenu: public Ui_UsrMainMenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USRMAINMENU_H
