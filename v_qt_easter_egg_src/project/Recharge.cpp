#include"Recharge.h"

//全局变量初始化
RechargeNode* Recharge::recharge_recs_head = new RechargeNode();
RechargeNode* Recharge::recharge_recs_tail = Recharge::recharge_recs_head;

//构造 & 析构函数
Recharge::Recharge() : usr_id_(""), money_(0) {}
Recharge::Recharge(string id, double m) : usr_id_(id), money_(m) {}
Recharge::~Recharge() {}

//全局函数
//文件IO
void Recharge::recharge_recs_init()
{
    ifstream infile;
    infile.open("./source/recharge_recs.txt");
    if(infile.is_open() == false) return;
    //利用表头进行校验
    string hid, hm;
    infile >> hid >> hm;
    if(hid != "UsrID" || hm != "Money") return;
    //读取数据
    while(!infile.eof())
    {
        string buf_id, buf_money;
        infile >> buf_id;
        infile >> buf_money;
        Recharge* p = new Recharge(buf_id, atof(buf_money.c_str()));
        Recharge::add_recharge_record(p);
    }
    infile.close();
    return;
}
void Recharge::recharge_recs_save()
{
    ofstream outfile;
    //检查文件夹路径是否存在，若不存在则进行创建
    if(access("./source/", 0) != 0) mkdir("./source/");
    outfile.open("./source/recharge_recs.txt");
    //追加表头
    outfile << "UsrID" << "\t\t\t";
    outfile << "Money";
    //存入数据
    RechargeNode* cursor = Recharge::recharge_recs_head->next;
    while(cursor != nullptr)
    {
        outfile << endl;
        outfile << cursor->val->usr_id_ << "\t\t\t";
        outfile << cursor->val->money_;
        cursor = cursor->next;
    }
    outfile.close();
    return;
}
//追加 & 查找
void Recharge::add_recharge_record(Recharge* new_rec)
{
    RechargeNode* p = new RechargeNode(new_rec);
    Recharge::recharge_recs_tail->next = p;
    Recharge::recharge_recs_tail = p;
    return;
}
void Recharge::find_recs_of_specific_usr(vector<Recharge*>& rst, string target_id)
{
    RechargeNode* cursor = Recharge::recharge_recs_head->next;
    while(cursor != nullptr)
    {
        if(cursor->val->usr_id_ == target_id)
        {
            rst.push_back(cursor->val);
        }
        cursor = cursor->next;
    }
    return;
}
