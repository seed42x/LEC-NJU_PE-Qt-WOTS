/********************************************************************************
** Form generated from reading UI file 'SellerMainMenu.ui'
**
** Created by: Qt User Interface Compiler version 6.2.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SELLERMAINMENU_H
#define UI_SELLERMAINMENU_H

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

class Ui_SellerMainMenu
{
public:
    QWidget *centralwidget;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *add_mer_btn;
    QPushButton *show_mers_btn;
    QPushButton *modify_merinfo_btn;
    QPushButton *remove_mer_btn;
    QPushButton *show_orderforms_btn;
    QPushButton *exit_btn;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *verticalSpacer_3;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *added_mer_title_label;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_7;
    QLabel *mer_name_label;
    QSpacerItem *horizontalSpacer_3;
    QLineEdit *mer_name_input;
    QSpacerItem *horizontalSpacer_8;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_9;
    QLabel *mer_price_label;
    QSpacerItem *horizontalSpacer_4;
    QLineEdit *mer_price_input;
    QSpacerItem *horizontalSpacer_10;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_11;
    QLabel *mer_num_label;
    QSpacerItem *horizontalSpacer_5;
    QLineEdit *mer_num_input;
    QSpacerItem *horizontalSpacer_12;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_13;
    QLabel *mer_desc_label;
    QSpacerItem *horizontalSpacer_6;
    QLineEdit *mer_desc_input;
    QSpacerItem *horizontalSpacer_14;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer_15;
    QPushButton *add_mer_sure_btn;
    QSpacerItem *horizontalSpacer_16;
    QPushButton *clear_content_btn;
    QSpacerItem *horizontalSpacer_17;
    QSpacerItem *verticalSpacer_4;
    QWidget *page_2;
    QVBoxLayout *verticalLayout_3;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_7;
    QSpacerItem *horizontalSpacer_18;
    QLabel *modify_mer_title_label;
    QSpacerItem *horizontalSpacer_19;
    QHBoxLayout *horizontalLayout_8;
    QSpacerItem *horizontalSpacer_20;
    QLabel *header_mer_id_label;
    QSpacerItem *horizontalSpacer_22;
    QLabel *mer_id_info_label;
    QSpacerItem *horizontalSpacer_21;
    QHBoxLayout *horizontalLayout_9;
    QSpacerItem *horizontalSpacer_23;
    QLabel *header_mer_name_label;
    QSpacerItem *horizontalSpacer_24;
    QLabel *mer_name_info_label;
    QSpacerItem *horizontalSpacer_25;
    QHBoxLayout *horizontalLayout_10;
    QSpacerItem *horizontalSpacer_26;
    QLabel *header_mer_price_label;
    QSpacerItem *horizontalSpacer_42;
    QLabel *mer_price_info_label;
    QSpacerItem *horizontalSpacer_27;
    QHBoxLayout *horizontalLayout_11;
    QSpacerItem *horizontalSpacer_28;
    QLabel *header_mer_num_label;
    QSpacerItem *horizontalSpacer_29;
    QLabel *mer_num_info_label;
    QSpacerItem *horizontalSpacer_30;
    QHBoxLayout *horizontalLayout_12;
    QSpacerItem *horizontalSpacer_31;
    QLabel *header_mer_desc_label;
    QSpacerItem *horizontalSpacer_32;
    QLabel *mer_desc_info_label;
    QSpacerItem *horizontalSpacer_33;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_13;
    QSpacerItem *horizontalSpacer_34;
    QLabel *header_new_price_label;
    QSpacerItem *horizontalSpacer_36;
    QLineEdit *new_price_input;
    QSpacerItem *horizontalSpacer_35;
    QHBoxLayout *horizontalLayout_14;
    QSpacerItem *horizontalSpacer_37;
    QLabel *header_new_desc_label;
    QSpacerItem *horizontalSpacer_38;
    QLineEdit *new_desc_input;
    QSpacerItem *horizontalSpacer_39;
    QHBoxLayout *horizontalLayout_15;
    QSpacerItem *horizontalSpacer_40;
    QPushButton *modify_sure_btn;
    QSpacerItem *horizontalSpacer_41;
    QSpacerItem *verticalSpacer_5;
    QWidget *page_3;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *SellerMainMenu)
    {
        if (SellerMainMenu->objectName().isEmpty())
            SellerMainMenu->setObjectName(QString::fromUtf8("SellerMainMenu"));
        SellerMainMenu->resize(600, 450);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(SellerMainMenu->sizePolicy().hasHeightForWidth());
        SellerMainMenu->setSizePolicy(sizePolicy);
        centralwidget = new QWidget(SellerMainMenu);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(30, 40, 121, 321));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        add_mer_btn = new QPushButton(layoutWidget);
        add_mer_btn->setObjectName(QString::fromUtf8("add_mer_btn"));

        verticalLayout->addWidget(add_mer_btn);

        show_mers_btn = new QPushButton(layoutWidget);
        show_mers_btn->setObjectName(QString::fromUtf8("show_mers_btn"));

        verticalLayout->addWidget(show_mers_btn);

        modify_merinfo_btn = new QPushButton(layoutWidget);
        modify_merinfo_btn->setObjectName(QString::fromUtf8("modify_merinfo_btn"));

        verticalLayout->addWidget(modify_merinfo_btn);

        remove_mer_btn = new QPushButton(layoutWidget);
        remove_mer_btn->setObjectName(QString::fromUtf8("remove_mer_btn"));

        verticalLayout->addWidget(remove_mer_btn);

        show_orderforms_btn = new QPushButton(layoutWidget);
        show_orderforms_btn->setObjectName(QString::fromUtf8("show_orderforms_btn"));

        verticalLayout->addWidget(show_orderforms_btn);

        exit_btn = new QPushButton(layoutWidget);
        exit_btn->setObjectName(QString::fromUtf8("exit_btn"));

        verticalLayout->addWidget(exit_btn);

        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(180, 10, 411, 381));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        verticalLayout_2 = new QVBoxLayout(page);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        added_mer_title_label = new QLabel(page);
        added_mer_title_label->setObjectName(QString::fromUtf8("added_mer_title_label"));

        horizontalLayout->addWidget(added_mer_title_label);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_7);

        mer_name_label = new QLabel(page);
        mer_name_label->setObjectName(QString::fromUtf8("mer_name_label"));

        horizontalLayout_2->addWidget(mer_name_label);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        mer_name_input = new QLineEdit(page);
        mer_name_input->setObjectName(QString::fromUtf8("mer_name_input"));

        horizontalLayout_2->addWidget(mer_name_input);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_8);


        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_9);

        mer_price_label = new QLabel(page);
        mer_price_label->setObjectName(QString::fromUtf8("mer_price_label"));

        horizontalLayout_3->addWidget(mer_price_label);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_4);

        mer_price_input = new QLineEdit(page);
        mer_price_input->setObjectName(QString::fromUtf8("mer_price_input"));

        horizontalLayout_3->addWidget(mer_price_input);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_10);


        verticalLayout_2->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_11);

        mer_num_label = new QLabel(page);
        mer_num_label->setObjectName(QString::fromUtf8("mer_num_label"));

        horizontalLayout_4->addWidget(mer_num_label);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_5);

        mer_num_input = new QLineEdit(page);
        mer_num_input->setObjectName(QString::fromUtf8("mer_num_input"));

        horizontalLayout_4->addWidget(mer_num_input);

        horizontalSpacer_12 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_12);


        verticalLayout_2->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalSpacer_13 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_13);

        mer_desc_label = new QLabel(page);
        mer_desc_label->setObjectName(QString::fromUtf8("mer_desc_label"));

        horizontalLayout_5->addWidget(mer_desc_label);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_6);

        mer_desc_input = new QLineEdit(page);
        mer_desc_input->setObjectName(QString::fromUtf8("mer_desc_input"));

        horizontalLayout_5->addWidget(mer_desc_input);

        horizontalSpacer_14 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_14);


        verticalLayout_2->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalSpacer_15 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_15);

        add_mer_sure_btn = new QPushButton(page);
        add_mer_sure_btn->setObjectName(QString::fromUtf8("add_mer_sure_btn"));

        horizontalLayout_6->addWidget(add_mer_sure_btn);

        horizontalSpacer_16 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_16);

        clear_content_btn = new QPushButton(page);
        clear_content_btn->setObjectName(QString::fromUtf8("clear_content_btn"));

        horizontalLayout_6->addWidget(clear_content_btn);

        horizontalSpacer_17 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_17);


        verticalLayout_2->addLayout(horizontalLayout_6);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_4);

        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        verticalLayout_3 = new QVBoxLayout(page_2);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        horizontalSpacer_18 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_18);

        modify_mer_title_label = new QLabel(page_2);
        modify_mer_title_label->setObjectName(QString::fromUtf8("modify_mer_title_label"));

        horizontalLayout_7->addWidget(modify_mer_title_label);

        horizontalSpacer_19 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_19);


        verticalLayout_3->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        horizontalSpacer_20 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_20);

        header_mer_id_label = new QLabel(page_2);
        header_mer_id_label->setObjectName(QString::fromUtf8("header_mer_id_label"));

        horizontalLayout_8->addWidget(header_mer_id_label);

        horizontalSpacer_22 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_22);

        mer_id_info_label = new QLabel(page_2);
        mer_id_info_label->setObjectName(QString::fromUtf8("mer_id_info_label"));

        horizontalLayout_8->addWidget(mer_id_info_label);

        horizontalSpacer_21 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_21);


        verticalLayout_3->addLayout(horizontalLayout_8);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        horizontalSpacer_23 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_23);

        header_mer_name_label = new QLabel(page_2);
        header_mer_name_label->setObjectName(QString::fromUtf8("header_mer_name_label"));

        horizontalLayout_9->addWidget(header_mer_name_label);

        horizontalSpacer_24 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_24);

        mer_name_info_label = new QLabel(page_2);
        mer_name_info_label->setObjectName(QString::fromUtf8("mer_name_info_label"));

        horizontalLayout_9->addWidget(mer_name_info_label);

        horizontalSpacer_25 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_25);


        verticalLayout_3->addLayout(horizontalLayout_9);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        horizontalSpacer_26 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_26);

        header_mer_price_label = new QLabel(page_2);
        header_mer_price_label->setObjectName(QString::fromUtf8("header_mer_price_label"));

        horizontalLayout_10->addWidget(header_mer_price_label);

        horizontalSpacer_42 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_42);

        mer_price_info_label = new QLabel(page_2);
        mer_price_info_label->setObjectName(QString::fromUtf8("mer_price_info_label"));

        horizontalLayout_10->addWidget(mer_price_info_label);

        horizontalSpacer_27 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_27);


        verticalLayout_3->addLayout(horizontalLayout_10);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        horizontalSpacer_28 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_11->addItem(horizontalSpacer_28);

        header_mer_num_label = new QLabel(page_2);
        header_mer_num_label->setObjectName(QString::fromUtf8("header_mer_num_label"));

        horizontalLayout_11->addWidget(header_mer_num_label);

        horizontalSpacer_29 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_11->addItem(horizontalSpacer_29);

        mer_num_info_label = new QLabel(page_2);
        mer_num_info_label->setObjectName(QString::fromUtf8("mer_num_info_label"));

        horizontalLayout_11->addWidget(mer_num_info_label);

        horizontalSpacer_30 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_11->addItem(horizontalSpacer_30);


        verticalLayout_3->addLayout(horizontalLayout_11);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        horizontalSpacer_31 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_12->addItem(horizontalSpacer_31);

        header_mer_desc_label = new QLabel(page_2);
        header_mer_desc_label->setObjectName(QString::fromUtf8("header_mer_desc_label"));

        horizontalLayout_12->addWidget(header_mer_desc_label);

        horizontalSpacer_32 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_12->addItem(horizontalSpacer_32);

        mer_desc_info_label = new QLabel(page_2);
        mer_desc_info_label->setObjectName(QString::fromUtf8("mer_desc_info_label"));

        horizontalLayout_12->addWidget(mer_desc_info_label);

        horizontalSpacer_33 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_12->addItem(horizontalSpacer_33);


        verticalLayout_3->addLayout(horizontalLayout_12);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_2);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        horizontalSpacer_34 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_13->addItem(horizontalSpacer_34);

        header_new_price_label = new QLabel(page_2);
        header_new_price_label->setObjectName(QString::fromUtf8("header_new_price_label"));

        horizontalLayout_13->addWidget(header_new_price_label);

        horizontalSpacer_36 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_13->addItem(horizontalSpacer_36);

        new_price_input = new QLineEdit(page_2);
        new_price_input->setObjectName(QString::fromUtf8("new_price_input"));

        horizontalLayout_13->addWidget(new_price_input);

        horizontalSpacer_35 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_13->addItem(horizontalSpacer_35);


        verticalLayout_3->addLayout(horizontalLayout_13);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setObjectName(QString::fromUtf8("horizontalLayout_14"));
        horizontalSpacer_37 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_14->addItem(horizontalSpacer_37);

        header_new_desc_label = new QLabel(page_2);
        header_new_desc_label->setObjectName(QString::fromUtf8("header_new_desc_label"));

        horizontalLayout_14->addWidget(header_new_desc_label);

        horizontalSpacer_38 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_14->addItem(horizontalSpacer_38);

        new_desc_input = new QLineEdit(page_2);
        new_desc_input->setObjectName(QString::fromUtf8("new_desc_input"));

        horizontalLayout_14->addWidget(new_desc_input);

        horizontalSpacer_39 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_14->addItem(horizontalSpacer_39);


        verticalLayout_3->addLayout(horizontalLayout_14);

        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setObjectName(QString::fromUtf8("horizontalLayout_15"));
        horizontalSpacer_40 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_15->addItem(horizontalSpacer_40);

        modify_sure_btn = new QPushButton(page_2);
        modify_sure_btn->setObjectName(QString::fromUtf8("modify_sure_btn"));

        horizontalLayout_15->addWidget(modify_sure_btn);

        horizontalSpacer_41 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_15->addItem(horizontalSpacer_41);


        verticalLayout_3->addLayout(horizontalLayout_15);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_5);

        stackedWidget->addWidget(page_2);
        page_3 = new QWidget();
        page_3->setObjectName(QString::fromUtf8("page_3"));
        stackedWidget->addWidget(page_3);
        SellerMainMenu->setCentralWidget(centralwidget);
        menubar = new QMenuBar(SellerMainMenu);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 600, 25));
        SellerMainMenu->setMenuBar(menubar);
        statusbar = new QStatusBar(SellerMainMenu);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        SellerMainMenu->setStatusBar(statusbar);

        retranslateUi(SellerMainMenu);

        stackedWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(SellerMainMenu);
    } // setupUi

    void retranslateUi(QMainWindow *SellerMainMenu)
    {
        SellerMainMenu->setWindowTitle(QCoreApplication::translate("SellerMainMenu", "\345\206\254\345\245\245\347\272\252\345\277\265\345\223\201\344\272\244\346\230\223\345\271\263\345\217\260-\345\215\226\345\256\266\344\270\273\350\217\234\345\215\225", nullptr));
        add_mer_btn->setText(QCoreApplication::translate("SellerMainMenu", "\345\217\221\345\270\203\345\225\206\345\223\201", nullptr));
        show_mers_btn->setText(QCoreApplication::translate("SellerMainMenu", "\346\237\245\347\234\213\345\217\221\345\270\203\345\225\206\345\223\201", nullptr));
        modify_merinfo_btn->setText(QCoreApplication::translate("SellerMainMenu", "\344\277\256\346\224\271\345\225\206\345\223\201\344\277\241\346\201\257", nullptr));
        remove_mer_btn->setText(QCoreApplication::translate("SellerMainMenu", "\344\270\213\346\236\266\345\225\206\345\223\201", nullptr));
        show_orderforms_btn->setText(QCoreApplication::translate("SellerMainMenu", "\346\237\245\347\234\213\345\216\206\345\217\262\350\256\242\345\215\225", nullptr));
        exit_btn->setText(QCoreApplication::translate("SellerMainMenu", "\350\277\224\345\233\236\347\224\250\346\210\267\344\270\273\347\225\214\351\235\242", nullptr));
        added_mer_title_label->setText(QCoreApplication::translate("SellerMainMenu", "\345\217\221\345\270\203\345\225\206\345\223\201", nullptr));
        mer_name_label->setText(QCoreApplication::translate("SellerMainMenu", "\345\225\206\345\223\201\345\220\215\347\247\260\357\274\232", nullptr));
        mer_price_label->setText(QCoreApplication::translate("SellerMainMenu", "\345\225\206\345\223\201\344\273\267\346\240\274\357\274\232", nullptr));
        mer_num_label->setText(QCoreApplication::translate("SellerMainMenu", "\345\225\206\345\223\201\346\225\260\351\207\217\357\274\232", nullptr));
        mer_desc_label->setText(QCoreApplication::translate("SellerMainMenu", "\345\225\206\345\223\201\346\217\217\350\277\260\357\274\232", nullptr));
        add_mer_sure_btn->setText(QCoreApplication::translate("SellerMainMenu", "\347\241\256\350\256\244\345\217\221\345\270\203", nullptr));
        clear_content_btn->setText(QCoreApplication::translate("SellerMainMenu", "\346\270\205\347\251\272\345\206\205\345\256\271", nullptr));
        modify_mer_title_label->setText(QCoreApplication::translate("SellerMainMenu", "\344\277\256\346\224\271\345\225\206\345\223\201\344\277\241\346\201\257", nullptr));
        header_mer_id_label->setText(QCoreApplication::translate("SellerMainMenu", "\345\225\206\345\223\201ID\357\274\232", nullptr));
        mer_id_info_label->setText(QString());
        header_mer_name_label->setText(QCoreApplication::translate("SellerMainMenu", "\345\225\206\345\223\201\345\220\215\347\247\260\357\274\232", nullptr));
        mer_name_info_label->setText(QString());
        header_mer_price_label->setText(QCoreApplication::translate("SellerMainMenu", "\345\225\206\345\223\201\344\273\267\346\240\274\357\274\232", nullptr));
        mer_price_info_label->setText(QString());
        header_mer_num_label->setText(QCoreApplication::translate("SellerMainMenu", "\345\225\206\345\223\201\346\225\260\351\207\217\357\274\232", nullptr));
        mer_num_info_label->setText(QString());
        header_mer_desc_label->setText(QCoreApplication::translate("SellerMainMenu", "\345\225\206\345\223\201\346\217\217\350\277\260\357\274\232", nullptr));
        mer_desc_info_label->setText(QString());
        header_new_price_label->setText(QCoreApplication::translate("SellerMainMenu", "\346\226\260\347\232\204\344\273\267\346\240\274\357\274\232", nullptr));
        header_new_desc_label->setText(QCoreApplication::translate("SellerMainMenu", "\346\226\260\347\232\204\346\217\217\350\277\260\357\274\232", nullptr));
        modify_sure_btn->setText(QCoreApplication::translate("SellerMainMenu", "\347\241\256\350\256\244\344\277\256\346\224\271", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SellerMainMenu: public Ui_SellerMainMenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SELLERMAINMENU_H
