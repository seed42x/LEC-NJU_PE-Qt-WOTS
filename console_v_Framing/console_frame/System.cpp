#include"System.h"

//构造 & 析构函数
System::System()
{
    //TODO3: init our system attributions

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
    //TODO4: finish exec function
    
    return;
}
