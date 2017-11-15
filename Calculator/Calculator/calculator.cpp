#include <QtGui>

#include "calculator.h"

Calculator::Calculator(QWidget *parent)
: QMainWindow(parent)
{
	setupUi(this);

	this->resize(345, 530);
	IsIn = false;
	board = QApplication::clipboard();
	dealButton();
	dealMenu();
}

void Calculator::dealMenu()
{
	QMenu *checkMenu = new QMenu(tr("查看(&V)"), newMenuBar);
	QMenu *editMenu = new QMenu(tr("编辑(&E)"), newMenuBar);
	QMenu *helpMenu = new QMenu(tr("帮助(&H)"), newMenuBar);
	copy = new QAction(tr("复制(&C)"), editMenu);
	paste = new QAction(tr("粘贴(&P)"), editMenu);
	help = new QAction(tr("帮助(&H)"), helpMenu);
	about = new QAction(tr("关于计算器(&A)"), helpMenu);
	connect(copy, SIGNAL(triggered()), this, SLOT(copyCal()));
	connect(paste, SIGNAL(triggered()), this, SLOT(pasteCal()));
	connect(help, SIGNAL(triggered()), this, SLOT(helpCal()));
	connect(about, SIGNAL(triggered()), this, SLOT(aboutCal()));
	editMenu->addAction(copy);
	editMenu->addAction(paste);
	helpMenu->addAction(help);
	helpMenu->addAction(about);
	newMenuBar->addMenu(checkMenu);
	newMenuBar->addMenu(editMenu);
	newMenuBar->addMenu(helpMenu);
}

void Calculator::aboutCal()
{
	QMessageBox::information(this, tr("About"),
		tr("By Aesma,QQ 676836533.  Qt 5.60"));
}

void Calculator::helpCal()
{
	QMessageBox::information(this, tr("Help"),
		tr("注意：\n算式里n代表√,s代表sin,c代表cos,t代表tan.\n进行pow运算的时候先按数字再按pow.\n百分号和取倒数还有平方只能在只有数字而且已经按过等号的时候使用."));
}

void Calculator::copyCal()
{
	board->setText(tempEqu + '\n' + QString::number(result));
}

void Calculator::pasteCal()
{
	QString str = board->text();
	textBrowser->setText(str);
}

