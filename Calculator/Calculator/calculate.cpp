#include "calculate.h"

Calculate::Calculate(QString E)
{
	eq = E;
	backEqu = "";
}

void Calculate::doCal()
{
	char *ch = new char[backEqu.length()];
	std::string str = backEqu.toStdString();
	ch = (char*)str.c_str();
	int i = 0;
	int j = 1;
	double tempNum = 0;
	while (i < strlen(ch))
	{
		if (!(ch[i] >= '0'&&ch[i] <= '9') && ch[i] != '.'&&ch[i] != ' '&&!(ch[i] == '-'&&ch[i - 1] == ' ')){
			j = 1;
			if (ch[i] != 'n'&&ch[i] != 's'&&ch[i] != 'c'&&ch[i] != 't'){
				double num1;
				double num2;
				sta_n.Pop(num1);
				sta_n.Pop(num2);
				switch (ch[i])
				{
				case '+':
					result = (num2 + num1);
					break;
				case '-':
					result = (num2 - num1);
					break;
				case '*':
					result = (num2 * num1);
					break;
				case '/':
					result = (num2 / num1);
					break;
				default:
					break;
				}
			}
			else{
				double num;
				sta_n.Pop(num);
				switch (ch[i])
				{
				case 'n':
					result = sqrt(num);
					break;
				case 's':
					result = sin(num);
					break;
				case 'c':
					result = cos(num);
					break;
				case 't':
					result = tan(num);
					break;
				default:
					break;
				}
			}
			sta_n.Push(result);
			i++;
		}
		if (i == strlen(ch)){
			break;
		}
		if (ch[i] == '-'&&ch[i - 1] == ' '){
			i++;
			continue;
		}
		if ((ch[i] >= '0'&&ch[i] <= '9') || ch[i] == '.' || ch[i] == ' '){
			if (ch[i] == '.' || ch[i] == ' '){
				i++;
				continue;
			}
			else if (ch[i - 1] == '-'&& ch[i - 2] == ' '){
				tempNum = 0 - (ch[i] - '0');
			}
			else if (ch[i - j] == '.'){
				double t = ch[i] - '0';
				if (tempNum >= 0){
					tempNum += t / pow(10, j);
				}
				else{
					tempNum = tempNum - t / pow(10, j);;
				}
				j++;
			}
			else if (ch[i - 1] >= 48 && ch[i - 1] <= 57){
				if (tempNum >= 0){
					tempNum = tempNum * 10 + (ch[i] - '0');
				}
				else{
					tempNum = tempNum * 10 - (ch[i] - '0');
				}
			}
			else{
				tempNum = ch[i] - '0';
			}
			i++;
			if (!(ch[i] >= 48 && ch[i] <= 57) && ch[i] != '.'){
				sta_n.Push(tempNum);
				tempNum = 0;
			}
		}
	}
	if (!sta_n.IsEmpty()){
		sta_n.Pop(result);
	}
}

void Calculate::getBackEqu()
{
	backEqu = "";
	char *ch = new char[eq.length()];
	LinkedStack<Operator>stack;
	std::string str = eq.toStdString();
	ch = (char*)str.c_str();
	int i = 0;
	int j = 1;
	double tempNum = 0;
	int len = eq.length();
	Operator op(ch[i++]);
	stack.Push(op);
	while (!stack.IsEmpty())
	{
		if (ch[i] >= 48 && ch[i] <= 57 || (ch[i] == '-'&&ch[i - 1] == '(')){
			if ((i > 2 && (ch[i - 2] == '(' && ch[i - 1] == '-')) || (i == 2 && ch[1] == '-')){
				tempNum = 0 - (ch[i] - '0');
			}
			else if (ch[i - j] == '.'){
				double t = ch[i] - '0';
				if (tempNum >= 0){
					tempNum += t / (pow(10, j));
				}
				else{
					tempNum = tempNum - t / (pow(10, j));
				}
				j++;
			}
			else if (ch[i - 1] >= 48 && ch[i - 1] <= 57){
				if (tempNum >= 0){
					tempNum = tempNum * 10 + (ch[i] - '0');
				}
				else{
					tempNum = tempNum * 10 - (ch[i] - '0');
				}
			}
			else{
				tempNum = ch[i] - '0';
			}
			i++;
			if (!(ch[i] >= 48 && ch[i] <= 57) && ch[i] != '.'){
				QString num = QString::number(tempNum);
				backEqu += (' ' + num);
				tempNum = 0;
			}
		}
		if (ch[i] == '.')
			i++;
		if (i == strlen(ch)){
			break;
		}
		if ((ch[i]<'0' || ch[i]>'9') && ch[i] != '.'){
			if ((ch[i] == '-' && (ch[i - 1]<'0' || ch[i - 1]>'9'))){
				i++;
				continue;
			}
			j = 1;
			Operator tempOp(ch[i]);
			Operator temp;
			stack.getTop(temp);
			if (tempOp >= temp || temp.op == '('){
				stack.Push(tempOp);
				i++;
			}
			while (tempOp < temp&&temp.op != '#'&&temp.op != '('){
				stack.getTop(tempOp);
				if (tempOp.op != '#'&&temp.op != '#'){
					stack.Pop(tempOp);
					backEqu += tempOp.op;
					stack.getTop(temp);
				}
				else{
					break;
				}
				if (temp.op == '(' || temp.op == ')'){
					stack.Pop(temp);
				}
			}
			if (ch[i] == '#'){
				while (!stack.IsEmpty())
				{
					stack.Pop(temp);
					if (temp.op != '#'){
						backEqu += temp.op;
					}
				}
			}
		}
	}
}

double Calculate::getResult()
{
	getBackEqu();
	doCal();

	return result;
}

Calculate::~Calculate()
{

}