#include "stock.h"
#include <Windows.h>
S::S(const string f, double b) : F(f)
{
	string file = acctnum + "s.txt";
	balance = b;
	ifstream fin;
	fin.open(file, ios_base::in | ios_base::binary);
	if (fin.is_open())
	{
		cout << " Initialization is done." << endl;
		int i = 0;
		for (i = 0; fin >> stock[i].s_name >> stock[i].s_num >> stock[i].price >> stock[i].hands; i++);
	}
	else
	{
		cout << " Initialization is wrong." << endl;
	}
	show();
}

void S::buy(string name, string num, double p, int h)
{
	int i;
	for (i = 0; stock[i].hands != 0; i++);
	stock[i].s_name = name;
	stock[i].s_num = num;
	stock[i].price = p;
	stock[i].hands = h;
	show();
	Sleep(200);
}

void S::sell(string name, string num, double p, int h)
{
	int i;
	for (i = 0; stock[i].s_num != num; i++);
	if (h > 0 && h < stock[i].hands)
	{
		stock[i].hands -= h;
		balance += h * p;
	}
	show();
	Sleep(200);
}

void S::show()
{
	cout << acctnum << " welcome!" << endl;
	cout << "your account's balance is " << balance << " $" << endl;
	cout << "Here are your stock service:" << endl;
	for (int i = 0; i < 200; i++)
	{
		if (stock[i].hands != 0)
		{
			cout << "You have the " << stock[i].hands*100 << " numbers " << stock[i].s_name << "which was bought for " << stock[i].price << " per unit" << endl;
		}
	}
	cout << endl << endl;
}

S::~S()
{
	ofstream fout;
	fout.open(acctnum + "s.txt", ios_base::out | ios_base::trunc);
	if (!fout.is_open())
	{
		std::cerr << "open the file faild" << endl;
	}
	for (int i = 0; i < 200; i++)
	{
		if (stock[i].hands != 0)
		{
			fout << stock[i].s_name << " " << stock[i].s_num << " " << stock[i].price << " " << stock[i].hands << endl;
		}
	}
	fout.close();
}
