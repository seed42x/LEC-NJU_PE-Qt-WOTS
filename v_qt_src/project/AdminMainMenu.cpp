#include "AdminMainMenu.h"
#include "ui_AdminMainMenu.h"
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
#include "SqlItem.h"

AdminMainMenu::AdminMainMenu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AdminMainMenu)
{
    ui->setupUi(this);
    setFixedSize(600, 450);
    setWindowIcon(QIcon(":/imgs/imgs/symbol.jpg"));
    /*信号和槽*/
    //按钮-查看所有商品
    connect(ui->show_all_mers_btn, &QPushButton::clicked, this, [=]()->void{
        ui->stackedWidget->setCurrentIndex(0);
        show_all_merchandises();
    });
    //按钮-搜索商品
    connect(ui->select_mer_btn, &QPushButton::clicked, this, [=]()->void{
        ui->stackedWidget->setCurrentIndex(1);
        select_merchandise();
    });
    //按钮-下架商品
    connect(ui->remove_mer_btn, &QPushButton::clicked, this, [=]()->void{
        ui->stackedWidget->setCurrentIndex(0);
        remove_merchandise();
    });
    //按钮-查看所有订单
    connect(ui->show_all_orderforms_btn, &QPushButton::clicked, this, [=]()->void{
        ui->stackedWidget->setCurrentIndex(0);
        show_all_orderforms();
    });
    //按钮-查看所有用户
    connect(ui->show_all_usrs_btn, &QPushButton::clicked, this, [=]()->void{
        ui->stackedWidget->setCurrentIndex(0);
        show_all_usrs();
    });
    //按钮-封禁用户
    connect(ui->ban_usr_btn, &QPushButton::clicked, this, [=]()->void{
        ui->stackedWidget->setCurrentIndex(0);
        ban_usr();
    });
    //按钮-注销
    connect(ui->exit_btn, &QPushButton::clicked, this, [=]()->void{
        ui->stackedWidget->setCurrentIndex(0);
        emit this->choose_scene_back();
    });
}

AdminMainMenu::~AdminMainMenu()
{
    delete ui;
}

#define ADMIN_SHOW(title, buf, red_content)\
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


void AdminMainMenu::show_all_merchandises()
{
    QStringList headers;
    headers << "商品ID" << "商品名称" << "价格" << "数量" << "上架时间" << "卖家ID" << "商品状态";
    std::vector<std::vector<std::string>> buf;
    Merchandise::admin_get_all_mers_info(buf);
    ADMIN_SHOW("管理员-查看所有商品", buf, "已下架")
#ifdef MYSQL
    SqlItem::change_admin_active();
    string admin_show_all_mers_order = SqlItem::generate_select_order(
        MYSQL_MER_LIST_NAME, "*", {}
    );
    SqlItem::dealwith_select_order(admin_show_all_mers_order);
    SqlItem::change_admin_inactive();
    SqlItem::save_all_items();
#endif
}

void AdminMainMenu::show_all_usrs()
{
    QStringList headers;
    headers << "用户ID" << "用户名称" << "联系方式" << "地址" << "钱包余额" << "用户状态";
    std::vector<std::vector<std::string>> buf;
    Usr::admin_get_all_usrs_info(buf);
    ADMIN_SHOW("管理员-查看所有用户", buf, "封禁")
#ifdef MYSQL
    SqlItem::change_admin_active();
    string admin_show_all_mers_order = SqlItem::generate_select_order(
        MYSQL_USR_LIST_NAME, "*", {}
    );
    SqlItem::dealwith_select_order(admin_show_all_mers_order);
    SqlItem::change_admin_inactive();
    SqlItem::save_all_items();
#endif
}

void AdminMainMenu::show_all_orderforms()
{
    QStringList headers;
    headers << "订单ID" << "商品ID" << "交易单价" << "交易数量" << "交易时间" << "卖家ID" << "买家ID";
    std::vector<std::vector<std::string>> buf;
    OrderForm::admin_get_all_orderforms_info(buf);
    ADMIN_SHOW("管理员-查看所有订单", buf, "");
#ifdef MYSQL
    SqlItem::change_admin_active();
    string admin_show_all_orderforms_order = SqlItem::generate_select_order(
        MYSQL_ORDER_LIST_NAME, "*", {}
    );
    SqlItem::dealwith_select_order(admin_show_all_orderforms_order);
    SqlItem::change_admin_inactive();
    SqlItem::save_all_items();
#endif
}

#define STATUSBAR_SHOW_MESSAGE(info)\
    ui->statusbar->showMessage(info);\
    QTimer::singleShot(DELAY, [=]()->void{\
       ui->statusbar->clearMessage();\
    });\

