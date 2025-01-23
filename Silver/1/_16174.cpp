#include <iostream>
#include <stack>
#include <utility>
using namespace std;
int dx[] = { 0, 1 };
int dy[] = { 1, 0 };

int N;
int** map;
bool** isVisited;

stack<pair<int, int>> dfsStack;
void dfs()
{
	dfsStack.push(pair(0, 0));
	isVisited[0][0] = true;
	while (!dfsStack.empty())
	{
		pair<int, int> current = dfsStack.top();
		bool isAdjacent = false;
		if (current.first == N - 1 && current.second == N - 1)
		{
			break;
		}
		for (int i = 0; i < 2 && isAdjacent==false; i++)
		{
			int nextX = current.first + dx[i] * map[current.first][current.second];
			int nextY = current.second + dy[i] *map[current.first][current.second];
			if (nextX >= 0 && nextX < N && nextY >= 0 && nextY < N && isVisited[nextX][nextY] == false)
			{
				isAdjacent = true;
				dfsStack.push(pair(nextX, nextY));
				isVisited[nextX][nextY] = true;
			}
		}
		if (isAdjacent == false)
		{
			dfsStack.pop();
		}
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	map = new int*[N];
	isVisited = new bool*[N];
	for (int i = 0; i < N; i++)
	{
		isVisited[i] = new bool[N];
		map[i] = new int[N];
		for (int j = 0; j < N; j++)
		{
			cin >> map[i][j];
			isVisited[i][j] = false;
		}
	}
	dfs();
	if (isVisited[N - 1][N - 1] == false)
	{
		cout << "Hing" << "\n";
	}
	else
	{
		cout << "HaruHaru" << "\n";
	}
	return 0;
}