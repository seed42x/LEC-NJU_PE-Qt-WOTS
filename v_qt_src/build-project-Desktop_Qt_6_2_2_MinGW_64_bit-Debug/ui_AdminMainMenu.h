/********************************************************************************
** Form generated from reading UI file 'AdminMainMenu.ui'
**
** Created by: Qt User Interface Compiler version 6.2.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINMAINMENU_H
#define UI_ADMINMAINMENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AdminMainMenu
{
public:
    QWidget *centralwidget;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *show_all_mers_btn;
    QPushButton *select_mer_btn;
    QPushButton *remove_mer_btn;
    QPushButton *show_all_orderforms_btn;
    QPushButton *show_all_usrs_btn;
    QPushButton *ban_usr_btn;
    QPushButton *exit_btn;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QWidget *page_2;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *select_label;
    QLineEdit *select_input;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *select_sure_btn;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label;
    QWidget *page_3;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *AdminMainMenu)
    {
        if (AdminMainMenu->objectName().isEmpty())
            AdminMainMenu->setObjectName(QString::fromUtf8("AdminMainMenu"));
        AdminMainMenu->resize(600, 450);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(AdminMainMenu->sizePolicy().hasHeightForWidth());
        AdminMainMenu->setSizePolicy(sizePolicy);
        centralwidget = new QWidget(AdminMainMenu);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 141, 391));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        show_all_mers_btn = new QPushButton(layoutWidget);
        show_all_mers_btn->setObjectName(QString::fromUtf8("show_all_mers_btn"));

        verticalLayout->addWidget(show_all_mers_btn);

        select_mer_btn = new QPushButton(layoutWidget);
        select_mer_btn->setObjectName(QString::fromUtf8("select_mer_btn"));

        verticalLayout->addWidget(select_mer_btn);

        remove_mer_btn = new QPushButton(layoutWidget);
        remove_mer_btn->setObjectName(QString::fromUtf8("remove_mer_btn"));

        verticalLayout->addWidget(remove_mer_btn);

        show_all_orderforms_btn = new QPushButton(layoutWidget);
        show_all_orderforms_btn->setObjectName(QString::fromUtf8("show_all_orderforms_btn"));

        verticalLayout->addWidget(show_all_orderforms_btn);

        show_all_usrs_btn = new QPushButton(layoutWidget);
        show_all_usrs_btn->setObjectName(QString::fromUtf8("show_all_usrs_btn"));

        verticalLayout->addWidget(show_all_usrs_btn);

        ban_usr_btn = new QPushButton(layoutWidget);
        ban_usr_btn->setObjectName(QString::fromUtf8("ban_usr_btn"));

        verticalLayout->addWidget(ban_usr_btn);

        exit_btn = new QPushButton(layoutWidget);
        exit_btn->setObjectName(QString::fromUtf8("exit_btn"));

        verticalLayout->addWidget(exit_btn);

        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(180, 80, 391, 201));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        verticalLayout_2 = new QVBoxLayout(page_2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        select_label = new QLabel(page_2);
        select_label->setObjectName(QString::fromUtf8("select_label"));

        horizontalLayout->addWidget(select_label);

        select_input = new QLineEdit(page_2);
        select_input->setObjectName(QString::fromUtf8("select_input"));

        horizontalLayout->addWidget(select_input);


        verticalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        select_sure_btn = new QPushButton(page_2);
        select_sure_btn->setObjectName(QString::fromUtf8("select_sure_btn"));

        horizontalLayout_2->addWidget(select_sure_btn);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        verticalLayout_2->addLayout(horizontalLayout_2);

        label = new QLabel(page_2);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout_2->addWidget(label);

        stackedWidget->addWidget(page_2);
        page_3 = new QWidget();
        page_3->setObjectName(QString::fromUtf8("page_3"));
        stackedWidget->addWidget(page_3);
        AdminMainMenu->setCentralWidget(centralwidget);
        menubar = new QMenuBar(AdminMainMenu);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 600, 25));
        AdminMainMenu->setMenuBar(menubar);
        statusbar = new QStatusBar(AdminMainMenu);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        AdminMainMenu->setStatusBar(statusbar);

        retranslateUi(AdminMainMenu);

        stackedWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(AdminMainMenu);
    } // setupUi

    void retranslateUi(QMainWindow *AdminMainMenu)
    {
        AdminMainMenu->setWindowTitle(QCoreApplication::translate("AdminMainMenu", "\345\206\254\345\245\245\347\272\252\345\277\265\345\223\201\344\272\244\346\230\223\345\271\263\345\217\260-\347\256\241\347\220\206\345\221\230\344\270\273\350\217\234\345\215\225", nullptr));
        show_all_mers_btn->setText(QCoreApplication::translate("AdminMainMenu", "\346\237\245\347\234\213\346\211\200\346\234\211\345\225\206\345\223\201", nullptr));
        select_mer_btn->setText(QCoreApplication::translate("AdminMainMenu", "\346\220\234\347\264\242\345\225\206\345\223\201", nullptr));
        remove_mer_btn->setText(QCoreApplication::translate("AdminMainMenu", "\344\270\213\346\236\266\345\225\206\345\223\201", nullptr));
        show_all_orderforms_btn->setText(QCoreApplication::translate("AdminMainMenu", "\346\237\245\347\234\213\346\211\200\346\234\211\350\256\242\345\215\225", nullptr));
        show_all_usrs_btn->setText(QCoreApplication::translate("AdminMainMenu", "\346\237\245\347\234\213\346\211\200\346\234\211\347\224\250\346\210\267", nullptr));
        ban_usr_btn->setText(QCoreApplication::translate("AdminMainMenu", "\345\260\201\347\246\201\347\224\250\346\210\267", nullptr));
        exit_btn->setText(QCoreApplication::translate("AdminMainMenu", "\346\263\250\351\224\200", nullptr));
        select_label->setText(QCoreApplication::translate("AdminMainMenu", "\346\220\234\347\264\242\346\240\217\357\274\232", nullptr));
        select_sure_btn->setText(QCoreApplication::translate("AdminMainMenu", "\350\277\233\350\241\214\346\220\234\347\264\242", nullptr));
        label->setText(QCoreApplication::translate("AdminMainMenu", "\360\237\220\225\350\257\267\350\276\223\345\205\245\345\225\206\345\223\201\345\220\215\347\247\260\350\277\233\350\241\214\346\243\200\347\264\242", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AdminMainMenu: public Ui_AdminMainMenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINMAINMENU_H
