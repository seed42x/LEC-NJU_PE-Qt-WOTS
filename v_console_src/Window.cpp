#include"Window.h"

//全局变量初始化
vector<string> Window::menubars_ =
{
    //MAIN_MENU
    "1.管理员登陆 2.用户注册 3.用户登录 4.退出程序",
    //ADMIN_MENU
    "1.查看所有商品 2.搜索商品 3.下架商品 4.查看所有订单 5.查看所有用户 6.封禁用户 7.注销",
    //USR_MENU
    "1.我是买家 2.我是卖家 3.个人信息管理 4.注销登陆",
    //USR_BUY_MENU
    "1.查看商品列表 2.购买商品 3.搜索商品 4.查看历史订单 5.查看商品详细信息 6.返回用户主界面",
    //USR_SELL_MENU
    "1.发布商品 2.查看发布商品 3.修改商品信息 4.下架商品 5.查看历史订单 6.返回用户主界面",
    //USR_INFO_MENU 个人信息管理子菜单
    "1.查看信息 2.修改信息 3.充值 4.返回用户主界面",
};
vector<regex> Window::regex_menu_choices_ =
{
    regex("[1-4]{1}"),  //MAIN_MENU
    regex("[1-7]{1}"),  //ADMIN_MENU
    regex("[1-4]{1}"),  //USR_MENU
    regex("[1-6]{1}"),  //USR_BUY_MENU
    regex("[1-6]{1}"),  //USR_SELL_MENU
    regex("[1-4]{1}"),  //USR_INFO_MENU
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
    CLEAR_SCREEN
    DRAW_DOUBLE_LINE(menubars_[this->type_].size());
    OUTPUT(vector<string>{HIGHLIGHT}, printf("%s\n", menubars_[this->type_].c_str()));
    DRAW_DOUBLE_LINE(menubars_[this->type_].size());
    return;
}
//消息分支
void Window::branches(bool& window_update, bool& exit, bool& admin_active, Usr*& cur_usr,
                      bool& window_exit, Window*& next_window)
{
    switch(this->type_)
    {
    case MAIN_MENU:
        main_menu_branches(window_update, exit, admin_active, cur_usr, window_exit, next_window);
        break;
    case ADMIN_MENU:
        admin_menu_branches(window_update, admin_active, window_exit, next_window);
        break;
    case USR_MENU:
        usr_menu_branches(window_update, cur_usr, window_exit, next_window);
        break;
    case USR_BUY_MENU:
        usr_buy_menu_branches(window_update, cur_usr, window_exit, next_window);
        break;
    case USR_SELL_MENU:
        usr_sell_menu_branches(window_update, cur_usr, window_exit, next_window);
        break;
    case USR_INFO_MENU:
        usr_info_menu_branches(window_update, cur_usr, window_exit, next_window);
        break;
    }
    return;
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
#ifndef MYSQL
        DRAW_STAR_LINE(180);
        OUTPUT(
            vector<string>{HIGHLIGHT},
            printf(
                "%-20s\t%-30s\t%-20s\t%-20s\t%-20s\t%-20s\t%-20s\n",
                string("商品ID").c_str(),
                string("商品名称").c_str(),
                string("价格").c_str(),
                string("数量").c_str(),
                string("上架时间").c_str(),
                string("卖家ID").c_str(),
                string("商品状态").c_str()
            )
        );
        DRAW_STAR_LINE(180);
        Merchandise::admin_show_all_merchandises_info();
        DRAW_STAR_LINE(180);
#endif
#ifdef MYSQL
        SqlItem::change_admin_active();
        string admin_show_all_mers_order = SqlItem::generate_select_order(
            MYSQL_MER_LIST_NAME, "*", {}
        );
        SqlItem::dealwith_select_order(admin_show_all_mers_order);
        SqlItem::change_admin_inactive();
        SqlItem::save_all_items();
#endif
        //利用输入等待进行退出
        show_prompt_info("按下回车键退出...");
        cin.clear();
        getpass("");
        window_update = true;
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
#ifndef MYSQL
        DRAW_STAR_LINE(180);
        OUTPUT(
            vector<string>{HIGHLIGHT},
            printf(
                "%-20s\t%-20s\t%-20s\t%-20s\t%-20s\t%-20s\t%-20s\n",
                string("订单ID").c_str(),
                string("商品ID").c_str(),
                string("交易单价").c_str(),
                string("交易数量").c_str(),
                string("交易时间").c_str(),
                string("卖家ID").c_str(),
                string("买家ID").c_str()
            )
        );
        DRAW_STAR_LINE(180);
        OrderForm::show_all_usrs_orderform_info();
        DRAW_STAR_LINE(180);
#endif
#ifdef MYSQL
        SqlItem::change_admin_active();
        string admin_show_all_orderforms_order = SqlItem::generate_select_order(
            MYSQL_ORDER_LIST_NAME, "*", {}
        );
        SqlItem::dealwith_select_order(admin_show_all_orderforms_order);
        SqlItem::change_admin_inactive();
        SqlItem::save_all_items();
#endif
        //利用输入等待进行退出
        show_prompt_info("按下回车键退回...");
        cin.clear();
        getpass("");
        window_update = true;
    }
    else if(choice == "5")          //5.查看所有用户
    {
#ifndef MYSQL
        //显示信息
        DRAW_STAR_LINE(180);
        OUTPUT(
            vector<string>{HIGHLIGHT},
            printf(
                "%-20s\t%-20s\t%-30s\t%-50s\t%-20s\t%-20s\n",
                string("用户ID").c_str(),
                string("用户名").c_str(),
                string("联系方式").c_str(),
                string("地址").c_str(),
                string("钱包余额").c_str(),
                string("用户状态").c_str()
            )
        );
        DRAW_STAR_LINE(180);
        Usr::show_all_usrs_info();
        DRAW_STAR_LINE(180);
#endif
#ifdef MYSQL
        string admin_show_all_usrs_order = SqlItem::generate_select_order(
            MYSQL_USR_LIST_NAME, "*", {}
        );
        SqlItem::change_admin_active();
        SqlItem::dealwith_select_order(admin_show_all_usrs_order);
        SqlItem::change_admin_inactive();
        SqlItem::save_all_items();
#endif
        //利用输入等待进行退出
        show_prompt_info("按下回车键退出...");
        cin.clear();
        getpass("");

        window_update = true;
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
#ifndef MYSQL
        DRAW_STAR_LINE(180);
        OUTPUT(
            vector<string>{HIGHLIGHT},
            printf(
                "%-20s\t%-30s\t%-20s\t%-20s\t%-20s\t%-20s\n",
                string("商品ID").c_str(),
                string("商品名称").c_str(),
                string("价格").c_str(),
                string("数量").c_str(),
                string("上架时间").c_str(),
                string("卖家ID").c_str()
            )
        );
        DRAW_STAR_LINE(180);
        Merchandise::usr_show_all_merchandises_info();
        DRAW_STAR_LINE(180);
#endif
#ifdef MYSQL
        string usr_show_all_mers_order = SqlItem::generate_select_order(
            MYSQL_MER_LIST_NAME, "*", {}
        );
        SqlItem::set_usr(cur_usr);
        SqlItem::dealwith_select_order(usr_show_all_mers_order);
        SqlItem::clear_usr();
        SqlItem::save_all_items();
#endif
        //利用输入等待进行退出
        show_prompt_info("按下回车键退出...");
        cin.clear();
        getpass("");
        window_update = true;
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
#ifndef MYSQL
        DRAW_STAR_LINE(180);
        OUTPUT(
            vector<string>{HIGHLIGHT},
            printf(
                "%-20s\t%-20s\t%-20s\t%-20s\t%-20s\t%-20s\n",
                string("订单ID").c_str(),
                string("商品ID").c_str(),
                string("交易单价").c_str(),
                string("交易数量").c_str(),
                string("交易时间").c_str(),
                string("卖家ID").c_str()
            )
        );
        DRAW_STAR_LINE(180);
        OrderForm::show_specific_buyer_orderform_info(cur_usr);
        DRAW_STAR_LINE(180);
#endif
#ifdef MYSQL
        string buyer_show_all_orderforms_order = SqlItem::generate_select_order(
            MYSQL_ORDER_LIST_NAME, "*", {}
        );
        SqlItem::set_usr(cur_usr);
        SqlItem::dealwith_select_order(buyer_show_all_orderforms_order);
        SqlItem::clear_usr();
        SqlItem::save_all_items();
#endif
        //利用输入等待进行退出
        show_prompt_info("按下回车键退回...");
        cin.clear();
        getpass("");
        window_update = true;
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
        //显示信息
        DRAW_STAR_LINE(180);
        OUTPUT(
            vector<string>{HIGHLIGHT},
            printf(
                "%-20s\t%-30s\t%-20s\t%-20s\t%-20s\t%-20s\n",
                string("商品ID").c_str(),
                string("商品名称").c_str(),
                string("价格").c_str(),
                string("数量").c_str(),
                string("上架时间").c_str(),
                string("商品状态").c_str()
            )
        );
        DRAW_STAR_LINE(180);
        Merchandise::show_specific_usr_merchandises_info(cur_usr);
        DRAW_STAR_LINE(180);
#endif
#ifdef MYSQL
        string seller_show_all_orderforms_order = SqlItem::generate_select_order(
            MYSQL_MER_LIST_NAME, "*", {}
        );
        SqlItem::set_usr(cur_usr);
        SqlItem::dealwith_select_order(seller_show_all_orderforms_order);
        SqlItem::clear_usr();
        SqlItem::save_all_items();
#endif
        //利用输入等待进行退出
        show_prompt_info("按下回车键退出...");
        cin.clear();
        getpass("");
        window_update = true;
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
        DRAW_STAR_LINE(180);
        OUTPUT(
            vector<string>{HIGHLIGHT},
            printf(
                "%-20s\t%-20s\t%-20s\t%-20s\t%-20s\t%-20s\n",
                string("订单ID").c_str(),
                string("商品ID").c_str(),
                string("交易单价").c_str(),
                string("交易数量").c_str(),
                string("交易时间").c_str(),
                string("买家ID").c_str()
            )
        );
        DRAW_STAR_LINE(180);
        OrderForm::show_specific_seller_orderform_info(cur_usr);
        DRAW_STAR_LINE(180);
#endif
#ifdef MYSQL
        string seller_show_all_orderforms_order = SqlItem::generate_select_order(
            MYSQL_ORDER_LIST_NAME, "*", {}
        );
        SqlItem::set_usr(cur_usr);
        SqlItem::dealwith_select_order(seller_show_all_orderforms_order);
        SqlItem::clear_usr();
        SqlItem::save_all_items();
#endif
        //利用输入等待进行退出
        show_prompt_info("按下回车键退出...");
        cin.clear();
        getpass("");
        window_update = true;
    }
    else if(choice == "6")              //6.返回用户主界面
    {
        window_exit = true;
        window_update = true;
    }
    return;
}
