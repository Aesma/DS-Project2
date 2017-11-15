#ifndef MDIALOG_H
#define MDIALOG_H

#pragma execution_character_set("utf-8")

#include <QDialog>

#include "ui_mDialog.h"

class NewDialog :public QDialog, public Ui::mDialog
{
	Q_OBJECT
public:
	NewDialog(QWidget *parent = 0);
	void dealDialog();
	void inPutRes(double res, bool IsIn);
	void getResult(double &res);
	~NewDialog();
public slots:
	void doPlus();
	void doRed();
	void doMC();
signals:
	void isMC();
protected:
	void paintEvent(QPaintEvent *event);
private:
	double result;
	double tempRes;
};

#endif