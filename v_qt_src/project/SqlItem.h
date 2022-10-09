#ifndef SQLITEM_H
#define SQLITEM_H

#pragma once
#include "General.h"
#include "Usr.h"
#include "Merchandise.h"
#include "OrderForm.h"
using namespace std;

struct SqlItemNode;

class SqlItem
{
private:
    //全局变量
    static bool admin_active;                   //管理员是否活跃
    static Usr* cur_usr;                        //用户是否活跃
    static int items_num;                       //指令数目
    static SqlItemNode* items_lib_head;         //存储-链表头
    static SqlItemNode* items_lib_tail;         //存储-链表尾
    //对象变量
    string created_time_;                       //执行时间
    string order_;                              //指令
public:
    //构造 & 析构函数
    SqlItem();
    SqlItem(string order);
    SqlItem(string order, string time);
    ~SqlItem();
    //全局函数
    //文件IO
    static void init_all_items();
    static void save_all_items();
    //指令追加
    static string get_new_created_time();
    static void add_item(SqlItem* new_item);
    //总指令处理（类似分线器，下分到各个其他处理函数）
    static void dealwith_order(const string& order);
    //INSERT INTO指令生成 与 处理
    static string generate_insert_order(const string& list_name, const vector<string>& attrs);
    static void dealwith_insert_order(const string& order);
    //UPDATE指令生成 与 处理
    static string generate_update_order(const string& list_name, const vector<pair<string, string>>& attrs, const vector<pair<string, string>>& choice);
    static void dealwith_update_order(const string& order);
    //SELECT指令生成 与 处理
    static string generate_select_order(const string& list_name, const string& format, const vector<pair<string, string>>& choices);
    static void dealwith_select_order(const string& order);
    //管理员状态切换
    static void change_admin_active() { admin_active = true; }
    static void change_admin_inactive() { admin_active = false; }
    //用户状态切换
    static void set_usr(Usr* new_usr) { cur_usr = new_usr; }
    static void clear_usr() { cur_usr = nullptr; }

    //库函数自实现
    static vector<string> mysql_sp(string s, char sp);
};

struct SqlItemNode
{
    SqlItem* val;
    SqlItemNode* next;
    SqlItemNode() { val = nullptr; next = nullptr; }
    SqlItemNode(SqlItem* v) { val = v; next = nullptr; }
};

#endif // SQLITEM_H
