#include"Usr.h"

//全局变量初始化
int Usr::usrs_num = 0;
UsrNode* Usr::usrs_lib_head = new UsrNode();
UsrNode* Usr::usrs_lib_tail = Usr::usrs_lib_head;

//构造 & 析构函数
Usr::Usr() :
id_("none"), name_("none"), passwd_("none"), phone_number_("none"), address_("none"), balance_(0), active_(true), mode_(BUYER) {}
Usr::Usr(string id, string name, string passwd, string p_num, string addr, double bal, bool sta) :
id_(id), name_(name), passwd_(passwd), phone_number_(p_num), address_(addr), balance_(bal), active_(sta), mode_(BUYER) {}
Usr::Usr(string name, string passwd) :
name_(name), passwd_(passwd), phone_number_("none"), address_("none"), balance_(0), active_(true), mode_(BUYER)
{
    id_ = get_new_id();
}
Usr::~Usr() {}

//全局方法
//文件IO
void Usr::init_all_usrs()
{
    ifstream infile;
    infile.open("./source/usrs.txt");
    if(infile.is_open() == false) return;
    //利用表头进行校验
    string hid, hname, hpasswd, hpnum, haddr, hbalance, hstate;
    infile >> hid >> hname >> hpasswd >> hpnum >> haddr >> hbalance >> hstate;
    if(hid != "ID" || hname != "Name" || hpasswd != "Passwd" || hpnum != "Tle" || haddr != "Address" ||
       hbalance != "Balance" || hstate != "State")
        return;
    //读取数据
    while(!infile.eof())
    {
        string buf_id, buf_name, buf_passwd, buf_pnum, buf_addr;
        bool buf_state;
        double buf_balance;
        infile >> buf_id;
        infile >> buf_name;
        infile >> buf_passwd;
        infile >> buf_pnum;
        infile >> buf_addr;
        infile >> buf_balance;
        infile >> buf_state;
        Usr* p = new Usr(buf_id, buf_name, buf_passwd, buf_pnum, buf_addr, buf_balance, buf_state);
        Usr::add_usr(p);
    }
    infile.close();
    return;
}
void Usr::save_all_usrs()
{
    ofstream outfile;
    //检查文件夹路径是否存在，若不存在则进行创建
    if(access("./source/", 0) != 0) mkdir("./source/", S_IRWXU);
    outfile.open("./source/usrs.txt");
    //追加表头
    outfile << "ID" << "\t\t\t";
    outfile << "Name" << "\t\t\t";
    outfile << "Passwd" << "\t\t\t";
    outfile << "Tle" << "\t\t\t";
    outfile << "Address" << "\t\t\t";
    outfile << "Balance" << "\t\t\t";
    outfile << "State";
    //存入数据
    UsrNode* cursor = Usr::usrs_lib_head->next;
    while(cursor != nullptr)
    {
        outfile << endl;
        outfile << cursor->val->id_ << "\t\t\t";
        outfile << cursor->val->name_ << "\t\t\t";
        outfile << cursor->val->passwd_ << "\t\t\t";
        outfile << cursor->val->phone_number_ << "\t\t\t";
        outfile << cursor->val->address_ << "\t\t\t";
        outfile << cursor->val->balance_ << "\t\t\t";
        outfile << cursor->val->active_;
        cursor = cursor->next;
    }
    outfile.close();
    return;
}
//追加用户
string Usr::get_new_id()
{
    string rst("U");
    string num = to_string(Usr::usrs_num);
    for(int i = 0; i < 3 - num.size(); i++) rst += "0";
    rst += num;
    return rst;
}
void Usr::add_usr(Usr* new_usr)
{
    Usr::usrs_num++;
    UsrNode* p = new UsrNode(new_usr);
    Usr::usrs_lib_tail->next = p;
    Usr::usrs_lib_tail = Usr::usrs_lib_tail->next;
    return;
}
//查找
Usr* Usr::find_usr_by_id(string target_id)
{
    UsrNode* cursor = Usr::usrs_lib_head->next;
    while(cursor != nullptr)
    {
        if(cursor->val->id_ == target_id) return cursor->val;
        cursor = cursor->next;
    }
    return nullptr;
}
Usr* Usr::find_usr_by_name(string target_name)
{
    UsrNode* cursor = Usr::usrs_lib_head->next;
    while(cursor != nullptr)
    {
        if(cursor->val->name_ == target_name) return cursor->val;
        cursor = cursor->next;
    }
    return nullptr;
}
//展示信息 & 封禁用户
void Usr::show_all_usrs_info()
{
    UsrNode* cursor = Usr::usrs_lib_head->next;
    while(cursor != nullptr)
    {
        printf(
            "%-20s\t%-20s\t%-30s\t%-50s\t%-20.1lf\t%-20s\n",
            cursor->val->get_id().c_str(),
            cursor->val->get_name().c_str(),
            cursor->val->get_p_num().c_str(),
            cursor->val->get_addr().c_str(),
            cursor->val->get_balance(),
            cursor->val->get_state().c_str()
        );
        cursor = cursor->next;
    }
    return;
}
void Usr::ban_usr(Usr* target)
{
    target->active_ = false;
}

//用户方法
//展示信息
void Usr::show_simple_info() const
{
    printf(
        "%-20s\t%-20s\t%-30s\t%-50s\t%-20.1lf\t%-20s\n",
        id_.c_str(),
        name_.c_str(),
        phone_number_.c_str(),
        address_.c_str(),
        balance_,
        this->get_state().c_str()
    );
    return;
}
void Usr::show_details_info() const
{
    printf("\033[1m用户ID：\033[0m\t\t%s\n", id_.c_str());
    printf("\033[1m用户名：\033[0m\t\t%s\n", name_.c_str());
    printf("\033[1m联系方式：\033[0m\t%s\n", phone_number_.c_str());
    printf("\033[1m地址：\033[0m\t\t%s\n", address_.c_str());
#ifndef CALCULATOR
    printf("\033[1m余额：\033[0m\t\t%.1lf\n", balance_);
#endif
    return;
}
