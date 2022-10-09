#include "UsrInfoMainMenu.h"
#include "ui_UsrInfoMainMenu.h"
#include "General.h"
#include "System.h"
#include "IOManager.h"
#include "Usr.h"
#include "QTimer"
#include "Recharge.h"
#include "OrderForm.h"
#include "IOManager.h"
#include "Calculator.h"

UsrInfoMainMenu::UsrInfoMainMenu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::UsrInfoMainMenu)
{
    ui->setupUi(this);
    setFixedSize(600, 450);
    setWindowIcon(QIcon(":/imgs/imgs/symbol.jpg"));
    ui->stackedWidget->setCurrentIndex(3);
    /*信号与槽*/
    //按钮-查看信息
    connect(ui->show_info_btn, &QPushButton::clicked, this, [=]()->void{
        ui->stackedWidget->setCurrentIndex(0);
        show_info();
    });
    //按钮-修改信息
    connect(ui->modify_info_btn, &QPushButton::clicked, this, [=]()->void{
        ui->stackedWidget->setCurrentIndex(1);
        modify_info();
    });
    //按钮-充值
    connect(ui->recharge_btn, &QPushButton::clicked, this, [=]()->void{
        ui->stackedWidget->setCurrentIndex(2);
        recharge();
    });
    //按钮-返回用户主界面
    connect(ui->exit_btn, &QPushButton::clicked, this, [=]()->void{
        emit this->choose_scene_back();
    });
}

UsrInfoMainMenu::~UsrInfoMainMenu()
{
    delete ui;
}

void UsrInfoMainMenu::show_info()
{
    Usr* cur_usr = System::get_cur_usr();
    ui->id_info_label->setText(QString::fromStdString(cur_usr->get_id()));
    ui->name_info_label->setText(QString::fromStdString(cur_usr->get_name()));
    ui->pnum_info_label->setText(QString::fromStdString(cur_usr->get_p_num()));
    ui->addr_info_label->setText(QString::fromStdString(cur_usr->get_addr()));

    //用户余额的计算
#ifdef CALCULATOR
    std::vector<OrderForm*> costs;
    std::vector<OrderForm*> incomes;
    std::vector<Recharge*> recharges;
    OrderForm::find_specific_buyer_orderforms(costs, cur_usr->get_id());
    OrderForm::find_specific_seller_orderforms(incomes, cur_usr->get_id());
    Recharge::find_recs_of_specific_usr(recharges, cur_usr->get_id());
    std::string base_expr = IOManager::generate_based_expr(costs, incomes, recharges);
    string simple_expr = Calculator::simplify_expr(base_expr);
    bool success = true;
    string err_info = "";
    double rst = Calculator::expr(success, err_info, simple_expr);
    assert(cur_usr->get_balance() == rst);
    std::string balance_buf = to_string(rst);
    if(balance_buf.find('.') != std::string::npos) balance_buf = balance_buf.substr(0, balance_buf.find('.')+2);
    ui->balance_info_label->setText(QString::fromStdString(balance_buf));
    ui->ori_expr_info_label->setText(QString::fromStdString(base_expr));
    ui->simple_simple_expr_info_label->setText(QString::fromStdString(simple_expr));
#endif

#ifndef CALCULATOR
    std::string balance_buf = to_string(cur_usr->get_balance());
    if(balance_buf.find('.') != std::string::npos) balance_buf = balance_buf.substr(0, balance_buf.find('.')+2);
    ui->balance_info_label->setText(QString::fromStdString(balance_buf));
#endif
    return;
}

#define STATUSBAR_SHOW_MESSAGE(info)\
{\
    ui->statusbar->showMessage(info);\
    QTimer::singleShot(DELAY, [=]()->void{\
       ui->statusbar->clearMessage();\
    });\
}

