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
int IOManager::check_ch_en_input(string input)      //检查 中文 + 大小写英文 长度
{
    int all_num = 0, ch_num = 0, en_num = 0;
    for(int i = 0; i < input.size(); i++)
    {
        if((input[i] >= 'a' && input[i] <= 'z') || (input[i] >= 'A' && input[i] <= 'Z')) en_num++;
        else
            if((input[i] > 0 && input[i] < 'A' || (input[i] > 'Z' && input[i] < 'a') || (input[i] > 'z')))
                return -1;
    }
    ch_num = (input.size() - en_num) / 3;
    all_num = ch_num + en_num;
    return all_num;
}
int IOManager::check_ch_en_num_input(string input)      //检查 中文 + 大小写英文 + 数字 长度
{
    int all_num = 0, ch_num = 0, en_num = 0, num_num = 0;
    for(int i = 0; i < input.size(); i++)
    {
        if((input[i] >= 'a' && input[i] <= 'z') || (input[i] >= 'A' && input[i] <= 'Z')) en_num++;
        else if(input[i] >= '0' && input[i] <= '9') num_num++;
        else
            if((input[i] > 0 && input[i] < 'A' || (input[i] > 'Z' && input[i] < 'a') || (input[i] > 'z')))
                return -1;
    }
    ch_num = (input.size() - en_num - num_num) / 3;
    all_num = ch_num + en_num + num_num;
    return all_num;
}
int IOManager::check_lowen_num_input(string input)      //检查 小写字母 + 数字 长度
{
    int cnt = 0;
    int len = input.size();
    for(int i = 0; i < len; i++)
    {
        if(!(input[i] >= 'a' && input[i] <= 'z' || input[i] >= '0' && input[i] <= '9'))
            return -1;
    }
    return input.size();
}

