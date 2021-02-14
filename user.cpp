#include <string>
#include "Financial management.h"
#include <conio.h>
#include "stock.h"
double g_user(string name, double balance);
using namespace std;
void show_1()
{
	cout << "Which kind of things do you want?(0 to back)" << endl;
	cout << "\t 1.deposit" << endl;
	cout << "\t 2.financial management" << endl;
	cout << "\t 3.into the stock accountant" << endl;
}
void show_2()
{
	cout << "Here are our financial products:" << endl;
	cout << "1.more than 1000$, more than a month, 3.75%" << endl;
	cout << "2.more than 10$, more than a week, 2.15%" << endl;
	cout << "3.more than 10000$, more than a month, 4.20%" << endl;
	cout << "4.more than 50000$, more than a year, 4.40%" << endl;
	cout << "Please choose your favorate, if you needn't enter 0" << endl;
	cout << "I choose the : ";
}
int user(string name){
	system("cls");
	F a_user(name);
	char ch;
	double money;
	int ans;
	show_1();
	ch = _getch();
	ans = ch - '0';
	system("cls");
	if (ans == 0)
	{
		return 1;
	}
	else if (ans == 1)
	{
		cout << "Welcome to deposit the money." << endl;
		cout << "how much do you want to deposit?" << endl;
		cout << "\t $: ";
		cin >> money;
		a_user.Deposit(money);
	}
	else if(ans == 2)
	{
		int choose;
		int day;
		show_2();
		cin >> choose;
		double balance;
 		if (choose == 0)
		{
			return 0;
		}
		else if (choose == 1)
		{
			cout << "please enter the money you want." << endl;
			cin >> balance;
			cout << "please enter the days you want." << endl;
			cin >> day;
			if (balance >= 1000 && day >= 30)
				a_user.F_M(balance, 0.0375, day);
			else if (balance < 1000)
				cout << "The money is below the least.";
			else if (day < 7)
				cout << "The days is below the least.";
		}
		else if (choose == 2)
		{
			cout << "please enter the money you want." << endl;
			cin >> balance;
			cout << "please enter the days you want." << endl;
			cin >> day;
			if (balance >= 10 && day >= 7)
				a_user.F_M(balance, 0.0215, day);
			else if (balance < 10)
				cout << "The money is below the least.";
			else if (day < 7)
				cout << "The days is below the least.";
		}
		else if (choose == 3)
		{
			cout << "please enter the money you want." << endl;
			cin >> balance;
			cout << "please enter the days you want." << endl;
			cin >> day;
			if (balance >= 10000 && day >= 30)
				a_user.F_M(balance, 0.0420, day);
			else if (balance < 10000)
				cout << "The money is below the least.";
			else if (day < 30)
				cout << "The days is below the least.";
		}
		else if (choose == 4)
		{
			cout << "please enter the money you want." << endl;
			cin >> balance;
			cout << "please enter the days you want." << endl;
			cin >> day;
			if (balance >= 50000 && day >= 365)
				a_user.F_M(balance, 0.0440, day);
			else if (balance < 50000)
				cout << "The money is below the least.";
			else if (day < 365)
				cout << "The days is below the least.";
		}
	}
	else if (ans == 3)
	{
		a_user.b(g_user(name,a_user.r_b()));
	}
	return 0;
}