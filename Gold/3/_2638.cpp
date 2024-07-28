#include <iostream>
#include <queue>
#include <utility>
using namespace std;

queue<pair<int, int>> bfsQueue;
int** map;
int** nextTimeMap;
bool** isVisited;
int dx[] = { -1, 0, 0, 1 };
int dy[] = { 0, -1, 1, 0 };
int N, M;

void bfs(int startX, int startY)
{
	bfsQueue.push(pair(startX, startY));
	while (!bfsQueue.empty())
	{
		pair<int, int> currentFront = bfsQueue.front();
		for (int i = 0; i < 4; i++)
		{
			int nextX = currentFront.first + dx[i];
			int nextY = currentFront.second + dy[i];
			if (nextX >= 0 && nextX < N&& nextY>=0 && nextY < M && isVisited[nextX][nextY]==false&& map[nextX][nextY]==0)
			{
				isVisited[nextX][nextY] = true;
				bfsQueue.push(pair(nextX, nextY));
			}
		}
		bfsQueue.pop();
	}
}

bool check(int x, int y)
{
	int count = 0;
	for (int i = 0; i < 4; i++)
	{
		int nextX = x + dx[i];
		int nextY = y + dy[i];
		if (nextX >= 0 && nextX < N && nextY >= 0 && nextY < M && isVisited[nextX][nextY] == true)
		{
			count++;
		}
	}
	if (count >= 2)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void copyNextTimeMap()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			isVisited[i][j] = false;
			map[i][j] = nextTimeMap[i][j];
		}
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	map = new int*[N];
	nextTimeMap = new int*[N];
	isVisited = new bool*[N];
	for (int i = 0; i < N; i++)
	{
		map[i] = new int[M];
		nextTimeMap[i] = new int[M];
		isVisited[i] = new bool[M];
		for (int j = 0; j < M; j++)
		{
			cin>>map[i][j];
			nextTimeMap[i][j] = 0;
			isVisited[i][j] = false;
		}
	}

	int time = 0;
	bool isChanged = false;
	while (true)
	{
		isChanged = false;
		bfs(0, 0);
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if (map[i][j] == 1)
				{
					isChanged = true;
					if (check(i, j) == true)
					{
						nextTimeMap[i][j] = 0;
					}
					else
					{
						nextTimeMap[i][j] = 1;
					}
				}
				else
				{
					nextTimeMap[i][j] = 0;
				}
			}
		}
		if (isChanged == false)
		{
			break;
		}
		else
		{
			time++;
			copyNextTimeMap();
		}
	}
	cout << time << "\n";
	return 0;
}