void Calculator::dealButton()
{
	result = 0;
	eq = "#";
	tempEqu = "";
	connect(exFiveButton, SIGNAL(clicked()), this, SLOT(exFive()));
	connect(sqrtButton, SIGNAL(clicked()), this, SLOT(doSqrt()));
	connect(squreButton, SIGNAL(clicked()), this, SLOT(doSquare()));
	connect(recButton, SIGNAL(clicked()), this, SLOT(rec()));
	connect(leftBraButton, SIGNAL(clicked()), this, SLOT(leftBra()));
	connect(rightBraButton, SIGNAL(clicked()), this, SLOT(rightBra()));
	connect(powButton, SIGNAL(clicked()), this, SLOT(doPow()));
	connect(sinButton, SIGNAL(clicked()), this, SLOT(doSin()));
	connect(cosButton, SIGNAL(clicked()), this, SLOT(doCos()));
	connect(tanButton, SIGNAL(clicked()), this, SLOT(doTan()));
	connect(ceButton, SIGNAL(clicked()), this, SLOT(doCE()));
	connect(cButton, SIGNAL(clicked()), this, SLOT(doC()));
	connect(backButton, SIGNAL(clicked()), this, SLOT(back()));
	connect(exButton, SIGNAL(clicked()), this, SLOT(doEx()));
	connect(sevenButton, SIGNAL(clicked()), this, SLOT(seven()));
	connect(eightButton, SIGNAL(clicked()), this, SLOT(eight()));
	connect(nineButton, SIGNAL(clicked()), this, SLOT(nine()));
	connect(mulButton, SIGNAL(clicked()), this, SLOT(doMul()));
	connect(fourButton, SIGNAL(clicked()), this, SLOT(four()));
	connect(fiveButton, SIGNAL(clicked()), this, SLOT(five()));
	connect(sixButton, SIGNAL(clicked()), this, SLOT(six()));
	connect(redButton, SIGNAL(clicked()), this, SLOT(doRed()));
	connect(oneButton, SIGNAL(clicked()), this, SLOT(one()));
	connect(twoButton, SIGNAL(clicked()), this, SLOT(two()));
	connect(threeButton, SIGNAL(clicked()), this, SLOT(three()));
	connect(plusButton, SIGNAL(clicked()), this, SLOT(doPlus()));
	connect(negButton, SIGNAL(clicked()), this, SLOT(doNeg()));
	connect(zeroButton, SIGNAL(clicked()), this, SLOT(zero()));
	connect(decButton, SIGNAL(clicked()), this, SLOT(dec()));
	connect(equButton, SIGNAL(clicked()), this, SLOT(equal()));
	connect(mplusButton, SIGNAL(clicked()), this, SLOT(doMPlus()));
	connect(mreButton, SIGNAL(clicked()), this, SLOT(doMRed()));
	connect(mButton, SIGNAL(clicked()), this, SLOT(doM()));

	textBrowser->setStyleSheet("border :1px; background:(0x00,0xff,0x00,0x00);font-size :42px");
	mcButton->setStyleSheet("QPushButton{border :1px;background-color:white}""QPushButton:hover{background-color:#E0E0E0;}""QPushButton:pressed{background-color:#D4D4D4;border - style: inset; }");
	mrButton->setStyleSheet("QPushButton{border :1px;background-color:white}""QPushButton:hover{background-color:#E0E0E0;}""QPushButton:pressed{background-color:#D4D4D4;border - style: inset; }");
	mplusButton->setStyleSheet("QPushButton{border :1px;background-color:white}""QPushButton:hover{background-color:#E0E0E0;}""QPushButton:pressed{background-color:#D4D4D4;border - style: inset; }");
	mreButton->setStyleSheet("QPushButton{border :1px;background-color:white}""QPushButton:hover{background-color:#E0E0E0;}""QPushButton:pressed{background-color:#D4D4D4;border - style: inset; }");
	msButton->setStyleSheet("QPushButton{border :1px;background-color:white}""QPushButton:hover{background-color:#E0E0E0;}""QPushButton:pressed{background-color:#D4D4D4;border - style: inset; }");
	mButton->setStyleSheet("QPushButton{border :1px;background-color:white}""QPushButton:hover{background-color:#E0E0E0;}""QPushButton:pressed{background-color:#D4D4D4;border - style: inset; }");
	exFiveButton->setStyleSheet("QPushButton{border :1px;background-color:white}""QPushButton:hover{background-color:#E0E0E0;}""QPushButton:pressed{background-color:#D4D4D4;border - style: inset; }");
	sqrtButton->setStyleSheet("QPushButton{border :1px;background-color:white}""QPushButton:hover{background-color:#E0E0E0;}""QPushButton:pressed{background-color:#D4D4D4;border - style: inset; }");
	squreButton->setStyleSheet("QPushButton{border :1px;background-color:white}""QPushButton:hover{background-color:#E0E0E0;}""QPushButton:pressed{background-color:#D4D4D4;border - style: inset; }");
	recButton->setStyleSheet("QPushButton{border :1px;background-color:white}""QPushButton:hover{background-color:#E0E0E0;}""QPushButton:pressed{background-color:#D4D4D4;border - style: inset; }");
	leftBraButton->setStyleSheet("QPushButton{border :1px;background-color:white}""QPushButton:hover{background-color:#E0E0E0;}""QPushButton:pressed{background-color:#D4D4D4;border - style: inset; }");
	rightBraButton->setStyleSheet("QPushButton{border :1px;background-color:white}""QPushButton:hover{background-color:#E0E0E0;}""QPushButton:pressed{background-color:#D4D4D4;border - style: inset; }");
	powButton->setStyleSheet("QPushButton{border :1px;background-color:#E3E3E3}""QPushButton:hover{background-color:#E0E0E0;}""QPushButton:pressed{background-color:#D4D4D4;border - style: inset; }");
	sinButton->setStyleSheet("QPushButton{border :1px;background-color:#E3E3E3}""QPushButton:hover{background-color:#E0E0E0;}""QPushButton:pressed{background-color:#D4D4D4;border - style: inset; }");
	cosButton->setStyleSheet("QPushButton{border :1px;background-color:#E3E3E3}""QPushButton:hover{background-color:#E0E0E0;}""QPushButton:pressed{background-color:#D4D4D4;border - style: inset; }");
	tanButton->setStyleSheet("QPushButton{border :1px;background-color:#E3E3E3}""QPushButton:hover{background-color:#E0E0E0;}""QPushButton:pressed{background-color:#D4D4D4;border - style: inset; }");
	ceButton->setStyleSheet("QPushButton{border :1px;background-color:#E3E3E3}""QPushButton:hover{background-color:#E0E0E0;}""QPushButton:pressed{background-color:#D4D4D4;border - style: inset; }");
	cButton->setStyleSheet("QPushButton{border :1px;background-color:#E3E3E3}""QPushButton:hover{background-color:#E0E0E0;}""QPushButton:pressed{background-color:#D4D4D4;border - style: inset; }");
	backButton->setStyleSheet("QPushButton{border :1px;background-color:#E3E3E3}""QPushButton:hover{background-color:#E0E0E0;}""QPushButton:pressed{background-color:#D4D4D4;border - style: inset; }");
	exButton->setStyleSheet("QPushButton{border :1px;background-color:#E3E3E3}""QPushButton:hover{background-color:#E0E0E0;}""QPushButton:pressed{background-color:#D4D4D4;border - style: inset; }");
	fourButton->setStyleSheet("QPushButton{border :1px;background-color:#E3E3E3}""QPushButton:hover{background-color:#E0E0E0;}""QPushButton:pressed{background-color:#D4D4D4;border - style: inset; }");
	mulButton->setStyleSheet("QPushButton{border :1px;background-color:#E3E3E3}""QPushButton:hover{background-color:#E0E0E0;}""QPushButton:pressed{background-color:#D4D4D4;border - style: inset; }");
	nineButton->setStyleSheet("QPushButton{border :1px;background-color:#E3E3E3}""QPushButton:hover{background-color:#E0E0E0;}""QPushButton:pressed{background-color:#D4D4D4;border - style: inset; }");
	eightButton->setStyleSheet("QPushButton{border :1px;background-color:#E3E3E3}""QPushButton:hover{background-color:#E0E0E0;}""QPushButton:pressed{background-color:#D4D4D4;border - style: inset; }");
	fiveButton->setStyleSheet("QPushButton{border :1px;background-color:#E3E3E3}""QPushButton:hover{background-color:#E0E0E0;}""QPushButton:pressed{background-color:#D4D4D4;border - style: inset; }");
	decButton->setStyleSheet("QPushButton{border :1px;background-color:#E3E3E3}""QPushButton:hover{background-color:#E0E0E0;}""QPushButton:pressed{background-color:#D4D4D4;border - style: inset; }");
	plusButton->setStyleSheet("QPushButton{border :1px;background-color:#E3E3E3}""QPushButton:hover{background-color:#E0E0E0;}""QPushButton:pressed{background-color:#D4D4D4;border - style: inset; }");
	oneButton->setStyleSheet("QPushButton{border :1px;background-color:#E3E3E3}""QPushButton:hover{background-color:#E0E0E0;}""QPushButton:pressed{background-color:#D4D4D4;border - style: inset; }");
	sixButton->setStyleSheet("QPushButton{border :1px;background-color:#E3E3E3}""QPushButton:hover{background-color:#E0E0E0;}""QPushButton:pressed{background-color:#D4D4D4;border - style: inset; }");
	twoButton->setStyleSheet("QPushButton{border :1px;background-color:#E3E3E3}""QPushButton:hover{background-color:#E0E0E0;}""QPushButton:pressed{background-color:#D4D4D4;border - style: inset; }");
	negButton->setStyleSheet("QPushButton{border :1px;background-color:#E3E3E3}""QPushButton:hover{background-color:#E0E0E0;}""QPushButton:pressed{background-color:#D4D4D4;border - style: inset; }");
	equButton->setStyleSheet("QPushButton{border :1px;background-color:#E3E3E3}""QPushButton:hover{background-color:#E0E0E0;}""QPushButton:pressed{background-color:#D4D4D4;border - style: inset; }");
	redButton->setStyleSheet("QPushButton{border :1px;background-color:#E3E3E3}""QPushButton:hover{background-color:#E0E0E0;}""QPushButton:pressed{background-color:#D4D4D4;border - style: inset; }");
	zeroButton->setStyleSheet("QPushButton{border :1px;background-color:#E3E3E3}""QPushButton:hover{background-color:#E0E0E0;}""QPushButton:pressed{background-color:#D4D4D4;border - style: inset; }");
	threeButton->setStyleSheet("QPushButton{border :1px;background-color:#E3E3E3}""QPushButton:hover{background-color:#E0E0E0;}""QPushButton:pressed{background-color:#D4D4D4;border - style: inset; }");
	sevenButton->setStyleSheet("QPushButton{border :1px;background-color:#E3E3E3}""QPushButton:hover{background-color:#E0E0E0;}""QPushButton:pressed{background-color:#D4D4D4;border - style: inset; }");
	mcButton->setStyleSheet("QPushButton{border :1px;background-color:#E3E3E3}""QPushButton:hover{background-color:#E0E0E0;}""QPushButton:pressed{background-color:#D4D4D4;border - style: inset; }");
	mrButton->setStyleSheet("QPushButton{border :1px;background-color:#E3E3E3}""QPushButton:hover{background-color:#E0E0E0;}""QPushButton:pressed{background-color:#D4D4D4;border - style: inset; }");
	textBrowser->setAlignment(Qt::AlignLeft);
	mcButton->setEnabled(false);
	mrButton->setEnabled(false);
}

