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
	Time();//初始化
	Time trans();//获取系统时间
	Time(int y, int m, int d);//初始化
	Time get(int y, int m, int d);//将3个数据转换成Time类的对象
	int date(Time a);//返回Time对象到0年0月0日的差值
	aa back(int time);//返回aa类型的时间
	friend int operator-(Time& b, Time& a);
	friend int operator-(int date, Time& a);
	friend std::ostream& operator<<(std::ostream& os, const Time a);
	friend std::ostream& operator<<(std::ostream& os, const aa a);
};
#endif // !DATE

