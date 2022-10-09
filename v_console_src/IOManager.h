#pragma once
//包含头文件
#include"General.h"
#include"Usr.h"
#include"Merchandise.h"
#include"OrderForm.h"
#include"SqlItem.h"
#include"Recharge.h"
#include"Calculator.cpp"

//宏定义
//格式设置
#define CLEAR_SCREEN printf("\033c");
#define HIGHLIGHT "\033[1m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define CLEAR_FORMAT printf("\033[0m");
//快速打印工具
#define DRAW_DOUBLE_LINE(len) for(int i = 0; i < len; i++) {printf("="); if(i == len - 1) printf("\n"); }
#define DRAW_STAR_LINE(len) for(int i = 0; i < len; i++) { printf("*"); if(i == len - 1) printf("\n"); }
#define OUTPUT(formats, output)\
{\
    for(int i = 0; i < formats.size(); i++)\
        printf("%s", formats[i].c_str());\
    output;\
    CLEAR_FORMAT\
}

//IO控制类
class IOManager
{
private:
public:
    //获取用户选择
    static string get_choice(regex input_spec);
    //展示成功/失败信息
    static void show_err_title();                           //错误头
    static void show_err_info(const char* info);            //错误详细信息
    static void show_succ_title();                          //成功头
    static void show_succ_info(const char* info);           //成功详细信息
    static void show_prompt_info(const char* info);         //提示信息
    //格式校验
    static int check_ch_en_input(string input);             //校验指定长度：中文+大小写英文
    static int check_ch_en_num_input(string input);         //校验指定长度：中文+大小写英文+数字
    static int check_lowen_num_input(string input);         //校验指定长度：小写英文
    //管理员
    static bool admin_login();                              //管理员登陆
    static void admin_ban_usr();                            //管理员封禁用户
    static void admin_search_merchandises();                //搜索商品，当不指定当前用户时为管理员搜索
    static void admin_remove_merchandise();                 //管理员移除商品
    //用户
    //登入登出
    static Usr* usr_login();                                    //用户登陆
    static bool usr_register();                                 //用户注册
    //个人信息
    static void show_specific_usr_details_info(Usr* cur_usr);   //展示用户详细信息
    static bool modify_usr_info(Usr* cur_usr);                  //修改用户信息
    static bool usr_recharge(Usr* cur_usr);                     //用户充值
    //买家
    static void usr_search_merchandises();                      //搜索商品
    static void usr_show_merchandise_details_info();            //显示商品详细信息
    static void purchase_merchandise(Usr* cur_usr);             //购买商品
    //卖家
    static void add_merchandise(Usr* cur_usr);                  //发布商品
    static bool modify_merchandise_info(Usr* cur_usr);          //修改商品信息
    static bool usr_remove_merchandise(Usr* cur_usr);           //下架商品
    //MYSQL指令生成
    static string generate_based_expr(vector<OrderForm*>& costs, vector<OrderForm*>& incomes, vector<Recharge*>& recharges);
};