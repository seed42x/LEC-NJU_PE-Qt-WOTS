#pragma once
#include"General.h"

/*基于BNF范式实现计算器*/

//token类型
enum
{
    NOTYPE = 256,
    NUM = 0,
    NEG = 1
};

//rule类型
struct rule
{
    string regex;
    int token_type;
};

//token结构体
typedef struct token
{
    int type;
    string str;
    token(int ty, string s) { type = ty; str = s; }
} Token;

//计算器类
class Calculator
{
private:
    static rule rules[];            //BNF全局规则
    static vector<Token> tokens;    //BNF全局tokens数组
public:
    //全局功能函数
    static void show_all_tokens();                                                  // for debugging
    static bool make_tokens(bool& success, string& err_info, string e);             // 生成tokens
    static bool check_parentheses(bool& success, string& err_info, int p, int q);   // 检查括号是否匹配
    static double eval(bool& success, string& err_info, int p, int q);              // 递归求值
    static double expr(bool& success, string& err_info, string expr);               // 顶层接口
    static string simplify_expr(string ori_expr);                                   // 适用于P2P的表达式简化
};