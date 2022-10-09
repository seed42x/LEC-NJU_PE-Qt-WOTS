#ifndef RECHARGE_H
#define RECHARGE_H

#pragma once
#include "General.h"
using namespace std;

struct RechargeNode;

class Recharge
{
private:
    //全局变量
    static RechargeNode* recharge_recs_head;        //存储-链表头
    static RechargeNode* recharge_recs_tail;        //存储-链表尾
    //对象变量
    string usr_id_;                                 //用户ID
    double money_;                                  //充值金额
public:
    //构造 & 析构函数
    Recharge();
    Recharge(string id, double m);
    ~Recharge();
    //全局函数
    //文件IO
    static void recharge_recs_init();                                                       //从文件初始化
    static void recharge_recs_save();                                                       //保存到文件
    //追加 & 查找
    static void add_recharge_record(Recharge* new_rec);                                     //追加充值记录
    static void find_recs_of_specific_usr(vector<Recharge*>& rst, string target_id);        //查找指定用户所有记录
    //对象函数
    //获取信息
    string get_usrid() const { return usr_id_; }
    double get_money() const { return money_; }
};

struct RechargeNode
{
    Recharge* val;
    RechargeNode* next;
    RechargeNode(Recharge* v) { val = v; next = nullptr; }
    RechargeNode() { val = nullptr; next = nullptr; }
};

#endif // RECHARGE_H
