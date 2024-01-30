#include <iostream>
#include <stack>
#include <utility>
#include <cmath>
using namespace std;
int** arr;
stack<pair<int, int>> dfsStack;
stack<pair<int, int>> s;
bool** isVisited;
int N, L, R;
bool canMove;

void dfs(int x, int y)
{
	s.push(make_pair(x, y));
	dfsStack.push(make_pair(x, y));
	int countryCount = 1;
	int peopleSum = arr[x][y];
	isVisited[x][y] = true;
	while (!dfsStack.empty())
	{
		pair<int, int> top = dfsStack.top();
		int i = top.first;
		int j = top.second;
		int currentPeople = arr[i][j];
		bool isAdjacent = false;
		if (i > 0 && isVisited[i - 1][j] == false && L <= abs(arr[i - 1][j]-currentPeople) && abs(arr[i - 1][j] - currentPeople) <= R)
		{
			countryCount++;
			peopleSum += arr[i - 1][j];
			isVisited[i - 1][j] = true;
			dfsStack.push(make_pair(i - 1, j));
			s.push(make_pair(i - 1, j));
			isAdjacent = true;
		}
		if (i < N-1 && isVisited[i + 1][j] == false && L <= abs(arr[i + 1][j] - currentPeople) && abs(arr[i + 1][j] - currentPeople) <= R)
		{
			countryCount++;
			peopleSum += arr[i + 1][j];
			isVisited[i + 1][j] = true;
			dfsStack.push(make_pair(i + 1, j));
			s.push(make_pair(i + 1, j));
			isAdjacent = true;
		}
		if (j > 0 && isVisited[i][j-1] == false && L <= abs(arr[i][j - 1] - currentPeople) && abs(arr[i][j - 1] - currentPeople) <= R)
		{
			countryCount++;
			peopleSum += arr[i][j - 1];
			isVisited[i][j-1] = true;
			dfsStack.push(make_pair(i, j-1));
			s.push(make_pair(i, j-1));
			isAdjacent = true;
		}
		if (j < N-1 && isVisited[i][j + 1] == false && L <= abs(arr[i][j + 1] - currentPeople) && abs(arr[i][j+1] - currentPeople) <= R)
		{
			countryCount++;
			peopleSum += arr[i][j + 1];
			isVisited[i][j + 1] = true;
			dfsStack.push(make_pair(i, j + 1));
			s.push(make_pair(i, j + 1));
			isAdjacent = true;
		}
		if (isAdjacent == false)
		{
			dfsStack.pop();
		}
	}
	if (s.size() != 1)
	{
		while (!s.empty())
		{
			pair<int, int> currentTop = s.top();
			arr[currentTop.first][currentTop.second] = peopleSum / countryCount;
			s.pop();
		}
		canMove = true;
	}
	else
	{
		s.pop();
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N>>L >> R;
	arr = new int*[N];
	isVisited = new bool* [N];
	int day = 0;
	for (int i = 0; i < N; i++)
	{
		arr[i] = new int[N];
		isVisited[i] = new bool[N];
		for (int j = 0; j < N; j++)
		{
			cin >> arr[i][j];
			isVisited[i][j] = false;
		}
	}
	while (true)
	{
		canMove = false;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (isVisited[i][j] == false)
				{
					dfs(i, j);
				}
			}
		}
		if (canMove == false)
		{
			break;
		}
		else
		{
			for (int i = 0; i < N; i++)
			{
				for (int j = 0; j < N; j++)
				{
					isVisited[i][j] = false;
				}
			}
		}
		day++;
	}
	cout << day << "\n";
	return 0;
}