#include <iostream>
#include <queue>
using namespace std;
bool* isVisited;

struct info
{
	long long num;
	int numCount;
	info(long long a, int b)
	{
		num = a;
		numCount = b;
	}
};
queue<info> bfsQueue;

void bfs(long long N)
{
	bfsQueue.push(info(N, 0));
	isVisited[N] = true;
	while (!bfsQueue.empty())
	{
		info currentFront= bfsQueue.front();
		long long currentNum = currentFront.num;
		int currentNumCount = currentFront.numCount;
		if (currentNum == 1)
		{
			cout << currentNumCount << "\n";
			break;
		}
		if (currentNum % 3 == 0 && isVisited[currentNum / 3] == false)
		{
			isVisited[currentNum / 3];
			bfsQueue.push(info(currentNum / 3, currentNumCount + 1));
		}
		if (currentNum % 2 == 0 && isVisited[currentNum / 2] == false)
		{
			isVisited[currentNum / 2];
			bfsQueue.push(info(currentNum / 2, currentNumCount + 1));
		}
		if (isVisited[currentNum - 1] == false)
		{
			isVisited[currentNum - 1];
			bfsQueue.push(info(currentNum - 1, currentNumCount + 1));
		}
		bfsQueue.pop();
	}
}

int main()
{
	long long N;
	cin >> N;
	isVisited = new bool[N + 1];
	for (int i = 0; i <= N; i++)
	{
		isVisited[i] = false;
	}
	bfs(N);
	return 0;
}