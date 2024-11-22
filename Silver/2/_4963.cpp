#include <iostream>
#include <stack>
#include <utility>
using namespace std;
int** arr;
bool** isVisited;
int W, H;

int dx[] = { -1, 0, 0, 1, -1, -1, 1, 1 };
int dy[] = { 0, -1, 1, 0, -1, 1, -1, 1 };
stack<pair<int, int>> dfsStack;
int answer = 0;

void dfs(int i, int j)
{
	dfsStack.push(pair(i, j));
	isVisited[i][j] = true;
	while (!dfsStack.empty())
	{
		pair<int, int> current = dfsStack.top();
		bool isAdjacent = false;
		for (int i = 0; i < 8 && isAdjacent == false; i++)
		{
			int nextX = current.first + dx[i];
			int nextY = current.second + dy[i];
			if (nextX >= 0 && nextX < H && nextY >= 0 && nextY < W && isVisited[nextX][nextY] == false && arr[nextX][nextY] == 1)
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

	while (true)
	{
		cin >> W >> H;
		if (W == 0 && H == 0)
		{
			break;
		}
		arr = new int* [H];
		isVisited = new bool* [H];
		answer = 0;
		for (int i = 0; i < H; i++)
		{
			arr[i] = new int[W];
			isVisited[i] = new bool[W];
			for (int j = 0; j < W; j++)
			{
				cin >> arr[i][j];
				isVisited[i][j] = false;
			}
		}
		for (int i = 0; i < H; i++)
		{
			for (int j = 0; j < W; j++)
			{
				if (isVisited[i][j] == false && arr[i][j] == 1)
				{
					dfs(i, j);
					answer++;
				}
			}
		}
		std::cout << answer << "\n";
	}
	return 0;
}