/********************************************************************************
** Form generated from reading UI file 'UsrInfoMainMenu.ui'
**
** Created by: Qt User Interface Compiler version 6.2.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USRINFOMAINMENU_H
#define UI_USRINFOMAINMENU_H

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

class Ui_UsrInfoMainMenu
{
public:
    QWidget *centralwidget;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *show_info_btn;
    QPushButton *modify_info_btn;
    QPushButton *recharge_btn;
    QPushButton *exit_btn;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QVBoxLayout *verticalLayout_3;
    QSpacerItem *verticalSpacer;
    QLabel *details_info_title_label;
    QHBoxLayout *horizontalLayout_13;
    QSpacerItem *horizontalSpacer_6;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *header_id_label;
    QSpacerItem *horizontalSpacer_7;
    QLabel *id_info_label;
    QHBoxLayout *horizontalLayout_2;
    QLabel *header_name_label;
    QSpacerItem *horizontalSpacer_8;
    QLabel *name_info_label;
    QHBoxLayout *horizontalLayout_3;
    QLabel *header_pnum_label;
    QSpacerItem *horizontalSpacer_9;
    QLabel *pnum_info_label;
    QHBoxLayout *horizontalLayout_4;
    QLabel *header_addr_label;
    QSpacerItem *horizontalSpacer_10;
    QLabel *addr_info_label;
    QHBoxLayout *horizontalLayout_5;
    QLabel *header_balance_label;
    QSpacerItem *horizontalSpacer_11;
    QLabel *balance_info_label;
    QHBoxLayout *horizontalLayout_14;
    QLabel *header_ori_expr_label;
    QSpacerItem *horizontalSpacer_12;
    QLabel *ori_expr_info_label;
    QHBoxLayout *horizontalLayout_15;
    QLabel *header_simple_expr_label;
    QSpacerItem *horizontalSpacer_13;
    QLabel *simple_simple_expr_info_label;
    QSpacerItem *horizontalSpacer_5;
    QSpacerItem *verticalSpacer_2;
    QWidget *page_2;
    QVBoxLayout *verticalLayout_4;
    QSpacerItem *verticalSpacer_3;
    QHBoxLayout *horizontalLayout_6;
    QLabel *modify_header_name_label;
    QLineEdit *modify_name_input;
    QHBoxLayout *horizontalLayout_7;
    QLabel *modify_header_pnum_label;
    QLineEdit *modify_pnum_input;
    QHBoxLayout *horizontalLayout_8;
    QLabel *modify_header_addr_label;
    QLineEdit *modify_addr_input;
    QHBoxLayout *horizontalLayout_9;
    QSpacerItem *horizontalSpacer;
    QPushButton *modify_sure_btn;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer_4;
    QWidget *page_3;
    QVBoxLayout *verticalLayout_5;
    QSpacerItem *verticalSpacer_5;
    QHBoxLayout *horizontalLayout_10;
    QLabel *header_cur_balance_label;
    QLabel *cur_balance_label;
    QHBoxLayout *horizontalLayout_11;
    QLabel *header_recharge_label;
    QLineEdit *recharge_input;
    QHBoxLayout *horizontalLayout_12;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *recharge_sure_btn;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *verticalSpacer_6;
    QWidget *page_4;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *UsrInfoMainMenu)
    {
        if (UsrInfoMainMenu->objectName().isEmpty())
            UsrInfoMainMenu->setObjectName(QString::fromUtf8("UsrInfoMainMenu"));
        UsrInfoMainMenu->resize(600, 450);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(UsrInfoMainMenu->sizePolicy().hasHeightForWidth());
        UsrInfoMainMenu->setSizePolicy(sizePolicy);
        centralwidget = new QWidget(UsrInfoMainMenu);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 80, 121, 251));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        show_info_btn = new QPushButton(layoutWidget);
        show_info_btn->setObjectName(QString::fromUtf8("show_info_btn"));

        verticalLayout->addWidget(show_info_btn);

        modify_info_btn = new QPushButton(layoutWidget);
        modify_info_btn->setObjectName(QString::fromUtf8("modify_info_btn"));

        verticalLayout->addWidget(modify_info_btn);

        recharge_btn = new QPushButton(layoutWidget);
        recharge_btn->setObjectName(QString::fromUtf8("recharge_btn"));

        verticalLayout->addWidget(recharge_btn);

        exit_btn = new QPushButton(layoutWidget);
        exit_btn->setObjectName(QString::fromUtf8("exit_btn"));

        verticalLayout->addWidget(exit_btn);

        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(193, 10, 391, 391));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        verticalLayout_3 = new QVBoxLayout(page);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);

        details_info_title_label = new QLabel(page);
        details_info_title_label->setObjectName(QString::fromUtf8("details_info_title_label"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(details_info_title_label->sizePolicy().hasHeightForWidth());
        details_info_title_label->setSizePolicy(sizePolicy1);
        details_info_title_label->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(details_info_title_label);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_13->addItem(horizontalSpacer_6);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        header_id_label = new QLabel(page);
        header_id_label->setObjectName(QString::fromUtf8("header_id_label"));

        horizontalLayout->addWidget(header_id_label);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_7);

        id_info_label = new QLabel(page);
        id_info_label->setObjectName(QString::fromUtf8("id_info_label"));

        horizontalLayout->addWidget(id_info_label);


        verticalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        header_name_label = new QLabel(page);
        header_name_label->setObjectName(QString::fromUtf8("header_name_label"));

        horizontalLayout_2->addWidget(header_name_label);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_8);

        name_info_label = new QLabel(page);
        name_info_label->setObjectName(QString::fromUtf8("name_info_label"));

        horizontalLayout_2->addWidget(name_info_label);


        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        header_pnum_label = new QLabel(page);
        header_pnum_label->setObjectName(QString::fromUtf8("header_pnum_label"));

        horizontalLayout_3->addWidget(header_pnum_label);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_9);

        pnum_info_label = new QLabel(page);
        pnum_info_label->setObjectName(QString::fromUtf8("pnum_info_label"));

        horizontalLayout_3->addWidget(pnum_info_label);


        verticalLayout_2->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        header_addr_label = new QLabel(page);
        header_addr_label->setObjectName(QString::fromUtf8("header_addr_label"));

        horizontalLayout_4->addWidget(header_addr_label);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_10);

        addr_info_label = new QLabel(page);
        addr_info_label->setObjectName(QString::fromUtf8("addr_info_label"));

        horizontalLayout_4->addWidget(addr_info_label);


        verticalLayout_2->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        header_balance_label = new QLabel(page);
        header_balance_label->setObjectName(QString::fromUtf8("header_balance_label"));

        horizontalLayout_5->addWidget(header_balance_label);

        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_11);

        balance_info_label = new QLabel(page);
        balance_info_label->setObjectName(QString::fromUtf8("balance_info_label"));

        horizontalLayout_5->addWidget(balance_info_label);


        verticalLayout_2->addLayout(horizontalLayout_5);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setObjectName(QString::fromUtf8("horizontalLayout_14"));
        header_ori_expr_label = new QLabel(page);
        header_ori_expr_label->setObjectName(QString::fromUtf8("header_ori_expr_label"));

        horizontalLayout_14->addWidget(header_ori_expr_label);

        horizontalSpacer_12 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_14->addItem(horizontalSpacer_12);

        ori_expr_info_label = new QLabel(page);
        ori_expr_info_label->setObjectName(QString::fromUtf8("ori_expr_info_label"));

        horizontalLayout_14->addWidget(ori_expr_info_label);


        verticalLayout_2->addLayout(horizontalLayout_14);

        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setObjectName(QString::fromUtf8("horizontalLayout_15"));
        header_simple_expr_label = new QLabel(page);
        header_simple_expr_label->setObjectName(QString::fromUtf8("header_simple_expr_label"));

        horizontalLayout_15->addWidget(header_simple_expr_label);

        horizontalSpacer_13 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_15->addItem(horizontalSpacer_13);

        simple_simple_expr_info_label = new QLabel(page);
        simple_simple_expr_info_label->setObjectName(QString::fromUtf8("simple_simple_expr_info_label"));

        horizontalLayout_15->addWidget(simple_simple_expr_info_label);


        verticalLayout_2->addLayout(horizontalLayout_15);


        horizontalLayout_13->addLayout(verticalLayout_2);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_13->addItem(horizontalSpacer_5);


        verticalLayout_3->addLayout(horizontalLayout_13);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_2);

        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        verticalLayout_4 = new QVBoxLayout(page_2);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer_3);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        modify_header_name_label = new QLabel(page_2);
        modify_header_name_label->setObjectName(QString::fromUtf8("modify_header_name_label"));

        horizontalLayout_6->addWidget(modify_header_name_label);

        modify_name_input = new QLineEdit(page_2);
        modify_name_input->setObjectName(QString::fromUtf8("modify_name_input"));

        horizontalLayout_6->addWidget(modify_name_input);


        verticalLayout_4->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        modify_header_pnum_label = new QLabel(page_2);
        modify_header_pnum_label->setObjectName(QString::fromUtf8("modify_header_pnum_label"));

        horizontalLayout_7->addWidget(modify_header_pnum_label);

        modify_pnum_input = new QLineEdit(page_2);
        modify_pnum_input->setObjectName(QString::fromUtf8("modify_pnum_input"));

        horizontalLayout_7->addWidget(modify_pnum_input);


        verticalLayout_4->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        modify_header_addr_label = new QLabel(page_2);
        modify_header_addr_label->setObjectName(QString::fromUtf8("modify_header_addr_label"));

        horizontalLayout_8->addWidget(modify_header_addr_label);

        modify_addr_input = new QLineEdit(page_2);
        modify_addr_input->setObjectName(QString::fromUtf8("modify_addr_input"));

        horizontalLayout_8->addWidget(modify_addr_input);


        verticalLayout_4->addLayout(horizontalLayout_8);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer);

        modify_sure_btn = new QPushButton(page_2);
        modify_sure_btn->setObjectName(QString::fromUtf8("modify_sure_btn"));

        horizontalLayout_9->addWidget(modify_sure_btn);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_2);


        verticalLayout_4->addLayout(horizontalLayout_9);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer_4);

        stackedWidget->addWidget(page_2);
        page_3 = new QWidget();
        page_3->setObjectName(QString::fromUtf8("page_3"));
        verticalLayout_5 = new QVBoxLayout(page_3);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer_5);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        header_cur_balance_label = new QLabel(page_3);
        header_cur_balance_label->setObjectName(QString::fromUtf8("header_cur_balance_label"));

        horizontalLayout_10->addWidget(header_cur_balance_label);

        cur_balance_label = new QLabel(page_3);
        cur_balance_label->setObjectName(QString::fromUtf8("cur_balance_label"));

        horizontalLayout_10->addWidget(cur_balance_label);


        verticalLayout_5->addLayout(horizontalLayout_10);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        header_recharge_label = new QLabel(page_3);
        header_recharge_label->setObjectName(QString::fromUtf8("header_recharge_label"));

        horizontalLayout_11->addWidget(header_recharge_label);

        recharge_input = new QLineEdit(page_3);
        recharge_input->setObjectName(QString::fromUtf8("recharge_input"));

        horizontalLayout_11->addWidget(recharge_input);


        verticalLayout_5->addLayout(horizontalLayout_11);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_12->addItem(horizontalSpacer_3);

        recharge_sure_btn = new QPushButton(page_3);
        recharge_sure_btn->setObjectName(QString::fromUtf8("recharge_sure_btn"));

        horizontalLayout_12->addWidget(recharge_sure_btn);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_12->addItem(horizontalSpacer_4);


        verticalLayout_5->addLayout(horizontalLayout_12);

        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer_6);

        stackedWidget->addWidget(page_3);
        page_4 = new QWidget();
        page_4->setObjectName(QString::fromUtf8("page_4"));
        stackedWidget->addWidget(page_4);
        UsrInfoMainMenu->setCentralWidget(centralwidget);
        menubar = new QMenuBar(UsrInfoMainMenu);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 600, 25));
        UsrInfoMainMenu->setMenuBar(menubar);
        statusbar = new QStatusBar(UsrInfoMainMenu);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        UsrInfoMainMenu->setStatusBar(statusbar);

        retranslateUi(UsrInfoMainMenu);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(UsrInfoMainMenu);
    } // setupUi

    void retranslateUi(QMainWindow *UsrInfoMainMenu)
    {
        UsrInfoMainMenu->setWindowTitle(QCoreApplication::translate("UsrInfoMainMenu", "\345\206\254\345\245\245\347\272\252\345\277\265\345\223\201\344\272\244\346\230\223\345\271\263\345\217\260-\347\224\250\346\210\267\344\277\241\346\201\257\347\256\241\347\220\206", nullptr));
        show_info_btn->setText(QCoreApplication::translate("UsrInfoMainMenu", "\346\237\245\347\234\213\344\277\241\346\201\257", nullptr));
        modify_info_btn->setText(QCoreApplication::translate("UsrInfoMainMenu", "\344\277\256\346\224\271\344\277\241\346\201\257", nullptr));
        recharge_btn->setText(QCoreApplication::translate("UsrInfoMainMenu", "\345\205\205\345\200\274", nullptr));
        exit_btn->setText(QCoreApplication::translate("UsrInfoMainMenu", "\350\277\224\345\233\236\347\224\250\346\210\267\344\270\273\347\225\214\351\235\242", nullptr));
        details_info_title_label->setText(QCoreApplication::translate("UsrInfoMainMenu", "\347\224\250\346\210\267\350\257\246\347\273\206\344\277\241\346\201\257", nullptr));
        header_id_label->setText(QCoreApplication::translate("UsrInfoMainMenu", "\347\224\250\346\210\267ID:", nullptr));
        id_info_label->setText(QString());
        header_name_label->setText(QCoreApplication::translate("UsrInfoMainMenu", "\347\224\250\346\210\267\345\247\223\345\220\215:", nullptr));
        name_info_label->setText(QString());
        header_pnum_label->setText(QCoreApplication::translate("UsrInfoMainMenu", "\350\201\224\347\263\273\346\226\271\345\274\217:", nullptr));
        pnum_info_label->setText(QString());
        header_addr_label->setText(QCoreApplication::translate("UsrInfoMainMenu", "\345\234\260\345\235\200:", nullptr));
        addr_info_label->setText(QString());
        header_balance_label->setText(QCoreApplication::translate("UsrInfoMainMenu", "\344\275\231\351\242\235:", nullptr));
        balance_info_label->setText(QString());
        header_ori_expr_label->setText(QCoreApplication::translate("UsrInfoMainMenu", "\345\210\235\345\247\213\350\241\250\350\276\276\345\274\217\357\274\232", nullptr));
        ori_expr_info_label->setText(QString());
        header_simple_expr_label->setText(QCoreApplication::translate("UsrInfoMainMenu", "\347\256\200\345\214\226\350\241\250\350\276\276\345\274\217\357\274\232", nullptr));
        simple_simple_expr_info_label->setText(QString());
        modify_header_name_label->setText(QCoreApplication::translate("UsrInfoMainMenu", "\347\224\250\346\210\267\345\247\223\345\220\215\357\274\232", nullptr));
        modify_header_pnum_label->setText(QCoreApplication::translate("UsrInfoMainMenu", "\350\201\224\347\263\273\346\226\271\345\274\217\357\274\232", nullptr));
        modify_header_addr_label->setText(QCoreApplication::translate("UsrInfoMainMenu", "\345\261\205\344\275\217\345\234\260\345\235\200\357\274\232", nullptr));
        modify_sure_btn->setText(QCoreApplication::translate("UsrInfoMainMenu", "\347\241\256\350\256\244\344\277\256\346\224\271", nullptr));
        header_cur_balance_label->setText(QCoreApplication::translate("UsrInfoMainMenu", "\345\275\223\345\211\215\344\275\231\351\242\235\357\274\232", nullptr));
        cur_balance_label->setText(QString());
        header_recharge_label->setText(QCoreApplication::translate("UsrInfoMainMenu", "\345\205\205\345\200\274\351\207\221\351\242\235\357\274\232", nullptr));
        recharge_sure_btn->setText(QCoreApplication::translate("UsrInfoMainMenu", "\347\241\256\350\256\244\345\205\205\345\200\274", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UsrInfoMainMenu: public Ui_UsrInfoMainMenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USRINFOMAINMENU_H