void UsrInfoMainMenu::modify_info()
{
    Usr* cur_usr = System::get_cur_usr();
    ui->modify_name_input->setText(QString::fromStdString(cur_usr->get_name()));
    ui->modify_pnum_input->setText(QString::fromStdString(cur_usr->get_p_num()));
    ui->modify_addr_input->setText(QString::fromStdString(cur_usr->get_addr()));
    connect(ui->modify_sure_btn, &QPushButton::clicked, this, [=]()->void{
        //获取修改后的各个属性
        string new_name = ui->modify_name_input->text().toStdString();
        string new_pnum = ui->modify_pnum_input->text().toStdString();
        string new_addr = ui->modify_addr_input->text().toStdString();
        //校验用户名
        int name_len = IOManager::check_ch_en_input(new_name);
        if(name_len <= 0)
        {
            STATUSBAR_SHOW_MESSAGE("用户名不可为空！");
            return;
        }
        else if(name_len == -1 || name_len > USR_NAME_MAXLEN)
        {
            STATUSBAR_SHOW_MESSAGE("用户名需由不超过十个的字母或中文字符组成！");
            return;
        }
        else if((Usr::find_usr_by_name(new_name) != nullptr && new_name != cur_usr->get_name()) || new_name == ADMIN_NAME)
        {
            if(new_name == ADMIN_NAME)
            {
                STATUSBAR_SHOW_MESSAGE("非法修改！");
                return;
            }
            else
            {
                STATUSBAR_SHOW_MESSAGE("该用户名已被使用！");
                return;
            }
        }
        //校验联系方式
        int pnum_len = 0;
        for(int i = 0; i < (int)new_pnum.size(); i++)
        {
            if(!(new_pnum[i] >= '0' && new_pnum[i] <= '9'))
            {
                pnum_len = -1;
                break;
            }
            else pnum_len++;
        }
        if(new_pnum == "none");
        else if(pnum_len == -1 || pnum_len > USR_PNUM_MAXLEN)
        {
            STATUSBAR_SHOW_MESSAGE("联系方式需由不超过二十个的纯数字组成！");
            return;
        }
        //校验地址
        int addr_len = IOManager::check_ch_en_input(new_addr);
        if(new_addr == "none");
        else if(addr_len == 0)
        {
            STATUSBAR_SHOW_MESSAGE("地址不可为空！");
            return;
        }
        else if(addr_len == -1 || addr_len > USR_ADDR_MAXLEN)
        {
            STATUSBAR_SHOW_MESSAGE("地址需由不超过四十个的字母或中文字符组成！");
            return;
        }
        cur_usr->update_name(new_name);
        cur_usr->update_phone_number(new_pnum);
        cur_usr->update_addr(new_addr);
        STATUSBAR_SHOW_MESSAGE("用户信息修改成功！");
        Usr::save_all_usrs();
        return;
    });
}

void UsrInfoMainMenu::recharge()
{
    Usr* cur_usr = System::get_cur_usr();
    std::string balance_buf = to_string(cur_usr->get_balance());
    if(balance_buf.find('.') != std::string::npos) balance_buf = balance_buf.substr(0, balance_buf.find('.')+2);
    ui->cur_balance_label->setText(QString::fromStdString(balance_buf));
    connect(ui->recharge_sure_btn, &QPushButton::clicked, this, [=]()->void{
        //检查是否符合规范
        string recharge_amount = ui->recharge_input->text().toStdString();
        if(regex_match(recharge_amount, MONEY_REGEX) == false)
        {
            STATUSBAR_SHOW_MESSAGE("充值金额需输入至多以为小数的正数！");
            return;
        }
        //检查充值金额是否过大
        double lf_charge = std::atof(recharge_amount.c_str());
        if(lf_charge > 1e6)
        {
            STATUSBAR_SHOW_MESSAGE("超出系统最大充值金额100万！");
            return;
        }
        //成功充值！
        cur_usr->recharge(lf_charge);
        Recharge* p = new Recharge(cur_usr->get_id(), lf_charge);
        Recharge::add_recharge_record(p);
        STATUSBAR_SHOW_MESSAGE("充值成功！");
        std::string new_balance = to_string(cur_usr->get_balance());
        if(new_balance.find('.') != std::string::npos) new_balance = new_balance.substr(0, new_balance.find('.')+2);
        ui->cur_balance_label->setText(QString::fromStdString(new_balance));
        Usr::save_all_usrs();
        Recharge::recharge_recs_save();
        return;
    });
}
