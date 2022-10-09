#pragma once

//标准库引用
#include<stdio.h>
#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<stack>
#include<unordered_map>
#include<regex>
#include<unistd.h>
#include<assert.h>
#include<termio.h>
#include<dirent.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<assert.h>

using namespace std;

/*宏定义*/

//管理员
#define ADMIN_NAME "admin"
#define ADMIN_PASSWD "123456"

//用户
#define USR_NAME_MAXLEN 10
#define USR_PASSWD_MAXLEN 20
#define USR_PNUM_MAXLEN 20
#define USR_ADDR_MAXLEN 40

//商品
#define MERCHANDISE_NAME_MAXLEN 20
#define MERCHANDISE_DESCRIPTION_MAXLEN 40

//表单
#define MYSQL_USR_LIST_NAME "usrs"
#define MYSQL_ORDER_LIST_NAME "orders"
#define MYSQL_MER_LIST_NAME "commodity"

//正则表达式
#define MONEY_REGEX regex("(([0]{1}[\\.]{1}[1-9]{1})|([1-9]{1}[0-9]*[\\.]{1}[0-9]{1})|([1-9]{1}[0-9]*))")

//系统消息延迟
#define DELAY 1

//状态类型
enum UsrMode{BUYER, SELLER};
enum MerchandiseMode{REMOVED, ONSALE};

//开关
//#define MYSQL           //是否使用自写数据库
//#define CALCULATOR      //是否使用自写计算器