void Calculator::exFive()
{
	if (result != 0){
		result = result / 100;
		tempEqu = QString::number(result);
	}
	else{
		double tempDou = tempEqu.toDouble();
		tempDou = tempDou / 100;
		tempEqu = QString::number(tempDou);
	}
	textBrowser->setText(tempEqu);
}

void Calculator::doSqrt()
{
	tempEqu += 'n';
	textBrowser->setText(tempEqu);
}

void Calculator::doSquare()
{
	result = result*result;
	QString num = QString::number(result);
	textBrowser->setText('\n' + num);
}

void Calculator::rec()
{
	result = 1 / result;
	QString num = QString::number(result);
	textBrowser->setText('\n' + num);
}

void Calculator::leftBra()
{
	tempEqu += '(';
	textBrowser->setText(tempEqu);
}

void Calculator::rightBra()
{
	tempEqu += ')';
	textBrowser->setText(tempEqu);
}

void Calculator::doPow()
{
	result = pow(result, powN);
	QString num = QString::number(result);
	textBrowser->setText('\n' + num);
}

void Calculator::doSin()
{
	tempEqu += 's';
	textBrowser->setText(tempEqu);
}

void Calculator::doCos()
{
	tempEqu += 'c';
	textBrowser->setText(tempEqu);
}

