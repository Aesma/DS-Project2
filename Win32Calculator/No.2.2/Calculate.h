#pragma once

#include "LinkedStack.h"

class Calculate
{
public:
	Calculate(string e);
	void doCal();
	double getRes();
	~Calculate();
private:
	LinkedStack<Operator>sta_o;
	LinkedStack<double>sta_n;
	char* equ;
	double result;
};
