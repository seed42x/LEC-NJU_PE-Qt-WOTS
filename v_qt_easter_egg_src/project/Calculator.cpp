#include"Calculator.h"

//全局规则初始化
rule Calculator::rules[] =
{
    {"([0]{1}|(([0]{1}[\\.]{1}[1-9]{1})|([1-9]{1}[0-9]*[\\.]{1}[0-9]{1})|([1-9]{1}[0-9]*)))", NUM},
    {"[ ]+", NOTYPE},
    {"\\+", '+'},
    {"\\-", '-'},
    {"\\-", NEG},
    {"\\*", '*'},
    {"\\/", '/'},
    {"\\(", '('},
    {"\\)", ')'}
};
//全局tokens数组初始化
vector<Token> Calculator::tokens = {};

void Calculator::show_all_tokens()
{
    cout << "index" << "\t\t\t" << "Token" << "\t\t\t" << "Type" << endl;
    for(int i = 0; i < (int)Calculator::tokens.size(); i++)
    {
        cout << i << "\t\t\t";
        cout << Calculator::tokens[i].str << "\t\t\t";
        if(Calculator::tokens[i].type == NUM) cout << "NUM";
        else if(Calculator::tokens[i].type == '+' || Calculator::tokens[i].type == '-' || Calculator::tokens[i].type == '*' || Calculator::tokens[i].type == '/') cout << (char)(Calculator::tokens[i].type);
        else if(Calculator::tokens[i].type == '(' || Calculator::tokens[i].type == ')') cout << (char)(Calculator::tokens[i].type);
        else if(Calculator::tokens[i].type == NEG) cout << "NEG";
        cout << endl;
    }
}

bool Calculator::make_tokens(bool& success, string& err_info, string e)
{
    string buf;
    for(int i = 0; i < (int)e.size(); i++)
    {
        if(regex_match(e.substr(i, 1), regex("[0-9]{1}|[\\.]{1}")))
        {
            buf.push_back(e[i]);
        }
        else
        {
            if(buf.size() != 0)
            {
                if(regex_match(buf, regex(rules[0].regex)))
                {
                    Calculator::tokens.push_back(Token(NUM, buf));
                    buf.clear();
                }
                else
                {
                    success = false;
                    err_info = "非法数字输入，所有数字应为至多一位小数的实数！";
                    return false;
                }
            }
            if(e[i] == '+') Calculator::tokens.push_back(Token('+', "+"));
            else if(e[i] == '-') Calculator::tokens.push_back(Token('-', "-"));
            else if(e[i] == '*') Calculator::tokens.push_back(Token('*', "*"));
            else if(e[i] == '/') Calculator::tokens.push_back(Token('/', "/"));
            else if(e[i] == '(') Calculator::tokens.push_back(Token('(', "("));
            else if(e[i] == ')') Calculator::tokens.push_back(Token(')', ")"));
            else
            {
                success = false;
                err_info = "非法符号！";
                return false;
            }
        }
    }
    if(buf.size() != 0)
    {
        if(regex_match(buf, regex(rules[0].regex)))
        {
            Calculator::tokens.push_back(Token(NUM, buf));
            buf.clear();
        }
        else
        {
            success = false;
            err_info = "非法数字输入，所有数字应为至多一位小数的实数！";
            return false;
        }
    }
    for(int i = 0; i < (int)Calculator::tokens.size(); i++)
    {
        if(Calculator::tokens[i].type == '-' && i == 0) Calculator::tokens[i].type = NEG;
        else if(Calculator::tokens[i].type == '-' && Calculator::tokens[i-1].type == '(') Calculator::tokens[i].type =NEG;
    }
    return true;
}

bool Calculator::check_parentheses(bool& success, string& err_info, int p, int q)
{
    if(success == false) return 0;
    if(Calculator::tokens[p].type != '(' || Calculator::tokens[q].type != ')') return false;
    int left_num = 0, right_num = 0;
    for(int i = p + 1; i < q; i++)
    {
        if(right_num > left_num) return false;
        if(Calculator::tokens[i].type == '(') left_num++;
        else if(Calculator::tokens[i].type == ')') right_num++;
    }
    if(right_num == left_num) return true;
    else return false;
}

