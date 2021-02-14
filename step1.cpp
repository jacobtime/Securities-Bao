#include <iostream>
#include <windows.h>
#include <iomanip>
#include <conio.h>
#include <conio.h>
using namespace std;
void step1()
{
	cout << "###############################################################################################################\n";
	cout << "                                       Welcome to Securities Bao system                   \n";
	cout << "  Help£ºThis system could help you using your wealth to get more profits from stock or financial management.";
	cout << "\n";
	cout << "\n";
	cout << "\n";
	cout << "\n";
	cout << "\n";
	cout << "\n";
	cout << "\n";
	cout << "\n";
	cout << "\n";
	cout << "\n";
	cout << "\n";
	cout << "\n";
	cout << "\n";
	for (int i = 1; i <= 100; i++)
	{
		cout << "loading ......   " << setw(3) << i << "%" << " have done";
		Sleep(150);
		cout << "\r";
	}
	cout << "\r";
	cout << "                                                            ";
	cout << "\r";
	cout << "loading is done";
	Sleep(500);
	cout << "\r";
	cout << "Welcome to Securities Bao system ";
	cout << "\n";
	cout << "                                                   2019 Àî¾°ÌÎ 8002118060 Èí¹¤3°à finished at 6/22\n";
	cout << "              This sofeware is made by jacob lee who is in Nanchang University School of Software\n";
	cout << "                                                                             Formal Edition      \n";
	cout << "                                                                             3.10 release        \n";
	cout << "                                                                             All Rights Reserved.\n";
	cout << "###############################################################################################################\n";
	cout << "Press any key to continue . . .\n";
	_getch();
	system("cls");
	return;
}