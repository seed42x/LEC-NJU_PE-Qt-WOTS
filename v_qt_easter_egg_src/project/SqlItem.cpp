#include"SqlItem.h"
#include"IOManager.h"
#include "TableWindow.h"
#include "QTimer"
using namespace std;

//全局变量初始化
bool SqlItem::admin_active = false;
Usr* SqlItem::cur_usr = nullptr;
int SqlItem::items_num = 0;
SqlItemNode* SqlItem::items_lib_head = new SqlItemNode();
SqlItemNode* SqlItem::items_lib_tail = SqlItem::items_lib_head;

//构造 & 析构函数
SqlItem::SqlItem() : order_(""), created_time_("") {}
SqlItem::SqlItem(string order)
{
    order_ = order;
    created_time_ = SqlItem::get_new_created_time();
}
SqlItem::SqlItem(string time, string order) : order_(order), created_time_(time) {}
SqlItem::~SqlItem() {}

//全局函数
//文件IO
void SqlItem::init_all_items()
{
    ifstream infile;
    infile.open("./source/sql_items.txt");
    if(infile.is_open() == false) return;
    while(!infile.eof())
    {
        string buf_order, buf_time;
        infile >> buf_time;
        infile.get();
        getline(infile, buf_order);
        SqlItem* p = new SqlItem(buf_time, buf_order);
        SqlItem::add_item(p);
    }
    infile.close();
    return;
}
void SqlItem::save_all_items()
{
    ofstream outfile;
    if(access("./source/", 0) != 0) mkdir("./source");
    outfile.open("./source/sql_items.txt");
    SqlItemNode* cursor = SqlItem::items_lib_head->next;
    while(cursor != nullptr)
    {
        outfile << cursor->val->created_time_ << "\t";
        outfile << cursor->val->order_;
        cursor = cursor->next;
        if(cursor != nullptr) outfile << endl;
    }
    outfile.close();
    return;
}
//指令追加
string SqlItem::get_new_created_time()
{
    //获取系统时间
    time_t cur_time;
    time(&cur_time);
    struct tm* buf;
    buf = localtime(&cur_time);
    buf->tm_year += 1900;
    buf->tm_mon += 1;
    //生成字符串
    string rst;
    rst += to_string(buf->tm_year);
    rst += "-";
    rst += (buf->tm_mon < 10 ? "0" : "") + to_string(buf->tm_mon);
    rst += "-";
    rst += (buf->tm_mday < 10 ? "0" : "") + to_string(buf->tm_mday);
    rst += "-" + to_string(buf->tm_hour);
    rst += ":" + to_string(buf->tm_min);
    rst += ":" + to_string(buf->tm_sec);
    return rst;
}
void SqlItem::add_item(SqlItem* new_item)
{
    SqlItemNode* p = new SqlItemNode(new_item);
    SqlItem::items_lib_tail->next = p;
    SqlItem::items_lib_tail = p;
    SqlItem::items_num++;
    return;
}

//总指令处理
void SqlItem::dealwith_order(const string& order)
{
    string order_header = order.substr(0, 6);
    if(order_header == "INSERT") dealwith_insert_order(order);
    else if(order_header == "UPDATE") dealwith_update_order(order);
    else if(order_header == "SELECT") dealwith_select_order(order);
    return;
}

//INSERT INTO指令生成与处理
string SqlItem::generate_insert_order(const string& list_name, const vector<string>& attrs)
{
    string rst = "INSERT INTO " + list_name + " VALUES (";
    for(int i = 0; i < (int)attrs.size(); i++)
    {
        if(i != (int)attrs.size() - 1) rst += attrs[i] + ",";
        else rst += attrs[i];
    }
    rst += ")";
    return rst;
    return string("");
}
void SqlItem::dealwith_insert_order(const string& order)
{
    //将指令添加到指令库中
    SqlItem* q = new SqlItem(SqlItem::get_new_created_time(), order);
    SqlItem::add_item(q);
    //对指令进行处理
    string buf = order.substr(order.find('(') + 1);
    buf.pop_back();
    vector<string> splits = SqlItem::mysql_sp(buf, ',');
    //解析表头进入分支处理
    if(order.substr(12, 4) == MYSQL_USR_LIST_NAME)          //用户表：用户注册
    {
        Usr* p = new Usr(splits[0], splits[1]);
        Usr::add_usr(p);
    }
    else if(order.substr(12, 6) == MYSQL_ORDER_LIST_NAME)   //订单表：添加订单
    {
        Merchandise* mer = Merchandise::find_mer_by_id(splits[0]);
        Usr* buyer = Usr::find_usr_by_id(splits[1]);
        int purchase_num = atoi(splits[2].c_str());
        OrderForm* p = new OrderForm(mer, buyer, purchase_num);
        OrderForm::add_orderform(p);
    }
    else if(order.substr(12, 9) == MYSQL_MER_LIST_NAME)    //商品表：添加商品
    {
        Merchandise* p = new Merchandise(
            splits[0], atof(splits[1].c_str()), atoi(splits[2].c_str()), splits[3], splits[4]
        );
        Merchandise::add_merchandise(p);
    }
    return;
}

