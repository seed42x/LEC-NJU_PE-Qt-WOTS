#pragma once

#include"General.h"
#include"Window.cpp"
#include"SqlItem.cpp"
#include"Recharge.cpp"

class System
{
private:
    bool exit_;                     //退出引脚
    bool window_update_;            //显示更新
    stack<Window*> windows_;        //窗口栈
    bool admin_active_;             //管理员是否活跃
    Usr* cur_usr_;                  //当前用户
public:
    //构造 & 析构函数
    System();
    ~System();
    //消息循环
    void exec();
};