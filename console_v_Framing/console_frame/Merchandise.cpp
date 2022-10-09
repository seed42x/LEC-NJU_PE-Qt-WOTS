#include"Merchandise.h"

//TODO8：全局变量初始化

//TODO8：构造函数 & 析构函数


//全局方法
//文件IO
void Merchandise::init_all_merchandises()
{
    //TODO17：商品列表-从文件中初始化所有商品列表

}
void Merchandise::save_all_merchandises()
{
    //TODO17：商品列表-将所有商品保存到文件当中
    
}


string Merchandise::get_new_id()
{
    //TODO8：追加商品

}
string Merchandise::get_new_added_time()
{
    //TODO8：根据当前商品库中的商品种类数量生成新的商品ID

}
void Merchandise::add_merchandise(Merchandise* new_merchandise)
{
    //TODO8：追加新的商品到商品库中

}
//查找
Merchandise* Merchandise::find_mer_by_name(string target_name)
{
    //TODO8：以商品名称为线索查找到商品

}
Merchandise* Merchandise::find_mer_by_id(string target_id)
{
    //TODO8：以商品ID为线索查找到商品
    
}
void Merchandise::search_merchandises_by_name(vector<Merchandise*>& rst, string target_name)
{
    //TODO8：以商品名称为线索查找所有同名商品，并以指针数组形式进行返回

}
//展示信息
void Merchandise::show_specific_usr_merchandises_info(Usr* cur_usr)
{
    //TODO8：展示特定用户的所有商品信息

}
void Merchandise::admin_show_all_merchandises_info()
{
    //TODO8：管理员查看所有商品信息

}
void Merchandise::usr_show_all_merchandises_info()
{
    //TODO8：买家查看所有商品信息

}
//其它
void Merchandise::remove_specific_usr_all_merchandises(Usr* usr)
{
    //TODO8：下架特定用户的所有商品

}

//对象方法
//获取信息
void Merchandise::show_details_info() const
{
    //TODO8：展示商品的详细信息

}
