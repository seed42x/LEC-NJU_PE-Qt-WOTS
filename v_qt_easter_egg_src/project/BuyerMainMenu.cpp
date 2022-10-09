#include "BuyerMainMenu.h"
#include "ui_BuyerMainMenu.h"
#include "QStringList"
#include "QTableWidget"
#include "TableWindow.h"
#include "Usr.h"
#include "Merchandise.h"
#include "OrderForm.h"
#include "QLineEdit"
#include "QTimer"
#include "ListWindow.h"
#include "General.h"
#include "QAbstractItemView"
#include "System.h"
#include "SqlItem.h"

#define BUYER_SHOW(title, buf, red_content)\
    TableWindow* all_info_table = new TableWindow(this);\
    all_info_table->table.setWindowTitle(title);\
    all_info_table->table.move(this->x(), this->y());\
    all_info_table->table.setColumnCount(headers.count());\
    for(int i = 0; i < headers.count(); i++)\
    {\
        QTableWidgetItem* header_item =  new QTableWidgetItem(headers.at(i));\
        QFont font = header_item->font();\
        font.setBold(true);\
        font.setPointSize(12);\
        all_info_table->table.setHorizontalHeaderItem(i, header_item);\
    }\
    all_info_table->table.setRowCount(all_info_table->table.rowCount() + buf.size());\
    for(int r = 0; r < (int)buf.size(); r++)\
    {\
        for(int c = 0; c < (int)buf[r].size(); c++)\
        {\
            QTableWidgetItem* item_buf = new QTableWidgetItem(QString::fromStdString(buf[r][c]));\
            if(c == (int)buf[r].size() - 1 && buf[r][c] == red_content) item_buf->setForeground(Qt::red);\
            all_info_table->table.setItem(r, c, item_buf);\
        }\
    }

#define STATUSBAR_SHOW_MESSAGE(info)\
    ui->statusbar->showMessage(info);\
    QTimer::singleShot(DELAY, [=]()->void{\
       ui->statusbar->clearMessage();\
    });\

BuyerMainMenu::BuyerMainMenu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::BuyerMainMenu)
{
    ui->setupUi(this);
    setFixedSize(600, 450);
    setWindowIcon(QIcon(":/imgs/imgs/symbol.jpg"));
    ui->stackedWidget->setCurrentIndex(3);
    /*信号与槽*/
    //按钮-查看商品列表
    connect(ui->show_mers_btn, &QPushButton::clicked, this, [=]()->void{
        ui->stackedWidget->setCurrentIndex(3);
        show_all_merchandises();
    });
    //按钮-购买商品
    connect(ui->purchase_mer_btn, &QPushButton::clicked, this, [=]()->void{
        ui->stackedWidget->setCurrentIndex(0);
        purchase_merchandise();
    });
    //按钮-搜索商品
    connect(ui->select_mer_btn, &QPushButton::clicked, this, [=]()->void{
        ui->stackedWidget->setCurrentIndex(2);
        select_merchandise();
    });
    //按钮-查看历史订单
    connect(ui->show_orderforms_btn, &QPushButton::clicked, this, [=]()->void{
        ui->stackedWidget->setCurrentIndex(3);
        show_all_orderforms();
    });
    //按钮-查看商品详细信息
    connect(ui->show_details_mer_btn, &QPushButton::clicked, this, [=]()->void{
        ui->stackedWidget->setCurrentIndex(1);
        show_specific_merchandise_details_info();
    });

    //按钮-返回用户主界面
    connect(ui->exit_btn, &QPushButton::clicked, this, [=]()->void{
        emit this->choose_scene_back();
    });
}

BuyerMainMenu::~BuyerMainMenu()
{
    delete ui;
}

void BuyerMainMenu::show_all_merchandises()
{
    Usr* cur_usr = System::get_cur_usr();
    QStringList headers;
    headers << "商品ID" << "商品名称" << "价格" << "数量" << "上架时间" << "卖家ID";
    std::vector<std::vector<std::string>> buf;
    Merchandise::buyer_get_all_mers_info(buf, cur_usr->get_id());
    BUYER_SHOW("买家-查看所有商品", buf, "");
#ifdef MYSQL
    string usr_show_all_mers_order = SqlItem::generate_select_order(
        MYSQL_MER_LIST_NAME, "*", {}
    );
    SqlItem::set_usr(cur_usr);
    SqlItem::dealwith_select_order(usr_show_all_mers_order);
    SqlItem::clear_usr();
    SqlItem::save_all_items();
#endif
    return;
}

