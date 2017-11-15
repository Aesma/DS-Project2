#ifndef CALCULATOR_H
#define CALCULATOR_H

#pragma execution_character_set("utf-8")

#include <QMainWindow>
#include <QMessageBox>
#include <QClipboard>
#include <QFont>
#include <cmath>

#include "ui_calculator.h"
#include "LinkedStack.h"
#include "calculate.h"
#include "mDialog.h"

class Calculator : public QMainWindow,public Ui::CalculatorClass
{
	Q_OBJECT
public:
	Calculator(QWidget *parent = 0);
	void dealMenu();
	void dealButton();
	~Calculator();
private slots:
	void helpCal();
	void aboutCal();
	void copyCal();
	void pasteCal();
protected slots:
	void exFive();
	void doSqrt();
	void doSquare();
	void rec();
	void leftBra();
	void rightBra();
	void doPow();
	void doSin();
	void doCos();
	void doTan();
	void doCE();
	void doC();
	void back();
	void doEx();
	void seven();
	void eight();
	void nine();
	void doMul();
	void four();
	void five();
	void six();
	void doRed();
	void one();
	void two();
	void three();
	void doPlus();
	void doNeg();
	void zero();
	void dec();
	void equal();
	void doMC();
	void doMR();
	void doMPlus();
	void doMRed();
	void doM();
	void allMc();
protected:
	void paintEvent(QPaintEvent *event);
private:
	QAction *copy;
	QAction *paste;
	QAction *help;
	QAction *about;
	QString eq;
	QString tempEqu;
	QString backEqu;
	QClipboard *board;
	NewDialog *mDialog;
private:
	int powN;
	bool IsIn;
	double result;
};

#endif // CALCULATOR_H