void Calculator::doTan()
{
	tempEqu += 't';
	textBrowser->setText(tempEqu);
}

void Calculator::doCE()
{
	tempEqu = "";
	result = 0;
	textBrowser->setText(tempEqu);
}

void Calculator::doC()
{
	tempEqu = tempEqu.left(tempEqu.length() - 1);
	textBrowser->setText(tempEqu);
}

void Calculator::back()
{
	tempEqu = tempEqu.left(tempEqu.length() - 1);
	textBrowser->setText(tempEqu);
}

void Calculator::doEx()
{
	tempEqu += '/';
	textBrowser->setText(tempEqu);
}

void Calculator::seven()
{
	if (result == 0){
		tempEqu += '7';
		textBrowser->setText(tempEqu);
	}
	powN = 7;
}

void Calculator::eight()
{
	if (result == 0){
		tempEqu += '8';
		textBrowser->setText(tempEqu);
	}
	powN = 8;
}

void Calculator::nine()
{
	if (result == 0){
		tempEqu += '9';
		textBrowser->setText(tempEqu);
	}
	powN = 9;
}

void Calculator::doMul()
{
	tempEqu += '*';
	textBrowser->setText(tempEqu);
}

void Calculator::four()
{
	if (result == 0){
		tempEqu += '4';
		textBrowser->setText(tempEqu);
	}
	powN = 4;
}

void Calculator::five()
{
	if (result == 0){
		tempEqu += '5';
		textBrowser->setText(tempEqu);
	}
	powN = 5;
}

void Calculator::six()
{
	if (result == 0){
		tempEqu += '6';
		textBrowser->setText(tempEqu);
	}
	powN = 6;
}

void Calculator::doRed()
{
	tempEqu += '-';
	textBrowser->setText(tempEqu);
}

void Calculator::one()
{
	if (result == 0){
		tempEqu += '1';
		textBrowser->setText(tempEqu);
	}
	powN = 1;
}

