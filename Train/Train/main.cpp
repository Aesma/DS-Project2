#include "stdafx.h"
#include "Train.h"
#include <iostream>
using namespace std;

#define K 3

int _tmain(int argc, _TCHAR* argv[])
{
	int n;
	cout << "�����복����:";
	cin >> n;
	Train train(n, K);
	train.trainSport();

	system("pause");

	return 0;
}

