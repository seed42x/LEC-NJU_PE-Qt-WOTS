#pragma once
#include"General.h"
#include"Usr.h"
#include"Merchandise.h"

struct OrderFormNode;

class OrderForm
{
private:
    //全局属性
    static int orderform_num;                               //订单数量
    static OrderFormNode* orderforms_lib_head;              //存储-链表头
    static OrderFormNode* orderforms_lib_tail;              //存储-链表尾
    //对象属性
    string id_;                                             //订单ID
    string mer_id_;                                         //商品ID
    double uint_price_;                                     //商品单价
    int mers_num_;                                          //成交数量
    string tran_time_;                                      //成交时间
    string seller_id_;                                      //卖家ID
    string buyer_id_;                                       //买家ID
public:
    //构造 & 析构函数
    OrderForm();
    OrderForm(Merchandise* mer, Usr* usr, int num);
    OrderForm(string mer_id, string seller_id, string buyer_id, double uintp, int mers_num);
    OrderForm(string id, string mer_id, string seller_id, string buyer_id, double uintp, int mer_num, string trans_time);
    ~OrderForm();
    //全局函数
    //文件IO
    static void init_all_orderforms();                                                                  //从文件初始化
    static void save_all_orderforms();                                                                  //保存到文件
    //追加商品
    static string get_new_id();                                                                         //获取新ID
    static string get_new_trantime();                                                                   //获取新交易时间
    static void add_orderform(OrderForm* new_orderform);                                                //添加订单
    //查找
    static void find_specific_buyer_orderforms(vector<OrderForm*>& rst, string target_id);              //查找买家订单
    static void find_specific_seller_orderforms(vector<OrderForm*>& rst, string target_id);             //查找卖家订单
    //展示信息
    static void show_specific_buyer_orderform_info(Usr* cur_usr);                                       //展示买家所有订单
    static void show_specific_seller_orderform_info(Usr* cur_usr);                                      //展示卖家所有订单
    static void show_all_usrs_orderform_info();                                                         //展示所有订单

    //对象函数
    //获取信息
    string get_id() { return id_; }
    string get_mer_id() { return mer_id_; }
    string get_seller_id() { return seller_id_; }
    string get_buyer_id() { return buyer_id_; }
    double get_uintp() { return uint_price_; }
    int get_num() { return mers_num_; }
    string get_tran_time() { return tran_time_; }
    void show_details_info() const;
};

struct OrderFormNode
{
    OrderForm* val;
    OrderFormNode* next;
    OrderFormNode() { val = nullptr; next = nullptr; }
    OrderFormNode(OrderForm* v) { val = v; next = nullptr; }
};