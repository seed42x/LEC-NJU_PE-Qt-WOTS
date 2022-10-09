#include"IOManager.h"

/*获取用户选择*/
string IOManager::get_choice(regex input_spec)
{
    string input;
    cin >> input;
    if(regex_match(input, input_spec)) return input;
    else
    {
        show_err_title();
        show_err_info("非法输入！");
        sleep(DELAY);
        return "ERR";
    }
}

/*展示成功/失败信息*/
void IOManager::show_err_title()
{
    vector<string> format{HIGHLIGHT, RED};
    OUTPUT(format, printf("ERR!\n"));
}
void IOManager::show_err_info(const char* info)
{
    vector<string> format{RED};
    OUTPUT(format, printf("%s\n", info));
}
void IOManager::show_succ_title()
{
    vector<string> format{HIGHLIGHT, GREEN};
    OUTPUT(format, printf("Done!\n"));
}
void IOManager::show_succ_info(const char* info)
{
    vector<string> format{GREEN};
    OUTPUT(format, printf("%s\n", info));
}
void IOManager::show_prompt_info(const char* info)
{
    vector<string> format{HIGHLIGHT};
    OUTPUT(format, printf("%s", info));
}

/*格式校验*/
int IOManager::check_ch_en_input(string input)
{
    //TODO11：检查 中文 + 大小写英文长度，如果有另外的字符则直接返回-1
}
int IOManager::check_ch_en_num_input(string input)
{
    //TODO11：检查 中文 + 大小写英文 + 数字长度，如果有另外的字符则直接返回-1

}
int IOManager::check_lowen_num_input(string input)
{
    //TODO11：检查 小写字母 + 数字长度，如果有另外的字符则直接返回-1

}

/*管理员*/
bool IOManager::admin_login()
{
    //TODO10：实现管理员登录

}
void IOManager::admin_ban_usr()
{
    //TODO16：管理员功能-封禁用户

}
void IOManager::admin_search_merchandises()
{
    //TODO16：管理员功能-搜索商品

}
void IOManager::admin_remove_merchandise()
{
    //TODO16：管理员功能-下架商品

}

/*用户*/
//登入登出
Usr* IOManager::usr_login()
{
    //TODO12：实现用户登录函数

}
bool IOManager::usr_register()
{
    //TODO11：实现用户注册函数

}
//个人信息
void IOManager::show_specific_usr_details_info(Usr* cur_usr)
{
    //TODO15：用户-查看个人信息
    
}
bool IOManager::modify_usr_info(Usr* cur_usr)
{
    //TODO15：用户-修改个人信息

}
bool IOManager::usr_recharge(Usr* cur_usr)
{
    //TODO15：用户-充值

}
//买家
void IOManager::usr_search_merchandises()
{
    //TODO14：买家功能-搜索商品
}
void IOManager::purchase_merchandise(Usr* cur_usr)
{
    //TODO14：买家功能-购买商品

}
//卖家
void IOManager::add_merchandise(Usr* cur_usr)
{
    //TODO13：实现卖家发布商品功能

}
bool IOManager::modify_merchandise_info(Usr* cur_usr)
{
    //TODO13：实现卖家修改商品信息

#ifndef MYSQL
    //TODO13：实现卖家修改商品信息-更新对应商品信息

}
bool IOManager::usr_remove_merchandise(Usr* cur_usr)
{
    //TODO13：实现卖家下架商品

}

void IOManager::usr_show_merchandise_details_info()
{
    //TODO14:买家功能-查看商品详细信息

}