//UPDATE指令生成 与 处理
string SqlItem::generate_update_order(const string &list_name, const vector<pair<string, string> > &attrs, const vector<pair<string, string> > &choice)
{
    string rst = "UPDATE " + list_name + " SET ";
    for(int i = 0; i < attrs.size(); i++)
    {
        rst += (attrs[i].first + "=" + attrs[i].second);
        if(i != attrs.size() - 1) rst += ",";
    }
    rst += " WHERE ";
    for(int i = 0; i < choice.size(); i++)
    {
        rst += (choice[i].first + "=" + choice[i].second);
        if(i != choice.size() - 1) rst += ",";
    }
    return rst;
}

void SqlItem::dealwith_update_order(const string &order)
{
    //将指令添加到指令库中
    SqlItem* q = new SqlItem(SqlItem::get_new_created_time(), order);
    SqlItem::add_item(q);
    //对指令进行处理
    //更新对
    string attrs_buf = order.substr(order.find("SET") + 4, order.find("WHERE") - order.find("SET") - 5);
    vector<pair<string, string>> attrs;
    while(true)
    {
        string buf_name = attrs_buf.substr(0, attrs_buf.find('='));
        attrs_buf = attrs_buf.substr(attrs_buf.find('=') + 1);
        if(attrs_buf.find(',') == string::npos)
        {
            attrs.push_back(pair<string, string>(buf_name, attrs_buf));
            break;
        }
        string buf_val = attrs_buf.substr(0, attrs_buf.find(','));
        attrs_buf = attrs_buf.substr(attrs_buf.find(',') + 1);
        attrs.push_back(pair<string, string>(buf_name, buf_val));
    }
    //选择对
    string choices_buf = order.substr(order.find("WHERE ") + 6);
    vector<pair<string, string>> choices;
    while(true)
    {
        string buf_name = choices_buf.substr(0, choices_buf.find('='));
        choices_buf = choices_buf.substr(choices_buf.find('=') + 1);
        if(choices_buf.find(',') == string::npos)
        {
            choices.push_back(pair<string, string>(buf_name, choices_buf));
            break;
        }
        string buf_val = choices_buf.substr(0, choices_buf.find(','));
        choices_buf = choices_buf.substr(choices_buf.find(',') + 1);
        choices.push_back(pair<string, string>(buf_name, buf_val));
    }
    if(order.substr(7, 4) == MYSQL_USR_LIST_NAME)       //用户表
    {
        if(attrs[0].first == "State" && choices[0].first == "UsrID")    //封禁用户
        {
            Usr* target = Usr::find_usr_by_id(choices[0].second);
            target->update_active(false);
        }
        else if(attrs[0].first == "Balance" && choices[0].first == "UsrID") //更新用户余额
        {
            Usr* target = Usr::find_usr_by_id(choices[0].second);
            target->update_balance(atof(attrs[0].second.c_str()));
        }
    }
    else if(order.substr(7, 9) == MYSQL_MER_LIST_NAME)        //商品表
    {
        if(attrs[0].first == "State" && choices[0].first == "SellerID")     //封禁用户-下架商品
        {
            Usr* target = Usr::find_usr_by_id(choices[0].second);
            Merchandise::remove_specific_usr_all_merchandises(target);
        }
        else if(attrs[0].first == "State" && choices[0].first == "MerID")   //下架商品
        {
            Merchandise* target = Merchandise::find_mer_by_id(choices[0].second);
            target->update_state(REMOVED);
        }
        else if(attrs[0].first == "Price" && choices[0].first == "MerID")   //修改商品价格
        {
            Merchandise* target = Merchandise::find_mer_by_id(choices[0].second);
            target->update_price(atof(attrs[0].second.c_str()));
        }
        else if(attrs[0].first == "Desc" && choices[0].first == "MerID")    //修改商品描述
        {
            Merchandise* target = Merchandise::find_mer_by_id(choices[0].second);
            target->update_description(attrs[0].second);
        }
        else if(attrs[0].first == "Num" && choices[0].first == "MerID")     //商品卖出，修改数量
        {
            Merchandise* target = Merchandise::find_mer_by_id(choices[0].second);
            target->update_num(atoi(attrs[0].second.c_str()));
        }
    }
    return;
}

//SELECT指令生成 与 处理
string SqlItem::generate_select_order(const string &list_name, const string &format, const vector<pair<string, string> > &choices)
{
    string rst = "SELECT " + format + " FROM " + list_name;
    if(choices.size() != 0) rst += " WHERE";
    for(int i = 0; i < choices.size(); i++)
    {
        rst += " " + choices[i].first + " CONTAINS " + choices[i].second;
    }
    return rst;
}

void SqlItem::dealwith_select_order(const string &order)
{
    //将指令添加到指令库中
    SqlItem* q = new SqlItem(SqlItem::get_new_created_time(), order);
    SqlItem::add_item(q);
    return;
}

vector<string> SqlItem::mysql_sp(string s, char sp)
{
    string buf;
    vector<string> rst;
    for(int i = 0; i < (int)s.size(); i++)
    {
        if(s[i] != sp) buf.push_back(s[i]);
        else
        {
            rst.push_back(buf);
            buf.clear();
        }
    }
    if(buf.size() != 0) rst.push_back(buf);
    return rst;
}
