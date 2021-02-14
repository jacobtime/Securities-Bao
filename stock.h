#pragma once
#include "Financial management.h"
#include <string>
#include <map>
#include <fstream>
#include <iostream>
#include <time.h> 
using std::ifstream;
using std::ofstream;
using std::cin;
using std::map;
using std::cout;
using std::endl;
using std::string;
using std::ios_base;
#ifndef _STOCK_H_//1
#define _STOCK_H_
struct stocks {
	string s_name;//股票名称
	string s_num;//股票代码
	double price = 0;//单价
	int hands = 0;//多少手（数量 == 手数 * 100）
};
class S:public F
{
private:
	stocks stock[200];//储存股票信息
public:
	S(const string f, double b);//初始化
	void buy(string name, string num, double p, int h);//买入股票
	void sell(string name, string num, double p, int h);//卖出股票
	void show();//展示已持有的股票
	double re(){ return balance; }//返回余额修改F类的balance
	~S();//写入文件
};

#endif // !1
