#ifndef IOMANAGER_H
#define IOMANAGER_H

#pragma once
#include "General.h"
#include "Usr.h"
#include "OrderForm.h"
#include "Recharge.h"

class IOManager
{
private:
public:
    //格式校验
    static int check_ch_en_input(string input);             //校验指定长度：中文+大小写英文
    static int check_ch_en_num_input(string input);         //校验指定长度：中文+大小写英文+数字
    static int check_lowen_num_input(string input);         //校验指定长度：小写英文
    //CALCULATOR计算式生成
    static string generate_based_expr(vector<OrderForm*>& costs, vector<OrderForm*>& incomes, vector<Recharge*>& recharges);
};

#endif // IOMANAGER_H
