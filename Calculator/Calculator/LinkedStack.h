#pragma once

#include <assert.h>
#include <iostream>
#include <cmath>
#include <string>
using namespace std;

struct Operator
{
	char op;
	int pr;
	Operator(){};
	Operator(char ope)
	{
		op = ope;
		if (op == '('){
			pr = 0;
		}
		else if (op == '*'){
			pr = 1;
		}
		else if (op == '/'){
			pr = 1;
		}
		else if (op == '+'){
			pr = 2;
		}
		else if (op == '-'){
			pr = 2;
		}
		else if (op == ')'){
			pr = 3;
		}
		else if (op == '#'){
			pr = 4;
		}
		else if (op == 'n' || op == 's' || op == 'c' || op == 't'){
			pr = 0;
		}
	}
	Operator(Operator &o)
	{
		op = o.op;
		pr = o.pr;
	}
	bool operator >=(const Operator&o2){
		if (pr <= o2.pr){
			return true;
		}
		else
			return false;
	}
	bool operator <(const Operator&o2){
		if (pr > o2.pr){
			return true;
		}
		else
			return false;
	}
};

template <class T>
struct StackNode
{
	T data;
	StackNode<T> *link;
	StackNode(T d = 0, StackNode<T> *next = NULL)
		: data(d), link(next){};
};

template<class T>
class LinkedStack 
{
public:
	LinkedStack() :top(NULL){};
	void Push(T& x);
	bool Pop(T& x);
	bool getTop(T& x);
	bool IsEmpty(){ return(top == NULL) ? true : false; }
	int getSize();
	void makeEmpty();
	~LinkedStack();
private:
	StackNode<T> *top;
};

template<class T>
void LinkedStack<T>::makeEmpty()
{
	StackNode<T> *p;
	while (top != NULL)
	{
		p = top;
		top = top->link;
		delete p;
	}
}

template<class T>
void LinkedStack<T>::Push(T&x)
{
	top = new StackNode<T>(x, top);
	assert(top != NULL);
}

template<class T>
bool LinkedStack<T>::Pop(T &x)
{
	if (IsEmpty() == true){
		return false;
	}
	StackNode<T> *p = top;
	top = top->link;
	x = p->data;
	delete p;

	return false;
}

template<class T>
bool LinkedStack<T>::getTop(T &x)
{
	if (IsEmpty() == true){
		return false;
	}
	x = top->data;

	return true;
}

template<class T>
int LinkedStack<T>::getSize()
{
	StackNode<T>*p = top;
	int k = 0;
	while (p != NULL)
	{
		p = p->link;
		k++;
	}

	return k;
}

template<class T>
LinkedStack<T>::~LinkedStack()
{
	makeEmpty();
}