#include"System.h"

//构造 & 析构函数
System::System()
{
    this->exit_ = false;
    this->window_update_ = false;

    this->admin_active_ = false;
    this->cur_usr_ = nullptr;

    Window* p = new Window(MAIN_MENU);
    this->windows_.push(p);

    Usr::init_all_usrs();
    Merchandise::init_all_merchandises();
    OrderForm::init_all_orderforms();
#ifdef MYSQL
    SqlItem::init_all_items();
#endif
#ifdef CALCULATOR
    Recharge::recharge_recs_init();
#endif
}
System::~System()
{
    Usr::save_all_usrs();
    Merchandise::save_all_merchandises();
    OrderForm::save_all_orderforms();
#ifdef MYSQL
    SqlItem::save_all_items();
#endif
#ifdef CALCULATOR
    Recharge::recharge_recs_save();
#endif
}
//消息循环
void System::exec()
{
    //初始展示主菜单
    windows_.top()->show();
    //每次消息循环后检查退出引脚
    while(!exit_)
    {
        //进入消息分支
        Window* next = nullptr;
        bool window_exit = false;
        cin.clear();
        windows_.top()->branches(window_update_, exit_, admin_active_, cur_usr_, window_exit, next);
        //若退出则将栈顶窗口弹出删除
        if(window_exit == true)
        {
            Window* p = windows_.top();
            windows_.pop();
            delete p;
        }
        //若进入新窗口则将窗口压入栈中
        if(next != nullptr) windows_.push(next);
        //是否更新窗口显示
        if(window_update_ == true)
        {
            CLEAR_SCREEN
            window_update_ = false;
            windows_.top()->show();
        }
    }
    return;
}
