#pragma warning(disable:6031)
#include <iostream>
#include <fstream>
#include <windows.h>
#include <iomanip>
#include <cstdlib>
#include <string>
#include "const.h"
#include "login_acct.h"
#include <conio.h>
#include <map>
using namespace std;
struct returned {
	bool flag;
	int a;
	string username;
};
struct returned r;
returned step2()
{
	login logs;
	login* f = &logs;
	char ch;
	int ans;
	cout << begin_1;
	cout << begin_2;
	cout << "please enter 0 to exit , 1 to into the administration , 2 to into the customer\n";
	ch = _getch();
	ans = ch - '0' ;
	system("cls");
	if (ans == 0)
	{
		exit(0);
	}
	else if (ans == 1)
	{
		r.a = 1;
		book teacher;
		teacher = logs.get();
		if (teacher.username == "admin" && teacher.password == "123456")
		{
			system("cls");
			cout << "Welcome administrator." << endl;
			r.flag = true;
		}
		else
		{
			system("cls");
			cout << "Wrong answer!" << endl;
		}
	}
	else if (ans == 2)
	{
		r.a = 2;
		book books = logs.get();
		if (logs.check(books))
		{
			cout << "welcome back !" << endl;
			Sleep(200);
			system("cls");
			r.flag = true;
			r.username = logs.encipher(books.username);
		}
	}
	else
	{
		r.a = 3;
	}
	cout << "Press any key to continue . . .\n";
	_getch();
	system("cls");
	return r;
}