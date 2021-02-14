#include <string>
#include "Financial management.h"
#include <conio.h>
#include "stock.h"
using namespace std;
struct re {
	string name, num;
	double price;
	int number;
};
struct re e;
re show()
{
	cout << "Please enter the number of this stock:";
	cin >> e.num;
	cout << "Please enter the name of this stock:";
	cin >> e.name;
	cout << "Please enter the price of this stock:";
	cin >> e.price;
	cout << "Please enter the numbers of this stock:";
	cin >> e.number;
	if (e.number % 100 != 0 || e.number <= 0)
		throw "The input number must be a positive number and is multiple of 100 .";
	return e;
}
double g_user(string name, double balance) {
	system("cls");
	S s(name,balance);
	char ch;
	int ans;
	double balances;
	cout << "Which kind of things do you want?(0 to back)" << endl;
	cout << "\t 1.BUY" << endl;
	cout << "\t 2.SELL" << endl;
	ch = _getch();
	ans = ch - '0';
	system("cls");
	if (ans == 0)
	{
		return 0;
	}
	else if (ans == 1)
	{
		system("cls");
		re e;
		while (1)
		{
			try {
				e = show();
				break;
			}
			catch(const char* s){
				cout << s << endl;
				cout << "Please enter the number again or 0 to Re-enter.";
				cin >> e.number;
				if (e.number == 0)
					return 0;
				else 
					break;
			}
		}
		s.buy(e.name, e.num, e.price, e.number / 100);
	}
	else if (ans == 2)
	{
		system("cls");
		re e;
		while (1)
		{
			try {
				e = show();
				break;
			}
			catch (const char* s) {
				cout << s << endl;
				cout << "Please enter the number again or 0 to Re-enter.";
				cin >> e.number;
				if (e.number == 0)
					return 0;
				else
					break;
			}
		}
			s.sell(e.name, e.num, e.price, e.number / 100);	
	}
	balances = s.re();
	return balances;
}