#include "stdafx.h"
#include "Calculate.h"

Calculate::Calculate(string e)
{
	equ = new char[e.length()];
	equ = (char*)e.c_str();
	result = 0;
	doCal();
}

void Calculate::doCal()
{
	int i = 0;
	int len = strlen(equ);
	Operator first(equ[i++]);
	double tempNum = 0;
	sta_o.Push(first);
	if (equ[i] == '-'){
		i++;
	}
	while (!sta_o.IsEmpty())
	{
		if (i < len){
			if (equ[i] >= 48 && equ[i] <= 57 || (equ[i] == '-'&&equ[i - 1] == '(')){
				if ((i > 2 && (equ[i - 2] == '('&& equ[i - 1] == '-')) || (i == 2 && equ[1] == '-')){
					tempNum = 0 - (equ[i] - '0');
				}
				else if (equ[i - 1] == '.'){
					double t = equ[i] - '0';
					if (tempNum >= 0){
						tempNum += t / 10;
					}
					else{
						tempNum = tempNum - t / 10;
					}
				}
				else if (equ[i - 1] >= 48 && equ[i - 1] <= 57){
					if (tempNum >= 0){
						tempNum = tempNum * 10 + (equ[i] - '0');
					}
					else{
						tempNum = tempNum * 10 - (equ[i] - '0');
					}
				}
				else{
					tempNum = equ[i] - '0';
				}
				i++;
				if (!(equ[i] >= 48 && equ[i] <= 57) && equ[i] != '.'){
					sta_n.Push(tempNum);
					tempNum = 0;
				}
			}
			if (equ[i] == '.')
				i++;
		}
		if (i >= len || (!(equ[i] >= 48 && equ[i] <= 57) && equ[i] != '.' && (equ[i - 1] != '('&&equ[i] != '-'))){
			Operator tempOp(equ[i]);
			Operator temp;
			sta_o.getTop(temp);
			i++;
			if (tempOp >= temp){
				sta_o.Push(tempOp);
			}
			else if (temp.op == '('){
				sta_o.Push(tempOp);
			}
			else if (tempOp.op == ')'){
				while (temp.op != '('){
					char op = temp.op;
					sta_o.Pop(temp);
					if (temp.op == '('){
						break;
					}
					double num1;
					double num2;
					sta_n.Pop(num1);
					sta_n.Pop(num2);
					switch (op)
					{
					case '+':
						result = (num1 + num2);
						break;
					case '-':
						result = (num1 - num2);
						break;
					case '*':
						result = (num1 * num2);
						break;
					case '/':
						result = (num1 / num2);
						break;
					default:
						break;
					}
					sta_n.Push(result);
				}
			}
			else if (tempOp < temp && temp.op != '('){
				char op = temp.op;
				sta_o.Pop(temp);
				double num1;
				double num2;
				sta_n.Pop(num1);
				sta_n.Pop(num2);
				switch (op)
				{
				case '+':
					result = (num1 + num2);
					break;
				case '-':
					result = (num1 - num2);
					break;
				case '*':
					result = (num1 * num2);
					break;
				case '/':
					result = (num1 / num2);
					break;
				default:
					break;
				}
				sta_n.Push(result);
			}
		}
		Operator Top;
		sta_o.getTop(Top);
		if (Top.op == '#'&&i >= len){
			sta_o.Pop(Top);
		}
	}
}

double Calculate::getRes()
{
	return result;
}

Calculate::~Calculate()
{

}
