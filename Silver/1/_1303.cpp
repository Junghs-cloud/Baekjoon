#include <iostream>
#include <stack>
#include <utility>
#include <algorithm>
using namespace std;

int N, M;
bool** isVisited;
char** map;

int dx[] = { -1, 0, 0, 1 };
int dy[] = { 0,-1, 1, 0 };
stack<pair<int, int>> dfsStack;
int blue;
int white;

void dfs(int i, int j)
{
	char color = map[i][j];
	int count = 0;
	dfsStack.push(pair(i, j));
	isVisited[i][j] = true;
	while (!dfsStack.empty())
	{
		pair<int, int> current = dfsStack.top();
		bool isConnectedLeft = false;
		for (int i = 0; i < 4 && isConnectedLeft == false; i++)
		{
			int nextX = current.first + dx[i];
			int nextY = current.second + dy[i];
			if (nextX>=0 && nextX < M && nextY >=0 && nextY < N && isVisited[nextX][nextY] == false && map[nextX][nextY] == color)
			{
				isConnectedLeft = true;
				dfsStack.push(pair(nextX, nextY));
				isVisited[nextX][nextY] = true;
			}
		}
		if (isConnectedLeft == false)
		{
			dfsStack.pop();
			count++;
		}
	}
	if (color == 'W')
	{
		white += count * count;
	}
	else
	{
		blue += count * count;
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	map = new char*[M];
	isVisited = new bool*[M];
	for (int i = 0; i < M; i++)
	{
		map[i] = new char[N];
		isVisited[i] = new bool[N];
		for (int j = 0; j < N; j++)
		{
			cin >> map[i][j];
			isVisited[i][j] = false;
		}
	}
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (isVisited[i][j] == false)
			{
				dfs(i, j);
			}
		}
	}
	cout << white << " " << blue << "\n";
	return 0;
}