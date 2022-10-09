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
    static void init_all_usrs();                                //从文件中初始化所有用户
    static void save_all_usrs();                                //保存当前所有用户数据到文件中
    //追加用户
    static string get_new_id();                                 //获取一个新的用户ID
    static void add_usr(Usr* new_usr);                          //向用户库中添加新用户
    //查找
    static Usr* find_usr_by_id(string target_id);               //以ID为线索查找对应用户
    static Usr* find_usr_by_name(string target_name);           //以姓名为线索查找对应用户
    //展示信息 & 封禁用户
    static void show_all_usrs_info();                           //展示所有用户的信息条目
    static void ban_usr(Usr* target);                           //封禁用户

    //对象方法
    //更新信息
    void update_name(string new_name) { name_ = new_name; }                             //更新用户名称
    void update_phone_number(string new_pnum) { phone_number_ = new_pnum; }             //更新用户联系方式
    void update_addr(string new_addr) { address_ = new_addr; }                          //更新用户地址
    void update_balance(double money) { balance_ = money; }                             //更新用户余额
    void update_active(bool new_state) { active_ = new_state; }                         //更新用户状态
    void recharge(double money) { balance_ += money; }                                  //用户充值
    void pay(double cost) { balance_ -= cost; }                                         //用户支付
    void update_mode(UsrMode new_mode) { mode_ = new_mode; }                            //更新用户模式：买家/卖家
    //获取信息
    string get_id() const { return id_; }                                                   //获取用户ID
    string get_passwd() const { return passwd_; }                                           //获取用户密码
    string get_name() const { return name_; }                                               //获取用户名称
    string get_p_num() const { return phone_number_; }                                      //获取用户电话号码
    string get_addr() const { return address_; }                                            //获取用户地址
    UsrMode get_mode() const { return mode_; }                                              //获取用户当前模式
    double get_balance() const { return balance_; }                                         //获取用户余额
    string get_state() const { return active_ ? "正常" : "\033[31m封禁\033[0m"; }           //获取用户状态（展示信息用）
    bool get_active() const { return active_; }                                             //获取用户状态
    //展示信息
    void show_simple_info() const;                                                          //展示用户简略信息
    void show_details_info() const;                                                         //展示用户详细信息
};

struct UsrNode                  //用户链表节点
{
    Usr* val;
    UsrNode* next;
    UsrNode() { val = nullptr; next = nullptr; }
    UsrNode(Usr* v) { val = v; next = nullptr; }
};