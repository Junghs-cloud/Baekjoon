#include <iostream>
#include <queue>
using namespace std;

int N;
bool* isVisited;

struct info
{
	int num;
	int clipBoard;
	int sec;
	info(int a, int b, int c)
	{
		num = a;
		clipBoard = b;
		sec = c;
	}
};
queue<info> bfsQueue;

void calc()
{
	bfsQueue.push(info(1, 0, 0));
	isVisited[1] = true;
	while (!bfsQueue.empty())
	{
		info currentFront = bfsQueue.front();
		isVisited[currentFront.num] = true;
		if (currentFront.num == N)
		{
			cout << currentFront.sec<< "\n";
			break;
		}
		else
		{
			if (currentFront.clipBoard != 0 && currentFront.num + currentFront.clipBoard < 1100 && isVisited[currentFront.num + currentFront.clipBoard] == false)
			{
				bfsQueue.push(info(currentFront.num + currentFront.clipBoard, currentFront.clipBoard, currentFront.sec + 1));
			}
			bfsQueue.push(info(currentFront.num, currentFront.num, currentFront.sec + 1));


			if (isVisited[currentFront.num - 1] == false)
			{
				bfsQueue.push(info(currentFront.num - 1, currentFront.clipBoard, currentFront.sec + 1));
			}
		}
		bfsQueue.pop();
	}
}



int main()
{
	cin >> N;
	isVisited = new bool[1100];
	for (int i = 0; i < 1100; i++)
	{
		isVisited[i] = false;
	}
	calc();
	return 0;
}