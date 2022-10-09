#include "UsrMainMenu.h"
#include "ui_UsrMainMenu.h"
#include "BuyerMainMenu.h"
#include "SellerMainMenu.h"
#include "UsrInfoMainMenu.h"
#include "System.h"


UsrMainMenu::UsrMainMenu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::UsrMainMenu)
{
    ui->setupUi(this);
    setFixedSize(600, 450);
    setWindowIcon(QIcon(":/imgs/imgs/symbol.jpg"));
    /*信号和槽*/
    //按钮-我是买家
    connect(ui->buyer_btn, &QPushButton::clicked, this, [=]()->void{
        //创建买家主菜单
        BuyerMainMenu* buyer_main_menu = new BuyerMainMenu();
        //保持窗口一致
        buyer_main_menu->setGeometry(this->geometry());
        //显示切换
        this->hide();
        buyer_main_menu->show();
        //TODO:监听买家主菜单内的退出按钮
        connect(buyer_main_menu, &BuyerMainMenu::choose_scene_back, this, [=]()->void{
            this->setGeometry(buyer_main_menu->geometry());
            buyer_main_menu->disconnect();
            delete buyer_main_menu;
            this->show();
        });
    });
    //按钮-我是卖家
    connect(ui->seller_btn, &QPushButton::clicked, this, [=]()->void{
        //创建卖家主菜单
        SellerMainMenu* seller_main_menu = new SellerMainMenu();
        //保持窗口一致
        seller_main_menu->setGeometry(this->geometry());
        //显示切换
        this->hide();
        seller_main_menu->show();
        //TODO:监听卖家主菜单内的退出按钮
        connect(seller_main_menu, &SellerMainMenu::choose_scene_back, this, [=]()->void{
            this->setGeometry(seller_main_menu->geometry());
            seller_main_menu->disconnect();
            delete seller_main_menu;
            this->show();
        });
    });
    //按钮-个人信息管理
    connect(ui->info_manage_btn, &QPushButton::clicked, this, [=]()->void{
        //创建个人信息管理菜单
        UsrInfoMainMenu* usrinfo_main_menu = new UsrInfoMainMenu();
        //保持窗口一致
        usrinfo_main_menu->setGeometry(this->geometry());
        //显示切换
        this->hide();
        usrinfo_main_menu->show();
        //TODO:监听个人信息管理菜单内的退出按钮
        connect(usrinfo_main_menu, &UsrInfoMainMenu::choose_scene_back, this, [=]()->void{
            this->setGeometry(usrinfo_main_menu->geometry());
            usrinfo_main_menu->disconnect();
            delete usrinfo_main_menu;
            this->show();
        });
    });
    //按钮-注销登录
    connect(ui->exit_btn, &QPushButton::clicked, this, [=]()->void{
       System::set_cur_usr(nullptr);
       emit this->choose_scene_back();
    });
}

UsrMainMenu::~UsrMainMenu()
{
    delete ui;
}
