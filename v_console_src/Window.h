#pragma once
#include"General.h"
#include"IOManager.cpp"

enum Page {MAIN_MENU, ADMIN_MENU, USR_MENU, USR_BUY_MENU, USR_SELL_MENU, USR_INFO_MENU};

class Window : public IOManager
{
private:
    //全局变量
    static vector<string> menubars_;                //菜单栏数据
    static vector<regex> regex_menu_choices_;       //正则表达式-选择限制
    //对象变量
    Page type_;
public:
    //构造 & 析构函数
    Window(Page pg);
    ~Window();
    //对象方法
    //显示
    void show();
    //消息分支
    void branches(bool& window_update, bool& exit, bool& admin_active, Usr*& cur_usr,               //总分支
                  bool& window_exit, Window*& next_window);
    void main_menu_branches(bool& window_update, bool& exit, bool& admin_active, Usr*& cur_usr,     //主菜单分支
                            bool& window_exit, Window*& next_window);
    void admin_menu_branches(bool& window_update, bool& admin_active,                               //管理员菜单分支
                             bool& window_exit, Window*& next_window);
    void usr_menu_branches(bool& window_update, Usr*& cur_usr,                                      //用户主菜单分支
                           bool& window_exit, Window*& next_window);
    void usr_info_menu_branches(bool& window_update, Usr*& cur_usr,                                 //用户信息菜单分支
                                bool& window_exit, Window*& next_window);
    void usr_buy_menu_branches(bool& window_update, Usr*& cur_usr,                                  //买家主菜单分支
                               bool& window_exit, Window*& next_window);
    void usr_sell_menu_branches(bool& window_update, Usr*& cur_usr,                                 //卖家主菜单分支
                                bool& window_exit, Window*& next_window);
};