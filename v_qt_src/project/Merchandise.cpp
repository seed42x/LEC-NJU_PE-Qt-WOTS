#include "Merchandise.h"

//全局变量初始化
int Merchandise::mers_type_num = 0;
MerchandiseNode* Merchandise::mers_lib_head = new MerchandiseNode();
MerchandiseNode* Merchandise::mers_lib_tail = Merchandise::mers_lib_head;

//构造函数 & 析构函数
Merchandise::Merchandise() :
id_(""), name_(""), price_(0), num_(0), description_(""), seller_id_(""), added_time_(""), state_(ONSALE) {}
Merchandise::Merchandise
(string id, string name, double price, int num, string descrip, string seller_id, string addtime, MerchandiseMode sta) :
id_(id), name_(name), price_(price), num_(num), description_(descrip), seller_id_(seller_id), added_time_(addtime), state_(sta) {}
Merchandise::Merchandise(string name, double price, int num, string descrip, string seller_id) :
name_(name), price_(price), num_(num), description_(descrip), seller_id_(seller_id)
{
    id_ = Merchandise::get_new_id();
    added_time_ = Merchandise::get_new_added_time();
    state_ = ONSALE;
}
Merchandise::~Merchandise()
{

}

//全局方法
//文件IO
void Merchandise::init_all_merchandises()
{
    ifstream infile;
    infile.open("./source/merchandises.txt");
    if(infile.is_open() == false) return;
    //利用表头进行校验
    string hid, hname, hunitp, hnum, hdesc, hsellerid, haddt, hsta;
    infile >> hid >> hname >> hunitp >> hnum >> hdesc >> hsellerid >> haddt >> hsta;
    if(hid != "ID" || hname != "Name" || hunitp != "UnitPrice" || hnum != "Num" || hdesc != "Desc" ||
       hsellerid != "SellerID" || haddt != "AddedTime" || hsta != "State")
        return;
    //读入数据
    string buf;
    while(!infile.eof())
    {
        string id_buf, name_buf, desp_buf, seller_id_buf, addedtime_buf;
        double price_buf;
        int num_buf;
        MerchandiseMode state_buf;
        infile >> id_buf;
        infile >> name_buf;
        infile >> price_buf;
        infile >> num_buf;
        infile >> desp_buf;
        infile >> seller_id_buf;
        infile >> addedtime_buf;
        infile >> buf;
        state_buf = (buf == "下架" ? REMOVED : ONSALE);
        Merchandise* p = new Merchandise(id_buf, name_buf, price_buf, num_buf, desp_buf, seller_id_buf, addedtime_buf, state_buf);
        Merchandise::add_merchandise(p);
    }
}
void Merchandise::save_all_merchandises()
{
    ofstream outfile;
    //检查文件夹路径是否存在，若不存在则进行创建
    if(access("./source/", 0) != 0) mkdir("./source/");
    outfile.open("./source/merchandises.txt");
    //追加表头
    outfile << "ID" << "\t\t\t";
    outfile << "Name" << "\t\t\t";
    outfile << "UnitPrice" << "\t\t\t";
    outfile << "Num" << "\t\t\t";
    outfile << "Desc" << "\t\t\t";
    outfile << "SellerID" << "\t\t\t";
    outfile << "AddedTime" << "\t\t\t";
    outfile << "State";
    //存入数据
    MerchandiseNode* cursor = Merchandise::mers_lib_head->next;
    while(cursor != nullptr)
    {
        outfile << endl;
        outfile << cursor->val->id_ << "\t\t\t";
        outfile << cursor->val->name_ << "\t\t\t";
        outfile << cursor->val->price_ << "\t\t\t";
        outfile << cursor->val->num_ << "\t\t\t";
        outfile << cursor->val->description_ << "\t\t\t";
        outfile << cursor->val->seller_id_ << "\t\t\t";
        outfile << cursor->val->added_time_ << "\t\t\t";
        outfile << (cursor->val->state_ == REMOVED ? string("下架") : string("销售中"));
        cursor = cursor->next;
    }
    outfile.close();
    return;
}
//追加商品
string Merchandise::get_new_id()
{
    string rst("M");
    string num = to_string(Merchandise::mers_type_num);
    for(int i = 0; i < 3 - num.size(); i++) rst += "0";
    rst += num;
    return rst;
}
string Merchandise::get_new_added_time()
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
    return rst;
}
void Merchandise::add_merchandise(Merchandise* new_merchandise)
{
    Merchandise::mers_type_num++;
    MerchandiseNode* p = new MerchandiseNode(new_merchandise);
    Merchandise::mers_lib_tail->next = p;
    Merchandise::mers_lib_tail = Merchandise::mers_lib_tail->next;
    return;
}
//查找
Merchandise* Merchandise::find_mer_by_name(string target_name)
{
    MerchandiseNode* cursor = Merchandise::mers_lib_head->next;
    while(cursor != nullptr)
    {
        if(cursor->val->name_ == target_name) return cursor->val;
        cursor = cursor->next;
    }
    return nullptr;
}
Merchandise* Merchandise::find_mer_by_id(string target_id)
{
    MerchandiseNode* cursor = Merchandise::mers_lib_head->next;
    while(cursor != nullptr)
    {
        if(cursor->val->id_ == target_id) return cursor->val;
        cursor = cursor->next;
    }
    return nullptr;
}
void Merchandise::search_merchandises_by_name(vector<Merchandise*>& rst, string target_name)
{
    MerchandiseNode* cursor = Merchandise::mers_lib_head->next;
    while(cursor != nullptr)
    {
        if(cursor->val->name_ == target_name) rst.push_back(cursor->val);
        cursor = cursor->next;
    }
    return;
}

