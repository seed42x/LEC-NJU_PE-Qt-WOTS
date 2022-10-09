#pragma once
#include"General.h"
#include"Usr.h"

struct MerchandiseNode;

class Merchandise
{
private:
    //全局属性
    static int mers_type_num;                       //商品种类的数量
    static MerchandiseNode* mers_lib_head;          //存储用-链表头
    static MerchandiseNode* mers_lib_tail;          //存储用-链表尾
    //对象属性
    string id_;                     //商品ID
    string name_;                   //商品名称
    double price_;                  //商品价格
    int num_;                       //商品数量
    string description_;            //商品描述
    string seller_id_;              //卖家ID
    string added_time_;             //发布时间
    MerchandiseMode state_;         //商品状态
public:
    //构造函数 & 析构函数
    Merchandise();
    Merchandise(string name, double price, int num, string descrip, string seller_id);
    Merchandise(string id, string name, double price, int num, string descrip, string seller_id, string addtime, MerchandiseMode sta);
    ~Merchandise();
    //全局方法
    //文件IO
    static void init_all_merchandises();                                                        //从文件初始化
    static void save_all_merchandises();                                                        //保存到文件
    //追加商品
    static string get_new_id();                                                                 //获取新ID
    static string get_new_added_time();                                                         //获取新时间
    static void add_merchandise(Merchandise* new_merchandise);                                  //追加商品
    //查找
    static Merchandise* find_mer_by_name(string target_name);                                   //以商品名查找商品
    static Merchandise* find_mer_by_id(string target_id);                                       //以ID查找商品
    static void search_merchandises_by_name(vector<Merchandise*>& rst, string target_name);     //查找商品
    //展示信息
    static void show_specific_usr_merchandises_info(Usr* cur_usr);                              //卖家查看发布商品
    static void admin_show_all_merchandises_info();                                             //管理员查看所有商品
    static void usr_show_all_merchandises_info();                                               //买家查看所有商品
    //其它
    static void remove_specific_usr_all_merchandises(Usr* usr);                                 //移除特定用户所有商品

    //对象方法
    //修改信息
    void update_price(double new_price) { price_ = new_price; }                                 //更新价格
    void update_description(string new_desp) { description_ = new_desp; }                       //更新描述
    void update_state(MerchandiseMode new_mode) { state_ = new_mode; }                          //更新状态
    void update_num(int new_num) { num_ = new_num; }                                            //更新数量
    //获取信息
    string get_id() const { return id_; }                                                       //获取商品ID
    string get_name() const { return name_; }                                                   //获取商品名称
    double get_price() const { return price_; }                                                 //获取商品价格
    int get_num() const { return num_; }                                                        //获取商品数量
    string get_description() const { return description_; }                                     //获取商品描述
    string get_seller_id() const { return seller_id_; }                                         //获取卖家ID
    string get_added_time() const { return added_time_; }                                       //获取商品发布时间
    MerchandiseMode get_mode() const { return state_; }                                         //获取商品当前状态
    string get_state() const { return state_ == ONSALE ? "销售中" : "\033[31m已下架\033[0m"; }   //获取商品状态（用于展示信息）
    void show_details_info() const;                                                             //展示商品详细信息
};

struct MerchandiseNode
{
    Merchandise* val;
    MerchandiseNode* next;
    MerchandiseNode() { val = nullptr; next = nullptr; }
    MerchandiseNode(Merchandise* v) { val = v; next = nullptr; }
};