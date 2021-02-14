#pragma once
#include <iostream>
#include "windows.h"
#ifndef DATE_H_
#define DATE_H_
struct aa {
	int year;
	int month;
	int day;
	friend std::ostream& operator<<(std::ostream& os, const aa a)
	{
		std::cout << a.year << "years," << a.month << "months" << a.day << "days" << std::endl;
		return os;
	}
};
class Time
{
private:
	int month, day, year;
public:
	Time();//��ʼ��
	Time trans();//��ȡϵͳʱ��
	Time(int y, int m, int d);//��ʼ��
	Time get(int y, int m, int d);//��3������ת����Time��Ķ���
	int date(Time a);//����Time����0��0��0�յĲ�ֵ
	aa back(int time);//����aa���͵�ʱ��
	friend int operator-(Time& b, Time& a);
	friend int operator-(int date, Time& a);
	friend std::ostream& operator<<(std::ostream& os, const Time a);
	friend std::ostream& operator<<(std::ostream& os, const aa a);
};
#endif // !DATE

