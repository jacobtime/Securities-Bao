#pragma warning(disable:C6031)
#pragma warning(disable:C4018)
#include "login_acct.h"
#include <vector>
#include "const.h"
#include <conio.h>
#include <fstream>
#include <iomanip>
const char* file = "username.txt";
using std::vector;
//在map中的变量均为不加密的，文件中均为加密内容

book login::get()//初始化读取界面，获得用户输入账户以及密码，返回为不加密值
{
	book book1;
	char ch;
	cout << begin_1 << begin_2 << endl;
	cout << "user:";
	cin >> book1.username;
	cout << endl;
	cout << "password:";
	int i = 0;
	ch = _getch();
	while (ch != '\r')
	{
		if (ch == '\b')
		{
			cout << '\b';
			--i;
			book1.password.erase(book1.password.end() - 1);
			system("cls");
			cout << begin_1 << begin_2 << endl;
			cout << "user:" << book1.username << endl << endl;
			cout << "password:";
			for (int k = 0; k < i; k++)
			{
				putchar('*');
			}
		}

		else
		{
			cout << '*';
			book1.password += ch;
			i++;
		}
		ch = _getch();
	}
	cout << endl;
	return book1;
}
void login::show()//展示用户名名称和数量
{
	string user;
	string pass;
	ifstream fin;
	fin.open(file, ios_base::in | ios_base::binary);
	int num = 0;
	cout << "admin:" << endl;
	if (fin.is_open())
	{
		while (fin >> user >> pass)
		{
			user = deciphering(user);
			pass = deciphering(pass);
			acct[pass] = user;
			cout << setw(20) << user << endl;
			num++;
		}
	}
	else
	{
		cerr << "message: open the username.txt failed!\n";
	}
	cout << "There are " << num << " people in the list ." << endl;
	cout << "Press any key to continue . . .\n" << setw(0);
	_getch();
	system("cls");
	fin.close();
}
string& login::encipher(string& a) //加密
{
	for (int i = 0; i < a.size(); i++)
		a[i] -= i/2 + 2;
	return a;
}
string& login::deciphering(string& a)//解密
{
	for (int i = 0; i < a.size(); i++)
		a[i] += i/2 + 2;
	return a;
}
bool login::get_new(book book2){//将新用户写入map中
	if (acct.find(book2.username) == acct.end())
	{
		acct[book2.username] = book2.password;
		return true;
	}
	else
	{
		cout << "User is exist! Try another please." << endl;
		return false;
	}
}
void login::write()//新建用户文件，写入用户名单表
{
	book book1 = get();
	if (get_new(book1))//获取用户
	{
		ofstream fout;
		fout.open(file, ios_base::out | ios_base::app);
		if (!fout.is_open())
		{
			cerr << "open the file faild" << endl;
		}
		book1.username = encipher(book1.username);
		book1.password = encipher(book1.password);
		fout << book1.username << ' ' << book1.password << endl;
		ofstream _new;
		_new.open(book1.username + ".txt", ios::out | ios::app | ios::binary);
		if (_new.is_open())
		{
			_new << (double)0;
			_new.close();
		}
		else
		{
			cout << "write " << book1.username << ".txt failed!";
		}
		fout.close();
		cout << "write succeed!";
	}
	else
	{
		cerr << "get failed" << endl;
	}
}
void login::read() {//读取文件中用户到map
	string user;
	string pass;
	ifstream fin;
	fin.open(file, ios_base::in | ios_base::binary);
	if (fin.is_open())
	{
		while (fin >> user >> pass)
		{
			user = deciphering(user);
			pass = deciphering(pass);
			acct[user] = pass;
		}
	}
	else
	{
		cerr << "message: open the username.txt failed!\n";
	}
}
bool login::check(book book1) {//判断登录是否正确
	read();
	map<string, string>::iterator it = acct.find(book1.username);
	if (it != acct.end())
	{
		if (it->second == book1.password)
			return true;
	}
	return false;
}
