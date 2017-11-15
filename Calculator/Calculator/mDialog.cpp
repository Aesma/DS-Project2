#include <QtGui>

#include "mDialog.h"

NewDialog::NewDialog(QWidget *parent)
:QDialog(parent)
{
	setupUi(this);

	connect(mcButton, SIGNAL(clicked()), this, SLOT(doMC()));
	connect(mPlusButton, SIGNAL(clicked()), this, SLOT(doPlus()));
	connect(mRedButton, SIGNAL(clicked()), this, SLOT(doRed()));

	dealDialog();
}

void NewDialog::inPutRes(double res, bool IsIn)
{
	if (IsIn){
		result = res;
		tempRes = result;
		QString str = QString::number(result);
		textBrowser->setText(str);
		mcButton->show();
		mPlusButton->show();
		mRedButton->show();
	}
	else{
		textBrowser->setText(tr("内存中没有内容"));
	}
}

void NewDialog::getResult(double &res)
{
	res = result;
}

void NewDialog::doMC()
{
	result = 0;
	textBrowser->setText(tr("内存中没有内容"));
	mcButton->hide();
	mPlusButton->hide();
	mRedButton->hide();

	emit isMC();
}

void NewDialog::doPlus()
{
	result += tempRes;
	QString str = QString::number(result);
	textBrowser->setText(str);
}

void NewDialog::doRed()
{
	result -= tempRes;
	QString str = QString::number(result);
	textBrowser->setText(str);
}

void NewDialog::dealDialog()
{
	textBrowser->setStyleSheet("border :1px; background:#F0F0F0;font-size :36px");
	mcButton->setStyleSheet("QPushButton{border :1px;background-color:#F0F0F0}""QPushButton:hover{background-color:#E0E0E0;}""QPushButton:pressed{background-color:#D4D4D4;border - style: inset; }");
	mPlusButton->setStyleSheet("QPushButton{border :1px;background-color:#F0F0F0}""QPushButton:hover{background-color:#E0E0E0;}""QPushButton:pressed{background-color:#D4D4D4;border - style: inset; }");
	mRedButton->setStyleSheet("QPushButton{border :1px;background-color:#F0F0F0}""QPushButton:hover{background-color:#E0E0E0;}""QPushButton:pressed{background-color:#D4D4D4;border - style: inset; }");
}

void NewDialog::paintEvent(QPaintEvent *event)
{
	textBrowser->setGeometry(QRect(0, 0, width(), height() * 0.67));
	mcButton->setGeometry(QRect(width() / 2, 0, width() / 6, height() * 0.25));
	mPlusButton->setGeometry(QRect(width() / 6 + width() / 2, 0, width() / 6, height() * 0.25));
	mRedButton->setGeometry(QRect(2 * width() / 6 + width() / 2, 0, width() / 6, height() * 0.25));
}

NewDialog::~NewDialog()
{

}