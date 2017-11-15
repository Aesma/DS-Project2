#pragma once

#include "SeqQueue.h"
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

struct Trains
{
	int trainNum;
	string from;
};

class Train
{
public:
	Train(int N,int k);
	void trainSport();
	void endToFirst(Trains t);
	void printTrain();
	void print();
	int minThree(int a, int b, int c);
	int minTwo(int a, int b);
	int max(int a, int b, int c);
	~Train();
private:
	SeqQueue<int> *H;
	Trains *train;
	int n;
	int k;
	int trainCount;
	int outTrain;
};