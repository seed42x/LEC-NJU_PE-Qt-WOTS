#include "MainMenu.h"
#include "ui_mainmenu.h"
#include "QPushButton"
#include "AdminMainMenu.h"
#include "UsrMainMenu.h"
#include "QTimer"
#include "General.h"
#include "IOManager.h"
#include "SqlItem.h"
#include "Usr.cpp"
#include "Merchandise.cpp"
#include "OrderForm.cpp"
#include "System.h"
#include "Recharge.h"
#include "QIcon"

#define MAINMENU_INPUT_CLEAR\
    ui->admin_login_name_input->clear();\
    ui->admin_login_passwd_input->clear();\
    ui->usr_login_name_input->clear();\
    ui->usr_login_passwd_input->clear();\
    ui->usr_regis_name_input->clear();\
    ui->usr_regis_passwd_input->clear();

/*构造 & 析构函数*/
MainMenu::MainMenu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainMenu)
{
    ui->setupUi(this);
    setFixedSize(600, 450);
    setWindowIcon(QIcon(":/imgs/imgs/symbol.jpg"));

    Usr::init_all_usrs();
    Merchandise::init_all_merchandises();
    OrderForm::init_all_orderforms();
    Recharge::recharge_recs_init();
    SqlItem::init_all_items();

    ui->stackedWidget->setCurrentIndex(0);
    MAINMENU_INPUT_CLEAR
    /*信号和槽*/
    //---管理员登录---//
    connect(ui->admin_login_btn, &QPushButton::clicked, [=]()->void{
        ui->stackedWidget->setCurrentIndex(0);
        MAINMENU_INPUT_CLEAR
    });
    connect(ui->admin_login_sure_btn, &QPushButton::clicked, [=]()->void{admin_login();});

    //---用户登录---//
    connect(ui->usr_login_btn, &QPushButton::clicked, [=]()->void{
        ui->stackedWidget->setCurrentIndex(1);
        MAINMENU_INPUT_CLEAR
    });
    connect(ui->usr_login_sure_btn, &QPushButton::clicked, [=]()->void{usr_login();});

    //---用户注册---//
    connect(ui->usr_register_btn, &QPushButton::clicked, [=]()->void{
        ui->stackedWidget->setCurrentIndex(2);
        MAINMENU_INPUT_CLEAR
    });
    connect(ui->usr_regis_sure_btn, &QPushButton::clicked, [=]()->void{usr_register();});

    //按钮-退出系统
    connect(ui->exit_btn, &QPushButton::clicked, this, [=]()->void{
        //返回主场景
        emit this->choose_scene_back();
    });
}

MainMenu::~MainMenu()
{
    delete ui;
}


#define STATUSBAR_SHOW_MESSAGE(info)\
    ui->statusbar->showMessage(info);\
    QTimer::singleShot(DELAY, [=]()->void{\
       ui->statusbar->clearMessage();\
    });\


/*成员函数*/
void MainMenu::admin_login()
{
    //获取管理员姓名 & 密码
    string login_name = ui->admin_login_name_input->text().toStdString();
    string login_passwd = ui->admin_login_passwd_input->text().toStdString();
    //姓名错误
    if(login_name != ADMIN_NAME)
    {
        STATUSBAR_SHOW_MESSAGE("管理员姓名错误！")
    }
    //密码错误
    else if(login_passwd != ADMIN_PASSWD)
    {
        STATUSBAR_SHOW_MESSAGE("管理员密码错误！")
    }
    //登录成功
    else
    {
        //创建管理员主菜单
        AdminMainMenu* admin_main_menu = new AdminMainMenu();
        //保持窗口一致
        admin_main_menu->setGeometry(this->geometry());
        //显示切换
        this->hide();
        admin_main_menu->show();
        //TODO:监听管理员主菜单内的退出按钮
        connect(admin_main_menu, &AdminMainMenu::choose_scene_back, this, [=]()->void{
            this->setGeometry(admin_main_menu->geometry());
            delete admin_main_menu;
            this->show();
        });
        MAINMENU_INPUT_CLEAR
    }
    return;
}

