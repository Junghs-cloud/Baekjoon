#include <iostream>
#include <queue>
#include <utility>
using namespace std;
int** temp;
int** arr;
int N, M;
bool** isVisited;
int searchCount;

queue<pair<int, int>> bfsQueue;

void search(int i, int j)
{
	bfsQueue.push(make_pair(i, j));
	isVisited[i][j] = true;
	while (!bfsQueue.empty())
	{
		int x = bfsQueue.front().first;
		int y = bfsQueue.front().second;
		if (x > 0 && arr[x - 1][y] != 0 && isVisited[x-1][y] == false)
		{
			isVisited[x-1][y] = true;
			bfsQueue.push(make_pair(x- 1, y));
		}
		if (x < N-1 && arr[x+ 1][y] != 0 && isVisited[ x + 1 ][ y ] == false)
		{
			isVisited[x+1][y] = true;
			bfsQueue.push(make_pair(x+ 1, y));
		}
		if (y> 0 && arr[x][y-1] != 0 && isVisited[x][y-1] == false)
		{
			isVisited[x][y-1] = true;
			bfsQueue.push(make_pair(x, y-1));
		}
		if (y < M - 1 && arr[x][y+1] != 0 && isVisited[x][y+1] == false)
		{
			isVisited[x][y+1] = true;
			bfsQueue.push(make_pair(x, y+1));
		}
		bfsQueue.pop();
	}
}

void melt(int i, int j)
{
	if (i > 0 && arr[i-1][j]==0 && temp[i][j] != 0)
	{
		temp[i][j]--;
	}
	if (i < N - 1 && arr[i + 1][j] == 0 && temp[i][j] != 0)
	{
		temp[i][j]--;
	}
	if (j > 0 && arr[i][j - 1] == 0 && temp[i][j] != 0)
	{
		temp[i][j]--;
	}
	if (j < M - 1 && arr[i][j + 1] == 0 && temp[i][j] != 0)
	{
		temp[i][j]--;
	}
}

void copy(int** a, int** b)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			a[i][j] = b[i][j];
		}
	}
}

void resetVisitArr()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			isVisited[i][j] = false;
		}
	}
}

bool checkInitial()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (arr[i][j] != 0 && isVisited[i][j] == false)
			{
				searchCount++;
				if (searchCount >= 2)
				{
					return true;
				}
				else
				{
					search(i, j);
				}
			}
		}
	}
	return false;
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	arr = new int*[N];
	temp = new int* [N];
	isVisited = new bool*[N];
	int year = 0;
	for (int i = 0; i < N; i++)
	{
		arr[i] = new int[M];
		temp[i] = new int[M];
		isVisited[i] = new bool[M];
		for (int j = 0; j < M; j++)
		{
			arr[i][j] = 0;
			isVisited[i][j] = false;
			cin >> arr[i][j];
		}
	}
	if (checkInitial() == true)
	{
		cout << year << "\n";
		return 0;
	}
	resetVisitArr();
	while (true)
	{
		searchCount = 0;
		copy(temp, arr);
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if (arr[i][j] != 0)
				{
					melt(i, j);
				}
			}
		}
		copy(arr, temp);
		bool noIce = true;
		bool isBroken = false;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if (arr[i][j] != 0 && isVisited[i][j]==false)
				{
					noIce = false;
					searchCount++;
					if (searchCount >= 2)
					{
						isBroken = true;
						break;
					}
					else
					{
						search(i, j);
					}
				}
			}
		}
		if (noIce==true)
		{
			year = 0;
			break;
		}
		year++;
		if (isBroken == true )
		{
			break;
		}
		resetVisitArr();

	}
	cout << year << "\n";
	return 0;
}