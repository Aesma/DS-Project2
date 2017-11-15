#pragma once

#include <cmath>
#include <QString>
#include "LinkedStack.h"

class Calculate
{
public:
	Calculate(QString E);
	void getBackEqu();
	void doCal();
	double getResult();
	~Calculate();
private:
	QString eq;
	QString backEqu;
	double result;
	LinkedStack<double>sta_n;
};