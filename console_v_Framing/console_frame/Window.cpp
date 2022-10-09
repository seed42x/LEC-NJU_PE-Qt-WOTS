#include"Window.h"

//全局变量初始化
vector<string> Window::menubars_ =
{
    //MAIN_MENU
    "1.管理员登陆 2.用户注册 3.用户登录 4.退出程序",
    //TODO5: finish other menubar data

};
vector<regex> Window::regex_menu_choices_ =
{
    regex("[1-4]{1}"),  //MAIN_MENU
    //TODO5: finish other user's choices regex

};

//构造 & 析构函数
Window::Window(Page pg)
{
    this->type_ = pg;
}
Window::~Window()
{

}

//对象方法
//显示
void Window::show()
{
    //TODO6: finish show function

}
//消息分支
void Window::branches(bool& window_update, bool& exit, bool& admin_active, Usr*& cur_usr,
                      bool& window_exit, Window*& next_window)
{
    //TODO6: call some branches you know

}
void Window::main_menu_branches(bool& window_update, bool& exit, bool& admin_active, Usr*& cur_usr,
                                bool& window_exit, Window*& next_window)
{
    //获取用户操作
    show_prompt_info("输入操作：");
    string choice;
    choice = get_choice(regex_menu_choices_[type_]);
    if(choice == "ERR")
    {
        window_update = true;
        return;
    }
    //进入选择分支
    if(choice == "1")                   //1.管理员登陆
    {
        if(admin_login() == true)
        {
            admin_active = true;
            next_window = new Window(ADMIN_MENU);
        }
        window_update = true;
    }
    else if(choice == "2")              //2.用户注册
    {
        usr_register();
        Usr::save_all_usrs();
        window_update = true;
    }
    else if(choice == "3")              //3.用户登陆
    {
        cur_usr = usr_login();
        if(cur_usr != nullptr) next_window = new Window(USR_MENU);
        window_update = true;
    }
    else if(choice == "4")              //4.退出程序
    {
        show_succ_title();
        show_succ_info("成功退出！");
        exit = true;
        window_exit = true;
        CLEAR_SCREEN
        sleep(DELAY);
    }
    return;
}
void Window::admin_menu_branches(bool& window_update, bool& admin_active,
                                 bool& window_exit, Window*& next_window)
{
    //获取用户操作
    show_prompt_info("输入操作：");
    string choice;
    choice = get_choice(regex_menu_choices_[type_]);
    if(choice == "ERR")
    {
        window_update = true;
        return;
    }
    //进入选择分支
    if(choice == "1")               //1.查看所有商品
    {
        //TODO16：管理员功能-查看所有商品

    }
    else if(choice == "2")          //2.搜索商品
    {
        admin_search_merchandises();
        window_update = true;
    }
    else if(choice == "3")          //3.下架商品
    {
        admin_remove_merchandise();
        sleep(DELAY);
        window_update = true;
    }
    else if(choice == "4")          //4.查看所有订单
    {
        //TODO16：管理员功能-查看所有订单

    }
    else if(choice == "5")          //5.查看所有用户
    {
        //TODO16：管理员功能-查看所有用户
        
    }
    else if(choice == "6")          //6.封禁用户
    {
        admin_ban_usr();
        window_update = true;
        return;
    }
    else if(choice == "7")          //7.注销
    {
        show_succ_title();
        show_succ_info("成功注销！");
        admin_active = false;
        window_exit = true;
        window_update = true;
        sleep(DELAY);
    }
    return;
}
void Window::usr_menu_branches(bool& window_update, Usr*& cur_usr,
                               bool& window_exit, Window*& next_window)
{
    //获取用户操作
    show_prompt_info("输入操作：");
    string choice;
    choice = get_choice(regex_menu_choices_[type_]);
    if(choice == "ERR")
    {
        window_update = true;
        return;
    }
    //进入选择分支
    if(choice == "1")               //我是买家
    {
        cur_usr->update_mode(BUYER);
        next_window = new Window(USR_BUY_MENU);
        window_update = true;
    }
    else if(choice == "2")          //我是卖家
    {
        cur_usr->update_mode(SELLER);
        next_window = new Window(USR_SELL_MENU);
        window_update = true;
    }
    else if(choice == "3")          //个人信息管理
    {
        next_window = new Window(USR_INFO_MENU);
        window_update = true;
    }
    else if(choice == "4")          //注销登陆
    {
        show_succ_title();
        show_succ_info("成功注销！");
        cur_usr = nullptr;
        window_exit = true;
        window_update = true;
        sleep(DELAY);
    }
    return;
}

