#include <iostream>
using namespace std;
struct returned {
	bool flag = false;
	int a = 1000;
	string name;
};
struct returned a;
int administrator();
void step1();
int user(string name);
returned step2();
int main(void)
{
	step1();
	pp:a = step2();
	if (a.flag && a.a == 1)
	{
	cc:if (!administrator())
		goto pp;
	   else
		goto cc;
	}
	else if (a.flag && a.a == 2)
	{
	dd:if(!user(a.name))
			goto dd;
		else
			goto pp;
	}
	else
	{
		goto pp;
	}
	return 0;
}