void Calculator::two()
{
	if (result == 0){
		tempEqu += '2';
		textBrowser->setText(tempEqu);
	}
	powN = 2;
}

void Calculator::three()
{
	if (result == 0){
		tempEqu += '3';
		textBrowser->setText(tempEqu);
	}
	powN = 3;
}

void Calculator::doPlus()
{
	tempEqu += '+';
	textBrowser->setText(tempEqu);
}

void Calculator::doNeg()
{
	result = 0 - result;
	QString num = QString::number(result);
	textBrowser->setText('\n' + num);
}

void Calculator::zero()
{
	if (result == 0){
		tempEqu += '0';
		textBrowser->setText(tempEqu);
	}
	powN = 0;
}

void Calculator::dec()
{
	tempEqu += '.';
	textBrowser->setText(tempEqu);
}

void Calculator::equal()
{
	if (tempEqu == ""){
		QMessageBox::warning(this, tr("WARNING"),
			tr("没有输入算式！"));
	}
	else{
		std::string str = tempEqu.toStdString();
		char *ch = (char*)str.c_str();
		for (int i = 0; i < strlen(ch); i++)
		{
			if (ch[i] == '0'&&ch[i - 1] == '/'){
				QMessageBox::warning(this, tr("WARNING"),
					tr("被除数不能为0！"));
				tempEqu = "";
				textBrowser->setText(tempEqu);

				return;
			}
		}
		eq += (tempEqu + '#');
		Calculate cal(eq);
		result = cal.getResult();
	}
	QString res = tempEqu + '\n' + QString::number(result);
	textBrowser->setText(res);
	tempEqu = "";
}

void Calculator::doMC()
{
	result = 0;
	IsIn = false;
	QString str = QString::number(result);
	textBrowser->setText(str);
	mDialog->doMC();
	mcButton->setEnabled(false);
	mrButton->setEnabled(false);
}

void Calculator::doMR()
{
	if (!IsIn){
		mDialog = new NewDialog;
	}
	mDialog->getResult(result);
	QString str = QString::number(result);
	textBrowser->setText(str);
}

void Calculator::doMPlus()
{
	if (!IsIn){
		mDialog = new NewDialog;
		mcButton->setEnabled(true);
		mrButton->setEnabled(true);
		IsIn = true;
		connect(mcButton, SIGNAL(clicked()), this, SLOT(doMC()));
		connect(mrButton, SIGNAL(clicked()), this, SLOT(doMR()));
		connect(mDialog, SIGNAL(isMC()), this, SLOT(allMc()));
		mDialog->inPutRes(result, IsIn);
	}
	mDialog->doPlus();
}

void Calculator::doMRed()
{
	if (!IsIn){
		mDialog = new NewDialog;
		mcButton->setEnabled(true);
		mrButton->setEnabled(true);
		IsIn = true;
		connect(mcButton, SIGNAL(clicked()), this, SLOT(doMC()));
		connect(mrButton, SIGNAL(clicked()), this, SLOT(doMR()));
		connect(mDialog, SIGNAL(isMC()), this, SLOT(allMc()));
		mDialog->inPutRes(result, IsIn);
	}
	mDialog->doRed();
}

void Calculator::doM()
{
	if (!IsIn){
		mDialog = new NewDialog;
		connect(mDialog, SIGNAL(isMC()), this, SLOT(allMc()));
	}
	mDialog->show();
}

void Calculator::allMc()
{
	mcButton->setEnabled(false);
	mrButton->setEnabled(false);
	result = 0;
	tempEqu = "";
	eq = "";
	backEqu = "";

	textBrowser->setText(tr(""));
}