/*管理员*/
bool IOManager::admin_login()
{
    show_prompt_info("请输入管理员姓名：");
    string login_name;
    cin >> login_name;
    if(login_name != ADMIN_NAME)
    {
        show_err_title();
        show_err_info("管理员姓名错误！");
        sleep(DELAY);
        return false;
    }
    show_prompt_info("请输入登陆密码：");
    string login_passwd;
    login_passwd = getpass("");
    if(login_passwd != ADMIN_PASSWD)
    {
        show_err_title();
        show_err_info("管理员密码错误！");
        sleep(DELAY);
        return false;
    }
    show_succ_title();
    show_succ_info("登陆成功！");
    sleep(DELAY);
    return true;
}
void IOManager::admin_ban_usr()
{
    //获取待封禁用户的ID
    string target_id;
    show_prompt_info("请输入要封禁用户的ID：");
    cin >> target_id;
    Usr* target = Usr::find_usr_by_id(target_id);
    //查询该用户是否存在
    if(target == nullptr)
    {
        show_err_title();
        show_err_info("该用户不存在！");
        sleep(DELAY);
        return;
    }
    //确认是否要封禁该用户
    show_prompt_info("确认要封禁该用户吗？\n");
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
    target->show_simple_info();
    DRAW_STAR_LINE(180);
    show_prompt_info("请选择(y/other for no):");
    string choice;
    cin >> choice;
    //显示操作结果
    show_succ_title();
    if(choice == "y")
    {
#ifndef MYSQL
        Usr::ban_usr(target);
#endif
#ifdef MYSQL
        string admin_ban_usr_order = SqlItem::generate_update_order(
            MYSQL_USR_LIST_NAME,
            vector<pair<string, string>>{pair<string, string>("State", "封禁")},
            vector<pair<string, string>>{pair<string, string>("UsrID", target->get_id())}
        );
        SqlItem::dealwith_update_order(admin_ban_usr_order);
        string remove_all_mers_order = SqlItem::generate_update_order(
            MYSQL_MER_LIST_NAME,
            vector<pair<string, string>>{pair<string, string>("State", "已下架")},
            vector<pair<string, string>>{pair<string, string>("SellerID", target->get_id())}
        );
        SqlItem::dealwith_update_order(remove_all_mers_order);
        SqlItem::save_all_items();
#endif
        Merchandise::remove_specific_usr_all_merchandises(target);
        show_succ_info("成功封禁该用户！");
        Merchandise::save_all_merchandises();
        Usr::save_all_usrs();
    }
    else show_succ_info("已取消操作！");
    sleep(DELAY);
}
void IOManager::admin_search_merchandises()
{
    //获取待搜索目标的名称
    show_prompt_info("请输入要搜索的商品名称：");
    string target_name;
    cin >> target_name;
#ifndef MYSQL
    //进行搜索
    vector<Merchandise*> rst;
    Merchandise::search_merchandises_by_name(rst, target_name);
    //未找到目标
    if(rst.size() == 0)
    {
        show_prompt_info("未找到目标商品...\n");
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
#endif
#ifdef MYSQL
    string admin_search_mer_order = SqlItem::generate_select_order(
        MYSQL_MER_LIST_NAME, "*", vector<pair<string, string>>{pair<string, string>("MerName", target_name)}
    );
    SqlItem::change_admin_active();
    SqlItem::dealwith_select_order(admin_search_mer_order);
    SqlItem::change_admin_inactive();
    SqlItem::save_all_items();
#endif
    //利用输入等待进行退出
    show_prompt_info("按下回车键退出...");
    cin.clear();
    getpass("");
    return;
}
void IOManager::admin_remove_merchandise()
{
    show_prompt_info("请输入要下架商品的ID：");
    string target_id;
    cin >> target_id;
    Merchandise* target = Merchandise::find_mer_by_id(target_id);
    //查询该商品是否存在
    if(target == nullptr)
    {
        show_err_title();
        show_err_info("该商品不存在！");
        return;
    }
    //检查该商品是否已经下架
    else if(target->get_mode() == REMOVED)
    {
        show_err_title();
        show_err_info("该商品已下架！");
        return;
    }
    //显示该商品信息 & 进行下架确认
    show_prompt_info("确认要下架该商品吗？\n");
    DRAW_STAR_LINE(50);
    target->show_details_info();
    DRAW_STAR_LINE(50);
    show_prompt_info("请选择(y/other for no)：");
    string choice;
    cin >> choice;
    if(choice != "y")
    {
        show_succ_title();
        show_succ_info("已成功取消修改操作！");
    }
    else
    {
#ifndef MYSQL
        target->update_state(REMOVED);
#endif
#ifdef MYSQL
        string admin_ban_mer_order = SqlItem::generate_update_order(
            MYSQL_MER_LIST_NAME,
            vector<pair<string, string>>{pair<string, string>("State", "已下架")},
            vector<pair<string, string>>{pair<string, string>("MerID", target->get_id())}
        );
        SqlItem::dealwith_update_order(admin_ban_mer_order);
#endif
        Merchandise::save_all_merchandises();
        show_succ_title();
        show_succ_info("该商品成功下架！");
    }
    return;
}

/*用户*/
//登入登出
Usr* IOManager::usr_login()
{
    //获取用户名
    show_prompt_info("请输入用户名：");
    string login_name;
    cin >> login_name;
    //检查用户名是否符合规范
    int name_check = check_ch_en_input(login_name);
    if(name_check == -1 || name_check > USR_NAME_MAXLEN)
    {
        show_err_title();
        show_err_info("用户名需由不超过十个的字母或中文字符组成！");
        sleep(DELAY);
        return nullptr;
    }
    else if(name_check <= 0)
    {
        show_err_title();
        show_err_info("用户名不可为空！");
        sleep(DELAY);
        return nullptr;
    }
    //查找用户是否存在
    Usr* target = Usr::find_usr_by_name(login_name);
    if(target == nullptr)
    {
        show_err_title();
        show_err_info("该用户不存在！");
        sleep(DELAY);
        return nullptr;
    }
    //检验该用户是否被封禁
    else if(target->get_active() == false)
    {
        show_err_title();
        show_err_info("该用户已被封禁，禁止登陆！");
        sleep(DELAY);
        return nullptr;
    }
    //获取密码
    show_prompt_info("请输入密码：");
    string login_passwd;
    login_passwd = getpass("");
    //检查密码是否正确
    if(target->get_passwd() != login_passwd)
    {
        show_err_title();
        show_err_info("密码错误！");
        sleep(DELAY);
        return nullptr;
    }
    //登陆成功！
    show_succ_title();
    show_succ_info("登陆成功！");
    sleep(DELAY);
    return target;
}
bool IOManager::usr_register()
{
    //获取用户名
    show_prompt_info("请输入用户名：");
    string regis_name;
    cin >> regis_name;
    //检查用户名是否符合规范要求
    int name_len = check_ch_en_input(regis_name);
    if(name_len == -1 || name_len > USR_NAME_MAXLEN)
    {
        show_err_title();
        show_err_info("用户名需由不超过10个的字母或中文字符组成！");
        sleep(DELAY);
        return false;
    }
    //检查用户名是否为空
    else if(name_len <= 0)
    {
        show_err_title();
        show_err_info("用户名不可为空！");
        sleep(DELAY);
        return false;
    }
    //检查用户名是否已被注册
    if(Usr::find_usr_by_name(regis_name) != nullptr || regis_name == ADMIN_NAME)
    {
        show_err_title();
        if(regis_name == ADMIN_NAME) show_err_info("非法注册！");
        else show_err_info("该用户名已被注册！");
        sleep(DELAY);
        return false;
    }

    //获取密码
    show_prompt_info("请输入密码：");
    string regis_passwd;
    regis_passwd = getpass("");
    //检查密码是否符合规范
    int passwd_len = check_lowen_num_input(regis_passwd);
    if(passwd_len == -1 || passwd_len > USR_PASSWD_MAXLEN)
    {
        show_err_title();
        show_err_info("密码应不超过20个字符，且仅由小写字母和数字组成！");
        sleep(DELAY);
        return false;
    }
    //检查密码是否为空
    else if(passwd_len <= 0)
    {
        show_err_title();
        show_err_info("密码不应当为空！");
        sleep(DELAY);
        return false;
    }

    //将新用户添加到用户列表中
#ifndef MYSQL
    Usr* p = new Usr(regis_name, regis_passwd);
    Usr::add_usr(p);
#endif
#ifdef MYSQL
    string usr_register_order = SqlItem::generate_insert_order(MYSQL_USR_LIST_NAME, vector<string>{regis_name, regis_passwd});
    SqlItem::dealwith_insert_order(usr_register_order);
#endif
    show_succ_title();
    show_succ_info("注册成功！");
    sleep(DELAY);
    return true;
}
//个人信息
void IOManager::show_specific_usr_details_info(Usr* cur_usr)
{
    printf("\033[1m用户ID：\033[0m\t\t%s\n", cur_usr->get_id().c_str());
    printf("\033[1m用户名：\033[0m\t\t%s\n", cur_usr->get_name().c_str());
    printf("\033[1m联系方式：\033[0m\t%s\n", cur_usr->get_p_num().c_str());
    printf("\033[1m地址：\033[0m\t\t%s\n", cur_usr->get_addr().c_str());
#ifndef CALCULATOR
    printf("\033[1m余额：\033[0m\t\t%.1lf\n", cur_usr->get_balance());
#endif
#ifdef CALCULATOR
    vector<OrderForm*> costs;
    vector<OrderForm*> incomes;
    vector<Recharge*> recharges;
    OrderForm::find_specific_buyer_orderforms(costs, cur_usr->get_id());
    OrderForm::find_specific_seller_orderforms(incomes, cur_usr->get_id());
    Recharge::find_recs_of_specific_usr(recharges, cur_usr->get_id());
    string base_expr = IOManager::generate_based_expr(costs, incomes, recharges);
    string simple_expr = Calculator::simplify_expr(base_expr);
    bool success = true;
    string err_info = "";
    double rst = Calculator::expr(success, err_info, simple_expr);
    assert(cur_usr->get_balance() == rst);
    //cout << rst << " " << cur_usr->get_balance() << endl;
    printf("\033[1m余额：\033[0m\t\t%.1lf\n", rst);
    cout << "初始表达式：" << base_expr << endl;
    cout << "简化表达式：" << simple_expr << endl;
#endif
    return;
}
bool IOManager::modify_usr_info(Usr* cur_usr)
{
    show_prompt_info("请选择修改的属性(1.用户名 2.联系方式 3.地址)：");
    string choice;
    cin >> choice;
    if(!regex_match(choice, regex("[1-3]{1}")))
    {
        show_err_title();
        show_err_info("非法输入！");
        return false;
    }
    if(choice == "1")               //1.修改用户名
    {
        //获取目标修改的用户名
        show_prompt_info("请输入修改后的用户名：");
        string new_name;
        cin >> new_name;
        //检查用户名是否符合规范
        int name_len = check_ch_en_input(new_name);
        if(name_len == -1 || name_len > USR_NAME_MAXLEN)
        {
            show_err_title();
            show_err_info("用户名需由不超过十个的字母或中文字符组成！");
            return false;
        }
        //检查用户名是否为空
        else if(name_len <= 0)
        {
            show_err_title();
            show_err_info("用户名不可为空！");
            return false;
        }
        //检查用户名是否已被使用
        if(Usr::find_usr_by_name(new_name) != nullptr || new_name == ADMIN_NAME)
        {
            show_err_title();
            if(new_name == ADMIN_NAME) show_err_info("非法注册！");
            else show_err_info("该用户名已被使用！");
            return false;
        }
        //检查无误，修改用户名
        cur_usr->update_name(new_name);
        show_succ_title();
        show_succ_info("成功修改用户名！");
        return true;
    }
    else if(choice == "2")          //2.修改联系方式
    {
        show_prompt_info("请输入修改后的联系方式：");
        string new_pnum;
        cin >> new_pnum;
        //检查联系方式是否符合规范
        int pnum_len = 0;
        for(int i = 0;  i < new_pnum.size(); i++)
        {
            if(!(new_pnum[i] >= '0' && new_pnum[i] <= '9'))
            {
                pnum_len = -1;
                break;
            }
            else pnum_len++;
        }
        if(pnum_len == -1 || pnum_len > USR_PNUM_MAXLEN)
        {
            show_err_title();
            show_err_info("联系方式需由不超过二十个纯数字组成！");
            return false;
        }
        //检查无误，修改用户联系方式
        cur_usr->update_phone_number(new_pnum);
        show_succ_title();
        show_succ_info("成功修改用户联系方式！");
        return true;
    }
    else if(choice == "3")          //3.修改地址
    {
        show_prompt_info("请输入修改后的地址：");
        string new_addr;
        cin >> new_addr;
        //检查地址是否符合规范
        int addr_len = check_ch_en_input(new_addr);
        if(addr_len == -1 || addr_len > USR_ADDR_MAXLEN)
        {
            show_err_title();
            show_err_info("地址需由不超过四十个的字母或中文字符组成！");
            return false;
        }
        //检查地址是否为空
        else if(addr_len <= 0)
        {
            show_err_title();
            show_err_info("地址不可为空！");
            return false;
        }
        //检查无误，修改用户地址
        cur_usr->update_addr(new_addr);
        show_succ_title();
        show_succ_info("成功修改用户地址！");
        return true;
    }
    Usr::save_all_usrs();
    return true;
}
bool IOManager::usr_recharge(Usr* cur_usr)
{
    //获取用户充值金额
    show_prompt_info("请输入您的充值金额：");
    string reset_amount;
    cin >> reset_amount;
    //检查用户输入是否符合规范
    if(regex_match(reset_amount, MONEY_REGEX) == false)
    {
        show_err_title();
        show_err_info("充值金额需输入至多一位小数的正数！");
        return false;
    }
    //检查充值金额是否过大
    double charge = atof(reset_amount.c_str());
    if(charge > 1e6)
    {
        show_err_title();
        show_err_info("超出系统最大充值金额100万！");
        return false;
    }
    //成功充值
#ifdef CALCULATOR
    Recharge* p = new Recharge(cur_usr->get_id(), charge);
    Recharge::add_recharge_record(p);
#endif
    cur_usr->recharge(charge);
    show_succ_title();
    show_succ_info("充值成功！");
    OUTPUT(vector<string>{HIGHLIGHT}, printf("当前余额为：%.1lf\n", cur_usr->get_balance()));
    Usr::save_all_usrs();
    return true;
}
//买家
void IOManager::usr_search_merchandises()
{
    //获取待搜索目标的名称
    show_prompt_info("请输入要搜索的商品名称：");
    string target_name;
    cin >> target_name;
#ifndef MYSQL
    //进行搜索
    vector<Merchandise*> rst;
    Merchandise::search_merchandises_by_name(rst, target_name);
    //未找到目标
    if(rst.size() == 0)
    {
        show_prompt_info("未找到目标商品...\n");
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
#endif
#ifdef MYSQL
    string usr_search_mer_order = SqlItem::generate_select_order(
        MYSQL_MER_LIST_NAME, "*", vector<pair<string, string>>{pair<string, string>("MerName", target_name)}
    );
    SqlItem::dealwith_select_order(usr_search_mer_order);
#endif
    //利用输入等待进行退出
    show_prompt_info("按下回车键退出...");
    cin.clear();
    getpass("");
    return;
}
void IOManager::usr_show_merchandise_details_info()
{
    //获取待查看商品的ID
    show_prompt_info("请输入您想要查看商品的ID：");
    string target_id;
    cin >> target_id;
#ifndef MYSQL
    Merchandise* target = Merchandise::find_mer_by_id(target_id);
    //查询该商品是否存在
    if(target == nullptr)
    {
        show_err_title();
        show_err_info("该商品不存在！");
        sleep(DELAY);
        return;
    }
    else if(target->get_mode() == REMOVED)
    {
        show_err_title();
        show_err_info("该商品已下架！");
        sleep(DELAY);
        return;
    }
    //展示商品详细信息
    DRAW_STAR_LINE(50);
    target->show_details_info();
    DRAW_STAR_LINE(50);
#endif
#ifdef MYSQL
    string buyer_show_details_mer_order = SqlItem::generate_select_order(
        MYSQL_MER_LIST_NAME, "*", vector<pair<string, string>>{pair<string, string>("MerID", target_id)}
    );
    SqlItem::dealwith_select_order(buyer_show_details_mer_order);
    SqlItem::save_all_items();
#endif
    //利用输入等待进行退出
    show_prompt_info("按下回车键退出...");
    cin.clear();
    getpass("");
    return;
}
void IOManager::purchase_merchandise(Usr* cur_usr)
{
    //获取待购买商品的ID
    show_prompt_info("请输入商品ID：");
    string target_id;
    cin >> target_id;
    Merchandise* target = Merchandise::find_mer_by_id(target_id);
    //检查目标商品是否存在
    if(target == nullptr)
    {
        show_err_title();
        show_err_info("该商品不存在！");
        sleep(DELAY);
        return;
    }
    //检查目标商品是否下架
    else if(target->get_mode() == REMOVED)
    {
        show_err_title();
        show_err_info("该商品已下架！");
        sleep(DELAY);
        return;
    }
    //检查目标商品是否售罄
    else if(target->get_num() == 0)
    {
        show_err_title();
        show_err_info("该商品已售罄！");
        sleep(DELAY);
        return;
    }
    //检查该商品是否是自己发布
    else if(target->get_seller_id() == cur_usr->get_id())
    {
        show_err_title();
        show_err_info("禁止购买自己发布的商品！");
        sleep(DELAY);
        return;
    }
    //展示商品信息
    DRAW_STAR_LINE(50);
    target->show_details_info();
    DRAW_STAR_LINE(50);
    show_prompt_info("请输入购买数量：");
    string purchase_num_buf;
    cin >> purchase_num_buf;
    //检验输入的数量是否合法
    if(!regex_match(purchase_num_buf, regex("([1-9]{1})([0-9]*)")))
    {
        show_err_title();
        show_err_info("非法输入！");
        sleep(DELAY);
        return;
    }
    int purchase_num = atoi(purchase_num_buf.c_str());
    int trans_state = 0;
    //检查是否有足够的商品
    if(purchase_num > target->get_num())
    {
        show_err_title();
        show_err_info("超出该商品存货量！");
        sleep(DELAY);
        return;
    }
    //检查是否由足够的余额
    if(purchase_num * target->get_price() > cur_usr->get_balance())
    {
        show_err_title();
        show_err_info("余额不足，请充值！");
        sleep(DELAY);
        return;
    }
    //再次确认是否下单
    OrderForm* p = new OrderForm(target, cur_usr, purchase_num);
    show_prompt_info("请确认是否下单：\n");
    DRAW_STAR_LINE(50);
    p->show_details_info();
    DRAW_STAR_LINE(50);
    show_prompt_info("您确认要支付该订单吗？(y/other for no)：");
    string choice;
    cin >> choice;
    if(choice != "y")
    {
        delete p;
        show_succ_title();
        show_succ_info("已成功取消该订单！");
        sleep(DELAY);
        return;
    }
    else
    {
        //商品卖出,商品数量改变
#ifndef MYSQL
        target->update_num(target->get_num() - purchase_num);#endif
#endif
#ifdef MYSQL
        string merchandise_sellout_order = SqlItem::generate_update_order(
            MYSQL_MER_LIST_NAME,
            vector<pair<string, string>>{pair<string, string>("Num", to_string(target->get_num() - purchase_num))},
            vector<pair<string, string>>{pair<string, string>("MerID", target->get_id())}
        );
        SqlItem::dealwith_update_order(merchandise_sellout_order);
#endif
        //商品卖出，买家钱花费
#ifndef MYSQL
        cur_usr->pay(purchase_num * target->get_price());
#endif
#ifdef MYSQL
        string usr_pay_order = SqlItem::generate_update_order(
            MYSQL_USR_LIST_NAME,
            vector<pair<string, string>>{pair<string, string>("Balance", to_string(cur_usr->get_balance() - purchase_num*target->get_price()))},
            vector<pair<string, string>>{pair<string, string>("UsrID", cur_usr->get_id())}
        );
        SqlItem::dealwith_update_order(usr_pay_order);
#endif
        //商品卖出，卖家获得钱
#ifndef MYSQL
        Usr* seller = Usr::find_usr_by_id(target->get_seller_id());
        seller->update_balance(seller->get_balance() + purchase_num * target->get_price());
#endif
#ifdef MYSQL
        Usr* seller = Usr::find_usr_by_id(target->get_seller_id());
        string seller_income_order = SqlItem::generate_update_order(
            MYSQL_USR_LIST_NAME,
            vector<pair<string, string>>{pair<string, string>("Balance", to_string(seller->get_balance() + purchase_num * target->get_price()))},
            vector<pair<string, string>>{pair<string, string>("UsrID", seller->get_id())}
        );
        SqlItem::dealwith_update_order(seller_income_order);
#endif

        //商品卖出，增加订单
#ifndef MYSQL
        OrderForm::add_orderform(p);
#endif
#ifdef MYSQL
    delete p;
    string add_orderform_order = SqlItem::generate_insert_order(
        MYSQL_ORDER_LIST_NAME,
        vector<string> {target->get_id(), target->get_seller_id(), cur_usr->get_id(), to_string(target->get_price()), to_string(purchase_num)}
    );
    SqlItem::dealwith_insert_order(add_orderform_order);
#endif

        SqlItem::save_all_items();
        Merchandise::save_all_merchandises();
        Usr::save_all_usrs();
        OrderForm::save_all_orderforms();
        
        DRAW_STAR_LINE(50);
        show_prompt_info("交易提醒！\n");
        p->show_details_info();
        printf("\033[1m交易状态：\033[0m\t\t交易成功\n");
        printf("\033[1m您的余额：\033[0m\t\t%.1lf\n", cur_usr->get_balance());

        DRAW_STAR_LINE(50);
        //利用输入等待进行退出
        show_prompt_info("按下回车键退出...");
        cin.clear();
        getpass("");
        return;
    }
    return;
}
//卖家
void IOManager::add_merchandise(Usr* cur_usr)
{
    string mer_name;
    string mer_price_buf;
    double mer_price;
    string mer_num_buf;
    int mer_num;
    string mer_desp;
    //获取商品名称
    show_prompt_info("请输入商品名称：");
    cin >> mer_name;
    //检验商品名称是否符合规范
    int name_len = check_ch_en_input(mer_name);
    if(name_len >= MERCHANDISE_NAME_MAXLEN || name_len == -1)
    {
        show_err_title();
        show_err_info("商品名称需由不超过20个的英文字母或汉字字符组成！");
        return;
    }
    else if(name_len <= 0)
    {
        show_err_title();
        show_err_info("商品名称不能为空！");
        return;
    }
    //获取商品价格
    show_prompt_info("请输入商品价格：");
    cin >> mer_price_buf;
    //检查价格输入是否符合规范
    if(!regex_match(mer_price_buf, MONEY_REGEX))
    {
        show_err_title();
        show_err_info("价格需要输入至多一位小数的正数！");
        return;
    }
    mer_price = atof(mer_price_buf.c_str());
    //获取商品数量
    show_prompt_info("请输入商品数量：");
    cin >> mer_num_buf;
    //检验商品数量是否符合规范
    if(!regex_match(mer_num_buf, regex("([1-9]{1})([0-9]*)")))
    {
        show_err_title();
        show_err_info("商品数量需为正整数！");
        return;
    }
    mer_num = atoi(mer_num_buf.c_str());
    //获取商品描述
    show_prompt_info("请输入商品描述：");
    cin >> mer_desp;
    //检验商品描述是否符合规范
    int desp_len = check_ch_en_num_input(mer_desp);
    if(desp_len == -1 || desp_len > MERCHANDISE_DESCRIPTION_MAXLEN)
    {
        show_err_title();
        show_err_info("商品描述需由不超过40个的英文字母、中文字符或数字组成！");
        return;
    }
    else if(desp_len <= 0)
    {
        show_err_title();
        show_err_info("商品描述不能为空！");
        return;
    }
    //通过所有检验，再次确认是否发布商品
    Merchandise* p = new Merchandise(mer_name, mer_price, mer_num, mer_desp, cur_usr->get_id());
    show_prompt_info("请确认发布的商品信息无误！\n");
    DRAW_STAR_LINE(50);
    p->show_details_info();
    DRAW_STAR_LINE(50);
    show_prompt_info("您确认要发布商品吗？(y/other for no)：");
    string choice;
    cin >> choice;
    if(choice != "y")
    {
        delete p;
        show_succ_title();
        show_succ_info("已成功取消该商品的发布！");
        return;
    }
    else
    {
#ifndef MYSQL
        Merchandise::add_merchandise(p);
#endif

#ifdef MYSQL
        delete p;
        string add_merchandise_order = SqlItem::generate_insert_order(
            MYSQL_MER_LIST_NAME,
            vector<string>{mer_name, to_string(mer_price), to_string(mer_num), mer_desp, cur_usr->get_id()}
        );
        SqlItem::dealwith_insert_order(add_merchandise_order);
        SqlItem::save_all_items();
#endif
        Merchandise::save_all_merchandises();
        show_succ_title();
        show_succ_info("发布商品成功！");
        return;
    }
}
bool IOManager::modify_merchandise_info(Usr* cur_usr)
{
    //获取待修改商品的ID
    show_prompt_info("请输入被修改商品的ID：");
    string target_id;
    cin >> target_id;
    Merchandise* target = Merchandise::find_mer_by_id(target_id);
    //查询该商品是否存在
    if(target == nullptr)
    {
        show_err_title();
        show_err_info("该商品不存在！");
        return false;
    }
    //检验该商品是否为当前用户发布，是否有权限修改
    else if(target->get_seller_id() != cur_usr->get_id())
    {
        show_err_title();
        show_err_info("你无权对他人商品进行修改！");
        return false;
    }
    //检查该商品是否被下架
    else if(target->get_mode() == REMOVED)
    {
        show_err_title();
        show_err_info("该商品已被下架！");
        return false;
    }
    //显示该商品信息
    DRAW_STAR_LINE(50);
    target->show_details_info();
    DRAW_STAR_LINE(50);
    //修改选项分支
    show_prompt_info("请选择修改的属性(1.价格 2.描述)：");
    string choice;
    cin >> choice;
    if(!regex_match(choice, regex("[1-2]{1}")))
    {
        show_err_title();
        show_err_info("非法输入！");
        return false;
    }
    if(choice == "1")           //1.修改商品价格
    {
        //获取修改后价格
        string modified_price_buf;
        show_prompt_info("请输入被修改商品的价格：");
        cin >> modified_price_buf;
        //检验输入是否符合规范
        if(!regex_match(modified_price_buf, MONEY_REGEX))
        {
            show_err_title();
            show_err_info("价格需要输入至多一位小数的正数！");
            return false;
        }
        double modified_price = atof(modified_price_buf.c_str());
        //确认是否进行修改
        show_prompt_info("请确认被修改商品的信息无误：\n");
        DRAW_STAR_LINE(50);
        printf("\033[1m商品ID：\033[0m\t\t%s\n", target->get_id().c_str());
        printf("\033[1m商品名称：\033[0m\t\t%s\n", target->get_name().c_str());
        printf("\033[1m商品价格：\033[0m\t\t%.1lf\n", modified_price);
        printf("\033[1m商品数量：\033[0m\t\t%d\n", target->get_num());
        printf("\033[1m商品描述：\033[0m\t\t%s\n", target->get_description().c_str());
        printf("\033[1m发布时间：\033[0m\t\t%s\n", target->get_added_time().c_str());
        DRAW_STAR_LINE(50);
        show_prompt_info("确认修改商品信息？(y/other for no)：");
        string choice;
        cin >> choice;
        if(choice != "y")
        {
            show_succ_title();
            show_succ_info("已成功取消修改操作！");
        }
        else
        {
#ifndef MYSQL
            target->update_price(modified_price);
#endif
#ifdef MYSQL
            string usr_modify_price_order = SqlItem::generate_update_order(
                MYSQL_MER_LIST_NAME,
                vector<pair<string, string>>{pair<string, string>("Price", to_string(modified_price))},
                vector<pair<string, string>>{pair<string, string>("MerID", target->get_id())}
            );
            SqlItem::dealwith_update_order(usr_modify_price_order);
            SqlItem::save_all_items();
#endif
            show_succ_title();
            show_succ_info("修改成功！");
        }
    }
    else if(choice == "2")      //2.修改商品描述
    {
        //获取修改后的商品描述
        string modified_desp;
        show_prompt_info("请输入被修改商品的描述：");
        cin >> modified_desp;
        //检验商品描述是否符合规范
        int desp_len = check_ch_en_num_input(modified_desp);
        if(desp_len == -1 || desp_len > MERCHANDISE_DESCRIPTION_MAXLEN)
        {
            show_err_title();
            show_err_info("商品描述需由不超过40个的英文字母、中文字符或数字组成！");
            return false;
        }
        else if(desp_len <= 0)
        {
            show_err_title();
            show_err_info("商品描述不能为空！");
            return false;
        }
        //确认是否进行修改
        show_prompt_info("请确认被修改商品的信息无误：\n");
        DRAW_STAR_LINE(50);
        printf("\033[1m商品ID：\033[0m\t\t%s\n", target->get_id().c_str());
        printf("\033[1m商品名称：\033[0m\t\t%s\n", target->get_name().c_str());
        printf("\033[1m商品价格：\033[0m\t\t%.1lf\n", target->get_price());
        printf("\033[1m商品数量：\033[0m\t\t%d\n", target->get_num());
        printf("\033[1m商品描述：\033[0m\t\t%s\n", modified_desp.c_str());
        printf("\033[1m发布时间：\033[0m\t\t%s\n", target->get_added_time().c_str());
        DRAW_STAR_LINE(50);
        show_prompt_info("确认修改商品信息？(y/other for no)：");
        string choice;
        cin >> choice;
        if(choice != "y")
        {
            show_succ_title();
            show_succ_info("已成功取消修改操作！");
        }
        else
        {
#ifndef MYSQL
            target->update_description(modified_desp);
#endif
#ifdef MYSQL
            string usr_modify_desc_order = SqlItem::generate_update_order(
                MYSQL_MER_LIST_NAME,
                vector<pair<string, string>>{pair<string, string>("Desc", modified_desp)},
                vector<pair<string, string>>{pair<string, string>("MerID", target->get_id())}
            );
            SqlItem::dealwith_update_order(usr_modify_desc_order);
            SqlItem::save_all_items();
#endif
            show_succ_title();
            show_succ_info("修改成功！");
        }
    }
    Merchandise::save_all_merchandises();
    return true;
}
bool IOManager::usr_remove_merchandise(Usr* cur_usr)
{
    show_prompt_info("请输入要下架商品的ID:");
    string target_id;
    cin >> target_id;
    Merchandise* target = Merchandise::find_mer_by_id(target_id);
    //查询该商品是否存在
    if(target == nullptr)
    {
        show_err_title();
        show_err_info("该商品不存在！");
        return false;
    }
    //查询该商品是否为当前用户发布，是否有权限修改
    else if(target->get_seller_id() != cur_usr->get_id())
    {
        show_err_title();
        show_err_info("你无权对他人商品进行修改！");
        return false;
    }
    //检查该商品是否已经下架
    else if(target->get_mode() == REMOVED)
    {
        show_err_title();
        show_err_info("该商品已下架！");
        return false;
    }
    //显示该商品信息 & 进行下架确认
    show_prompt_info("确认要下架该商品吗？\n");
    DRAW_STAR_LINE(50);
    target->show_details_info();
    DRAW_STAR_LINE(50);
    show_prompt_info("请选择(y/other for no)：");
    string choice;
    cin >> choice;
    if(choice != "y")
    {
        show_succ_title();
        show_succ_info("已成功取消修改操作！");
    }
    else
    {
#ifndef MYSQL
        target->update_state(REMOVED);
#endif
#ifdef MYSQL
        string usr_ban_mer_order = SqlItem::generate_update_order(
            MYSQL_MER_LIST_NAME,
            vector<pair<string, string>>{pair<string, string>("State", "已下架")},
            vector<pair<string, string>>{pair<string, string>("MerID", target->get_id())}
        );
        SqlItem::dealwith_update_order(usr_ban_mer_order);
        SqlItem::save_all_items();
#endif
        Merchandise::save_all_merchandises();
        show_succ_title();
        show_succ_info("该商品成功下架！");
    }
    return true;
}
//MYSQL指令生成
string IOManager::generate_based_expr(vector<OrderForm*>& costs, vector<OrderForm*>& incomes, vector<Recharge*>& recharges)
{
    string rst;
    for(int i = 0; i < incomes.size(); i++)
    {
        if(i != 0) rst += "+";
        string num = to_string(incomes[i]->get_num());
        string unitp = to_string(incomes[i]->get_uintp());
        rst += num + "*" + unitp.substr(0, unitp.find('.')+2);
    }
    if(incomes.size() != 0 && recharges.size() != 0) rst += "+";
    for(int i = 0; i < recharges.size(); i++)
    {
        if(i != 0) rst += "+";
        string buf = to_string(recharges[i]->get_money());
        rst += buf.substr(0, buf.find('.')+2);
    }
    for(int i = 0; i < costs.size(); i++)
    {
        string num = to_string(costs[i]->get_num());
        string unitp = to_string(costs[i]->get_uintp());
        rst += "-" + num + "*" + unitp.substr(0, unitp.find('.')+2);
    }
    if(rst.size() == 0) rst = "0";
    return rst;
}