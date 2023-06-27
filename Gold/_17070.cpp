#include <iostream>
#include <queue>
using namespace std;
int N;
int** arr;
int moveCount = 0;

struct info
{
	int xPos;
	int yPos;
	int dir; //1=가로, 2=대각선, 3=세로
	info(int a, int b, int c)
	{
		xPos = a;
		yPos = b;
		dir = c;
	}
};
queue<info> bfsQueue;

void bfs()
{
	bfsQueue.push(info(0, 1, 1));
	while (!bfsQueue.empty())
	{
		info currentFront = bfsQueue.front();
		if (currentFront.xPos == N - 1 && currentFront.yPos == N - 1)
		{
			moveCount++;
		}
		if (currentFront.dir == 1)
		{
			if (currentFront.yPos < N - 1 && arr[currentFront.xPos][currentFront.yPos + 1] != 1)
			{
				bfsQueue.push(info(currentFront.xPos, currentFront.yPos + 1, 1));
			}
			if (currentFront.yPos < N - 1 && currentFront.xPos < N - 1 && arr[currentFront.xPos + 1][currentFront.yPos + 1] != 1 && arr[currentFront.xPos + 1][currentFront.yPos] != 1 && arr[currentFront.xPos][currentFront.yPos + 1] != 1)
			{
				bfsQueue.push(info(currentFront.xPos + 1, currentFront.yPos + 1, 2));
			}
		}
		else if (currentFront.dir == 2)
		{
			if (currentFront.yPos < N - 1 && arr[currentFront.xPos][currentFront.yPos + 1] != 1)
			{
				bfsQueue.push(info(currentFront.xPos, currentFront.yPos + 1, 1));
			}
			if (currentFront.xPos < N - 1 && arr[currentFront.xPos + 1][currentFront.yPos] != 1)
			{
				bfsQueue.push(info(currentFront.xPos + 1, currentFront.yPos, 3));
			}
			if (currentFront.xPos < N - 1 && currentFront.yPos < N - 1 && arr[currentFront.xPos + 1][currentFront.yPos + 1] != 1 && arr[currentFront.xPos + 1][currentFront.yPos] != 1 && arr[currentFront.xPos][currentFront.yPos + 1] != 1)
			{
				bfsQueue.push(info(currentFront.xPos + 1, currentFront.yPos + 1, 2));
			}
		}
		else
		{
			if (currentFront.xPos < N - 1 && arr[currentFront.xPos + 1][currentFront.yPos] != 1)
			{
				bfsQueue.push(info(currentFront.xPos + 1, currentFront.yPos, 3));
			}
			if (currentFront.xPos < N - 1 && currentFront.yPos < N - 1 && arr[currentFront.xPos + 1][currentFront.yPos + 1] != 1 && arr[currentFront.xPos + 1][currentFront.yPos] != 1 && arr[currentFront.xPos][currentFront.yPos + 1] != 1)
			{
				bfsQueue.push(info(currentFront.xPos + 1, currentFront.yPos + 1, 2));
			}
		}
		bfsQueue.pop();
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	arr = new int*[N];
	for (int i = 0; i < N; i++)
	{
		arr[i] = new int[N];
		for (int j = 0; j < N; j++)
		{
			cin >> arr[i][j];
		}
	}
	bfs();
	cout << moveCount << "\n";
	return 0;
}