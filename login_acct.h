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
	map<string, string> acct;//���ڴ����û���Ϣ
public:
	string& encipher(string& a);//����
	string& deciphering(string& a);//����
	bool get_new(book book2);//�����û�д��map��
	void write();//�½��û��ļ���д���û�������
	void read();//��ȡ�û������û�����
	bool check(book book1);//�жϵ�¼�Ƿ���ȷ
	book get();//��ʼ����ȡ���棬����û������˻��Լ����룬����Ϊ������ֵ
	void show();//չʾ�û������ƺ�����
};

#endif // !1
