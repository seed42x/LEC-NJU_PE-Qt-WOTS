#include"SqlItem.h"
#include"IOManager.h"
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
    for(int i = 0; i < attrs.size(); i++)
    {
        if(i != attrs.size() - 1) rst += attrs[i] + ",";
        else rst += attrs[i];
    }
    rst += ")";
    return rst;
}
void SqlItem::dealwith_insert_order(const string& order)
{
    //将指令添加到指令库中
    SqlItem* q = new SqlItem(SqlItem::get_new_created_time(), order);
    SqlItem::add_item(q);
    //对指令进行处理
    string buf = order.substr(order.find('(') + 1);
    buf.pop_back();
    vector<string> splits = split(buf, ',');
    //解析表头进入分支处理
    if(order.substr(12, 4) == MYSQL_USR_LIST_NAME)          //用户表：用户注册
    {
        Usr* p = new Usr(splits[0], splits[1]);
        Usr::add_usr(p);
    }
    else if(order.substr(12, 6) == MYSQL_ORDER_LIST_NAME)   //订单表：添加订单
    {
        OrderForm* p = new OrderForm(splits[0], splits[1], splits[2], atof(splits[3].c_str()), atoi(splits[4].c_str()));
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
//UPDATE指令生成与处理
string SqlItem::generate_update_order(const string& list_name, const vector<pair<string, string>>& attrs, const vector<pair<string, string>>& choice)
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
void SqlItem::dealwith_update_order(const string& order)
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
    //解析表头进入分支处理
    if(order.substr(7, 4) == MYSQL_USR_LIST_NAME)           //用户表
    {
        if(attrs[0].first == "State" && choices[0].first == "UsrID")     //封禁用户
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
    else if(order.substr(7, 6) == MYSQL_ORDER_LIST_NAME)    //订单表
    {

    }
    else if(order.substr(7, 9) == MYSQL_MER_LIST_NAME)      //商品表
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
//SELECT指令生成与处理
string SqlItem::generate_select_order(const string& list_name, const string& format, const vector<pair<string, string>>& choices)
{
    string rst = "SELECT " + format + " FROM " + list_name;
    if(choices.size() != 0) rst += " WHERE";
    for(int i = 0; i < choices.size(); i++)
    {
        rst += " " + choices[i].first + " CONTAINS " + choices[i].second;
    }
    return rst;
}
void SqlItem::dealwith_select_order(const string& order)
{
    //将指令添加到指令库中
    SqlItem* q = new SqlItem(SqlItem::get_new_created_time(), order);
    SqlItem::add_item(q);
    //对指令进行处理
    string format = order.substr(7, 1);
    if(order.find("WHERE") == string::npos)     //查看整张表
    {
        string list_name = order.substr(order.find("FROM ") + 5);
        if(list_name == MYSQL_USR_LIST_NAME)                //查看所有用户
        {
            if(admin_active == true)    //管理员权限
            {
                DRAW_STAR_LINE(180);
                OUTPUT(
                    vector<string>{HIGHLIGHT},
                    printf(
                        "%-20s\t%-20s\t%-30s\t%-50s\t%-20s\t%-20s\n",
                        string("用户ID").c_str(),
                        string("用户名").c_str(),
                        string("联系方式").c_str(),
                        string("地址").c_str(),
                        string("钱包余额").c_str(),
                        string("用户状态").c_str()
                    )
                );
                DRAW_STAR_LINE(180);
                Usr::show_all_usrs_info();
                DRAW_STAR_LINE(180);
            }
        }
        else if(list_name == MYSQL_MER_LIST_NAME)           //查看所有商品
        {
            if(admin_active == true)        //管理员权限
            {
                DRAW_STAR_LINE(180);
                OUTPUT(
                    vector<string>{HIGHLIGHT},
                    printf(
                        "%-20s\t%-30s\t%-20s\t%-20s\t%-20s\t%-20s\t%-20s\n",
                        string("商品ID").c_str(),
                        string("商品名称").c_str(),
                        string("价格").c_str(),
                        string("数量").c_str(),
                        string("上架时间").c_str(),
                        string("卖家ID").c_str(),
                        string("商品状态").c_str()
                    )
                );
                DRAW_STAR_LINE(180);
                Merchandise::admin_show_all_merchandises_info();
                DRAW_STAR_LINE(180);
            }
            else if(cur_usr != nullptr && cur_usr->get_mode() == BUYER)     //普通用户(买家)权限
            {
                DRAW_STAR_LINE(180);
                OUTPUT(
                    vector<string>{HIGHLIGHT},
                    printf(
                        "%-20s\t%-30s\t%-20s\t%-20s\t%-20s\t%-20s\n",
                        string("商品ID").c_str(),
                        string("商品名称").c_str(),
                        string("价格").c_str(),
                        string("数量").c_str(),
                        string("上架时间").c_str(),
                        string("卖家ID").c_str()
                    )
                );
                DRAW_STAR_LINE(180);
                Merchandise::usr_show_all_merchandises_info();
                DRAW_STAR_LINE(180);
            }
            else if(cur_usr != nullptr && cur_usr->get_mode() == SELLER)    //普通用户(卖家)权限
            {
                DRAW_STAR_LINE(180);
                OUTPUT(
                    vector<string>{HIGHLIGHT},
                    printf(
                        "%-20s\t%-30s\t%-20s\t%-20s\t%-20s\t%-20s\n",
                        string("商品ID").c_str(),
                        string("商品名称").c_str(),
                        string("价格").c_str(),
                        string("数量").c_str(),
                        string("上架时间").c_str(),
                        string("商品状态").c_str()
                    )
                );
                DRAW_STAR_LINE(180);
                Merchandise::show_specific_usr_merchandises_info(cur_usr);
                DRAW_STAR_LINE(180);
            }
        }
        else if(list_name == MYSQL_ORDER_LIST_NAME)         //查看所有订单
        {
            if(admin_active == true)            //管理员权限
            {
                DRAW_STAR_LINE(180);
                OUTPUT(
                    vector<string>{HIGHLIGHT},
                    printf(
                        "%-20s\t%-20s\t%-20s\t%-20s\t%-20s\t%-20s\t%-20s\n",
                        string("订单ID").c_str(),
                        string("商品ID").c_str(),
                        string("交易单价").c_str(),
                        string("交易数量").c_str(),
                        string("交易时间").c_str(),
                        string("卖家ID").c_str(),
                        string("买家ID").c_str()
                    )
                );
                DRAW_STAR_LINE(180);
                OrderForm::show_all_usrs_orderform_info();
                DRAW_STAR_LINE(180);
            }
            else if(cur_usr != nullptr && cur_usr->get_mode() == BUYER)           //普通用户(买家)权限
            {
                DRAW_STAR_LINE(180);
                OUTPUT(
                    vector<string>{HIGHLIGHT},
                    printf(
                        "%-20s\t%-20s\t%-20s\t%-20s\t%-20s\t%-20s\n",
                        string("订单ID").c_str(),
                        string("商品ID").c_str(),
                        string("交易单价").c_str(),
                        string("交易数量").c_str(),
                        string("交易时间").c_str(),
                        string("卖家ID").c_str()
                    )
                );
                DRAW_STAR_LINE(180);
                OrderForm::show_specific_buyer_orderform_info(SqlItem::cur_usr);
                DRAW_STAR_LINE(180);
            }
            else if(cur_usr != nullptr && cur_usr->get_mode() == SELLER)        //普通用户(卖家)权限
            {
                DRAW_STAR_LINE(180);
                OUTPUT(
                    vector<string>{HIGHLIGHT},
                    printf(
                        "%-20s\t%-20s\t%-20s\t%-20s\t%-20s\t%-20s\n",
                        string("订单ID").c_str(),
                        string("商品ID").c_str(),
                        string("交易单价").c_str(),
                        string("交易数量").c_str(),
                        string("交易时间").c_str(),
                        string("买家ID").c_str()
                    )
                );
                DRAW_STAR_LINE(180);
                OrderForm::show_specific_seller_orderform_info(cur_usr);
                DRAW_STAR_LINE(180);
            }
        }
    }
    else                                        //查询部分项
    {
        string list_name = order.substr(order.find("FROM ") + 5, order.find(" WHERE") - order.find("FROM ") - 5);
        vector<pair<string, string>> choices;
        string buf = order.substr(order.find("WHERE ") + 6);
        //条件对
        string buf_key = buf.substr(0, buf.find(" CONTAINS"));
        string buf_val = buf.substr(buf.find("CONTAINS ") + 9);
        choices.push_back(pair<string, string>(buf_key, buf_val));
        if(list_name == MYSQL_MER_LIST_NAME)
        {
            if(SqlItem::admin_active == true && choices[0].first == "MerName")
            {
                string target = choices[0].second;
                vector<Merchandise*> rst;
                Merchandise::search_merchandises_by_name(rst, target);
                if(rst.size() == 0)
                {
                    IOManager::show_prompt_info("未找到目标商品...\n");
                    sleep(DELAY);
                    return;
                }
                //找到目标并进行罗列
                DRAW_STAR_LINE(180);
                OUTPUT(
                    vector<string>{HIGHLIGHT},
                    printf(
                        "%-20s\t%-30s\t%-20s\t%-20s\t%-20s\t%-20s\t%-20s\n",
                        string("商品ID").c_str(),
                        string("商品名称").c_str(),
                        string("价格").c_str(),
                        string("数量").c_str(),
                        string("上架时间").c_str(),
                        string("卖家ID").c_str(),
                        string("商品状态").c_str()
                    )
                );
                DRAW_STAR_LINE(180);
                for(int i = 0; i < rst.size(); i++)
                {
                    printf(
                        "%-20s\t%-30s\t%-20.1lf\t%-20d\t%-20s\t%-20s\t%-20s\n",
                        rst[i]->get_id().c_str(),
                        rst[i]->get_name().c_str(),
                        rst[i]->get_price(),
                        rst[i]->get_num(),
                        rst[i]->get_added_time().c_str(),
                        rst[i]->get_seller_id().c_str(),
                        rst[i]->get_state().c_str()
                    );
                }
                DRAW_STAR_LINE(180);
            }
            else if(admin_active == false)         //普通用户(买家)权限
            {
                if(choices[0].first == "MerName")           //买家搜索商品
                {
                    string target_name = choices[0].second;
                    vector<Merchandise*> rst;
                    Merchandise::search_merchandises_by_name(rst, target_name);
                    //未找到目标
                    if(rst.size() == 0)
                    {
                        IOManager::show_prompt_info("未找到目标商品...\n");
                        sleep(DELAY);
                        return;
                    }
                    //找到目标并进行罗列
                    DRAW_STAR_LINE(180);
                    OUTPUT(
                        vector<string>{HIGHLIGHT},
                        printf(
                            "%-20s\t%-30s\t%-20s\t%-20s\t%-20s\t%-20s\n",
                            string("商品ID").c_str(),
                            string("商品名称").c_str(),
                            string("价格").c_str(),
                            string("数量").c_str(),
                            string("上架时间").c_str(),
                            string("卖家ID").c_str()
                        )
                    );
                    DRAW_STAR_LINE(180);
                    for(int i = 0; i < rst.size(); i++)
                    {
                        if(rst[i]->get_mode() == ONSALE)
                        {
                            printf(
                                "%-20s\t%-30s\t%-20.1lf\t%-20d\t%-20s\t%-20s\n",
                                rst[i]->get_id().c_str(),
                                rst[i]->get_name().c_str(),
                                rst[i]->get_price(),
                                rst[i]->get_num(),
                                rst[i]->get_added_time().c_str(),
                                rst[i]->get_seller_id().c_str()
                            );
                        }
                    }
                    DRAW_STAR_LINE(180);
                }
                else if(choices[0].first == "MerID")        //买家查看商品详细信息
                {
                    string target_id = choices[0].second;
                    Merchandise* target = Merchandise::find_mer_by_id(target_id);
                    //查询该商品是否存在
                    if(target == nullptr)
                    {
                        IOManager::show_err_title();
                        IOManager::show_err_info("该商品不存在！");
                        sleep(DELAY);
                        return;
                    }
                    else if(target->get_mode() == REMOVED)
                    {
                        IOManager::show_err_title();
                        IOManager::show_err_info("该商品已下架！");
                        sleep(DELAY);
                        return;
                    }
                    //展示商品详细信息
                    DRAW_STAR_LINE(50);
                    target->show_details_info();
                    DRAW_STAR_LINE(50);
                }
            }
        }
    }
}
