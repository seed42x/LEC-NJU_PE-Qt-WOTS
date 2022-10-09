#include "SellerMainMenu.h"
#include "ui_SellerMainMenu.h"
#include "Merchandise.h"
#include "System.h"
#include "Usr.h"
#include "IOManager.h"
#include "General.h"
#include "QTimer"
#include "TableWindow.h"
#include "QStringList"
#include "OrderForm.h"
#include "ListWindow.h"
#include "QAbstractItemView"
#include "SqlItem.h"

#define STATUSBAR_SHOW_MESSAGE(info)\
{\
    ui->statusbar->showMessage(info);\
    QTimer::singleShot(DELAY, [=]()->void{\
       ui->statusbar->clearMessage();\
    });\
}

SellerMainMenu::SellerMainMenu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SellerMainMenu)
{
    ui->setupUi(this);
    setFixedSize(600, 450);
    setWindowIcon(QIcon(":/imgs/imgs/symbol.jpg"));
    ui->stackedWidget->setCurrentIndex(2);
    /*信号与槽*/
    //按钮-发布商品
    connect(ui->add_mer_btn, &QPushButton::clicked, this, [=]()->void{
        ui->stackedWidget->setCurrentIndex(0);
        add_merchandise();
    });
    //按钮-查看发布商品
    connect(ui->show_mers_btn, &QPushButton::clicked, this, [=]()->void{
        ui->stackedWidget->setCurrentIndex(2);
        show_my_added_merchandises();
    });
    //按钮-修改商品信息
    connect(ui->modify_merinfo_btn, &QPushButton::clicked, this, [=]()->void{
        ui->stackedWidget->setCurrentIndex(2);
        modify_merchandise_info();
    });
    //按钮-下架商品
    connect(ui->remove_mer_btn, &QPushButton::clicked, this, [=]()->void{
        ui->stackedWidget->setCurrentIndex(2);
        remove_merchandise();
    });
    //按钮-查看历史订单
    connect(ui->show_orderforms_btn, &QPushButton::clicked, this, [=]()->void{
        ui->stackedWidget->setCurrentIndex(2);
        show_my_orderforms();
    });
    //按钮-返回用户主界面
    connect(ui->exit_btn, &QPushButton::clicked, this, [=]()->void{
        emit this->choose_scene_back();
    });
}

SellerMainMenu::~SellerMainMenu()
{
    delete ui;
}

void SellerMainMenu::add_merchandise()
{
    connect(ui->add_mer_sure_btn, &QPushButton::clicked, this, [=]()->void{
        ui->add_mer_sure_btn->setEnabled(false);
        Usr* cur_usr = System::get_cur_usr();
        //获取发布商品的各项信息
        string mer_name = ui->mer_name_input->text().toStdString();
        string mer_price_buf = ui->mer_price_input->text().toStdString();
        string mer_num_buf = ui->mer_num_input->text().toStdString();
        string mer_desc = ui->mer_desc_input->text().toStdString();
        //校验商品名称是否符合规范
        int name_len = IOManager::check_ch_en_input(mer_name);
        if(name_len <= 0)
        {
            STATUSBAR_SHOW_MESSAGE("商品名称不能为空！");
            ui->add_mer_sure_btn->setEnabled(true);
            return;
        }
        else if(name_len > MERCHANDISE_NAME_MAXLEN || name_len == -1)
        {
            STATUSBAR_SHOW_MESSAGE("商品名称需由不超过20个的英文字母或汉字字符组成！");
            ui->add_mer_sure_btn->setEnabled(true);
            return;
        }
        //校验商品价格是否符合规范
        if(!regex_match(mer_price_buf, MONEY_REGEX))
        {
            STATUSBAR_SHOW_MESSAGE("商品价格需要至多一位小数的正实数！");
            ui->add_mer_sure_btn->setEnabled(true);
            return;
        }
        double mer_price = std::atof(mer_price_buf.c_str());
        //校验商品数量是否符合规范
        if(!regex_match(mer_num_buf, regex("([1-9]{1})([0-9]*)")))
        {
            STATUSBAR_SHOW_MESSAGE("商品数量需为正整数！");
            ui->add_mer_sure_btn->setEnabled(true);
            return;
        }
        int mer_num = std::atoi(mer_num_buf.c_str());
        //校验商品描述是否符合规范
        int desc_len = IOManager::check_ch_en_num_input(mer_desc);
        if(desc_len <= 0)
        {
            STATUSBAR_SHOW_MESSAGE("商品描述不能为空！");
            ui->add_mer_sure_btn->setEnabled(true);
            return;
        }
        else if(desc_len == -1 || desc_len > MERCHANDISE_DESCRIPTION_MAXLEN)
        {
            STATUSBAR_SHOW_MESSAGE("商品描述需由不超过40个的英文字母、中文字符或数字组成！");
            ui->add_mer_sure_btn->setEnabled(true);
            return;
        }
        //经过所有校验，发布商品
        Merchandise* p = new Merchandise(mer_name, mer_price, mer_num, mer_desc, cur_usr->get_id());
        STATUSBAR_SHOW_MESSAGE("商品发布成功！");
#ifndef MYSQL
        Merchandise::add_merchandise(p);
#endif
#ifdef MYSQL
        delete p;
        std::string add_merchandise_order = SqlItem::generate_insert_order(
            MYSQL_MER_LIST_NAME,
            std::vector<std::string>{mer_name, to_string(mer_price), to_string(mer_num), mer_desc, cur_usr->get_id()}
        );
        SqlItem::dealwith_order(add_merchandise_order);
        SqlItem::save_all_items();
#endif
        Merchandise::save_all_merchandises();
        ui->add_mer_sure_btn->setEnabled(true);
        return;
    });

    connect(ui->clear_content_btn, &QPushButton::clicked, this, [=]()->void{
        ui->mer_name_input->clear();
        ui->mer_price_input->clear();
        ui->mer_num_input->clear();
        ui->mer_desc_input->clear();
        return;
    });
}

