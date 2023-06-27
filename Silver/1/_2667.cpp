#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

struct pos
{
	int i;
	int j;
	pos(int x, int y)
	{
		i = x;
		j = y;
	}
};

int N;
stack<pos> dfsStack;
vector<int> apartDanjis;
int** arr;
bool** isVisited;
int apartCount = 0;
int danjiCount = 0;

void dfs(int startX, int startY)
{
	int x;
	int y;
	bool isAdjacent;
	dfsStack.push(pos(startX, startY));
	apartCount++;
	while (!dfsStack.empty())
	{
		pos currentTop = dfsStack.top();
		x = currentTop.i;
		y = currentTop.j;
		isVisited[x][y] = true;
		isAdjacent = false;
		if (x < N - 1)
		{
			if (arr[x + 1][y] == 1 && isVisited[x + 1][y] == false)
			{
				isAdjacent = true;
				apartCount++;
				dfsStack.push(pos(x + 1, y));
			}
		}
		if (x > 0 && isAdjacent == false)
		{
			if (arr[x - 1][y] == 1 && isVisited[x - 1][y] == false)
			{
				isAdjacent = true;
				apartCount++;
				dfsStack.push(pos(x - 1, y));
			}
		}
		if (y < N - 1 && isAdjacent == false)
		{
			if (arr[x][y + 1] == 1 && isVisited[x][y + 1] == false)
			{
				isAdjacent = true;
				apartCount++;
				dfsStack.push(pos(x, y + 1));
			}
		}
		if (y > 0 && isAdjacent == false)
		{
			if (arr[x][y - 1] == 1 && isVisited[x][y - 1] == false)
			{
				isAdjacent = true;
				apartCount++;
				dfsStack.push(pos(x, y - 1));
			}
		}
		if (isAdjacent == false)
		{
			dfsStack.pop();
		}
	}
	apartDanjis.push_back(apartCount);
}

void findFromArray()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (isVisited[i][j] == false)
			{
				if (arr[i][j] == 1)
				{
					apartCount = 0;
					danjiCount++;
					dfs(i, j);
				}
			}
		}
	}
}

int main()
{

	string line;
	cin >> N;
	arr = new int*[N];
	isVisited = new bool* [N];

	for (int i = 0; i < N; i++)
	{
		arr[i] = new int[N];
		isVisited[i] = new bool[N];
		cin >> line;
		for (int j = 0; j < N; j++)
		{
			arr[i][j] = line[j]-48;
			isVisited[i][j] = false;
		}
	}
	findFromArray();
	sort(apartDanjis.begin(), apartDanjis.end());
	cout << danjiCount<<"\n";
	for (int i = 0; i < (signed) apartDanjis.size(); i++)
	{
		cout << apartDanjis[i]<<"\n";
	}
	return 0;
}