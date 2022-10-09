#pragma once
#include"General.h"
#include"Calculator.h"
#include"Recharge.h"

struct UsrNode;

class Usr
{
private:
    //全局变量
    static int usrs_num;                    //用户数量
    static UsrNode* usrs_lib_head;          //存储-链表头
    static UsrNode* usrs_lib_tail;          //存储-链表尾
    //对象变量
    string id_;                             //用户ID
    string name_;                           //用户姓名
    string passwd_;                         //用户密码
    string phone_number_;                   //联系方式
    string address_;                        //地址
    double balance_;                        //余额
    bool active_;                           //用户状态
    UsrMode mode_;                          //买家/买家模式
public:
    //构造函数 & 析构函数
    Usr();
    Usr(string id, string name, string passwd, string p_num, string addr, double bal, bool sta);
    Usr(string name, string passwd);
    ~Usr();
    //全局方法
    //文件IO
    static void init_all_usrs();
    static void save_all_usrs();
    //追加用户
    static string get_new_id();
    static void add_usr(Usr* new_usr);
    //查找
    static Usr* find_usr_by_id(string target_id);
    static Usr* find_usr_by_name(string target_name);
    //展示信息 & 封禁用户
    static void show_all_usrs_info();
    static void ban_usr(Usr* target);

    //对象方法
    //更新信息
    void update_name(string new_name) { name_ = new_name; }
    void update_phone_number(string new_pnum) { phone_number_ = new_pnum; }
    void update_addr(string new_addr) { address_ = new_addr; }
    void update_balance(double money) { balance_ = money; }
    void update_active(bool new_state) { active_ = new_state; }
    void recharge(double money) { balance_ += money; }
    void pay(double cost) { balance_ -= cost; }
    void update_mode(UsrMode new_mode) { mode_ = new_mode; }
    //获取信息
    string get_id() const { return id_; }
    string get_passwd() const { return passwd_; }
    string get_name() const { return name_; }
    string get_p_num() const { return phone_number_; }
    string get_addr() const { return address_; }
    UsrMode get_mode() const { return mode_; }
    double get_balance() const { return balance_; }
    string get_state() const { return active_ ? "正常" : "\033[31m封禁\033[0m"; }
    bool get_active() const { return active_; }
    //展示信息
    void show_simple_info() const;
    void show_details_info() const;
};

struct UsrNode
{
    Usr* val;
    UsrNode* next;
    UsrNode() { val = nullptr; next = nullptr; }
    UsrNode(Usr* v) { val = v; next = nullptr; }
};