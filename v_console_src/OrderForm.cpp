#include"OrderForm.h"

//全局属性初始化
int OrderForm::orderform_num = 0;
OrderFormNode* OrderForm::orderforms_lib_head = new OrderFormNode();
OrderFormNode* OrderForm::orderforms_lib_tail = OrderForm::orderforms_lib_head;

//构造 & 析构函数
OrderForm::OrderForm() :
id_(""), mer_id_(""), seller_id_(""), buyer_id_(""), uint_price_(0), mers_num_(0), tran_time_("") {}
OrderForm::OrderForm(string id, string mer_id, string seller_id, string buyer_id, double uintp, int mer_num, string trans_time) :
id_(id), mer_id_(mer_id), seller_id_(seller_id), buyer_id_(buyer_id), uint_price_(uintp), mers_num_(mer_num), tran_time_(trans_time) {}
OrderForm::OrderForm(string mer_id, string seller_id, string buyer_id, double uintp, int mers_num) :
mer_id_(mer_id), seller_id_(seller_id_), buyer_id_(buyer_id), uint_price_(uintp), mers_num_(mers_num)
{
    id_ = get_new_id();
    tran_time_ = get_new_trantime();
}
OrderForm::OrderForm(Merchandise* mer, Usr* usr, int num)
{
    id_ = get_new_id();
    tran_time_ = get_new_trantime();
    mer_id_ = mer->get_id();
    seller_id_ = mer->get_seller_id();
    buyer_id_ = usr->get_id();
    uint_price_ = mer->get_price();
    mers_num_ = num;
}
OrderForm::~OrderForm() {}

