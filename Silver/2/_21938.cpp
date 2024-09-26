#include <iostream>
#include <stack>
#include <utility>
using namespace std;
int N, M;
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};
int** arr;
bool** isVisited;
stack<pair<int, int>> dfsStack;

void dfs(int x, int y)
{
	dfsStack.push(pair(x, y));
	isVisited[x][y] = true;
	while (!dfsStack.empty())
	{
		pair<int, int> current = dfsStack.top();
		bool isAdjacent = false;
		for (int i = 0; i < 4; i++)
		{
			int nextX = dx[i] + current.first;
			int nextY = dy[i] + current.second;
			if (isAdjacent==false && nextX >= 0 && nextX < N && nextY >= 0 && nextY < M && isVisited[nextX][nextY]==false && arr[nextX][nextY]==255)
			{
				isVisited[nextX][nextY] = true;
				dfsStack.push(pair(nextX, nextY));
				isAdjacent = true;
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

	int T;
	int r, g, b;
	int answer = 0;
	cin >> N >> M;
	arr = new int*[N];
	isVisited = new bool*[N];
	for (int i = 0; i < N; i++)
	{
		arr[i] = new int[M];
		isVisited[i] = new bool[M];
		for (int j = 0; j < M; j++)
		{
			isVisited[i][j] = false;
			cin >> r >> g >> b;
			arr[i][j] = (r + g + b) / 3;
		}
	}
	cin >> T;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (arr[i][j] >= T)
			{
				arr[i][j] = 255;
			}
			else
			{
				arr[i][j] = 0;
			}
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (arr[i][j] == 255 && isVisited[i][j] == false)
			{
				dfs(i, j);
				answer++;
			}
		}
	}
	cout << answer << "\n";
	return 0;
}