void MainMenu::usr_login()
{
    //获取用户姓名 & 密码
    string login_name = ui->usr_login_name_input->text().toStdString();
    string login_passwd = ui->usr_login_passwd_input->text().toStdString();
    //检查用户名是否符合规范
    int name_check = IOManager::check_ch_en_input(login_name);
    if(name_check <= 0)
    {
        STATUSBAR_SHOW_MESSAGE("用户名不可为空！")
    }
    else if(name_check == -1 || name_check > USR_NAME_MAXLEN)
    {
        STATUSBAR_SHOW_MESSAGE("用户名需由不超过十个的字母或中文字符组成！")
    }
    //查找用户是否存在
    Usr* target = Usr::find_usr_by_name(login_name);
    if(target == nullptr)
    {
        STATUSBAR_SHOW_MESSAGE("该用户不存在！")
        return;
    }
    //检验该用户是否被封禁
    else if(target->get_active() == false)
    {
        STATUSBAR_SHOW_MESSAGE("该用户已被封禁，禁止登录！");
    }
    //检查密码是否正确
    else if(target->get_passwd() != login_passwd)
    {
        STATUSBAR_SHOW_MESSAGE("密码错误！");
    }
    //登录成功
    else
    {
        //切换当前系统用户
        System::set_cur_usr(target);
        //创建用户主菜单
        UsrMainMenu* usr_main_menu = new UsrMainMenu();
        //保持窗口一致
        usr_main_menu->setGeometry(this->geometry());
        //显示切换
        this->hide();
        usr_main_menu->show();
        //TODO:监听用户主菜单内的退出按钮
        connect(usr_main_menu, &UsrMainMenu::choose_scene_back, this, [=]()->void{
            this->setGeometry(usr_main_menu->geometry());
            delete usr_main_menu;
            this->show();
        });
        MAINMENU_INPUT_CLEAR
    }
    return;
}

void MainMenu::usr_register()
{
    string regis_name = ui->usr_regis_name_input->text().toStdString();
    string regis_passwd = ui->usr_regis_passwd_input->text().toStdString();
    int name_len = IOManager::check_ch_en_input(regis_name);
    int passwd_len = IOManager::check_lowen_num_input(regis_passwd);
    //检查用户名是否符合规范要求
    if(name_len <= 0)
    {
        STATUSBAR_SHOW_MESSAGE("用户名不可为空！")
    }
    else if(name_len == -1 || name_len > USR_NAME_MAXLEN)
    {
        STATUSBAR_SHOW_MESSAGE("用户名需由不超过10个字的字母或中文字符组成！")
    }
    //检查用户名是否已被使用
    else if(Usr::find_usr_by_name(regis_name) != nullptr || regis_name == ADMIN_NAME)
    {
        if(regis_name == ADMIN_NAME)
        {
            STATUSBAR_SHOW_MESSAGE("非法注册！");
        }
        else
        {
            STATUSBAR_SHOW_MESSAGE("该用户名已被注册！");
        }
    }
    //检查密码是否符合规范
    else if(passwd_len <= 0)
    {
        STATUSBAR_SHOW_MESSAGE("密码不应当为空！");
    }
    else if(passwd_len == -1 || passwd_len > USR_PASSWD_MAXLEN)
    {
        STATUSBAR_SHOW_MESSAGE("密码应不超过20个字符，且仅由小写字母和数字组成")
    }
    //注册成功
    else
    {
#ifndef MYSQL
       Usr* p = new Usr(regis_name, regis_passwd);
       Usr::add_usr(p);
#endif
#ifdef MYSQL
        std::string usr_register_order = SqlItem::generate_insert_order(MYSQL_USR_LIST_NAME, vector<string>{regis_name, regis_passwd});
        SqlItem::dealwith_order(usr_register_order);
        SqlItem::save_all_items();
#endif
       Usr::save_all_usrs();
       STATUSBAR_SHOW_MESSAGE("注册成功！");
       MAINMENU_INPUT_CLEAR
    }
}