//全局函数
//文件IO
void OrderForm::init_all_orderforms()
{
    ifstream infile;
    infile.open("./source/orderforms.txt");
    if(infile.is_open() == false) return;
    //利用表头进行校验
    string hid, hmerid, hsid, hbid, hunitp, hnum, htime;
    infile >> hid >> hmerid >> hsid >> hbid >> hunitp >> hnum >> htime;
    if(hid != "ID" || hmerid != "MerID" || hsid != "SellerID" || hbid != "BuyerID" || hunitp != "UnitPrice" || hnum != "Num" || htime != "Time")
        return;
    //读入数据
    while(!infile.eof())
    {
        string id_buf, mer_id_buf, seller_id_buf, buyer_id_buf, trantime_buf;
        double uintp_buf;
        int mers_num_buf;
        infile >> id_buf;
        infile >> mer_id_buf;
        infile >> seller_id_buf;
        infile >> buyer_id_buf;
        infile >> uintp_buf;
        infile >> mers_num_buf;
        infile >> trantime_buf;
        OrderForm* p = new OrderForm(id_buf, mer_id_buf, seller_id_buf, buyer_id_buf, uintp_buf, mers_num_buf, trantime_buf);
        OrderForm::add_orderform(p);
    }
    infile.close();
    return;
}
void OrderForm::save_all_orderforms()
{
    ofstream outfile;
    //检查文件夹路径是否存在，若不存在则进行创建
    if(access("./source/", 0) != 0) mkdir("./source/", S_IRWXU);
    outfile.open("./source/orderforms.txt");
    //追加表头
    outfile << "ID" << "\t\t\t";
    outfile << "MerID" << "\t\t\t";
    outfile << "SellerID" << "\t\t\t";
    outfile << "BuyerID" << "\t\t\t";
    outfile << "UnitPrice" << "\t\t\t";
    outfile << "Num" << "\t\t\t";
    outfile << "Time";
    //存入数据
    OrderFormNode* cursor = OrderForm::orderforms_lib_head->next;
    while(cursor != nullptr)
    {
        outfile << endl;
        outfile << cursor->val->id_ << "\t\t\t";
        outfile << cursor->val->mer_id_ << "\t\t\t";
        outfile << cursor->val->seller_id_ << "\t\t\t";
        outfile << cursor->val->buyer_id_ << "\t\t\t";
        outfile << cursor->val->uint_price_ << "\t\t\t";
        outfile << cursor->val->mers_num_ << "\t\t\t";
        outfile << cursor->val->tran_time_;
        cursor = cursor->next;
    }
    outfile.close();
    return;
}
//追加商品
string OrderForm::get_new_id()
{
    string rst("T");
    string num = to_string(OrderForm::orderform_num);
    for(int i = 0; i < 3 - num.size(); i++) rst += "0";
    rst += num;
    return rst;
}
string OrderForm::get_new_trantime()
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
void OrderForm::add_orderform(OrderForm* new_orderform)
{
    OrderForm::orderform_num++;
    OrderFormNode* p = new OrderFormNode(new_orderform);
    OrderForm::orderforms_lib_tail->next = p;
    OrderForm::orderforms_lib_tail = OrderForm::orderforms_lib_tail->next;
    return;
}
//查找
void OrderForm::find_specific_buyer_orderforms(vector<OrderForm*>& rst, string target_id)
{
    OrderFormNode* cursor = OrderForm::orderforms_lib_head->next;
    while(cursor != nullptr)
    {
        if(cursor->val->buyer_id_ == target_id) rst.push_back(cursor->val);
        cursor = cursor->next;
    }
    return;
}
void OrderForm::find_specific_seller_orderforms(vector<OrderForm*>& rst, string target_id)
{
    OrderFormNode* cursor = OrderForm::orderforms_lib_head->next;
    while(cursor != nullptr)
    {
        if(cursor->val->seller_id_ == target_id) rst.push_back(cursor->val);
        cursor = cursor->next;
    }
    return;
}
//展示信息
void OrderForm::show_specific_buyer_orderform_info(Usr* cur_usr)
{
    OrderFormNode* cursor = OrderForm::orderforms_lib_head->next;
    while(cursor != nullptr)
    {
        if(cursor->val->buyer_id_ == cur_usr->get_id())
        {
            printf(
                "%-20s\t%-20s\t%-20.1lf\t%-20d\t%-20s\t%-20s\n",
                cursor->val->id_.c_str(),
                cursor->val->mer_id_.c_str(),
                cursor->val->uint_price_,
                cursor->val->mers_num_,
                cursor->val->tran_time_.c_str(),
                cursor->val->seller_id_.c_str()
            );
        }
        cursor = cursor->next;
    }
    return;
}
void OrderForm::show_specific_seller_orderform_info(Usr* cur_usr)
{
    OrderFormNode* cursor = OrderForm::orderforms_lib_head->next;
    while(cursor != nullptr)
    {
        if(cursor->val->seller_id_ == cur_usr->get_id())
        {
            printf(
                "%-20s\t%-20s\t%-20.1lf\t%-20d\t%-20s\t%-20s\n",
                cursor->val->id_.c_str(),
                cursor->val->mer_id_.c_str(),
                cursor->val->uint_price_,
                cursor->val->mers_num_,
                cursor->val->tran_time_.c_str(),
                cursor->val->buyer_id_.c_str()
            );
        }
        cursor = cursor->next;
    }
    return;
}
void OrderForm::show_all_usrs_orderform_info()
{
    OrderFormNode* cursor = OrderForm::orderforms_lib_head->next;
    while(cursor != nullptr)
    {
        printf(
            "%-20s\t%-20s\t%-20.1lf\t%-20d\t%-20s\t%-20s\t%-20s\n",
            cursor->val->id_.c_str(),
            cursor->val->mer_id_.c_str(),
            cursor->val->uint_price_,
            cursor->val->mers_num_,
            cursor->val->tran_time_.c_str(),
            cursor->val->seller_id_.c_str(),
            cursor->val->buyer_id_.c_str()
        );
        cursor = cursor->next;
    }
    return;
}
void OrderForm::show_details_info() const
{
    printf("\033[1m订单ID：\033[0m\t\t%s\n", id_.c_str());
    printf("\033[1m商品ID：\033[0m\t\t%s\n", mer_id_.c_str());
    printf("\033[1m卖家ID：\033[0m\t\t%s\n", seller_id_.c_str());
    printf("\033[1m买家ID：\033[0m\t\t%s\n", buyer_id_.c_str());
    printf("\033[1m商品单价：\033[0m\t\t%.1lf\n", uint_price_);
    printf("\033[1m购买数量：\033[0m\t\t%d\n", mers_num_);
    printf("\033[1m商品总价：\033[0m\t\t%.1lf\n", mers_num_ * uint_price_);
    printf("\033[1m交易时间：\033[0m\t\t%s\n", tran_time_.c_str());
    return;
}
