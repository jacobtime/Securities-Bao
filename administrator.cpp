#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include <iomanip>
#include "login_acct.h"
using std::ios_base;
using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::ifstream;
using std::ofstream;
int administrator()
{
	login log;
	login* f = &log;
	char ch;
	int ans;
	system("cls");
	cout << "Please enter the number to choose which function do you want :" << endl;
	cout << "\t0.back\t1.show the customer's admin\t2.add a customer" << endl;
	ch = _getch();
	ans = ch - '0';
	system("cls");
	if (ans == 0)
	{
		return 0;
	}
	else if (ans == 1)
	{
		log.show();
	}
	else if (ans == 2)
	{
		log.write();
	}
	return 1;
}