double Calculator::eval(bool& success, string& err_info, int p, int q)
{
    /*for debugging*/
    // cout << p << " " << q << endl;
    // cin.clear();
    // getpass("");
    if(success == false) return 0;
    //括号合法性检查
    int check = 0;
    for(int i = p; i <= q; i++)
    {
        if(tokens[i].type == '(') check++;
        else if(tokens[i].type == ')') check--;
        if(check < 0)
        {
            success = false;
            err_info = "非法括号使用！";
            return 0;
        }
    }
    if(check != 0)
    {
        success = false;
        err_info = "非法括号使用！";
        return 0;
    }

    if(p > q)
    {
        success = false;
        err_info = "非法运算符号使用！";
        return 0;
    }
    else if(p == q)
    {
        if(Calculator::tokens[p].type == NUM) return atof(Calculator::tokens[p].str.c_str());
    }
    else if(check_parentheses(success, err_info, p, q) == true) return eval(success, err_info, p+1, q-1);
    else if(Calculator::tokens[p].type == NEG)
    {
        if(tokens[p+1].type == '(')
        {
            double buf = eval(success, err_info, p+1, q);
            return -buf;
        }
        else if(tokens[p+1].type == NUM)
        {
            tokens[p+1].str = "-" + tokens[p+1].str;
            return eval(success, err_info, p+1, q);
        }
    }
    else
    {
        int op_index = 0;
        int op_priority = 100;
        int if_in_parent = 0;
        int i = q;
        while(i > p)
        {
            if(Calculator::tokens[i].type == ')') if_in_parent++;
            else if(Calculator::tokens[i].type == '(') if_in_parent--;
            if(if_in_parent == 0)
            {
                if(op_priority > 3 && (Calculator::tokens[i].type == '+' || Calculator::tokens[i].type == '-'))
                {
                    op_index = i;
                    op_priority = 3;
                }
                else if(op_priority > 4 && (Calculator::tokens[i].type == '*' || Calculator::tokens[i].type == '/'))
                {
                    op_index = i;
                    op_priority = 4;
                }
            }
            i--;
        }
        double val1 = eval(success, err_info, p, op_index-1);
        double val2 = eval(success, err_info, op_index+1, q);
        switch(Calculator::tokens[op_index].type)
        {
            case '+' : return val1 + val2;
            case '-' : return val1 - val2;
            case '*' : return val1 * val2;
            case '/' :
                if(val2 == 0)
                {
                    success = false;
                    err_info = "除数为0！";
                    return 0;
                }
                return val1 / val2;
            default :
                success = false;
                err_info = "非法运算符！";
                return 0;
        }
    }
    return 0;
}

double Calculator::expr(bool& success, string& err_info, string expr)
{
    success = success;
    err_info = err_info;
    Calculator::tokens.clear();

    Calculator::make_tokens(success, err_info, expr);
    //Calculator::show_all_tokens();  //for debugging
    if(success == false) return 0;
    double ans = eval(success, err_info, 0, Calculator::tokens.size() - 1);
    if(success == false) return 0;
    tokens.clear();
    return ans;
}

string Calculator::simplify_expr(string ori_expr)
{
    bool success = true;
    string err_info = "";
    Calculator::make_tokens(success, err_info, ori_expr);
    if(tokens.size() == 1) return ori_expr;

    vector<pair<int, double>> buflib;
    for(int i = 0; i < tokens.size(); i++)
    {
        if(tokens[i].type == NUM)
        {
            if(i == 0 && tokens[i+1].type != '*') buflib.push_back(pair<int, double>(1, atof(tokens[i].str.c_str())));
            else if(i == (int)tokens.size() - 1 && tokens[i-1].type != '*')
            {
                if(tokens[i-1].type == '-') buflib.push_back(pair<int, double>(1, -atof(tokens[i].str.c_str())));
                else if(tokens[i-1].type == '+') buflib.push_back(pair<int, double>(1, atof(tokens[i].str.c_str())));
            }
            else if(tokens[i-1].type != '*' && tokens[i+1].type != '*')
            {
                if(tokens[i-1].type == '-') buflib.push_back(pair<int, double>(1, -atof(tokens[i].str.c_str())));
                else if(tokens[i-1].type == '+') buflib.push_back(pair<int, double>(1, atof(tokens[i].str.c_str())));
            }
        }
        else if(tokens[i].type == '*')
        {
            int num = atoi(tokens[i-1].str.c_str());
            double price = atof(tokens[i+1].str.c_str());
            if(i - 2 >= 0 && tokens[i-2].type == '-') buflib.push_back(pair<int, double>(num, -price));
            else buflib.push_back(pair<int, double>(num, price));
        }
    }
    unordered_map<int, vector<double>> hash_map;
    for(int i = 0; i < (int)buflib.size(); i++)
    {
        hash_map[buflib[i].first].push_back(buflib[i].second);
    }

    string simple_expr;
    for(auto it : hash_map)
    {
        simple_expr += "+";
        simple_expr += to_string(it.first) + "*" + "(";
        for(int i = 0; i < (int)it.second.size(); i++)
        {
            if(i != 0 && it.second[i] > 0) simple_expr += "+";
            string buf = to_string(it.second[i]);
            simple_expr += buf.substr(0, buf.find('.')+2);
        }
        simple_expr += ")";
    }
    simple_expr = simple_expr.substr(1);
    return simple_expr;
}
