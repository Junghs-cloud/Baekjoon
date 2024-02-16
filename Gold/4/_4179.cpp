#include <iostream>
#include <queue>
using namespace std;
int N, M;
char** arr;
bool** isVisited;
int** fireMove;
int initJX, initJY;
struct info
{
	int x;
	int y;
	int length;
	info(int a, int b, int c)
	{
		x = a;
		y = b;
		length = c;
	}
};
queue<info> bfsQueue;

void moveFire(int initFireX, int initFireY)
{
	fireMove[initFireX][initFireY] = 0;
	bfsQueue.push(info(initFireX, initFireY, 0));
	while (!bfsQueue.empty())
	{
		info current = bfsQueue.front();
		fireMove[current.x][current.y] = current.length;
		if (current.x > 0 && current.length+1 < fireMove[current.x-1][current.y] && arr[current.x - 1][current.y] != '#')
		{
			fireMove[current.x-1][current.y] = current.length;
			bfsQueue.push(info(current.x - 1, current.y, current.length+1));
		}
		if (current.x < N-1 && current.length + 1 < fireMove[current.x + 1][current.y] && arr[current.x + 1][current.y] != '#')
		{
			fireMove[current.x+1][current.y] = current.length;
			bfsQueue.push(info(current.x + 1, current.y, current.length+1));
		}
		if (current.y > 0 && current.length + 1 < fireMove[current.x][current.y-1] && arr[current.x][current.y-1] != '#')
		{
			fireMove[current.x][current.y-1] = current.length;
			bfsQueue.push(info(current.x, current.y - 1, current.length+1));
		}
		if (current.y < M-1 && current.length + 1 < fireMove[current.x][current.y+1] && arr[current.x][current.y + 1] != '#')
		{
			fireMove[current.x][current.y+1] = current.length;
			bfsQueue.push(info(current.x, current.y + 1, current.length+1));
		}
		bfsQueue.pop();
	}
}

void moveJihoon()
{
	isVisited[initJX][initJY] = true;
	bfsQueue.push(info(initJX, initJY, 0));
	bool canEscape = false;
	while (!bfsQueue.empty())
	{
		info current = bfsQueue.front();
		if (current.x == 0 || current.y == 0 || current.x==N-1 || current.y == M-1)
		{
			canEscape = true;
			cout << current.length + 1 << "\n";
			break;
		}
		if (current.x > 0 && isVisited[current.x - 1][current.y] == false && arr[current.x - 1][current.y] != '#' && current.length + 1 < fireMove[current.x-1][current.y])
		{
			isVisited[current.x - 1][current.y] = true;
			bfsQueue.push(info(current.x - 1, current.y, current.length + 1));
		}
		if (current.x < N - 1 && isVisited[current.x + 1][current.y] == false && arr[current.x + 1][current.y] != '#' &&current.length + 1 < fireMove[current.x + 1][current.y])
		{
			isVisited[current.x + 1][current.y] = true;
			bfsQueue.push(info(current.x + 1, current.y, current.length + 1));
		}
		if (current.y > 0 && isVisited[current.x][current.y - 1] == false && arr[current.x][current.y - 1] != '#' && current.length + 1 < fireMove[current.x][current.y-1])
		{
			isVisited[current.x][current.y - 1] = true;
			bfsQueue.push(info(current.x, current.y - 1, current.length + 1));
		}
		if (current.y < M - 1 && isVisited[current.x][current.y + 1] == false && arr[current.x][current.y + 1] != '#' && current.length + 1 < fireMove[current.x][current.y+1])
		{
			isVisited[current.x][current.y + 1] = true;
			bfsQueue.push(info(current.x, current.y + 1, current.length + 1));
		}
		bfsQueue.pop();
	}
	if (canEscape == false)
	{
		cout << "IMPOSSIBLE" << "\n";
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N>>M;
	arr = new char*[N];
	isVisited = new bool*[N];
	fireMove = new int*[N];

	for (int i = 0; i < N; i++)
	{
		arr[i] = new char[M];
		isVisited[i] = new bool[M];
		fireMove[i] = new int[M];
		for (int j = 0; j < M; j++)
		{
			cin >> arr[i][j];
			isVisited[i][j] = false;
			fireMove[i][j] = 100000000;
			if (arr[i][j] == 'J')
			{
				initJX = i;
				initJY = j;
			}
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (arr[i][j] == 'F')
			{
				moveFire(i, j);
			}
		}
	}

	moveJihoon();
	return 0;
}