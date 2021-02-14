#pragma once
#include <string>
#include <map>
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::map;

struct book {
	string username;
	string password;
};

#ifndef LOGIN_ACCT_H_
#define LOGIN_ACCT_H_
class login
{
private:
	map<string, string> acct;//用于储存用户信息
public:
	string& encipher(string& a);//加密
	string& deciphering(string& a);//解密
	bool get_new(book book2);//将新用户写入map中
	void write();//新建用户文件，写入用户名单表
	void read();//读取用户名及用户数量
	bool check(book book1);//判断登录是否正确
	book get();//初始化读取界面，获得用户输入账户以及密码，返回为不加密值
	void show();//展示用户名名称和数量
};

#endif // !1