//其它
void Merchandise::remove_specific_usr_all_merchandises(Usr* usr)
{
    MerchandiseNode* cursor = Merchandise::mers_lib_head->next;
    while(cursor != nullptr)
    {
        if(cursor->val->seller_id_ == usr->get_id()) cursor->val->update_state(REMOVED);
        cursor = cursor->next;
    }
    return;
}

//管理员获取所有商品信息
void Merchandise::admin_get_all_mers_info(vector<vector<string>>& rst)
{
    MerchandiseNode* cursor = Merchandise::mers_lib_head->next;
    vector<string> buf;
    while(cursor != nullptr)
    {
        buf.push_back(cursor->val->get_id());
        buf.push_back(cursor->val->get_name());
        string price_buf = to_string(cursor->val->get_price());
        if(price_buf.find('.') != string::npos) price_buf = price_buf.substr(0, price_buf.find('.')+2);
        buf.push_back(price_buf);
        buf.push_back(to_string(cursor->val->get_num()));
        buf.push_back(cursor->val->get_added_time());
        buf.push_back(cursor->val->get_seller_id());
        buf.push_back(cursor->val->get_state());
        rst.push_back(buf);
        buf.clear();
        cursor = cursor->next;
    }
    return;
}

void Merchandise::admin_get_all_onsale_mers_info(vector<vector<string> > &rst)
{
    MerchandiseNode* cursor = Merchandise::mers_lib_head->next;
    vector<string> buf;
    while(cursor != nullptr)
    {
        if(cursor->val->get_mode() == ONSALE)
        {
            buf.push_back(cursor->val->get_id());
            buf.push_back(cursor->val->get_name());
            string price_buf = to_string(cursor->val->get_price());
            if(price_buf.find('.') != string::npos) price_buf = price_buf.substr(0, price_buf.find('.')+2);
            buf.push_back(price_buf);
            buf.push_back(to_string(cursor->val->get_num()));
            buf.push_back(cursor->val->get_added_time());
            buf.push_back(cursor->val->get_seller_id());
            buf.push_back(cursor->val->get_state());
            rst.push_back(buf);
            buf.clear();
        }
        cursor = cursor->next;
    }
    return;
}

