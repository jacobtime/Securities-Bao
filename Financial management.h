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
	double balance = 0;//���
	double rate = 0;//����
	int days = 0;//���������ķ���
};
class F {
protected:
		string acctnum;
		double balance = 0;//���
private:
		Record record[200];//��Ʒ�����Ϣ
public:
	F(const string f);//��ʼ��
	void F_M(double value, double r, int day);//���
	void Deposit(double money);//���
	virtual void show();//չʾ
	virtual ~F();//д���ļ�
	double r_b() { return balance; };//�������
	void b(double b) { balance = b; }//��S������µ����ֵ����F��
};
#endif // !1
