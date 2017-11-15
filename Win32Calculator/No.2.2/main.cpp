
#include "stdafx.h"
#include "Calculate.h"

int _tmain(int argc, _TCHAR* argv[])
{
	string equ;
	cout << "Please enter the equ(like #1*2#) :";
	cin >> equ;
	Calculate cal(equ);
	cout << cal.getRes();
	system("pause");

	return 0;
}
