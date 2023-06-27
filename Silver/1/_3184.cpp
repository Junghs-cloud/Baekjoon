#include <iostream>
#include <queue>
using namespace std;
char** arr;
bool** isVisited;
int R, C;
int lambs;
int wolves;

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

void bfs(int i, int j)
{
	int lamb = 0;
	int wolf = 0;
	isVisited[i][j] = true;
	bfsQueue.push(pos(i, j));
	while (!bfsQueue.empty())
	{
		pos currentPos = bfsQueue.front();
		int currentX = currentPos.x;
		int currentY = currentPos.y;
		if (arr[currentX][currentY] == 'o')
		{
			lamb++;
		}
		if (arr[currentX][currentY] == 'v')
		{
			wolf++;
		}
		if (currentPos.x > 0 && arr[currentX - 1][currentY] != '#' && isVisited[currentX - 1][currentY] == false)
		{
			isVisited[currentX - 1][currentY] = true;
			bfsQueue.push(pos(currentX - 1, currentY));
		}
		if (currentPos.x < R - 1 && arr[currentX + 1][currentY] != '#' && isVisited[currentX + 1][currentY] == false)
		{
			isVisited[currentX + 1][currentY] = true;
			bfsQueue.push(pos(currentX + 1, currentY));
		}
		if (currentPos.y > 0 && arr[currentX][currentY-1] != '#' && isVisited[currentX][currentY - 1] == false)
		{
			isVisited[currentX][currentY - 1] = true;
			bfsQueue.push(pos(currentX, currentY - 1));
		}
		if (currentPos.y < C - 1 && arr[currentX][currentY + 1] != '#' && isVisited[currentX][currentY + 1] == false)
		{
			isVisited[currentX][currentY + 1] = true;
			bfsQueue.push(pos(currentX, currentY + 1));
		}
		bfsQueue.pop();
	}
	if (lamb > wolf)
	{
		lambs += lamb;
	}
	else
	{
		wolves += wolf;
	}
}

int main()
{
	string row;
	cin >> R >> C;
	arr = new char* [R];
	isVisited = new bool* [R];
	lambs = 0;
	wolves = 0;
	for (int i = 0; i < R; i++)
	{
		arr[i] = new char[C];
		isVisited[i] = new bool[C];
		cin >> row;
		for (int j = 0; j < C; j++)
		{
			arr[i][j] = row[j];
			isVisited[i][j] = false;
		}
	}
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			if (arr[i][j] != '#' && isVisited[i][j] == false)
			{
				bfs(i, j);
			}
		}
	}
	cout << lambs << " " << wolves << "\n";
	return 0;
}