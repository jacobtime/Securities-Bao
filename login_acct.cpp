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
//��map�еı�����Ϊ�����ܵģ��ļ��о�Ϊ��������

book login::get()//��ʼ����ȡ���棬����û������˻��Լ����룬����Ϊ������ֵ
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
void login::show()//չʾ�û������ƺ�����
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
string& login::encipher(string& a) //����
{
	for (int i = 0; i < a.size(); i++)
		a[i] -= i/2 + 2;
	return a;
}
string& login::deciphering(string& a)//����
{
	for (int i = 0; i < a.size(); i++)
		a[i] += i/2 + 2;
	return a;
}
bool login::get_new(book book2){//�����û�д��map��
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
void login::write()//�½��û��ļ���д���û�������
{
	book book1 = get();
	if (get_new(book1))//��ȡ�û�
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
void login::read() {//��ȡ�ļ����û���map
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
bool login::check(book book1) {//�жϵ�¼�Ƿ���ȷ
	read();
	map<string, string>::iterator it = acct.find(book1.username);
	if (it != acct.end())
	{
		if (it->second == book1.password)
			return true;
	}
	return false;
}