void Merchandise::admin_select_mers_info(string target_name, vector<vector<string>>& rst)
{
    MerchandiseNode* cursor = Merchandise::mers_lib_head->next;
    vector<string> buf;
    while(cursor != nullptr)
    {
        if(cursor->val->get_name() == target_name)
        {
            buf.push_back(cursor->val->get_id());
            buf.push_back(cursor->val->get_name());
            string price_buf = to_string(cursor->val->get_price());
            if(price_buf.find('.') != string::npos) price_buf = price_buf.substr(0, price_buf.find('.')+2);
            buf.push_back(price_buf);
            buf.push_back(to_string(cursor->val->get_num()));
            buf.push_back(cursor->val->get_added_time());
            buf.push_back(cursor->val->get_seller_id());
            buf.push_back(cursor->val->get_state());
            rst.push_back(buf);
            buf.clear();
        }
        cursor = cursor->next;
    }
    return;
}

void Merchandise::seller_get_all_mers_info(vector<vector<string>>& rst, string seller_id)
{
    MerchandiseNode* cursor = Merchandise::mers_lib_head->next;
    vector<string> buf;
    while(cursor != nullptr)
    {
        if(cursor->val->get_seller_id() == seller_id)
        {
            buf.push_back(cursor->val->get_id());
            buf.push_back(cursor->val->get_name());
            string price_buf = to_string(cursor->val->get_price());
            if(price_buf.find('.') != string::npos) price_buf = price_buf.substr(0, price_buf.find('.')+2);
            buf.push_back(price_buf);
            buf.push_back(to_string(cursor->val->get_num()));
            buf.push_back(cursor->val->get_added_time());
            buf.push_back(cursor->val->get_state());
            rst.push_back(buf);
            buf.clear();
        }
        cursor = cursor->next;
    }
    return;
}

void Merchandise::buyer_get_all_mers_info(vector<vector<string>> &rst, string buyer_id)
{
    MerchandiseNode* cursor = Merchandise::mers_lib_head->next;
    vector<string> buf;
    while(cursor != nullptr)
    {
        if(cursor->val->get_mode() != REMOVED)
        {
            buf.push_back(cursor->val->get_id());
            buf.push_back(cursor->val->get_name());
            string price_buf = to_string(cursor->val->get_price());
            if(price_buf.find('.') != string::npos) price_buf = price_buf.substr(0, price_buf.find('.')+2);
            buf.push_back(price_buf);
            buf.push_back(to_string(cursor->val->get_num()));
            buf.push_back(cursor->val->get_added_time());
            buf.push_back(cursor->val->get_seller_id());
            rst.push_back(buf);
            buf.clear();
        }
        cursor = cursor->next;
    }
    return;
}

void Merchandise::seller_get_all_onsale_mers_info(vector<vector<string> > &rst, string seller_id)
{
    MerchandiseNode* cursor = Merchandise::mers_lib_head->next;
    vector<string> buf;
    while(cursor != nullptr)
    {
        if(cursor->val->get_seller_id() == seller_id && cursor->val->get_mode() == ONSALE)
        {
            buf.push_back(cursor->val->get_id());
            buf.push_back(cursor->val->get_name());
            string price_buf = to_string(cursor->val->get_price());
            if(price_buf.find('.') != string::npos) price_buf = price_buf.substr(0, price_buf.find('.')+2);
            buf.push_back(price_buf);
            buf.push_back(to_string(cursor->val->get_num()));
            buf.push_back(cursor->val->get_added_time());
            buf.push_back(cursor->val->get_state());
            rst.push_back(buf);
            buf.clear();
        }
        cursor = cursor->next;
    }
    return;
}

void Merchandise::buyer_select_mers_info(string target_name, vector<vector<string>> &rst)
{
    MerchandiseNode* cursor = Merchandise::mers_lib_head->next;
    vector<string> buf;
    while(cursor != nullptr)
    {
        if(cursor->val->get_mode() != REMOVED && cursor->val->get_name() == target_name)
        {
            buf.push_back(cursor->val->get_id());
            buf.push_back(cursor->val->get_name());
            string price_buf = to_string(cursor->val->get_price());
            if(price_buf.find('.') != string::npos) price_buf = price_buf.substr(0, price_buf.find('.')+2);
            buf.push_back(price_buf);
            buf.push_back(to_string(cursor->val->get_num()));
            buf.push_back(cursor->val->get_added_time());
            buf.push_back(cursor->val->get_seller_id());
            rst.push_back(buf);
            buf.clear();
        }
        cursor = cursor->next;
    }
    return;
}
