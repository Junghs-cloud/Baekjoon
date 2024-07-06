#include <iostream>
#include <queue>
#include <utility>
#include <set>
using namespace std;
int** map;
bool** isVisited;
set<int>** checkVisitedWithNum;
set<int>::iterator it;

int currentIslandCount = 1;
queue<pair<int, int>> bfsQueue;
int N;

int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0 , 0, -1, 1 };

struct info
{
	int x;
	int y;
	int length;
	int startLand;
	info(int a, int b, int c, int d)
	{
		x = a;
		y = b;
		length = c;
		startLand = d;
	}
};

queue<info> bridgeQueue;

void checkIslands(int x,  int y)
{
	isVisited[x][y] = true;
	map[x][y] = -1 * currentIslandCount;
	bfsQueue.push(pair(x, y));
	while (!bfsQueue.empty())
	{
		pair<int, int> current = bfsQueue.front();
		for (int i = 0; i < 4; i++)
		{
			int nextX = current.first + dx[i];
			int nextY = current.second + dy[i];
			if (nextX >= 0 && nextX < N && nextY >= 0 && nextY < N && isVisited[nextX][nextY]==false && map[nextX][nextY]==-1)
			{
				isVisited[nextX][nextY] = true;
				map[nextX][nextY] = -1 * currentIslandCount;
				bfsQueue.push(pair(nextX, nextY));
			}
		}
		bfsQueue.pop();
	}
	currentIslandCount++;
}

bool isTouchToOtherIsland(info currentInfo)
{
	for (int i = 0; i < 4; i++)
	{
		int nextX = currentInfo.x + dx[i];
		int nextY = currentInfo.y + dy[i];
		if (nextX >= 0 && nextX < N && nextY >= 0 && nextY < N && map[nextX][nextY] < 0 && map[nextX][nextY] !=  currentInfo.startLand)
		{
			return true;
		}
	}
	return false;
}

void checkBridgeLength()
{
	while (!bridgeQueue.empty())
	{
		info current = bridgeQueue.front();
		if (isTouchToOtherIsland(current))
		{
			cout << current.length << "\n";
			break;
		}
		for (int i = 0; i < 4; i++)
		{
			int nextX = current.x + dx[i];
			int nextY = current.y + dy[i];
			if (nextX >= 0 && nextX < N && nextY >= 0 && nextY < N && map[nextX][nextY] == 0)
			{
				it = checkVisitedWithNum[nextX][nextY].find(current.startLand);
				if (it == checkVisitedWithNum[nextX][nextY].end())
				{
					checkVisitedWithNum[nextX][nextY].insert(current.startLand);
					bridgeQueue.push(info(nextX, nextY, current.length + 1, current.startLand));
				}
			}
		}
		bridgeQueue.pop();
	}
}

int isEdge(int x, int y)
{
	for (int i = 0; i < 4; i++)
	{
		int nextX = x+ dx[i];
		int nextY = y + dy[i];
		if (nextX >= 0 && nextX < N && nextY >= 0 && nextY < N&& map[nextX][nextY] < 0)
		{
			return map[nextX][nextY];
		}
	}
	return 0;
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	map = new int*[N];
	isVisited = new bool*[N];
	checkVisitedWithNum = new set<int>*[N];
	for (int i = 0; i < N; i++)
	{
		map[i] = new int[N];
		isVisited[i] = new bool[N];
		checkVisitedWithNum[i] = new set<int>[N];
		for (int j = 0; j < N; j++)
		{
			cin >> map[i][j];
			isVisited[i][j] = false;
			if (map[i][j] == 1)
			{
				map[i][j] = -1;
			}
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (map[i][j] == -1 && isVisited[i][j] == false)
			{
				checkIslands(i, j);
			}
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (isVisited[i][j] == false && isEdge(i, j) != 0)
			{
				int islandNum = isEdge(i, j);
				checkVisitedWithNum[i][j].insert(islandNum);
				bridgeQueue.push(info(i, j, 1, islandNum));
			}
		}
	}
	checkBridgeLength();
	return 0;
}