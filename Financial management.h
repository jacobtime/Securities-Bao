#pragma once
#ifndef _Financial_management_H_
#define _Financial_management_H_
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
struct Record {
	double balance = 0;//金额
	double rate = 0;//利率
	int days = 0;//购买多少天的服务
};
class F {
protected:
		string acctnum;
		double balance = 0;//余额
private:
		Record record[200];//理财服务信息
public:
	F(const string f);//初始化
	void F_M(double value, double r, int day);//理财
	void Deposit(double money);//存款
	virtual void show();//展示
	virtual ~F();//写入文件
	double r_b() { return balance; };//返回余额
	void b(double b) { balance = b; }//将S类的最新的余额值更新F类
};
#endif // !1