#define SELLER_SHOW(title, buf, red_content)\
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
            if(c == buf[r].size() - 1 && buf[r][c] == red_content) item_buf->setForeground(Qt::red);\
            all_info_table->table.setItem(r, c, item_buf);\
        }\
    }

void SellerMainMenu::show_my_added_merchandises()
{
    Usr* cur_usr = System::get_cur_usr();
    QStringList headers;
    headers << "商品ID" << "商品名称" << "价格" << "数量" << "上架时间" << "商品状态";
    std::vector<std::vector<std::string>> buf;
    Merchandise::seller_get_all_mers_info(buf, cur_usr->get_id());
    SELLER_SHOW("卖家-查看发布商品", buf, "已下架");
#ifdef MYSQL
    string seller_show_all_orderforms_order = SqlItem::generate_select_order(
        MYSQL_MER_LIST_NAME, "*", {}
    );
    SqlItem::set_usr(cur_usr);
    SqlItem::dealwith_select_order(seller_show_all_orderforms_order);
    SqlItem::clear_usr();
    SqlItem::save_all_items();
#endif
    return;
}

#define SHOW_MERCHANDISE_INFO\
    ui->mer_id_info_label->setText(QString::fromStdString(target->get_id()));\
    ui->mer_name_info_label->setText(QString::fromStdString(target->get_name()));\
    std::string price_buf = std::to_string(target->get_price());\
    if(price_buf.find('.') != std::string::npos) price_buf = price_buf.substr(0, price_buf.find('.')+2);\
    ui->mer_price_info_label->setText(QString::fromStdString(price_buf));\
    ui->mer_num_info_label->setText(QString::fromStdString(std::to_string(target->get_num())));\
    ui->mer_desc_info_label->setText(QString::fromStdString(target->get_description()));


