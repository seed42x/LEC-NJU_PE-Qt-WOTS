#include "IOManager.h"

/*格式校验*/
int IOManager::check_ch_en_input(string input)      //检查 中文 + 大小写英文 长度
{
    int all_num = 0, ch_num = 0, en_num = 0;
    for(int i = 0; i < (int)input.size(); i++)
    {
        if((input[i] >= 'a' && input[i] <= 'z') || (input[i] >= 'A' && input[i] <= 'Z')) en_num++;
        else
            if(((input[i] > 0 && input[i] < 'A') || (input[i] > 'Z' && input[i] < 'a') || (input[i] > 'z')))
                return -1;
    }
    ch_num = (input.size() - en_num) / 3;
    all_num = ch_num + en_num;
    return all_num;
}
int IOManager::check_ch_en_num_input(string input)      //检查 中文 + 大小写英文 + 数字 长度
{
    int all_num = 0, ch_num = 0, en_num = 0, num_num = 0;
    for(int i = 0; i < (int)input.size(); i++)
    {
        if((input[i] >= 'a' && input[i] <= 'z') || (input[i] >= 'A' && input[i] <= 'Z')) en_num++;
        else if(input[i] >= '0' && input[i] <= '9') num_num++;
        else
            if(((input[i] > 0 && input[i] < 'A') || (input[i] > 'Z' && input[i] < 'a') || (input[i] > 'z')))
                return -1;
    }
    ch_num = (input.size() - en_num - num_num) / 3;
    all_num = ch_num + en_num + num_num;
    return all_num;
}
int IOManager::check_lowen_num_input(string input)      //检查 小写字母 + 数字 长度
{
    int len = input.size();
    for(int i = 0; i < len; i++)
    {
        if(!((input[i] >= 'a' && input[i] <= 'z') || (input[i] >= '0' && input[i] <= '9')))
            return -1;
    }
    return input.size();
}

string IOManager::generate_based_expr(vector<OrderForm*>& costs, vector<OrderForm*>& incomes, vector<Recharge*>& recharges)
{
    string rst;
    for(int i = 0; i < (int)incomes.size(); i++)
    {
        if(i != 0) rst += "+";
        string num = to_string(incomes[i]->get_num());
        string unitp = to_string(incomes[i]->get_uintp());
        rst += num + "*" + unitp.substr(0, unitp.find('.')+2);
    }
    if(incomes.size() != 0 && recharges.size() != 0) rst += "+";
    for(int i = 0; i < (int)recharges.size(); i++)
    {
        if(i != 0) rst += "+";
        string buf = to_string(recharges[i]->get_money());
        rst += buf.substr(0, buf.find('.')+2);
    }
    for(int i = 0; i < (int)costs.size(); i++)
    {
        string num = to_string(costs[i]->get_num());
        string unitp = to_string(costs[i]->get_uintp());
        rst += "-" + num + "*" + unitp.substr(0, unitp.find('.')+2);
    }
    if(rst.size() == 0) rst = "0";
    return rst;
}