void AdminMainMenu::select_merchandise()
{
    connect(ui->select_sure_btn, &QPushButton::clicked, this, [=]()->void{
       string target_name = ui->select_input->text().toStdString();
       QStringList headers;
       headers << "商品ID" << "商品名称" << "价格" << "数量" << "上架时间" << "卖家ID" << "商品状态";
       std::vector<std::vector<std::string>> buf;
       Merchandise::admin_select_mers_info(target_name, buf);
       if(buf.size() == 0)
       {
            STATUSBAR_SHOW_MESSAGE("未找到相关商品！")
       }
       else
       {
            ADMIN_SHOW("管理员-搜索商品", buf, "已下架")
       }
#ifdef MYSQL
       string admin_search_mer_order = SqlItem::generate_select_order(
           MYSQL_MER_LIST_NAME, "*", vector<pair<string, string>>{pair<string, string>("MerName", target_name)}
       );
       SqlItem::change_admin_active();
       SqlItem::dealwith_select_order(admin_search_mer_order);
       SqlItem::change_admin_inactive();
       SqlItem::save_all_items();
#endif
    });
}

void AdminMainMenu::remove_merchandise()
{
    ListWindow* mers_list = new ListWindow(this);
    //设置QListWidget可多选
    mers_list->list.setSelectionMode(QAbstractItemView::ContiguousSelection);
    mers_list->setGeometry(this->geometry());
    mers_list->setWindowTitle("管理员-下架商品");
    this->hide();
    mers_list->show();

    std::vector<std::vector<std::string>> buf;
    Merchandise::admin_get_all_onsale_mers_info(buf);
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
            std::string admin_ban_mer_order = SqlItem::generate_update_order(
                MYSQL_MER_LIST_NAME,
                vector<pair<string, string>>{pair<string, string>("State", "已下架")},
                vector<pair<string, string>>{pair<string, string>("MerID", target_id)}
            );
            SqlItem::dealwith_order(admin_ban_mer_order);
            SqlItem::save_all_items();
#endif
        }
        Merchandise::save_all_merchandises();
        this->setGeometry(mers_list->geometry());
        this->show();
        mers_list->disconnect();
        delete mers_list;
    });
}

void AdminMainMenu::ban_usr()
{
    ListWindow* usrs_list = new ListWindow(this);
    //设置QListWidget可多选
    usrs_list->list.setSelectionMode(QAbstractItemView::ContiguousSelection);
    usrs_list->setGeometry(this->geometry());
    usrs_list->setWindowTitle("管理员-封禁用户");
    this->hide();
    usrs_list->show();

    std::vector<std::vector<std::string>> buf;
    Usr::admin_get_all_noban_usrs_info(buf);
    for(int i = 0; i < (int)buf.size(); i++)
    {
        string buffer = "";
        for(int j = 0; j < (int)buf[i].size(); j++)
        {
            buffer += buf[i][j] + "\t\t";
        }
        usrs_list->list.addItem(QString::fromStdString(buffer));
    }

    connect(usrs_list, &ListWindow::choose_scene_back, this, [=]()->void{
        this->setGeometry(usrs_list->geometry());
        this->show();
        usrs_list->disconnect();
        delete usrs_list;
    });
    connect(usrs_list, &ListWindow::choose_sure, this, [=]()->void{
        QList<QListWidgetItem*> ban_list = usrs_list->list.selectedItems();
        for(int i = 0; i < ban_list.count(); i++)
        {
            std::string target_id = ban_list.at(i)->data(0).toString().toStdString().substr(0, 4);
            //封禁用户 & 下架对应用户的所有商品
#ifndef MYSQL
            Usr* p = Usr::find_usr_by_id(target_id);
            p->update_active(false);
            Merchandise::remove_specific_usr_all_merchandises(p);
#endif
#ifdef MYSQL
            string admin_ban_usr_order = SqlItem::generate_update_order(
                MYSQL_USR_LIST_NAME,
                vector<pair<string, string>>{pair<string, string>("State", "封禁")},
                vector<pair<string, string>>{pair<string, string>("UsrID", target_id)}
            );
            SqlItem::dealwith_order(admin_ban_usr_order);
            string remove_all_mers_order = SqlItem::generate_update_order(
                MYSQL_MER_LIST_NAME,
                vector<pair<string, string>>{pair<string, string>("State", "已下架")},
                vector<pair<string, string>>{pair<string, string>("SellerID", target_id)}
            );
            SqlItem::dealwith_order(remove_all_mers_order);
            SqlItem::save_all_items();
#endif
        }
        Usr::save_all_usrs();
        Merchandise::save_all_merchandises();
        this->setGeometry(usrs_list->geometry());
        this->show();
        usrs_list->disconnect();
        delete usrs_list;
    });
}
