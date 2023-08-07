#include <iostream>
#include <queue>
using namespace std;
int** arr;
int** original;
int N, M;
bool** isVisited;
struct pos
{
	int x;
	int y;
	pos(int a, int b)
	{
		x = a;
		y = b;
	}
};
queue<pos> bfsQueue;
int maxCount;

void count()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (arr[i][j] == 2)
			{
				isVisited[i][j] = true;
				bfsQueue.push(pos(i, j));
			}
		}
	}
	while (!bfsQueue.empty())
	{
		pos currentFront = bfsQueue.front();
		if (currentFront.x > 0 && isVisited[currentFront.x - 1][currentFront.y] == false && arr[currentFront.x-1][currentFront.y] == 0)
		{
			isVisited[currentFront.x - 1][currentFront.y] = true;
			arr[currentFront.x - 1][currentFront.y] = 2;
			bfsQueue.push(pos(currentFront.x - 1, currentFront.y));
		}
		if (currentFront.x < N - 1 && isVisited[currentFront.x + 1][currentFront.y] == false && arr[currentFront.x + 1][currentFront.y] == 0)
		{
			isVisited[currentFront.x + 1][currentFront.y] = true;
			arr[currentFront.x + 1][currentFront.y] = 2;
			bfsQueue.push(pos(currentFront.x + 1, currentFront.y));
		}
		if (currentFront.y > 0 && isVisited[currentFront.x][currentFront.y - 1] == false && arr[currentFront.x][currentFront.y -1] == 0)
		{
			isVisited[currentFront.x][currentFront.y - 1] = true;
			arr[currentFront.x][currentFront.y - 1] = 2;
			bfsQueue.push(pos(currentFront.x, currentFront.y - 1));
		}
		if (currentFront.y < M-1 && isVisited[currentFront.x][currentFront.y + 1] == false && arr[currentFront.x][currentFront.y + 1] == 0)
		{
			isVisited[currentFront.x][currentFront.y + 1] = true;
			arr[currentFront.x][currentFront.y + 1] = 2;
			bfsQueue.push(pos(currentFront.x , currentFront.y + 1));
		}
		bfsQueue.pop();
	}
	int safeCount = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			isVisited[i][j] = false;
			if (arr[i][j] == 0)
			{
				safeCount++;
			}
			if (arr[i][j] == 2)
			{
				arr[i][j] = original[i][j];
			}
		}
	}
	if (safeCount > maxCount)
	{
		maxCount = safeCount;
	}
}

void backTracking(int wallCount)
{
	if (wallCount == 3)
	{
		count();
		return;
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (arr[i][j] == 0)
			{
				wallCount++;
				arr[i][j] = 1;
				backTracking(wallCount);
				arr[i][j] = 0;
				wallCount--;
			}
		}
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	arr = new int*[N];
	isVisited = new bool* [N];
	original = new int* [N];
	maxCount = 0;
	for (int i = 0; i < N; i++)
	{
		arr[i] = new int[M];
		original[i] = new int[M];
		isVisited[i] = new bool[M];
		for (int j = 0; j < M; j++)
		{
			cin >> arr[i][j];
			original[i][j] = arr[i][j];
			isVisited[i][j] = false;
		}
	}
	backTracking(0);
	cout << maxCount << "\n";
	return 0;
}