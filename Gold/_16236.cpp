#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
int** sea;
bool** isVisited;
int N;
int sharkSize = 2;
int eat = 0;
int currentTime = 0;
int remainFish = 9999;
int sharkX = 0;
int sharkY = 0;
bool canNotMove = false;

struct pos
{
	int x;
	int y;
	int length = 0;
	pos(int a, int b, int c)
	{
		x = a;
		y = b;
		length = c;
	}
};
queue<pos> posQueue;

void makeQueueEmpty()
{
	if (!posQueue.empty())
	{
		while (!posQueue.empty())
		{
			posQueue.pop();
		}
	}
}

bool compare(pos& p1, pos& p2)
{
	if (p1.length < p2.length)
	{
		return true;
	}
	else if (p1.length == p2.length)
	{
		if (p1.x < p2.x)
		{
			return true;
		}
		else if (p1.x == p2.x)
		{
			return p1.y < p2.y;
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}

void bfs(int x, int y)
{
	makeQueueEmpty();
	posQueue.push(pos(x, y, 0));
	isVisited[x][y] = true;
	int currentMinLength = 9999;
	vector<pos> minLengths;
	while (!posQueue.empty())
	{
		pos current = posQueue.front();
		if (sea[current.x][current.y] > 0 && sea[current.x][current.y] < sharkSize)
		{
			if (current.length <= currentMinLength)
			{
				currentMinLength = current.length;
				minLengths.push_back(pos(current.x, current.y, current.length));
			}
		}
		if (current.x > 0 && sea[current.x - 1][current.y] <= sharkSize && isVisited[current.x - 1][current.y] == false)
		{
			isVisited[current.x - 1][current.y] = true;
			posQueue.push(pos(current.x - 1, current.y, current.length + 1));
		}
		if (current.y > 0 && sea[current.x][current.y - 1] <= sharkSize && isVisited[current.x][current.y - 1] == false)
		{
			isVisited[current.x][current.y - 1] = true;
			posQueue.push(pos(current.x, current.y - 1, current.length + 1));
		}
		if (current.x < N - 1 && sea[current.x + 1][current.y] <= sharkSize && isVisited[current.x + 1][current.y] == false)
		{
			isVisited[current.x + 1][current.y] = true;
			posQueue.push(pos(current.x + 1, current.y, current.length + 1));
		}
		if (current.y < N - 1 && sea[current.x][current.y + 1] <= sharkSize && isVisited[current.x][current.y + 1] == false)
		{
			isVisited[current.x][current.y + 1] = true;
			posQueue.push(pos(current.x, current.y + 1, current.length + 1));
		}
		posQueue.pop();
	}
	if (minLengths.size() != 0)
	{
		sort(minLengths.begin(), minLengths.end(), compare);
		pos minPos = minLengths.at(0);
		eat++;
		if (eat == sharkSize)
		{
			eat = 0;
			sharkSize++;
		}
		sea[minPos.x][minPos.y] = 9;
		sea[sharkX][sharkY] = 0;
		currentTime += minPos.length;
		minLengths.clear();
	}
	else
	{
		canNotMove = true;
	}
}

int main()
{
	cin >> N;
	sea = new int* [N];
	isVisited = new bool* [N];
	for (int i = 0; i < N; i++)
	{
		sea[i] = new int[N];
		isVisited[i] = new bool[N];
		for (int j = 0; j < N; j++)
		{
			cin >> sea[i][j];
			isVisited[i][j] = false;
		}
	}
	while (remainFish != 0)
	{
		if (canNotMove == true)
		{
			break;
		}
		remainFish = 0;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				isVisited[i][j] = false;
				if (sea[i][j] >= 1 && sea[i][j] <= 6 && sea[i][j] < sharkSize)
				{
					remainFish++;
				}
				if (sea[i][j] == 9)
				{
					sharkX = i;
					sharkY = j;
				}
			}
		}
		if (remainFish != 0)
		{
			sea[sharkX][sharkY] = 0;
			bfs(sharkX, sharkY);
		}
	}
	cout << currentTime << "\n";
	return 0;
}