#include"OrderForm.h"

//TODO9：全局属性初始化


//TODO9：构造 & 析构函数


//全局函数
//文件IO
void OrderForm::init_all_orderforms()
{
    //TODO17：订单列表-从文件中初始化所有订单

}
void OrderForm::save_all_orderforms()
{
    //TODO17：订单列表-将所有订单保存到文件当中
    
}


string OrderForm::get_new_id()
{
    //TODO9：以订单库中订单数量生成新的订单ID
}
string OrderForm::get_new_trantime()
{
    //TODO9：获取当前系统时间作为交易时间

}
void OrderForm::add_orderform(OrderForm* new_orderform)
{
    //TODO9：向订单库中追加新的订单

}
//查找
void OrderForm::find_specific_buyer_orderforms(vector<OrderForm*>& rst, string target_id)
{
    //TODO9：查找指定买家的所有订单，并且以数组形式返回

}
void OrderForm::find_specific_seller_orderforms(vector<OrderForm*>& rst, string target_id)
{
   //TODO9：查找指定卖家的所有订单，并且以数组形式返回

}
//展示信息
void OrderForm::show_specific_buyer_orderform_info(Usr* cur_usr)
{
    //TODO9：展示指定买家的所有订单信息

}
void OrderForm::show_specific_seller_orderform_info(Usr* cur_usr)
{
    //TODO9：展示指定卖家的所有订单信息

}
void OrderForm::show_all_usrs_orderform_info()
{
    //TODO9：展示所有订单信息

}
void OrderForm::show_details_info() const
{
    //TODO9：展示订单的详细信息
    
}
