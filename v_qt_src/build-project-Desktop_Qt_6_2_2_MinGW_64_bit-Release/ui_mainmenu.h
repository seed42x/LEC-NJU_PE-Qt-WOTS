/********************************************************************************
** Form generated from reading UI file 'mainmenu.ui'
**
** Created by: Qt User Interface Compiler version 6.2.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINMENU_H
#define UI_MAINMENU_H

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

class Ui_MainMenu
{
public:
    QWidget *centralwidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *admin_login_btn;
    QPushButton *usr_login_btn;
    QPushButton *usr_register_btn;
    QPushButton *exit_btn;
    QStackedWidget *stackedWidget;
    QWidget *admin_login;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *admin_login_name_label;
    QLineEdit *admin_login_name_input;
    QHBoxLayout *horizontalLayout_2;
    QLabel *admin_login_passwd_label;
    QLineEdit *admin_login_passwd_input;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer;
    QPushButton *admin_login_sure_btn;
    QSpacerItem *horizontalSpacer_2;
    QWidget *usr_login;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_6;
    QLabel *usr_login_name_label;
    QLineEdit *usr_login_name_input;
    QHBoxLayout *horizontalLayout_4;
    QLabel *usr_login_passwd_label;
    QLineEdit *usr_login_passwd_input;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *usr_login_sure_btn;
    QSpacerItem *horizontalSpacer_4;
    QWidget *usr_register;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_7;
    QLabel *usr_regis_name_lable;
    QLineEdit *usr_regis_name_input;
    QHBoxLayout *horizontalLayout_8;
    QLabel *usr_regis_passwd_label;
    QLineEdit *usr_regis_passwd_input;
    QHBoxLayout *horizontalLayout_9;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *usr_regis_sure_btn;
    QSpacerItem *horizontalSpacer_6;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainMenu)
    {
        if (MainMenu->objectName().isEmpty())
            MainMenu->setObjectName(QString::fromUtf8("MainMenu"));
        MainMenu->resize(600, 450);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainMenu->sizePolicy().hasHeightForWidth());
        MainMenu->setSizePolicy(sizePolicy);
        centralwidget = new QWidget(MainMenu);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 50, 211, 271));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        admin_login_btn = new QPushButton(verticalLayoutWidget);
        admin_login_btn->setObjectName(QString::fromUtf8("admin_login_btn"));

        verticalLayout->addWidget(admin_login_btn);

        usr_login_btn = new QPushButton(verticalLayoutWidget);
        usr_login_btn->setObjectName(QString::fromUtf8("usr_login_btn"));

        verticalLayout->addWidget(usr_login_btn);

        usr_register_btn = new QPushButton(verticalLayoutWidget);
        usr_register_btn->setObjectName(QString::fromUtf8("usr_register_btn"));

        verticalLayout->addWidget(usr_register_btn);

        exit_btn = new QPushButton(verticalLayoutWidget);
        exit_btn->setObjectName(QString::fromUtf8("exit_btn"));

        verticalLayout->addWidget(exit_btn);

        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(300, 80, 281, 221));
        sizePolicy.setHeightForWidth(stackedWidget->sizePolicy().hasHeightForWidth());
        stackedWidget->setSizePolicy(sizePolicy);
        admin_login = new QWidget();
        admin_login->setObjectName(QString::fromUtf8("admin_login"));
        verticalLayout_2 = new QVBoxLayout(admin_login);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        admin_login_name_label = new QLabel(admin_login);
        admin_login_name_label->setObjectName(QString::fromUtf8("admin_login_name_label"));

        horizontalLayout->addWidget(admin_login_name_label);

        admin_login_name_input = new QLineEdit(admin_login);
        admin_login_name_input->setObjectName(QString::fromUtf8("admin_login_name_input"));

        horizontalLayout->addWidget(admin_login_name_input);


        verticalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        admin_login_passwd_label = new QLabel(admin_login);
        admin_login_passwd_label->setObjectName(QString::fromUtf8("admin_login_passwd_label"));

        horizontalLayout_2->addWidget(admin_login_passwd_label);

        admin_login_passwd_input = new QLineEdit(admin_login);
        admin_login_passwd_input->setObjectName(QString::fromUtf8("admin_login_passwd_input"));
        admin_login_passwd_input->setEchoMode(QLineEdit::Password);

        horizontalLayout_2->addWidget(admin_login_passwd_input);


        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        admin_login_sure_btn = new QPushButton(admin_login);
        admin_login_sure_btn->setObjectName(QString::fromUtf8("admin_login_sure_btn"));

        horizontalLayout_3->addWidget(admin_login_sure_btn);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);


        verticalLayout_2->addLayout(horizontalLayout_3);

        stackedWidget->addWidget(admin_login);
        usr_login = new QWidget();
        usr_login->setObjectName(QString::fromUtf8("usr_login"));
        verticalLayout_4 = new QVBoxLayout(usr_login);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        usr_login_name_label = new QLabel(usr_login);
        usr_login_name_label->setObjectName(QString::fromUtf8("usr_login_name_label"));

        horizontalLayout_6->addWidget(usr_login_name_label);

        usr_login_name_input = new QLineEdit(usr_login);
        usr_login_name_input->setObjectName(QString::fromUtf8("usr_login_name_input"));

        horizontalLayout_6->addWidget(usr_login_name_input);


        verticalLayout_4->addLayout(horizontalLayout_6);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        usr_login_passwd_label = new QLabel(usr_login);
        usr_login_passwd_label->setObjectName(QString::fromUtf8("usr_login_passwd_label"));

        horizontalLayout_4->addWidget(usr_login_passwd_label);

        usr_login_passwd_input = new QLineEdit(usr_login);
        usr_login_passwd_input->setObjectName(QString::fromUtf8("usr_login_passwd_input"));
        usr_login_passwd_input->setEchoMode(QLineEdit::Password);

        horizontalLayout_4->addWidget(usr_login_passwd_input);


        verticalLayout_4->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_3);

        usr_login_sure_btn = new QPushButton(usr_login);
        usr_login_sure_btn->setObjectName(QString::fromUtf8("usr_login_sure_btn"));

        horizontalLayout_5->addWidget(usr_login_sure_btn);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_4);


        verticalLayout_4->addLayout(horizontalLayout_5);

        stackedWidget->addWidget(usr_login);
        usr_register = new QWidget();
        usr_register->setObjectName(QString::fromUtf8("usr_register"));
        verticalLayout_3 = new QVBoxLayout(usr_register);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        usr_regis_name_lable = new QLabel(usr_register);
        usr_regis_name_lable->setObjectName(QString::fromUtf8("usr_regis_name_lable"));

        horizontalLayout_7->addWidget(usr_regis_name_lable);

        usr_regis_name_input = new QLineEdit(usr_register);
        usr_regis_name_input->setObjectName(QString::fromUtf8("usr_regis_name_input"));

        horizontalLayout_7->addWidget(usr_regis_name_input);


        verticalLayout_3->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        usr_regis_passwd_label = new QLabel(usr_register);
        usr_regis_passwd_label->setObjectName(QString::fromUtf8("usr_regis_passwd_label"));

        horizontalLayout_8->addWidget(usr_regis_passwd_label);

        usr_regis_passwd_input = new QLineEdit(usr_register);
        usr_regis_passwd_input->setObjectName(QString::fromUtf8("usr_regis_passwd_input"));

        horizontalLayout_8->addWidget(usr_regis_passwd_input);


        verticalLayout_3->addLayout(horizontalLayout_8);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_5);

        usr_regis_sure_btn = new QPushButton(usr_register);
        usr_regis_sure_btn->setObjectName(QString::fromUtf8("usr_regis_sure_btn"));

        horizontalLayout_9->addWidget(usr_regis_sure_btn);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_6);


        verticalLayout_3->addLayout(horizontalLayout_9);

        stackedWidget->addWidget(usr_register);
        MainMenu->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainMenu);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 600, 25));
        MainMenu->setMenuBar(menubar);
        statusbar = new QStatusBar(MainMenu);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainMenu->setStatusBar(statusbar);

        retranslateUi(MainMenu);

        stackedWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainMenu);
    } // setupUi

    void retranslateUi(QMainWindow *MainMenu)
    {
        MainMenu->setWindowTitle(QCoreApplication::translate("MainMenu", "\345\206\254\345\245\245\347\272\252\345\277\265\345\223\201\344\272\244\346\230\223\345\271\263\345\217\260-\344\270\273\350\217\234\345\215\225", nullptr));
        admin_login_btn->setText(QCoreApplication::translate("MainMenu", "\347\256\241\347\220\206\345\221\230\347\231\273\345\275\225", nullptr));
        usr_login_btn->setText(QCoreApplication::translate("MainMenu", "\347\224\250\346\210\267\347\231\273\345\275\225", nullptr));
        usr_register_btn->setText(QCoreApplication::translate("MainMenu", "\347\224\250\346\210\267\346\263\250\345\206\214", nullptr));
        exit_btn->setText(QCoreApplication::translate("MainMenu", "\351\200\200\345\207\272\347\263\273\347\273\237", nullptr));
        admin_login_name_label->setText(QCoreApplication::translate("MainMenu", "\347\256\241\347\220\206\345\221\230\345\247\223\345\220\215\357\274\232", nullptr));
        admin_login_passwd_label->setText(QCoreApplication::translate("MainMenu", "\347\256\241\347\220\206\345\221\230\345\257\206\347\240\201\357\274\232", nullptr));
        admin_login_sure_btn->setText(QCoreApplication::translate("MainMenu", "\347\241\256\350\256\244\347\231\273\345\275\225", nullptr));
        usr_login_name_label->setText(QCoreApplication::translate("MainMenu", "\347\224\250\346\210\267\345\247\223\345\220\215\357\274\232", nullptr));
        usr_login_passwd_label->setText(QCoreApplication::translate("MainMenu", "\347\224\250\346\210\267\345\257\206\347\240\201\357\274\232", nullptr));
        usr_login_sure_btn->setText(QCoreApplication::translate("MainMenu", "\347\241\256\350\256\244\347\231\273\345\275\225", nullptr));
        usr_regis_name_lable->setText(QCoreApplication::translate("MainMenu", "\347\224\250\346\210\267\345\247\223\345\220\215\357\274\232", nullptr));
        usr_regis_passwd_label->setText(QCoreApplication::translate("MainMenu", "\347\224\250\346\210\267\345\257\206\347\240\201\357\274\232", nullptr));
        usr_regis_sure_btn->setText(QCoreApplication::translate("MainMenu", "\347\241\256\350\256\244\346\263\250\345\206\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainMenu: public Ui_MainMenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINMENU_H
