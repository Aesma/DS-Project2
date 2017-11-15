// Train.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "Train.h"
#include <iostream>
#include <sstream>
using namespace std;

Train::Train(int N, int K)
{
	n = N;
	k = K;
	outTrain = 1;
	trainCount = 0;
	H = new SeqQueue<int>[k];
	train = new Trains[n];
	int *mark = new int[n];
	srand((unsigned)time(NULL));
	for (int i = 0; i < n;)
	{
		int r = rand() % n;
		if (mark[r] != 1){
			train[r].trainNum = i + 1;
			train[r].from = "";
			mark[r] = 1;
			i++;
		}
	}
}

void Train::trainSport()
{
	printTrain();

	endToFirst(train[trainCount]);

	print();
}

void Train::endToFirst(Trains x)
{
	int rearTrain = 0;
	int j;
	int temp = 0;
	bool outH = true;
	if (x.trainNum == outTrain){
		trainCount++;
		outTrain++;
	}
	else{
		for (j = 0, outH = false; outH == false && j < k-1&&trainCount < n;)
		{
			H[j].getRear(rearTrain);
			if (H[j].IsEmpty()){
				rearTrain = 0;
			}
			if (!H[j].IsFull() && rearTrain < x.trainNum){
				H[j].EnQueue(x.trainNum);
				string tempStr;
				stringstream ss;
				ss << (j + 1);
				ss >> tempStr;
				train[trainCount].from += ("H" + tempStr + " ");
				trainCount++;
				outH = true;
			}
			j++;
			if (outH == false && j == k-1){
				int count = 0;
				while (!H[1].IsEmpty())
				{
					int temp;
					H[1].getFront(temp);
					if (temp < train[trainCount].trainNum){
						H[1].DeQueue(temp);
						H[2].EnQueue(temp);
						for (int a = 0; a < n; a++)
						{
							if (temp == train[a].trainNum){
								train[a].from += "H3 ";
							}
						}
						count = 1;
					}
					else{
						if (count == 1){
							H[2].EnQueue(train[trainCount].trainNum);
							train[trainCount].from += "H3 ";
						}
						H[1].DeQueue(temp);
						H[2].EnQueue(temp);
						for (int a = 0; a < n; a++)
						{
							if (temp == train[n].trainNum){
								train[n].from += "H3 ";
							}
						}
						count = 2;
					}
				}
				if (H[1].IsEmpty() && !H[2].IsEmpty()){
					while (!H[2].IsEmpty())
					{
						int temp;
						H[2].DeQueue(temp);
						H[1].EnQueue(temp);
						for (int a = 0; a < n; a++)
						{
							if (temp == train[a].trainNum){
								train[a].from += "H2 ";
							}
						}
					}
					trainCount++;
				}
			}
		}
	}
	if (trainCount == n){
		return;
	}
	endToFirst(train[trainCount]);
}

void Train::printTrain()
{
	cout << "随机产生的车厢序号为：";
	for (int i = 0; i < n; i++)
		cout << train[i].trainNum << " ";
	cout << endl;
}

void Train::print()
{
	int front = 0;
	for (int out = 1; out < n + 1; out++)
	{
		bool isOut = false;
		for (int i = 0; i < k; i++)
		{
			H[i].getFront(front);
			if (front == out){
				for (int j = 0; j < n; j++)
				{
					if (train[j].trainNum == out){
						cout << out << "号车厢出自缓冲轨道:" << train[j].from << endl;
						break;
					}
				}
				H[i].DeQueue(front);
				isOut = true;
				break;
			}
		}
		if (isOut == false){
			cout << out << "号车厢直接出轨" << endl;
		}
	}
}

int Train::minThree(int a ,int b,int c)
{
	return (a < b ? a : b) < c ? (a < b ? a : b) : c;
}

int Train::minTwo(int a, int b)
{
	return a<b ? a : b;
}

int Train::max(int a, int b, int c)
{
	return (a > b ? a : b) > c ? (a > b ? a : b) : c;
}

Train::~Train()
{
	delete[]train;
	for (int i = 0; i < k; i++)
		H[i].makeEmpty();
	delete[]H;
}
