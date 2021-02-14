#include "Financial management.h"
#include "date.h"
using std::ios;
Time times;


F::F(const string f)
{
	
	double rate, value;
	int date;
	acctnum = f;
	ifstream user;
	user.open(f + ".txt", ios_base::in | ios_base::binary);
	if (user.is_open())
	{
		cout << " Initialization is done." << endl;
		user >> balance;
		int i = 0;
		for (int i = 0; user >> value >> rate >> date; i++)
		{
			record[i].balance = value;
			record[i].rate = rate;
			record[i].days = date;
		}
	}
	else
	{
		cout << " Initialization is wrong." << endl;
	}
	show();
}

void F::F_M(double value, double r, int day)
{
	int i;
	if (balance > value)
	{
		for (i = 0; record[i].days != 0; i++);
		record[i].balance = value;
		record[i].rate = r;
		record[i].days = day+ times.date(times.trans());
		balance -= value;
	}
	else
		cout << "You don't have the enough balance to buy it ." << endl;
}

void F::Deposit(double money)
{
	if (money > 0)
	{
		balance += money;
	}
	else
		cout << "money must be a positive number.";
}

void F::show()
{
	for (int i = 0; i < 200; i++)
	{
		if (record[i].days <= times.date(times.trans()) && record[i].days != 0)
		{
			balance += record[i].balance * (1 + record[i].rate);
			record[i].balance = record[i].rate = 0.0;
			record[i].days = 0;
		}
	}
	cout << acctnum << " welcome!" << endl;
	cout << "your account's balance is " << balance << " $" << endl;
	cout << "Here are your other service:" << endl;
	for (int i = 0; i < 200; i++)
	{
		if (record[i].days != 0)
		{
			cout << "          at the" << times.back(record[i].days);
			cout << "principal is " << record[i].balance << "rate is " << record[i].rate << endl;
		}
	}
	cout << endl << endl;
}

F::~F()
{
	ofstream fout;
	fout.open(acctnum + ".txt", ios::out | ios::trunc);
	if (!fout.is_open())
	{
		std::cerr << "open the file faild" << endl;
	}
	fout << balance << " ";
	for (int i = 0; i < 200; i++)
	{
		if (record[i].days != 0)
		{
			fout << record[i].balance << " " << record[i].rate << " " << record[i].days << endl;
		}
	}
	fout.close();
}