void Window::usr_info_menu_branches(bool& window_update, Usr*& cur_usr,
                                    bool& window_exit, Window*& next_window)
{
    //获取用户操作
    show_prompt_info("输入操作：");
    string choice;
    choice = get_choice(regex_menu_choices_[type_]);
    if(choice == "ERR")
    {
        window_update = true;
        return;
    }
    //进入选择分支
    if(choice == "1")               //1.查看信息
    {
        DRAW_STAR_LINE(50);
        //cur_usr->show_details_info();
        IOManager::show_specific_usr_details_info(cur_usr);
        DRAW_STAR_LINE(50);

        show_prompt_info("按下回车键退出...");
        cin.clear();
        getpass("");
        window_update = true;
    }
    else if(choice == "2")          //2.修改信息
    {
        modify_usr_info(cur_usr);
        sleep(DELAY);
        window_update = true;
    }
    else if(choice == "3")          //3.充值
    {
        usr_recharge(cur_usr);
        sleep(DELAY);
        window_update = true;
    }
    else if(choice == "4")          //4.返回用户主界面
    {
        window_exit = true;
        window_update = true;
    }
    return;
}
void Window::usr_buy_menu_branches(bool& window_update, Usr*& cur_usr,
                                   bool& window_exit, Window*& next_window)
{
    //获取用户操作
    show_prompt_info("输入操作：");
    string choice;
    choice = get_choice(regex_menu_choices_[type_]);
    if(choice == "ERR")
    {
        window_update = true;
        return;
    }
    //进入选择分支
    if(choice == "1")                   //1.查看商品列表
    {
        //TODO14：买家功能-查看商品列表

    }
    else if(choice == "2")              //2.购买商品
    {
        purchase_merchandise(cur_usr);
        window_update = true;
    }
    else if(choice == "3")              //3.搜索商品
    {
        usr_search_merchandises();
        window_update = true;
    }
    else if(choice == "4")              //4.查看历史订单
    {
        //TODO14：买家功能-查看历史订单
        
    }
    else if(choice == "5")              //5.查看商品详细信息
    {
        usr_show_merchandise_details_info();
        window_update = true;
    }
    else if(choice == "6")              //6.返回用户主界面
    {
        window_exit = true;
        window_update = true;
    }
    return;
}
void Window::usr_sell_menu_branches(bool& window_update, Usr*& cur_usr,
                                    bool& window_exit, Window*& next_window)
{
    //获取用户操作
    show_prompt_info("输入操作：");
    string choice;
    choice = get_choice(regex_menu_choices_[type_]);
    if(choice == "ERR")
    {
        window_update = true;
        return;
    }
    //进入选择分支
    if(choice == "1")                   //1.发布商品
    {
        add_merchandise(cur_usr);
        sleep(DELAY);
        window_update = true;
        return;
    }
    else if(choice == "2")              //2.查看发布商品
    {
#ifndef MYSQL
        //TODO13：卖家查看发布商品

    }
    else if(choice == "3")              //3.修改商品信息
    {
        modify_merchandise_info(cur_usr);
        sleep(DELAY);
        window_update = true;
    }
    else if(choice == "4")              //4.下架商品
    {
        usr_remove_merchandise(cur_usr);
        sleep(DELAY);
        window_update = true;
    }
    else if(choice == "5")              //5.查看历史订单
    {
#ifndef MYSQL
        //TODO13：事项卖家查看历史订单功能

}
