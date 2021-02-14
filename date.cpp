#include <iostream>
#include "date.h"
#include <cmath>
#include <string>
using std::string;

int mon[12] = { 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334 };
Time::Time()
{
	year = day = month = 0;
}

Time Time::trans()
{
	struct aa a;
	string tmp;
	SYSTEMTIME st;
	GetLocalTime(&st);
	Time time(st.wYear, st.wMonth, st.wDay);
	return time;
}

Time::Time(int y, int m, int d)
{
	year = y;
	month = m;
	day = d;
}

int operator-(Time& b, Time& a)
{
	int day1, day2;
	day1 = (b.year - 1) * 365 + (b.year - 1) / 4 - (b.year - 1) / 400 + mon[b.month - 1] + b.day;
	if (b.month > 2 && b.year % 4 == 0 && b.year % 400 != 0)
		day1++;
	day2 = (a.year - 1) * 365 + (a.year - 1) / 4 - (a.year - 1) / 400 + mon[a.month - 1] + a.day;
	if (a.month > 2 && a.year % 4 == 0 && a.year % 400 != 0)
		day2++;
	return std::abs(day1 - day2);
}
int operator-(int date, Time& a)
{
	int day2;
	day2 = (a.year - 1) * 365 + (a.year - 1) / 4 - (a.year - 1) / 400 + mon[a.month - 1] + a.day;
	if (a.month > 2 && a.year % 4 == 0 && a.year % 400 != 0)
		day2++;
	return std::abs(date - day2);
}
Time Time::get(int y, int m, int d)
{
	Time a(y, m, d);
	return a;
}
int Time::date(Time a)
{
	int day2;
	day2 = (a.year - 1) * 365 + (a.year - 1) / 4 - (a.year - 1) / 400 + mon[a.month - 1] + a.day;
	if (a.month > 2 && a.year % 4 == 0 && a.year % 400 != 0)
		day2++;
	return day2;
}
aa Time::back(int time)
{
	struct aa a;
	a.year = time / 365 + 1;//计算出经过多少个365天然后+1到当年
	int year = 365;
	if ((a.year - 1) / 4 == 0 && (a.year - 1) % 100 != 0)//如果该年前一年为闰年，则前一年有366
	{
		year++;
	}
	if ((a.year - 2) / 4 - (a.year - 2) / 400 >= year)//如果闰年闰的天多于上一年的日子
		a.year--;
	int dayss = ((time - (a.year - 1) * 365 - (a.year - 1) / 4 + (a.year - 1) / 400));//减去年后的日子
	int i = 0;
	for (i = 0; mon[i] < dayss ; i++);
		a.month = i;
	a.day = dayss - mon[a.month - 1];
	return a;
}
std::ostream& operator<<(std::ostream& os, const Time a)
{
	std::cout << a.year << "years," << a.month << "months" << a.day << "days" << std::endl;
	return os;
}