void BuyerMainMenu::show_all_orderforms()
{
    Usr* cur_usr = System::get_cur_usr();
    QStringList headers;
    headers << "订单ID" << "商品ID" << "交易单价" << "交易数量" << "交易时间" << "卖家ID";
    std::vector<std::vector<std::string>> buf;
    OrderForm::buyer_get_all_orderforms_info(buf, cur_usr->get_id());
    BUYER_SHOW("买家-查看所有订单", buf, "");
#ifdef MYSQL
    string buyer_show_all_orderforms_order = SqlItem::generate_select_order(
        MYSQL_ORDER_LIST_NAME, "*", {}
    );
    SqlItem::set_usr(cur_usr);
    SqlItem::dealwith_select_order(buyer_show_all_orderforms_order);
    SqlItem::clear_usr();
    SqlItem::save_all_items();
#endif
    return;
}

void BuyerMainMenu::purchase_merchandise()
{
    Usr* cur_usr = System::get_cur_usr();
    ListWindow* mers_list = new ListWindow(this);
    mers_list->setGeometry(this->geometry());
    mers_list->setWindowTitle("买家-选择要购买的商品");
    this->hide();
    mers_list->show();

    std::vector<std::vector<std::string>> buf;
    Merchandise::buyer_get_all_mers_info(buf, cur_usr->get_id());
    for(int i = 0; i < (int)buf.size(); i++)
    {
        string buffer = "";
        for(int j = 0; j < (int)buf[i].size(); j++)
        {
            buffer += buf[i][j] + "\t\t";
        }
        mers_list->list.addItem(QString::fromStdString(buffer));
    }

    connect(mers_list, &ListWindow::choose_scene_back, this, [=]()->void{
        this->setGeometry(mers_list->geometry());
        this->show();
        ui->stackedWidget->setCurrentIndex(3);
        mers_list->disconnect();
        delete mers_list;
    });

    Merchandise* target = nullptr;
    connect(mers_list, &ListWindow::choose_sure, this, [=, &target]()->void{
        QList<QListWidgetItem*> purchase_list = mers_list->list.selectedItems();
        for(int i = 0; i < purchase_list.count(); i++)
        {
            std::string target_id = purchase_list.at(i)->data(0).toString().toStdString().substr(0, 4);
            target = Merchandise::find_mer_by_id(target_id);
        }
        this->setGeometry(mers_list->geometry());
        this->show();
        mers_list->disconnect();
        delete mers_list;
        if(target != nullptr)
        {
            //显示有关信息
            ui->purchase_mer_id_info_label->setText(QString::fromStdString(target->get_id()));
            ui->purchase_mer_name_info_label->setText(QString::fromStdString(target->get_name()));
            std::string price_buf = std::to_string(target->get_price());
            if(price_buf.find('.') != std::string::npos) price_buf = price_buf.substr(0, price_buf.find('.')+2);
            ui->purchase_mer_price_info_label->setText(QString::fromStdString(price_buf));
            ui->purchase_mer_num_info_label->setText(QString::fromStdString(std::to_string(target->get_num())));
            ui->purchase_mer_addtime_info_label->setText(QString::fromStdString(target->get_added_time()));
            ui->purchase_mer_sellerid_label->setText(QString::fromStdString(target->get_seller_id()));
            connect(ui->purchase_sure_btn, &QPushButton::clicked, this, [=]()->void{
                //获取购买数量
                string purchase_num_buf = ui->purchase_num_input->text().toStdString();
                //检验输入的数量是否合法
                if(!regex_match(purchase_num_buf, regex("([1-9]{1})([0-9]*)")))
                {
                    STATUSBAR_SHOW_MESSAGE("非法输入！");
                    return;
                }
                int purchase_num = std::atoi(purchase_num_buf.c_str());
                if(purchase_num > target->get_num())
                {
                    STATUSBAR_SHOW_MESSAGE("超出该商品存货量！");
                    return;
                }
                else if(purchase_num * target->get_price() > cur_usr->get_balance())
                {
                    STATUSBAR_SHOW_MESSAGE("余额不足，请充值！");
                    return;
                }
                //成功购买
                //商品卖出，商品数量改变
#ifndef MYSQL
                target->update_num(target->get_num() - purchase_num);
#endif
#ifdef MYSQL
                string merchandise_sellout_order = SqlItem::generate_update_order(
                    MYSQL_MER_LIST_NAME,
                    vector<pair<string, string>>{pair<string, string>("Num", to_string(target->get_num() - purchase_num))},
                    vector<pair<string, string>>{pair<string, string>("MerID", target->get_id())}
                );
                SqlItem::dealwith_update_order(merchandise_sellout_order);
                //后续会对SqlItem进行本地化保存
#endif
                //商品卖出，买家钱花出
#ifndef MYSQL
                cur_usr->pay(purchase_num * target->get_price());
#endif
#ifdef MYSQL
                string usr_pay_order = SqlItem::generate_update_order(
                    MYSQL_USR_LIST_NAME,
                    vector<pair<string, string>>{pair<string, string>("Balance", to_string(cur_usr->get_balance() - purchase_num*target->get_price()))},
                    vector<pair<string, string>>{pair<string, string>("UsrID", cur_usr->get_id())}
                );
                SqlItem::dealwith_update_order(usr_pay_order);
                //后续会对SqlItem进行本地化保存
#endif
                //商品卖出，卖家获得收益
#ifndef MYSQL
                Usr* seller = Usr::find_usr_by_id(target->get_seller_id());
                seller->update_balance(seller->get_balance() + purchase_num * target->get_price());
#endif
#ifdef MYSQL
                Usr* seller = Usr::find_usr_by_id(target->get_seller_id());
                string seller_income_order = SqlItem::generate_update_order(
                    MYSQL_USR_LIST_NAME,
                    vector<pair<string, string>>{pair<string, string>("Balance", to_string(seller->get_balance() + purchase_num * target->get_price()))},
                    vector<pair<string, string>>{pair<string, string>("UsrID", seller->get_id())}
                );
                SqlItem::dealwith_update_order(seller_income_order);
#endif
                //商品卖出，追加新订单
                OrderForm* p = new OrderForm(target, cur_usr, purchase_num);
#ifndef MYSQL
                OrderForm::add_orderform(p);
#endif
#ifdef MYSQL
                std::string add_orderform_order = SqlItem::generate_insert_order(
                    MYSQL_ORDER_LIST_NAME,
                    std::vector<std::string> {target->get_id(), cur_usr->get_id(), to_string(purchase_num)}
                );
                SqlItem::dealwith_insert_order(add_orderform_order);
                SqlItem::save_all_items();
#endif
                //清空信息
                ui->purchase_mer_id_info_label->clear();
                ui->purchase_mer_name_info_label->clear();
                ui->purchase_mer_price_info_label->clear();
                ui->purchase_mer_num_info_label->clear();
                ui->purchase_mer_addtime_info_label->clear();
                ui->purchase_mer_sellerid_label->clear();
                //清空输入
                ui->purchase_num_input->clear();
                //显示交易成功的相关信息
                ui->stackedWidget->setCurrentIndex(4);
                ui->purchase_success_id_info_label->setText(QString::fromStdString(p->get_id()));
                ui->purchase_success_merid_info_label->setText(QString::fromStdString(p->get_mer_id()));
                ui->purchase_success_sellerid_info_label->setText(QString::fromStdString(p->get_seller_id()));
                ui->purchase_success_buyerid_info_label->setText(QString::fromStdString(p->get_buyer_id()));
                std::string unitp_buf = std::to_string(p->get_uintp());
                if(unitp_buf.find('.') != std::string::npos) unitp_buf = unitp_buf.substr(0, unitp_buf.find('.')+2);
                ui->purchase_success_unitp_info_label->setText(QString::fromStdString(unitp_buf));
                ui->purchase_success_num_info_label->setText(QString::fromStdString(to_string(p->get_num())));
                ui->purchase_success_time_info_label->setText(QString::fromStdString(p->get_tran_time()));
                double sum_dbuf = p->get_uintp() * p->get_num();
                std::string sum_buf = std::to_string(sum_dbuf);
                if(sum_buf.find('.') != std::string::npos) sum_buf = sum_buf.substr(0, sum_buf.find('.')+2);
                ui->purchase_success_sum_info_label->setText(QString::fromStdString(sum_buf));
                ui->purchase_success_state_info_label->setText(QString("交易成功"));
                std::string balance_buf = to_string(cur_usr->get_balance());
                if(balance_buf.find('.') != std::string::npos) balance_buf = balance_buf.substr(0, balance_buf.find('.')+2);
                ui->purchase_success_balance_info_label->setText(QString::fromStdString(balance_buf));
                //后台处理
                STATUSBAR_SHOW_MESSAGE("购买成功！");
                Usr::save_all_usrs();
                Merchandise::save_all_merchandises();
                OrderForm::save_all_orderforms();
                ui->purchase_sure_btn->disconnect();
                return;
            });
            connect(ui->purchase_exit_btn, &QPushButton::clicked, this, [=]()->void{
                ui->purchase_mer_id_info_label->clear();
                ui->purchase_mer_name_info_label->clear();
                ui->purchase_mer_price_info_label->clear();
                ui->purchase_mer_num_info_label->clear();
                ui->purchase_mer_addtime_info_label->clear();
                ui->purchase_mer_sellerid_label->clear();
                ui->stackedWidget->setCurrentIndex(3);
                ui->purchase_exit_btn->disconnect();
                return;
            });
        }
        else
        {
            ui->stackedWidget->setCurrentIndex(3);
            return;
        }

    });
}

