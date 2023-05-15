#include <iostream>
#include <stack>
using namespace std;

struct point
{
	int i;
	int j;
	point(int a, int b)
	{
		i = a;
		j = b;
	}
};
stack<point> dfsStack;
bool** isVisited;
int** arr;
int N, M;
int biggestArea = 0;
int picture;

void dfs(int i, int j)
{
	dfsStack.push(point(i, j));
	isVisited[i][j] = true;
	int area = 0;
	while (!dfsStack.empty())
	{
		point currentTop = dfsStack.top();
		int x = currentTop.i;
		int y = currentTop.j;
		bool canMove = false;
		if (x > 0 && isVisited[x - 1][y] == false && arr[x - 1][y] == 1)
		{
			canMove = true;
			isVisited[x - 1][y] = true;
			dfsStack.push(point(x - 1, y));
		}
		else if (x < N - 1 && isVisited[x + 1][y] == false && arr[x + 1][y] == 1)
		{
			canMove = true;
			isVisited[x + 1][y] = true;
			dfsStack.push(point(x + 1, y));
		}
		else if (y > 0 &&isVisited[x][y - 1] == false && arr[x][y - 1] == 1)
		{
			canMove = true;
			isVisited[x][y - 1] = true;
			dfsStack.push(point(x, y - 1));
		}
		else if (y < M - 1 && isVisited[x][y + 1] == false && arr[x][y + 1] == 1)
		{
			canMove = true;
			isVisited[x][y + 1] = true;
			dfsStack.push(point(x, y + 1));
		}

		if (canMove == false)
		{
			area++;
			dfsStack.pop();
		}
	}
	if (biggestArea < area)
	{
		biggestArea = area;
	}
	picture++;
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);


	cin >> N>> M;
	arr = new int*[N];
	isVisited = new bool* [N];
	for (int i = 0; i < N; i++)
	{
		arr[i] = new int[M];
		isVisited[i] = new bool[M];
		for (int j = 0; j < M; j++)
		{
			isVisited[i][j] = false;
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> arr[i][j];
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (arr[i][j] == 1 && isVisited[i][j] == false)
			{
				dfs(i, j);
			}
		}
	}
	cout << picture << "\n";
	cout << biggestArea << "\n";
	return 0;
}