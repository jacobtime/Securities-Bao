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
	string s_name;//��Ʊ����
	string s_num;//��Ʊ����
	double price = 0;//����
	int hands = 0;//�����֣����� == ���� * 100��
};
class S:public F
{
private:
	stocks stock[200];//�����Ʊ��Ϣ
public:
	S(const string f, double b);//��ʼ��
	void buy(string name, string num, double p, int h);//�����Ʊ
	void sell(string name, string num, double p, int h);//������Ʊ
	void show();//չʾ�ѳ��еĹ�Ʊ
	double re(){ return balance; }//��������޸�F���balance
	~S();//д���ļ�
};

#endif // !1