void SellerMainMenu::modify_merchandise_info()
{
    Usr* cur_usr = System::get_cur_usr();
    ListWindow* mers_list = new ListWindow(this);
    mers_list->setGeometry(this->geometry());
    mers_list->setWindowTitle("卖家-选择要修改的商品");
    this->hide();
    mers_list->show();

    std::vector<std::vector<std::string>> buf;
    Merchandise::seller_get_all_onsale_mers_info(buf, cur_usr->get_id());
    for(int i = 0; i < (int)buf.size(); i++)
    {
        string buffer = "";
        for(int j = 0; j < (int)buf[i].size(); j++)
        {
            buffer += buf[i][j] + "\t\t";
        }
        mers_list->list.addItem(QString::fromStdString(buffer));
    }

    Merchandise* target = nullptr;
    connect(mers_list, &ListWindow::choose_sure, this, [=, &target]()->void{
        QList<QListWidgetItem*> modify_list = mers_list->list.selectedItems();
        for(int i = 0; i < modify_list.count(); i++)
        {
            std::string target_id = modify_list.at(i)->data(0).toString().toStdString().substr(0, 4);
            target = Merchandise::find_mer_by_id(target_id);
        }
        this->setGeometry(mers_list->geometry());
        this->show();
        mers_list->disconnect();
        delete mers_list;
        //将选中商品的当前信息进行展示
        if(target != nullptr)
        {
            std::string ori_price_buf = to_string(target->get_price());
            if(ori_price_buf.find('.') != std::string::npos) ori_price_buf = ori_price_buf.substr(0, ori_price_buf.find('.')+2);
            ui->new_price_input->setText(QString::fromStdString(ori_price_buf));
            ui->new_desc_input->setText(QString::fromStdString(target->get_description()));
            SHOW_MERCHANDISE_INFO;
            ui->stackedWidget->setCurrentIndex(1);
        }
        //以下执行修改操作
        connect(ui->modify_sure_btn, &QPushButton::clicked, this, [=]()->void{
            //获取当前各项信息
            string new_price = ui->new_price_input->text().toStdString();
            string new_desc = ui->new_desc_input->text().toStdString();
            //校验价格是否符合规范
            if(!regex_match(new_price, MONEY_REGEX))
            {
                STATUSBAR_SHOW_MESSAGE("价格需要输入至多一位小数的正实数！");
                return;
            }
            //检验描述是否符合规范
            int desc_len = IOManager::check_ch_en_num_input(new_desc);
            if(desc_len <= 0)
            {
                STATUSBAR_SHOW_MESSAGE("商品描述不能为空！");
                return;
            }
            else if(desc_len == -1 || desc_len > MERCHANDISE_DESCRIPTION_MAXLEN)
            {
                STATUSBAR_SHOW_MESSAGE("商品描述需由不超过40个的英文字母、中文字符或数字组成！");
                return;
            }
            //修改成功
            //修改价格
#ifndef MYSQL
            target->update_price(std::atof(new_price.c_str()));
#endif
#ifdef MYSQL
            string usr_modify_price_order = SqlItem::generate_update_order(
                MYSQL_MER_LIST_NAME,
                vector<pair<string, string>>{pair<string, string>("Price", new_price)},
                vector<pair<string, string>>{pair<string, string>("MerID", target->get_id())}
            );
            SqlItem::dealwith_update_order(usr_modify_price_order);
            SqlItem::save_all_items();
#endif
            //修改描述
#ifndef MYSQL
            target->update_description(new_desc);
#endif
#ifdef MYSQL
            string usr_modify_desc_order = SqlItem::generate_update_order(
                MYSQL_MER_LIST_NAME,
                vector<pair<string, string>>{pair<string, string>("Desc", new_desc)},
                vector<pair<string, string>>{pair<string, string>("MerID", target->get_id())}
            );
            SqlItem::dealwith_update_order(usr_modify_desc_order);
            SqlItem::save_all_items();
#endif
            SHOW_MERCHANDISE_INFO;
            STATUSBAR_SHOW_MESSAGE("修改商品信息成功！");
            Merchandise::save_all_merchandises();
            return;
        });
    });

    connect(mers_list, &ListWindow::choose_scene_back, this, [=]()->void{
        this->setGeometry(mers_list->geometry());
        this->show();
        mers_list->disconnect();
        delete mers_list;
    });
}

void SellerMainMenu::remove_merchandise()
{
    Usr* cur_usr = System::get_cur_usr();
    ListWindow* mers_list = new ListWindow(this);
    //设置QListWidget可多选
    mers_list->list.setSelectionMode(QAbstractItemView::ContiguousSelection);
    mers_list->setGeometry(this->geometry());
    mers_list->setWindowTitle("卖家-下架商品");
    this->hide();
    mers_list->show();

    std::vector<std::vector<std::string>> buf;
    Merchandise::seller_get_all_onsale_mers_info(buf, cur_usr->get_id());
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
        mers_list->disconnect();
        delete mers_list;
    });

    connect(mers_list, &ListWindow::choose_sure, this, [=]()->void{
        QList<QListWidgetItem*> remove_list = mers_list->list.selectedItems();
        for(int i = 0; i < remove_list.count(); i++)
        {
            std::string target_id = remove_list.at(i)->data(0).toString().toStdString().substr(0, 4);
            //下架商品
#ifndef MYSQL
            Merchandise* p = Merchandise::find_mer_by_id(target_id);
            p->update_state(REMOVED);
#endif
#ifdef MYSQL
            string usr_ban_mer_order = SqlItem::generate_update_order(
                MYSQL_MER_LIST_NAME,
                vector<pair<string, string>>{pair<string, string>("State", "已下架")},
                vector<pair<string, string>>{pair<string, string>("MerID", target_id)}
            );
            SqlItem::dealwith_update_order(usr_ban_mer_order);
            SqlItem::save_all_items();
#endif
        }
        Merchandise::save_all_merchandises();
        this->setGeometry(mers_list->geometry());
        this->show();
        mers_list->disconnect();
        delete mers_list;
    });
    return;
}

void SellerMainMenu::show_my_orderforms()
{
    Usr* cur_usr = System::get_cur_usr();
    QStringList headers;
    headers << "订单ID" << "商品ID" << "交易单价" << "交易数量" << "交易时间" << "买家ID";
    std::vector<std::vector<std::string>> buf;
    OrderForm::seller_get_all_orderforms_info(buf, cur_usr->get_id());
    SELLER_SHOW("卖家-查看历史订单", buf, "");
#ifdef MYSQL
    string seller_show_all_orderforms_order = SqlItem::generate_select_order(
        MYSQL_ORDER_LIST_NAME, "*", {}
    );
    SqlItem::set_usr(cur_usr);
    SqlItem::dealwith_select_order(seller_show_all_orderforms_order);
    SqlItem::clear_usr();
    SqlItem::save_all_items();
#endif
    return;
}