void Calculator::paintEvent(QPaintEvent *event)
{
	double h = height() - 30;
	h = 4 * h / 5;
	textBrowser->setGeometry(QRect(0, 0, width(), (height()) / 5));
	mcButton->setGeometry(QRect(0, (height()) / 5, width() / 6, h / 14));
	mrButton->setGeometry(QRect(width() / 6, height() / 5, width() / 6, h / 14));
	mplusButton->setGeometry(QRect(2 * width() / 6, height() / 5, width() / 6, h / 14));
	mreButton->setGeometry(QRect(3 * width() / 6, height() / 5, width() / 6, h / 14));
	msButton->setGeometry(QRect(4 * width() / 6, height() / 5, width() / 6, h / 14));
	mButton->setGeometry(QRect(5 * width() / 6, height() / 5, width() / 6, h / 14));
	exFiveButton->setGeometry(QRect(0, h / 14 + height() / 5, width() / 6, h / 14));
	sqrtButton->setGeometry(QRect(width() / 6, h / 14 + height() / 5, width() / 6, h / 14));
	squreButton->setGeometry(QRect(2 * width() / 6, h / 14 + height() / 5, width() / 6, h / 14));
	recButton->setGeometry(QRect(3 * width() / 6, h / 14 + height() / 5, width() / 6, h / 14));
	leftBraButton->setGeometry(QRect(4 * width() / 6, h / 14 + height() / 5, width() / 6, h / 14));
	rightBraButton->setGeometry(QRect(5 * width() / 6, h / 14 + height() / 5, width() / 6, h / 14));
	powButton->setGeometry(QRect(0, 2 * h / 14 + height() / 5, width() / 4, h / 7));
	sinButton->setGeometry(QRect(width() / 4, 2 * h / 14 + height() / 5, width() / 4, h / 7));
	cosButton->setGeometry(QRect(2 * width() / 4, 2 * h / 14 + height() / 5, width() / 4, h / 7));
	tanButton->setGeometry(QRect(3 * width() / 4, 2 * h / 14 + height() / 5, width() / 4, h / 7));
	ceButton->setGeometry(QRect(0, h / 7 + 2 * h / 14 + height() / 5, width() / 4, h / 7));
	cButton->setGeometry(QRect(width() / 4, h / 7 + 2 * h / 14 + height() / 5, width() / 4, h / 7));
	backButton->setGeometry(QRect(2 * width() / 4, h / 7 + 2 * h / 14 + height() / 5, width() / 4, h / 7));
	exButton->setGeometry(QRect(3 * width() / 4, h / 7 + 2 * h / 14 + height() / 5, width() / 4, h / 7));
	sevenButton->setGeometry(QRect(0, 2 * h / 7 + 2 * h / 14 + height() / 5, width() / 4, h / 7));
	eightButton->setGeometry(QRect(width() / 4, 2 * h / 7 + 2 * h / 14 + height() / 5, width() / 4, h / 7));
	nineButton->setGeometry(QRect(2 * width() / 4, 2 * h / 7 + 2 * h / 14 + height() / 5, width() / 4, h / 7));
	mulButton->setGeometry(QRect(3 * width() / 4, 2 * h / 7 + 2 * h / 14 + height() / 5, width() / 4, h / 7));
	fourButton->setGeometry(QRect(0, 3 * h / 7 + 2 * h / 14 + height() / 5, width() / 4, h / 7));
	fiveButton->setGeometry(QRect(width() / 4, 3 * h / 7 + 2 * h / 14 + height() / 5, width() / 4, h / 7));
	sixButton->setGeometry(QRect(2 * width() / 4, 3 * h / 7 + 2 * h / 14 + height() / 5, width() / 4, h / 7));
	redButton->setGeometry(QRect(3 * width() / 4, 3 * h / 7 + 2 * h / 14 + height() / 5, width() / 4, h / 7));
	oneButton->setGeometry(QRect(0, 4 * h / 7 + 2 * h / 14 + height() / 5, width() / 4, h / 7));
	twoButton->setGeometry(QRect(width() / 4, 4 * h / 7 + 2 * h / 14 + height() / 5, width() / 4, h / 7));
	threeButton->setGeometry(QRect(2 * width() / 4, 4 * h / 7 + 2 * h / 14 + height() / 5, width() / 4, h / 7));
	plusButton->setGeometry(QRect(3 * width() / 4, 4 * h / 7 + 2 * h / 14 + height() / 5, width() / 4, h / 7));
	negButton->setGeometry(QRect(0, 5 * h / 7 + 2 * h / 14 + height() / 5, width() / 4, h / 7));
	zeroButton->setGeometry(QRect(width() / 4, 5 * h / 7 + 2 * h / 14 + height() / 5, width() / 4, h / 7));
	decButton->setGeometry(QRect(2 * width() / 4, 5 * h / 7 + 2 * h / 14 + height() / 5, width() / 4, h / 7));
	equButton->setGeometry(QRect(3 * width() / 4, 5 * h / 7 + 2 * h / 14 + height() / 5, width() / 4, h / 7));
}

Calculator::~Calculator()
{

}