void BuyerMainMenu::select_merchandise()
{
    connect(ui->select_sure_btn, &QPushButton::clicked, this, [=]()->void{
        string target_name = ui->select_input->text().toStdString();
        QStringList headers;
        headers << "商品ID" << "商品名称" << "价格" << "数量" << "上架时间" << "卖家ID";
        std::vector<std::vector<std::string>> buf;
        Merchandise::buyer_select_mers_info(target_name, buf);
        if(buf.size() == 0)
        {
            STATUSBAR_SHOW_MESSAGE("未找到相关商品！");
            return;
        }
        else
        {
            BUYER_SHOW("买家-搜索商品", buf, "");
        }
#ifdef MYSQL
        string usr_search_mer_order = SqlItem::generate_select_order(
            MYSQL_MER_LIST_NAME, "*", vector<pair<string, string>>{pair<string, string>("MerName", target_name)}
        );
        SqlItem::dealwith_select_order(usr_search_mer_order);
#endif
    });
}

void BuyerMainMenu::show_specific_merchandise_details_info()
{
    Usr* cur_usr = System::get_cur_usr();
    ListWindow* mers_list = new ListWindow(this);
    mers_list->setGeometry(this->geometry());
    mers_list->setWindowTitle("买家-选择查看详细信息的商品");
    this->hide();
    mers_list->show();
    std::vector<std::vector<std::string>> buf;
    Merchandise::buyer_get_all_mers_info(buf, cur_usr->get_id());
    for(int i = 0; i < (int)buf.size(); i++)
    {
        string buffer = "";
        for(int j = 0; j < (int)buf[i].size(); j++)
        {
            buffer += buf[i][j] + "\t\t";
        }
        mers_list->list.addItem(QString::fromStdString(buffer));
    }
    connect(mers_list, &ListWindow::choose_scene_back, this, [=]()->void{
        this->setGeometry(mers_list->geometry());
        this->show();
        ui->stackedWidget->setCurrentIndex(3);
        mers_list->disconnect();
        delete mers_list;
    });
    Merchandise* target = nullptr;
    connect(mers_list, &ListWindow::choose_sure, this, [=, &target]()->void{
        QList<QListWidgetItem*> show_list = mers_list->list.selectedItems();
        for(int i = 0; i < show_list.count(); i++)
        {
            std::string target_id = show_list.at(i)->data(0).toString().toStdString().substr(0, 4);
            target = Merchandise::find_mer_by_id(target_id);
        }
        this->setGeometry(mers_list->geometry());
        this->show();
        mers_list->disconnect();
        delete mers_list;
        if(target != nullptr)
        {
            ui->details_id_info_label->setText(QString::fromStdString(target->get_id()));
            ui->details_name_info_label->setText(QString::fromStdString(target->get_name()));
            std::string price_buf = to_string(target->get_price());
            if(price_buf.find('.') != std::string::npos) price_buf = price_buf.substr(0, price_buf.find('.')+2);
            ui->details_unitp_info_label->setText(QString::fromStdString(price_buf));
            ui->details_num_info_label->setText(QString::fromStdString(std::to_string(target->get_num())));
            ui->details_desc_info_label->setText(QString::fromStdString(target->get_description()));
            ui->details_addtime_info_label->setText(QString::fromStdString(target->get_added_time()));
            ui->details_sellerid_info_label->setText(QString::fromStdString(target->get_seller_id()));
#ifdef MYSQL
            string buyer_show_details_mer_order = SqlItem::generate_select_order(
                MYSQL_MER_LIST_NAME, "*", vector<pair<string, string>>{pair<string, string>("MerID", target->get_id())}
            );
            SqlItem::dealwith_select_order(buyer_show_details_mer_order);
            SqlItem::save_all_items();
#endif
            return;
        }
        else
        {
            ui->stackedWidget->setCurrentIndex(3);
            return;
        }
    });
}

















