#include"Usr.h"

//TODO7：全局变量初始化


//TODO7：构造 & 析构函数

//全局方法
//文件IO
void Usr::init_all_usrs()
{
    //TODO17：用户列表-从文件中初始化所有用户

}
void Usr::save_all_usrs()
{
    //TODO17：用户列表-将所有用户保存到文件当中
    
}
//追加用户
string Usr::get_new_id()
{
    //TODO7：创建新用户时，根据当前记录的总用户数目生成新的ID

}
void Usr::add_usr(Usr* new_usr)
{
    //TODO7：向用户库中追加新的用户，注意用户总数目的变化

}
//查找
Usr* Usr::find_usr_by_id(string target_id)
{
    //TODO7：以ID为线索查找用户

}
Usr* Usr::find_usr_by_name(string target_name)
{
    //TODO7：以姓名为线索查找用户

}
//展示信息 & 封禁用户
void Usr::show_all_usrs_info()
{
    //TODO7：展示所有用户的信息，通过循环调用一堆打印函数即可

}
void Usr::ban_usr(Usr* target)
{
    //TODO7：封禁用户

}

//用户方法
//展示信息
void Usr::show_simple_info() const
{
    //TODO7：展示用户的简要信息

}
void Usr::show_details_info() const
{
    //TODO7：展示用户的详细信息
    
}
